#define LEFTHE_PIN 3
#define RIGHTHE_PIN 2
#define CARLENFT .521
#define WHEELLENFT .133

volatile double gxPos = 0;
volatile double gyPos = 0;
volatile double ganglePos = 1.57;
int glastRightCount = 0;
int glastLeftCount = 0;
volatile int gleftcount = 0;
volatile int grightcount = 0;

void LEFTHE_ISR() {
  gleftcount++;
  updatePos();
  
  
}

void RIGHTHE_ISR() {
  grightcount++;
 
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
   Serial.print("X POS IS :");
   Serial.println(gxPos, DEC);
   Serial.print("Y POS IS :");
   Serial.println(gyPos, DEC);
   Serial.print("left: ");
  Serial.println(gleftcount, DEC);
   Serial.print("right: ");
  Serial.println(grightcount, DEC);
  Serial.print("distance traveled: ");
  Serial.println(distanceTraveled, DEC);
   Serial.print("angle: ");
  Serial.println((ganglePos*180/3.14), DEC);
  Serial.println("*****************************");
}
void setup() {
  attachInterrupt(1, LEFTHE_ISR, FALLING);
  attachInterrupt(0, RIGHTHE_ISR, FALLING);
  sei();
  Serial.begin(9600);
}

void loop() {
  
}
