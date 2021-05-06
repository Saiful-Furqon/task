void algorithm() {


  //if(state == 4 && left == 0){
  //  digitalWrite(motor_right, HIGH);
  //  digitalWrite(motor_left, HIGH);
  //  delay(1000);
  //  state = 1;
  //}
  //else {
  //  digitalWrite(motor_right, LOW);
  //  digitalWrite(motor_left, LOW);
  //}
  //1 -> motor stop in the left
  //2 -> motor moving to right
  //3 -> motor stop in the right
  //4 -> motor moving to left



  if (left == LOW && state == 4) {

    digitalWrite(motor_left, HIGH);
    digitalWrite(motor_right, HIGH);
    if (trig == false) {
      digitalWrite(motor_on, LOW);
    }
    else if (trig == true) {
      digitalWrite(motor_on, HIGH);
      state = 1;
    }
  }

  if (state == 1) {
    digitalWrite(motor_left, LOW);
    digitalWrite(motor_right, HIGH);
    state = 2;
  }
  if (state == 2 && trig == false) {
    state = 3;
  }

  if (right == LOW && state == 2) {
    digitalWrite(motor_left, HIGH);
    digitalWrite(motor_right, HIGH);
    state = 3;
  }

  if (state == 3) {
    digitalWrite(motor_left, HIGH);
    digitalWrite(motor_right, LOW);
    state = 4;
  }

}
