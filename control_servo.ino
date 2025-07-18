#include <Servo.h>

Servo servo1;
char button;r
void setup(){
  Serial.begin(9600);
  servo1.attach(8, 500, 2500);
  servo1.writeMicroseconds(1500);
}

void loop(){
   if (Serial.available()) {
    button = Serial.read();
  }
    
  if (button  == 'a'){
    servo1.writeMicroseconds(2500);
    delay(500);
  }
  
  else if (button  == 's'){
    servo1.writeMicroseconds(2000);
    delay(500);
  }

  else if (button  == 'd'){
    servo1.writeMicroseconds(1500);
    delay(500);
  }

  else if (button  == 'f'){
    servo1.writeMicroseconds(1000);
    delay(500);
  }

  else if (button  == 'g'){
    servo1.writeMicroseconds(500);
    delay(500);
  }
}
