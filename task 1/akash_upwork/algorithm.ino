void algorithm(){

    
    static int timer_one = 0;  
    static int timer_two = 0;
    static int timer_three = 0;
    static unsigned int state_one = 0;
    static unsigned int state_two = 0;
    static unsigned int state_three = 0;
    
  
    //0 -> idle state
    //1 -> timer on state
    //2 -> debounce state
    //3 -> waiting clear state
    
    unsigned long distance1 = readUS_one();
    unsigned long distance2 = readUS_two();
    bool proxCondition = readProx();

    bool trig_one;11
    bool trig_two;
    
    if (distance1 > 20 && distance1 < 50){
      trig_one = true;
    }else{
      trig_one = false;
    }

    if(distance2 > 20 && distance2 < 50){
      trig_two = true;
    }else{
      trig_two = false;
    }

    
    //sensor 1 (ultrasonic) ******************************************************************************
    if(trig_one && state_one == 0){
      state_one = 1;

      //activate relay
      digitalWrite(relay_one, HIGH);
    }
    if(state_one == 1 && timer_one >= 10){
      state_one = 2;
      timer_one = 0;
      
      //deactivate relay
      digitalWrite(relay_one, LOW);
    }
    if(state_one == 2 && timer_one >= 20){
      state_one = 3;
      timer_one = 0;
    }

    if(state_one == 3 && trig_one == false){
      state_one = 0;
    }
    // sensor 2 (ultrasonic)**************************************************************************************************** 
    if(trig_two && state_two == 0){
      state_two = 1;

      //activate relay
      digitalWrite(relay_two, HIGH);
 
    }
    if(state_two == 1 && timer_two >= 10){
      state_two = 2;
      timer_two = 0;
      
      //deactivate relay
      digitalWrite(relay_two, LOW);
 
    }
    if(state_two == 2 && timer_two >= 20){
      state_two = 3;
      timer_two = 0;

    }
    if(state_two == 3 && trig_two == false){
      state_two = 0;
    }

    //sensor 3 (proximity) *******************************************************************************
    if(proxCondition && state_three == 0){
      state_three = 1;

      //activate relay
      digitalWrite(relay_three, HIGH);
      
      
    }
    if(state_three == 1 && timer_three >= 10){
      state_three = 2;
      timer_three = 0;
      
      //deactivate relay
      digitalWrite(relay_three, LOW);
      
    }
    if(state_three == 2 && timer_three >= 20){
      state_three = 3;
      timer_three = 0;
      
    }
    if(state_three == 3 && proxCondition == false){
      state_three = 0; 
      
    }


    //ACTION///###########################################################################################################################

    //sensor ultrasonic 1
    if(state_one == 1){
      timer_one++;
    }
    if(state_one == 2){
      timer_one++;
    }

    //sensor ultrasonic 2
    if(state_two == 1){
      timer_two++;
    }
    if(state_two == 2){
      timer_two++;
    }
    
    //sensor proximity
    if(state_three == 1){
      timer_three++;
    }
    if(state_three == 2){
      timer_three++;
    }
   ////#################################################################################################################################
}
