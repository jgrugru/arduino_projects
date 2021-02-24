int xAxis_pin = A0;
int yAxis_pin = A1;
int xLed = A2;
int yLed = A3;
int xPosition, yPosition; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(yAxis_pin, INPUT);
pinMode(xAxis_pin, INPUT);
pinMode(xLed, OUTPUT);
pinMode(yLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("xaxis: ");
  xPosition = map(analogRead(xAxis_pin), 0, 1023, 0, 255);
  //xPosition = analogRead(xAxis_pin);
  Serial.println(xPosition);
  Serial.print("yaxis: "); 
  analogWrite(xLed, xPosition);

  
  yPosition = map(analogRead(yAxis_pin), 0, 1023, 0, 255);
  //yPosition = analogRead(yAxis_pin);
  Serial.println(yPosition);
  analogWrite(yLed, yPosition);
  //delay(1000);
}
