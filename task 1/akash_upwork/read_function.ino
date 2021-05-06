int readUS_one(){ //return distance in mm
  unsigned long duration;
  int distance;

  //clear trigger pin
  digitalWrite(trigPin_one, LOW);
  delayMicroseconds(2);

  //set the trigPin on HIGH for 10us
  digitalWrite(trigPin_one, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_one, LOW);

  //read echo pin pulse duration
  //return us in unsigned long type
  duration = pulseIn(echoPin_one, HIGH, 24000);

  //calculate distance
  // sound speed 343 m/s = 0.343 mm/us
  // multiply duration with 0.343 will result distance
  // divide by 2

  //datasheet min distance 2cm; max 4m
  
  distance = duration * 22479 >> 17; //result in mm
  
  return distance;  
}

int readUS_two(){ //return distance in mm
  unsigned long duration;
  int distance;

  //clear trigger pin
  digitalWrite(trigPin_two, LOW);
  delayMicroseconds(2);

  //set the trigPin on HIGH for 10us
  digitalWrite(trigPin_two, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_two, LOW);

  //read echo pin pulse duration
  //return us in unsigned long type
  //timeout 24 ms for 4m
  duration = pulseIn(echoPin_two, HIGH, 24000);

  //calculate distance
  // sound speed 343 m/s = 0.343 mm/us
  // multiply duration with 0.343 will result distance
  // divide by 2

  //datasheet min distance 2cm; max 4m
  
  distance = duration * 22479 >> 17; //result in mm
  
  return distance;  
}


bool readProx(){
  int readPin = digitalRead(proxPin);
  bool logiclvl;
  if (readPin == 1){
    logiclvl = false;
  }else{
    logiclvl = true;
  }
  return logiclvl;
}
