int ledPin = 5;
int buttonOnPin = 9;
int buttonOffPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP); 
}

void loop(){
  if(digitalRead(buttonOnPin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  
  if(digitalRead(buttonOffPin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
