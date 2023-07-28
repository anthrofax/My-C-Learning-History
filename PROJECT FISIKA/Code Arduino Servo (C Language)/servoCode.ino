#include <Servo.h>
Servo myservo1, myservo2;
int angle =0;
int angleStep =50;

void setup() { 
  myservo1.attach(8);
  myservo2.attach(9);
  pinMode(2,INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2) == HIGH){
myservo1.write(-180);
myservo2.write(-180);

  }
  else {
  myservo1.write(180);
  myservo2.write(180);


  }
}
