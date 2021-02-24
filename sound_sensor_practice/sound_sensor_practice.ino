int sound_pin = 3;
int led_pin = 13;



void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(sound_pin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sound_pin)==HIGH){
    digitalWrite(led_pin, HIGH);
    Serial.println("1");
    
  }
  else{
    digitalWrite(led_pin, LOW);
    Serial.println("0");
  }
}
