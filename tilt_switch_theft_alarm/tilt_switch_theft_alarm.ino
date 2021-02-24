int ledPin = 8;
int buzzerPin = 9;
int tiltPin = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
  
  //Make sure LED and buzzer are turned off
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop(){
  
  if(digitalRead(tiltPin) == HIGH){
   digitalWrite(ledPin, HIGH);
   digitalWrite(buzzerPin, HIGH); 
  }
  
  if(digitalRead(tiltPin) == LOW){
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW); 
  }
}
