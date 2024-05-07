#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,6,4,3,2);
const int temprature=A0;
const int D=8;
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(D,OUTPUT);
}
void loop()
{
  digitalWrite(D,LOW);
  int Temp=analogRead(temprature);
  float volts=(Temp/965.0)*5;
  float celcius =(volts-0.5)*100;
  float farenheit=(celcius*9/5+32);
  Serial.println(farenheit);
  lcd.setCursor(5,0);
  lcd.print(farenheit);
  delay(20);
}

