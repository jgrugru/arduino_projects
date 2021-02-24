int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(25);
  digitalWrite(led, LOW);
  delay(975);
}
