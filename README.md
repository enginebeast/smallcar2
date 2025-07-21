< [Main Page](https://enginebeast.github.io/) < [RC car project](https://enginebeast.github.io/RCcar)

If you want to use the code, click 'View on Github' button.

### Result
```
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
```

### Process
First, I programmed a servo motor to change angle gradually.

When I simulate the code below on Tinkercad, it works fine. But, it does not work on real hardware. I concluded its because delay in this code is too short, so the servo motor cannot react to signal of the Arduino board. So, I gave up the method that didn't work, and select a method to change angle of the servo motor suddenly.

But, I have to find a way to change angle gradually, because in the real environment there are always sudden changes.

```
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
