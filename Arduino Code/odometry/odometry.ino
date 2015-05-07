#include <Servo.h>

#define LEFTHE_PIN 3
#define RIGHTHE_PIN 2
#define CARLENFT .521
#define WHEELLENFT .0649
#define ULTRASONICCALIBRATE 90
#define STEERINGCALIBRATE 105

/*PINS IN USE*/
#define ULTRASOUNDSERVOPIN 9
#define STEERINGSERVOPIN 10
#define FORWARDSTEERPIN 8
#define TRIGPIN 7
#define ECHOPIN 6
#define ONOFF 5

volatile double gxPos = 0;
volatile double gyPos = 0;
volatile double ganglePos = 1.57;
volatile int glastRightCount = 0;
volatile int glastLeftCount = 0;
volatile int gleftcount = 0;
volatile int grightcount = 0;

int gforward = false;
int gon = false;
int steeringServoAngle = STEERINGCALIBRATE; 
int ultrasoundServoAngle = ULTRASONICCALIBRATE;
Servo steeringServo;
Servo ultrasoundServo;

void LEFTHE_ISR() {
  gleftcount++;
  updatePos();
}

void RIGHTHE_ISR() {
  grightcount++;
}

void printSurroundings(double distance, double angleRevise){
  Serial.print(gxPos, DEC);
  Serial.print(" ");
  Serial.print(gyPos, DEC);
  Serial.print(" ");
  Serial.print((ganglePos-angleRevise), DEC);
  Serial.print(" ");
  Serial.println(distance, DEC);
}

int ultrasoundRead(){
  digitalWrite(TRIGPIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGPIN, LOW);
  double duration = pulseIn(ECHOPIN, HIGH);
  double distance = (duration/2) / 29.1;
  return distance;
}

void scanSurroundings(){
  double duration, distance;
  int angleRotation = 45;
  boolean direction = false;
  double angleCalibrate = 0;
  for (int i = 160; i >= 30; i-=7.5){
      ultrasoundServo.write(i);
      delay(100);
      distance = ultrasoundRead();
      if (distance < 7 || distance > 150) distance = 0;
      angleCalibrate = (i-ULTRASONICCALIBRATE)*(3.14/180);
      printSurroundings(distance, angleCalibrate);
    }
}

void updatePos(){
  double rightChange = (grightcount - glastRightCount)*WHEELLENFT;
  double leftChange = (gleftcount - glastLeftCount)*WHEELLENFT;
    //Serial.print("RIGHT SPINS IS:");
  double theRightAnswer = grightcount - glastRightCount;
  double theLeftAnswer = gleftcount - glastLeftCount;
  //Serial.println(theRightAnswer, DEC);
  //Serial.print("LEFT SPINS IS:");
  //Serial.println(theLeftAnswer, DEC);
  glastLeftCount = gleftcount;
  glastRightCount = grightcount; 
  double distanceTraveled = (rightChange+leftChange)/2.0;
  double servoAngleDif = steeringServoAngle - ULTRASONICCALIBRATE;
  double angleChange = 2 * (rightChange - leftChange)/(2.0*CARLENFT);
  if (abs(servoAngleDif) < 15){
  	angleChange = 0;
  }
  /*servoangle and actual angle are opposites*/
  else if (servoAngleDif < -15 && angleChange < 0){
    angleChange = 0;
  }
  else if (servoAngleDif > 15 && angleChange > 0){
    angleChange = 0;
  }
  
  ganglePos += angleChange;
  double xChange = distanceTraveled*cos(ganglePos);
  double yChange = distanceTraveled*sin(ganglePos);
  gxPos += xChange;
  gyPos += yChange;
}

void printPos() {
//  Serial.print("X POS IS:");
//  Serial.print(gxPos, DEC);
//  Serial.println();
//  Serial.print("Y POS IS:");
//  Serial.print(gyPos, DEC);
//  Serial.println();
//  Serial.print("ANGLE IS");
//  Serial.print((ganglePos*180/3.14), DEC);
//  Serial.println();
//  Serial.println("***************************");
}

void setup() {
  attachInterrupt(1, LEFTHE_ISR, FALLING);
  attachInterrupt(0, RIGHTHE_ISR, FALLING);
  steeringServo.attach(STEERINGSERVOPIN);
  ultrasoundServo.attach(ULTRASOUNDSERVOPIN);
  steeringServo.write(steeringServoAngle);
  ultrasoundServo.write(ultrasoundServoAngle);
  sei();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char value = Serial.read();
    if (value == 'w'){
      gforward = !gforward;
      if(gforward) {
        digitalWrite(FORWARDSTEERPIN, LOW);
        digitalWrite(FORWARDSTEERPIN, HIGH);
        digitalWrite(FORWARDSTEERPIN, LOW);
//        Serial.println("GO FORWARD");
      }
      else {
        digitalWrite(FORWARDSTEERPIN, LOW);
        digitalWrite(FORWARDSTEERPIN, HIGH);
        digitalWrite(FORWARDSTEERPIN, LOW);
//        Serial.println("GO BACKWARD");
      }  
    }
    else if (value == 'd'){
      if (steeringServoAngle > 130) {
        steeringServoAngle = 132;
      }
      else {
        steeringServoAngle +=16;
      }
//      Serial.println("GO RIGHT");
//      Serial.println("STEERING ANGLE");
//      Serial.println(steeringServoAngle);
    }
    else if (value == 'a'){
      if (steeringServoAngle < 70) {
        steeringServoAngle = 68;
      }
      else {
        steeringServoAngle -=16;
      }
//      Serial.println("GO LEFT");
//      Serial.println("STEERING ANGLE");
//      Serial.println(steeringServoAngle);
    }
    else if (value == 'r'){
       steeringServoAngle = STEERINGCALIBRATE;
       ultrasoundServoAngle = ULTRASONICCALIBRATE;
       ultrasoundServo.write(ultrasoundServoAngle);
       gxPos = 0.0;
       gyPos = 0.0;
       ganglePos = 1.57;
       printPos();
    }
    else if (value == 's'){
//      Serial.println("SCAN SURROUNDINGS");
        scanSurroundings();
    }
    else if (value == 'o'){
        printPos();
        gon = !gon;
        if (gon){
          digitalWrite(ONOFF, LOW);
          digitalWrite(ONOFF, HIGH);
          digitalWrite(ONOFF, LOW);
//          Serial.println("ON");
        }
        else {
          digitalWrite(ONOFF, LOW);
          digitalWrite(ONOFF, HIGH);
          digitalWrite(ONOFF, LOW);
//          Serial.println("OFF");
        }
    }
    steeringServo.write(steeringServoAngle);
  }
  delay(50);
}
