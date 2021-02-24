#include <LiquidCrystal.h>



const int rs = 12, en=11, d4=5, d5=4, d6=3, d7=2, buttonPin=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool isPressed = false;

void setup()
{
  lcd.begin(16,2);
  lcd.print("hello, world");
  pinMode(buttonPin, INPUT);
  lcd.setCursor(0,1);
  lcd.print("it's not pressed"); 

}

void loop()
{
  lcd.setCursor(14,0);
  lcd.print(millis()/1000);
  lcd.setCursor(0,1);
  
  if(digitalRead(buttonPin) == HIGH){
    lcd.print("It's been pressed");
    //isPressed = !isPressed;
  }
//  else  {
//   lcd.print("it's not pressed"); 
//  }
  //if(isPressed){
  //  lcd.print("it is set");
  //}
  //else{
  //  lcd.print("it is not set");
  //}

  
}
