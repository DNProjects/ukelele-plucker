#include <Servo.h>

// Pins
const int servoPin1 = 3;
const int servoPin2 = 4;
const int servoPin3 = 5;
const int servoPin4 = 6;

//Motor A
const int motorPin1  = 7;  // Pin 7 of L293
const int motorPin2  = 8;  // Pin 8 of L293

//Motor B
const int motorPin3  = 9;  // Pin 9 of L293
const int motorPin4  = 10; // Pin 10 of L293

//Motor C
const int motorPin5  = 11; // Pin 11 of L293
const int motorPin6  = 12; // Pin 12 of L293

//Motor D
const int motorPin7  = 13; // Pin 13 of L293
const int motorPin8  = 14; // Pin 14 of L293

// create servo object to control a servo
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

// Populate
int rotateA[] = {0, 3};
int rotateB[] = {0, };
int rotateC[] = {0, };
int rotateD[] = {0, };

// Current Rotation Index of DC Motors
int currA = 0;
int currB = 0;
int currC = 0;
int currD = 0;

// Servo objects can be created on most boards
#define WAIT 1000
#define ROTATE 35
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
  return;
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
}

void setup() {
  mySetUp();
  
  // Music Here
  // Maybe rotate motorD back????
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

  currA = moveDCMotor(currA, 1, motorPin1, motorPin2, rotateA);
  pick(servo1);

  // Stop all DC motors
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
        
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 0);
  
  analogWrite(motorPin7, 0);
  analogWrite(motorPin8, 0);
}

void loop() {

}

//void loop() {
//    servo1.write(INITIAL+ROTATE);
//    delay(WAIT);
//    servo2.write(INITIAL+ROTATE);
//    delay(WAIT);
//    servo3.write(INITIAL+ROTATE);
//    delay(WAIT);
//    servo4.write(INITIAL+ROTATE);
//    delay(WAIT);
//    
//    servo4.write(INITIAL-ROTATE);
//    delay(WAIT);
//    servo3.write(INITIAL-ROTATE);
//    delay(WAIT);
//    servo2.write(INITIAL-ROTATE);
//    delay(WAIT);
//    servo1.write(INITIAL-ROTATE);
//    delay(WAIT);
//  }
