< [Main Page](https://enginebeast.github.io/) < [RC car project](https://enginebeast.github.io/RCcar)

If you want to use the code, click 'View on Github' button.

### Error code
```C++
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
    if (angle > 2000)
      angle -= 4;
    else if (angle < 2000)
      angle += 4;
  }
  
  else if (button == 'd'){
    if (angle > 1500)
      angle -= 4;
    else if (angle < 1500)
      angle += 4;
  }

  else if (button  == 'f'){
    if (angle > 1000)
      angle -= 4;
    else if (angle < 1000)
      angle += 4;
  }
  
  else if (button  == 'g'){
    if (angle > 500)
      angle -= 4;
  }
  
  servo1.writeMicroseconds(angle);
  delay(5);
}
```
