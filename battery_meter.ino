#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);
  analogWrite(13, 10);
  delay(5000);
}

void loop() {
  int V = analogRead(9);
  V = V/19.9+2;
  lcd.clear();
  lcd.print(V);
}
