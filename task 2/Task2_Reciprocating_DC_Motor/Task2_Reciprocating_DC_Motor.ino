
const int motor_right(12);
const int motor_left(7);
const int motor_on(9);
const int limit_right(4);
const int limit_left(3);
int state = 4;
unsigned long jeda = 0;
int left, right, nilai;
bool trig;

uint8_t read_2_button() { // read button if there is logic change
  uint8_t button = digitalRead(2);
  static uint8_t button_z = 1;
  uint8_t event = 0;

  if (button_z == 1 && button == 0) {
    event = 1;
  }

  button_z = button;
  if (event == 1) {
    trig = !trig;
  }
  Serial.print("buttonState :");
  Serial.println(button_z);
  return event;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_right, OUTPUT);
  pinMode(motor_left, OUTPUT);
  pinMode(motor_on, OUTPUT);
  pinMode(limit_right, INPUT_PULLUP); //ini ngikutin modulku
  pinMode(limit_left, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // detecting push button & limit switch
  left = digitalRead(limit_left);
  right = digitalRead(limit_right);
  //  nilai = digitalRead(motor_on);

  if (millis() - jeda >= 100) {
    jeda = millis();
    read_2_button();
    algorithm();
  }


  //  Serial.print("trig :");
  //  Serial.println(trig);
  //    Serial.print("motor_on :");
  //    Serial.println(nilai);
  //    Serial.print("limit_left :");
  //    Serial.println(left);
  //    Serial.print("limit_right :");
  //    Serial.println(right);
  //      Serial.print("state :");
  //      Serial.println(state);

}
