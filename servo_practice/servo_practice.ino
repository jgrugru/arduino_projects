
#include <Servo.h>

Servo myServo;
int servoDelay = 1000;
int servoMax = 180;
int servoMin=0;
int servoPos=0;
int timerSeconds=60;



void setup(){
  myServo.attach(9);
  
}


void loop(){
//  myServo.write(servoMax);
//  delay(servoDelay);
//  
//  myServo.write(servoMin);
//  delay(servoDelay);
  
  //creates a 60 second countdown on the servo
  for(servoPos=servoMin; servoPos <= servoMax; servoPos += (servoMax/timerSeconds)){
    myServo.write(servoPos);
    delay(servoDelay);
  }
  
}
