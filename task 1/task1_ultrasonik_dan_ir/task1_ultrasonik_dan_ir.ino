const int ultra1Pin = 5;    //pin i/o for ultrasonic sensor 1
const int ultra2Pin = 6;    //pin i/o for ultrasonic sensor 2
const int irPin = 7;        //pin i/o for ir proximity sensor 
int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int read_ir = HIGH;
long duration_1, duration_2, distance_1, distance_2;
unsigned long cur_time, prev_time, on_time1, on_time2, on_time3; 
unsigned long check1, check2, check3, delay1, delay2, delay3;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  cur_time = millis();
  prev_time = 0;
  check1 = 0;
  check2 = 0;
  check3 = 0;
  on_time1 = 0;
  on_time2 = 0;
  on_time3 = 0;
  delay1 = 0;
  delay2 = 0;
  delay3 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (cur_time - prev_time >= 100) {
    prev_time = cur_time;
    //send out a signal for ultrasonic sensor 1 and ultrasonic sensor 2
    pinMode(ultra1Pin, OUTPUT);
    pinMode(ultra2Pin, OUTPUT);
    digitalWrite(ultra1Pin, LOW);   //Give a short LOW pulse beforehand to ensure a clean HIGH pulse
    digitalWrite(ultra2Pin, LOW);
    delayMicroseconds(2); 
    digitalWrite(ultra1Pin, HIGH);
    digitalWrite(ultra2Pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(ultra1Pin, LOW);
    digitalWrite(ultra2Pin, LOW);
    pinMode(ultra1Pin, INPUT);
    pinMode(ultra2Pin, INPUT);

    //reading signal with ultrasonic sensor 1 
    if (cur_time - check1 >= delay1) {
      duration_1 = pulseIn(ultra1Pin, HIGH);
      distance_1 = microsecondsToCentimeters(duration_1);
      check1 = cur_time;
      on_time1 = cur_time;
    }
    //reading signal with ultrasonic sensor 2 
    if (cur_time - check2 >= delay2) {
      duration_2 = pulseIn(ultra2Pin, HIGH);
      distance_2 = microsecondsToCentimeters(duration_2);
      check2 = cur_time;
      on_time2 = cur_time;
    }
    //reading signal with ir proximity sensor 
    if (cur_time - check3 >= delay3) {
      read_ir = digitalRead(irPin);
      check3 = cur_time;
      on_time3 = cur_time;
    }      
  }
  //if an object is detected within 5 cm range in front of ultrasonic sensor 1
  if (distance_1 <= 5){
     digitalWrite(relay1, HIGH);   //relay 1 is on
     delay1 = 3000;                //this is so that the sensor is not triggered for the next 3sec
  }
  //if the object is leaving the 5 cm range then count for 1sec to turn off the relay 
  else if (distance_1 >= 5 && cur_time - on_time1 >= 1000) {
     delay1 = 0;                  //the sensor pause is lifted
     digitalWrite(relay1, LOW);   //relay 1 is off
  }
  //if there is no object detected
  else { 
    delay1 = 0;                   //the sensor pause is lifted                  
    digitalWrite(relay1, LOW);    //relay 1 is off
  }
  
  //this is for ultrasonic sensor 2 the content is similar
  if (distance_2 <= 5){
     digitalWrite(relay2, HIGH);
     delay2 = 3000;
  }
  else if (distance_2 >= 5 && cur_time - on_time2 >= 1000) {
     delay2 = 0;
     digitalWrite(relay2, LOW);
  }
  else {
    delay2 = 0;
    digitalWrite(relay2, LOW);
  }

  //this is for ir proximity sensor
  if (read_ir == LOW){
    digitalWrite(relay3, HIGH);
    delay3 = 3000;
  }
  else if (read_ir == LOW && cur_time - on_time3 >= 1000) {
     digitalWrite(relay2, LOW);
     delay3 = 0;
  }
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
