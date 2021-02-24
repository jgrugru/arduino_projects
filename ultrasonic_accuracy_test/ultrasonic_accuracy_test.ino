
//specify pins for communicating with the sensor
byte trig_pin = 10;
byte echo_pin = 9;

//list all function headers
void sendPulse();
double calculateDistance(double);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Code for the ultrasonic sensor
  double duration;
  sendPulse();
  duration = pulseIn(echo_pin, HIGH);
  Serial.println(calculateDistance(duration));
}

void sendPulse() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(trig_pin, HIGH);
}

double calculateDistance(double duration) {
  return (0.034 * (duration)) / 2.0;
}
