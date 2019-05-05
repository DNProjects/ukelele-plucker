#include <Servo.h>

// Pins
const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
const int servoPin4 = 5;

//Motor A
const int motorPin1  = 6;  // Pin 6 of L293
const int motorPin2  = 7;  // Pin 7 of L293

//Motor B
const int motorPin3  = 8;  // Pin 8 of L293
const int motorPin4  = 9; // Pin 9 of L293

//Motor C
const int motorPin5  = 10; // Pin 10 of L293
const int motorPin6  = 11; // Pin 11 of L293

//Motor D
const int motorPin7  = 12; // Pin 12 of L293
const int motorPin8  = 13; // Pin 13 of L293

// create servo object to control a servo
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

// Populate
int rotateA[] = {0, 3000, 3725, 4000};
int rotateB[] = {0, 3000, 3725, 4000 };
int rotateC[] = {0, 3000, 3725, 4000 };
int rotateD[] = {0, 3000, 3725, 4000 };

// Current Rotation Index of DC Motors
int currA = 0;
int currB = 0;
int currC = 0;
int currD = 0;

int wait = 100;

// Servo objects can be created on most boards
#define WAIT 1000
#define ROTATE 20
#define INITIAL 90 - (ROTATE/2)

bool isLeft(int pos) {
  // If isLeft == True, then +ROTATE. else -ROTATE
  if(pos < 90) {
    return true; 
  }
  return false;
}

void pick(Servo servo) {
  if(isLeft(servo.read())){
    servo.write(INITIAL + ROTATE);
  } else {
    servo.write(INITIAL - ROTATE);
  }
}

int moveDCMotor(int curr, int dest, int motorPinA, int motorPinB, int rotateArr[]) {
  // DC Motor that moved will not have the destination Index (currA, currB, currC, currD)
  if(dest == curr) {
    return curr;
  }
  
  if(dest > curr) {
    // We have to go up
    int rotate =  rotateArr[dest] - rotateArr[curr];
    analogWrite(motorPinA, 0);
    analogWrite(motorPinB, rotate);
  }
  
  if(dest < curr) {
    // We have to go down
    int rotate = rotateArr[curr] - rotateArr[dest];
    analogWrite(motorPinA, rotate);
    analogWrite(motorPinB, 0);
  }
  
  return dest;
}

void mySetUp(){
  // Initial Setting Up
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  
  servo1.write(INITIAL);
  servo2.write(INITIAL);
  servo3.write(INITIAL);
  servo4.write(INITIAL);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);

  servo1.write(INITIAL+ROTATE);
  servo2.write(INITIAL+ROTATE);
  servo3.write(INITIAL+ROTATE);
  servo4.write(INITIAL+ROTATE);
}


void pickAllString(){
  pick(servo1);
  delay(wait);
  pick(servo2);
  delay(wait);
  pick(servo3);
  delay(wait);
  pick(servo4);

  delay(750);

  pick(servo4);
  delay(wait);
  pick(servo3);
  delay(wait);
  pick(servo2);
  delay(wait);
  pick(servo1);

  delay(750);

  pick(servo1);
  delay(wait);
  pick(servo2);
  delay(wait);
  pick(servo3);
  delay(wait);
  pick(servo4);

  delay(750);

  pick(servo4);
  delay(wait);
  pick(servo3);
  delay(wait);
  pick(servo2);
  delay(wait);
  pick(servo1);
}

void part2And4(){
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(3000);
  pick(servo4);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(4250);
  pick(servo4);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(500);
  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(3725);
  pick(servo4);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(500);

  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(1525);
  pick(servo4);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(500);

    digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000);
  pick(servo4);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(500);

  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(1675);  

    digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void setup() {
  mySetUp();
  
  // Music Here
  // Rotate MotorD Back Manually
  /* example of picking a note
    currA = moveDCMotor(currA, 1, motorPin1, motorPin2, rotateA);
    pick(servo1);
    currB = moveDCMotor(currB, 2, motorPin3, motorPin4, rotateB);
    pick(servo2);
    currC = moveDCMotor(currC, 3, motorPin5, motorPin6, rotateC);
    pick(servo3);
    currD = moveDCMotor(currD, 4, motorPin7, motorPin8, rotateD);
    pick(servo4);
  */

  delay(5000);

  
  // Part 1
  pick(servo4);
  delay(2500);
  pick(servo1);
  delay(2500);
  pick(servo4);
  delay(3000);

  // Part 2
  part2And4();

  // Part 3
  pick(servo2);
  delay(3000);
  pick(servo3);
  delay(3000);
  pick(servo4);

// Part 4
  part2And4();
  pick(servo4);

  

  
  // Stop all DC motors
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
}

void loop() {

}
