//specify pins for communicating with the sensor
byte trig_pin = 10;
byte echo_pin = 9;
byte dht11_pin = 11;

//list all function headers
void sendPulse();
double calculateDistance(double);
void sendStartSignal();
bool checksum(int, int, int, int, int);
void dht11();

//create global variables
bool startSignalSent = false;

byte dht11Data[4];


void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  //Code for the ultrasonic sensor
  //  double duration;
  //  sendPulse();
  //  duration = pulseIn(echo_pin, HIGH);
  //Serial.println(calculateDistance(duration));

  //Code for the dht11 sensor
  dht11();
}
//***********************************************
//***********************************************

void dht11() {
  byte dht11Response[45];
  long int responseTime = micros();
  int bitCounter = 0;
  bool binary_alternator = false;

  if (!startSignalSent) {
    startSignalSent = true;
    sendStartSignal();
  }
  else {
    while (micros() - responseTime < 150) { //captures lengths of signals
      if (digitalRead(dht11_pin) == 0 && !binary_alternator) {
        binary_alternator = true;
        dht11Response[bitCounter] = micros() - responseTime;
        bitCounter++;
        responseTime = micros();
      }
      else if (digitalRead(dht11_pin) == 1) {
        binary_alternator = false;
      }
    }

    for (int x = 2; x < bitCounter; x++) { //determine if 1 or 0 bit, store in dht11Response[]
      if (dht11Response[x] <= 90)
        dht11Response[x] = 0;
      else
        dht11Response[x] = 1;
      //Serial.print(dht11Response[x]); Serial.print(" ");

    }

    for (int  j = 0; j < 5; j++) { // redo it for the 5 Bytes (40 Databits /8 = 5)
      for (int  i = 0; i < 8; i++) {
        int index = i + 2 + (j * 8);
        bitWrite(dht11Data[j], 7 - i, dht11Response[index]); // Create 5 Databytes from the 40 Databits (Ignoring the 2 first Databits)
      }
      //Serial.println(dht11Data[j]);     
    }
     if (checksum(dht11Data[4], dht11Data[0], dht11Data[1], dht11Data[2], dht11Data[3])) {
        Serial.print("Humidity: "); Serial.print(dht11Data[0]); Serial.print("."); Serial.println(dht11Data[1]);
        Serial.print("Temperature: "); Serial.print(dht11Data[2]); Serial.print("."); Serial.println(dht11Data[3]);
        Serial.print("Checksum: "); Serial.println(dht11Data[4]);
        Serial.println("-----------");
        startSignalSent = false;

      }
      else Serial.println("Checksum wasn't a success");
    delay(2600);
  }
}

void sendStartSignal() {
  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH); //set as high and wait for the dht11 to enter energy saving mode
  delay(250);
  digitalWrite(dht11_pin, LOW); //send out the starting signal with voltage drop of 18ms or greater
  delay(30);
  digitalWrite(dht11_pin, HIGH);
  delayMicroseconds(50);
  pinMode(dht11_pin, INPUT);
}

bool checksum(int sum, int v1, int v2, int v3, int v4) {
  if (v1 + v2 + v3 + v4 == sum ) {
    return true;
  }
  else
    return false;
}

//void sendPulse() {
//  digitalWrite(trig_pin, LOW);
//  delayMicroseconds(10);
//  digitalWrite(trig_pin, HIGH);
//}
//
//double calculateDistance(double duration) {
//  return (0.034 * (duration)) / 2.0;
//}
