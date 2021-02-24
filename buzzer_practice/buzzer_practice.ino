/////*
////  Melody
////
//// Plays a melody
////
//// circuit:
//// * 8-ohm speaker on digital pin 8
////
//// created 21 Jan 2010
//// modified 30 Aug 2011
//// by Tom Igoe
////
////This example code is in the public domain.
////
//// http://www.arduino.cc/en/Tutorial/Tone
////
//// */
////#define NOTE_C4  262
////#define NOTE_G3  196
////#define NOTE_A3  220
////#define NOTE_B3  247
////#define NOTE_C4  262
////
////
////// notes in the melody:
////int melody[] = {
////  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
////};
////
////// note durations: 4 = quarter note, 8 = eighth note, etc.:
////int noteDurations[] = {
////  4, 8, 8, 4, 4, 4, 4, 4
////};
////
////void setup() {
////  // iterate over the notes of the melody:
////  for (int thisNote = 0; thisNote < 8; thisNote++) {
////
////    // to calculate the note duration, take one second
////    // divided by the note type.
////    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
////    int noteDuration = 1000 / noteDurations[thisNote];
////    tone(8, melody[thisNote], noteDuration);
////
////    // to distinguish the notes, set a minimum time between them.
////    // the note's duration + 30% seems to work well:
////    int pauseBetweenNotes = noteDuration * 1.30;
////    delay(pauseBetweenNotes);
////    // stop the tone playing:
////    noTone(8);
////  }
////}
////
////void loop() {
////  // no need to repeat the melody.
////}
//
//
//
///*
//  Keyboard
//
//  Plays a pitch that changes based on a changing
//  input circuit:
//  * 3 pushbuttons from +5V to analog in 0 through
//  3
//  * 3 10K resistors from analog in 0 through 3 to
//  ground
//  * 8-ohm speaker on digital pin 8
//*/
//
//int pos = 0;
//
//void setup()
//{
//  pinMode(A0, INPUT_PULLUP);
//  pinMode(8, OUTPUT);
//  pinMode(A1, INPUT_PULLUP);
//  pinMode(A2, INPUT_PULLUP );
//}
//
//void loop()
//{
//  // if button press on A0 is detected
//  if (digitalRead(A0) == HIGH) {
//    tone(8, 247, 100); // play tone 57 (A4 = 440 Hz)
//  }
//  // if button press on A1 is detected
//  if (digitalRead(A1) == HIGH) {
//    tone(8, 262, 100); // play tone 59 (B4 = 494 Hz)
//  }
//  // if button press on A0 is detected
//  if (digitalRead(A2) == HIGH) {
//    tone(8, 294, 100); // play tone 60 (C5 = 523 Hz)
//  }
//    if (digitalRead(A3) == HIGH) {
//    tone(8, 330, 100); // play tone 59 (B4 = 494 Hz)
//  }
//  // if button press on A0 is detected
//  if (digitalRead(A4) == HIGH) {
//    tone(8, 350, 100); // play tone 60 (C5 = 523 Hz)
//  }
//  delay(10); // Delay a little bit to improve simulation performance
//}



int buzzerPin = 3;

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop(){

  
  for(int i=0; i<250; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(1);
    digitalWrite(buzzerPin, LOW);
    delay(1);
  }

  for(int i=0; i<125; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(2);
    digitalWrite(buzzerPin, LOW);
    delay(2);
  }
    
}
