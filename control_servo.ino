#include <Servo.h>

Servo servo1;
char button;
int angle = 1500;

void setup(){
  Serial.begin(9600);
  servo1.attach(8, 500, 2500);
  servo1.write(angle);
}

void loop(){
   if (Serial.available()) {
    button = Serial.read();
  }
    
  if (button  == 'a'){
    if (angle < 2500)
      angle += 4;
  }
  
  else if (button  == 's'){
    if (angle > 2250)
      angle -= 4;
    else if (angle < 2250)
      angle += 4;
  }
  
  else if (button  == 'd'){
    if (angle > 2000)
      angle -= 4;
    else if (angle < 2000)
      angle += 4;
  }
  
  else if (button  == 'f'){
    if (angle > 1750)
      angle -= 4;
    else if (angle < 1750)
      angle += 4;
  }
  
  else if (button == 'g' || button == 'h'){
    if (angle > 1500)
      angle -= 4;
    else if (angle < 1500)
      angle += 4;
  }
  
  else if (button  == 'j'){
    if (angle > 1250)
      angle -= 4;
    else if (angle < 1250)
      angle += 4;
  }

  else if (button  == 'k'){
    if (angle > 1000)
      angle -= 4;
    else if (angle < 1000)
      angle += 4;
  }
  
  else if (button  == 'l'){
    if (angle > 750)
      angle -= 4;
    else if (angle < 750)
      angle += 4;
  }
  
  else if (button  == ';'){
    if (angle > 1000)
      angle -= 4;
  }
  
  servo1.writeMicroseconds(angle);
  delay(5);
}