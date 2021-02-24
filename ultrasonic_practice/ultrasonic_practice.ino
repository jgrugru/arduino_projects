//specify pins for communicating with the sensor
int trig_pin = 10;
int echo_pin = 9;
int led_pin = 7;


void setup(){
  Serial.begin(9600);
  //  pinMode(led_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}


void loop(){
  double duration, distance;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(trig_pin, HIGH);

  duration = pulseIn(echo_pin, HIGH);
//  Serial.println(duration);
  distance = (0.034*(duration))/2.0;
  Serial.println(distance);
  //  Serial.println(distance);
  //  delay(1000);

  //  distance = (duration/2)/29.1;
  //  Serial.print(distance);
  //  Serial.println("CM");
  //  delay(100);
  //  
  //  
  //  if (distance <= 10){
  //    digitalWrite(led_pin, HIGH);
  //  }
  //  else{
  //   digitalWrite(led_pin, LOW); 
  //  }
}








//
//
//int countOfTaps = 0;
//unsigned long delayStart = 0;
//boolean delayRunning = false;
//
//void loop(){
//  if ((millis() - delayStart) >= 1000){  //check if delay is running and if it is over
//    if(countOfTaps >= 25){  //if delay is over, enter this loop and check the set amount of taps
//      toggleLed();          //toggle the led to its opposite state
//    }
//    delayRunning = false;
//    countOfTaps = 0;
//  }
//  
//  if(digitalRead(tiltPin) == HIGH){  //if a tap is detected, enter this if loop
//    countOfTaps += 1;                //start counting the # of taps
//    Serial.println(countOfTaps);
//    if(delayRunning){
//      if ((millis() - delayStart) >= 1000){  //check if delay is running and if it is over
//        Serial.println("Ending delay");
//        
//        if(countOfTaps >= 25){  //if delay is over, enter this loop and check the set amount of taps
//          toggleLed();          //toggle the led to its opposite state
//        }
//        startDelay();
//      }
//    }
//    else{
//      Serial.println("beginning delay");
//      startDelay();
//    }
//  }
//}
//
//void startDelay(){
//  countOfTaps = 0;
//  delayStart = millis();
//  delayRunning = true;
//}
