#include <Servo.h>

Servo servo;
int a,c;

void setup (){
  Serial.begin(9600);
  servo.attach (10);
}

void medir(){
  a = analogRead(A0);
  Serial.println(a);
  delay (200);
}
void mapear(){
  a = analogRead(A0);
  c = map(a, 0, 650, 0, 180);
  servo.write (c);
  Serial.println(c);
  delay (200);
}
void loop (){
  mapear();
  //medir();
}

// arriba 70
// abajo 0
