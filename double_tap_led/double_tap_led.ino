//int ledPin = 8;
//int buzzerPin = 9;
//int tiltPin = 10;
//
//void setup() {
//  pinMode(ledPin, OUTPUT);
//  pinMode(tiltPin, INPUT_PULLUP);
//  Serial.begin(9600);
//  //Make sure LED and buzzer are turned off
//  digitalWrite(ledPin, LOW);
//}
//
//
//int countOfTaps = 0;
//int previousCountOfTaps = 0;
//boolean ledIsOn = false;
//
//void loop(){
//  
//  if(digitalRead(tiltPin) == HIGH){
//    countOfTaps += 1;
//    delay(25);
//    Serial.println("Count of taps: " + countOfTaps);
//    digitalWrite(ledPin, HIGH);
//  }
//  else{
//   previousCountOfTaps = countOfTaps;
//   
//  if(countOfTaps > previousCountOfTaps + 75){
//    if (ledIsOn){
//     digitalWrite(ledPin, LOW);
//    }
//    else{
//     digitalWrite(ledPin, HIGH);
//     ledIsOn = true;
//    }
//   Serial.println("previous count of taps: " + previousCountOfTaps); 
//  }
//
//  }
//}

int ledPin = 8;
int tiltPin = 10;
int countOfTaps = 0;
unsigned long delayStart = 0;
boolean delayRunning = false;
boolean isLedOn = false;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop(){
  if ((millis() - delayStart) >= 1000){  //check if delay is running and if it is over
    if(countOfTaps >= 25){  //if delay is over, enter this loop and check the set amount of taps
      toggleLed();          //toggle the led to its opposite state
    }
    delayRunning = false;
    countOfTaps = 0;
  }
  
  if(digitalRead(tiltPin) == HIGH){  //if a tap is detected, enter this if loop
    countOfTaps += 1;                //start counting the # of taps
    Serial.println(countOfTaps);
    if(delayRunning){
      if ((millis() - delayStart) >= 1000){  //check if delay is running and if it is over
        Serial.println("Ending delay");
        
        if(countOfTaps >= 25){  //if delay is over, enter this loop and check the set amount of taps
          toggleLed();          //toggle the led to its opposite state
        }
        startDelay();
      }
    }
    else{
      Serial.println("beginning delay");
      startDelay();
    }
  }
}

void startDelay(){
  countOfTaps = 0;
  delayStart = millis();
  delayRunning = true;
}

void toggleLed(){
  if(isLedOn){
    digitalWrite(ledPin, LOW);
    isLedOn = false;
  }
  else{
    digitalWrite(ledPin, HIGH);
    isLedOn = true;
  }
}

