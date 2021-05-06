const int trigPin_one(2); //pin D2
const int echoPin_one(3); //pin D3
const int trigPin_two(4); //pin D4
const int echoPin_two(5); //pin D5
const int proxPin(6);     //pin D6
const int relay_one(7);   //pin D7
const int relay_two(8);   //pin D8
const int relay_three(9); //pin D9

uint32_t tickms(0);

void setup() {
  // put your setup code here, to run once:
  
  //ultrasonic sensor define pin mode
  pinMode(trigPin_one, OUTPUT);
  pinMode(trigPin_two, OUTPUT);
  pinMode(echoPin_one, INPUT);
  pinMode(echoPin_two, INPUT);
 
  //proximity sensor define pin mode
  pinMode (proxPin, INPUT_PULLUP);

  //relay output define mode
  pinMode (relay_one, OUTPUT);
  pinMode (relay_two, OUTPUT);
  pinMode (relay_three, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - tickms >= 100){
    tickms = millis();
    
//    unsigned long distance1 = readUS_one();
//    unsigned long distance2 = readUS_two();
//    bool proxCondition = readProx();
//
//    Serial.print("ultraSonic 1:");
//    Serial.print(distance1);
//    Serial.println("mm");
//
//    Serial.print("ultraSonic 2:");
//    Serial.print(distance2);
//    Serial.println("mm");
//
//    Serial.print("proximity: ");
//    if(proxCondition){
//      Serial.println("on");
//    }else{
//      Serial.println("off");
//    }

    algorithm();
    
  }
} 
