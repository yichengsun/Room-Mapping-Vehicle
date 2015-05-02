#include <Servo.h>

#define LEFTHE_PIN 3
#define RIGHTHE_PIN 2
#define CARLENFT .521
#define WHEELLENFT .133
#define SERVOCALIBRATE 90

/*PINS IN USE*/
#define SERVOPIN 9
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
int servoAngle = 90;
Servo steeringServo;

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
  Serial.print((ganglePos+angleRevise), DEC);
  Serial.print(" ");
  Serial.println(distance, DEC);
}

int ultrasoundRead(){
  digitalWrite(TRIGPIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGPIN, LOW);
  long duration = pulseIn(ECHOPIN, HIGH);
  long distance = (duration/2) / 29.1;
  return distance;
}

void scanSurroundings(){
  long duration, distance;
  int angleRotation = 45;
  boolean direction = false;
  double angleCalibrate = 0;
  for (int i = 160; i >= 30; i-=4.5){
      steeringServo.write(i);
      delay(100);
      distance = ultrasoundRead();
      if (distance < 7 || distance > 150) distance = 0;
      angleCalibrate = (i-SERVOCALIBRATE)*(3.14/180);
      printSurroundings(distance, angleCalibrate);
    }
    for (int i = 30; i <= 160; i+=4.5){
      steeringServo.write(i);
      delay(100);
      distance = ultrasoundRead();
      if (distance < 7 || distance > 150) distance = 0;
       angleCalibrate = (i-SERVOCALIBRATE)*(3.14/180);
      printSurroundings(distance, angleCalibrate);
    } 
}

void updatePos(){
  double rightChange = (grightcount - glastRightCount)*WHEELLENFT;
  double leftChange = (gleftcount - glastLeftCount)*WHEELLENFT;
  glastLeftCount = gleftcount;
  glastRightCount = grightcount; 
  double distanceTraveled = (rightChange+leftChange)/2.0;
  double angleChange = 2 * (rightChange - leftChange)/(2.0*CARLENFT);
  ganglePos += angleChange;
  double xChange = distanceTraveled*cos(ganglePos);
  double yChange = distanceTraveled*sin(ganglePos);
  gxPos += xChange;
  gyPos += yChange;
}

void setup() {
  attachInterrupt(1, LEFTHE_ISR, FALLING);
  attachInterrupt(0, RIGHTHE_ISR, FALLING);
  steeringServo.attach(SERVOPIN);
  sei();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char value = Serial.read();
    if (value == 'w'){
      gforward = !gforward;
      if (gforward){     
          digitalWrite(FORWARDSTEERPIN, HIGH);
      }
      else {
        digitalWrite(FORWARDSTEERPIN, LOW);
      }
    }
    else if (value == 'd'){
      servoAngle +=7;
    }
    else if (value == 'a'){
      servoAngle-=7;
    }
    else if (value == 'r'){
       servoAngle = 90;
    }
    else if (value == 's'){
        scanSurroundings();
    }
    else if (value == 'o'){
        gon = !gon;
        if (gon){
          digitalWrite(ONOFF, HIGH);
        }
        else {
          digitalWrite(ONOFF, LOW);
        }
    }
    steeringServo.write(servoAngle);
  }
  steeringServo.write(90);
  Serial.println("lol");
  delay(50);
}
