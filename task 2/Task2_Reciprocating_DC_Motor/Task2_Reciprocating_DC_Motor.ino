
const int motor_right(12);
const int motor_left(7);
const int motor_on(9);
const int limit_right(4);
const int limit_left(3);
const int button(2);
int state = 4;
bool trig;
unsigned long jeda = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 30;
int buttonState, left, right, nilai, reading;
int lastButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_right, OUTPUT);
  pinMode(motor_left, OUTPUT);
  pinMode(motor_on, OUTPUT);
  pinMode(limit_right, INPUT_PULLUP); //ini ngikutin modulku
  pinMode(limit_left, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);
  trig = true;
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // detecting push button & limit switch
  left = digitalRead(limit_left);
  right = digitalRead(limit_right);
  nilai = digitalRead(motor_on);
  reading = digitalRead(button);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
  if (buttonState == LOW) {
    trig = !trig;
  }
  lastButtonState = reading;

  if (millis() - jeda >= 100) {
    jeda = millis();
    algorithm();
  }

  //  Serial.print("buttonState :");
  //  Serial.println(buttonState);
  Serial.print("trig :");
  Serial.println(trig);
  //    Serial.print("motor_on :");
  //    Serial.println(nilai);
  //    Serial.print("limit_left :");
  //    Serial.println(left);
  //    Serial.print("limit_right :");
  //    Serial.println(right);
  //      Serial.print("state :");
  //      Serial.println(state);

}
