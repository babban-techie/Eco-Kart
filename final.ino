#include <LiquidCrystal.h>
#include <NewPing.h>
 
#define TRIGGER_PIN  10
#define ECHO_PIN     9
#define MAX_DISTANCE 200
#define RED 5
#define GREEN 8
int firepin = A0;
int fire = 0;
int led = 13;

char data = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   pinMode(led,OUTPUT);
  analogWrite(6,10);
  // Print a message to the LCD.
  lcd.print("BATTERY=96%");
   pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);

}

void loop() {
 
 int x = sonar.ping_cm();
  delay(50);
  if (x>20 || x==0)
  {
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
  }
  else
  {
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,HIGH);
  }
  Serial.print("Ping: ");
  Serial.print(x);
  Serial.println("cm");
    fire = analogRead(A0);
  if (fire<100)
  {
    Serial.println(fire);
    digitalWrite(led,HIGH);
  }
  else
  {
    Serial.println(fire);
    digitalWrite(led,LOW);
  }
}

