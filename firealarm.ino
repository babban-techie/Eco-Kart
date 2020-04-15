#include<Servo.h>

int firepin = A0;
int fire = 0;
int led = 13;
int pos = 0;

Servo myservo;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  myservo.attach(9);
}

void loop() {
  fire = analogRead(A0);
  if (fire<100)
  {
    Serial.println(fire);
    digitalWrite(led,HIGH);
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(2000);                       // waits 15ms for the servo to reach the position
  }
  else
  {
    Serial.println(fire);
    digitalWrite(led,LOW);
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(2000);              
  }
}
