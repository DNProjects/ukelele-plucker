#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
// twelve servo objects can be created on most boards
#define WAIT 1000
#define INITIAL 90
#define ROTATE 35
int pos = 0;

void setup() {
  //myservo.attach(9);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo1.write(INITIAL);
  servo2.write(INITIAL);
  servo3.write(INITIAL);
  servo4.write(INITIAL);
  
}

void loop() {
    servo1.write(INITIAL+ROTATE);
    delay(WAIT);
    servo2.write(INITIAL+ROTATE);
    delay(WAIT);
    servo3.write(INITIAL+ROTATE);
    delay(WAIT);
    servo4.write(INITIAL+ROTATE);
    delay(WAIT);
    
    servo4.write(INITIAL-ROTATE);
    delay(WAIT);
    servo3.write(INITIAL-ROTATE);
    delay(WAIT);
    servo2.write(INITIAL-ROTATE);
    delay(WAIT);
    servo1.write(INITIAL-ROTATE);
    delay(WAIT);
  }
