#include <Stepper.h>
#include <Servo.h>

int led = 13;
int x = 20;
const int steps = 260;// 360 number of steps per/rev                               
// initialize the stepper library on pins 2-5 n 8-11 
Stepper myStepper1(steps,2,3,4,5);
Stepper myStepper2(steps,8,9,11,12);  

Servo servo;

void setup() {
  pinMode(led, OUTPUT);
  // set the speed at 60 rpm:
  myStepper1.setSpeed(90);//left
  myStepper2.setSpeed(90);//right
  servo.attach (10);
  
  servo.write(60);//arriba
  delay (500); 
  servo.write(20);//abajo
  delay (1000); 
  servo.write(60);//arriba
  delay (500); 
}

void loop() { 
  
  for(int i=0;i<5;i++){
    digitalWrite(led, HIGH);  
    delay(50);                       
    digitalWrite(led, LOW);    
    delay(50);
  }
  
  myStepper1.step(steps); // x
  delay(x);   
  myStepper1.step(-steps); 
  delay(x); 
  
  myStepper2.step(steps);  // y
  delay(x); 
  myStepper2.step(-steps);
  delay(x);
   
  delay(2000);
}
