// Libraries
#include <SoftwareSerial.h>
#include <Servo.h>

// Servo pins
#define ESC_PIN 5
#define WHEEL_PIN 6

// Lidar pins
#define L_LIDAR_TRIG 13
#define L_LIDAR_MON 10
#define L_LIDAR_ENABLE 4
#define R_LIDAR_TRIG 8
#define R_LIDAR_MON 9
#define R_LIDAR_ENABLE 12

// Ultrasonic pins
#define ULTRA_LEFT 11 
#define ULTRA_RIGHT 7 // 7

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  GLOBAL VARS    GLOBAL VARS    GLOBAL VARS    GLOBAL VARS    GLOBAL VARS    GLOBAL VARS    GLOBAL VARS  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Set these
//const double minHallWidthInFt = 0;  // 5
//const int padding = 50;

// Remote
SoftwareSerial XBee(2,3); // RX, TX
int Start = 0;

// Servo global variables
Servo wheels;
Servo esc;

// Lidar readings
unsigned long lidar_L, lidar_R;
double leftDistance, rightDistance;

// Ultrasonic global variables
int objectDetected = 0;

// PID global variables
unsigned long lastTime;
double input, output, setpoint;
double error, errSum, lastInput;
double kp, ki, kd;
int sampleTime = 10; // 20ms    (check lidar maximum sample time)

// Movement
int minHallWidth;
int sign;
int Angle;
int Speed;
int elevator = 0;

// corner variables
int cornerBins[4] = {1, 6, 11, 18};
int binNum = 0;

// Manual controls
int driveMode = 0; // 0 for autonomous, 1 for manual (toggled with manualToggle)
int stopToggle = 0; // 0 for stopped, 1 for not stopped
int manualSpeed = 90;
int manualAngle = 90;
const char manualToggle = 'T';
const char manualIncreaseSpeed = 'U';
const char manualDecreaseSpeed = 'D'; // also works to reverse
const char manualLeftTurn = '<';
const char manualRightTurn = '>';
const char manualCenter = 'C';
const char manualStopToggle = 'S';


int turnCount = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT    PRINT  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Print() {
  // Lidars
  Serial.print("Left: ");
  Serial.print(leftDistance);
  Serial.print("cm       ");
  Serial.print("Right: ");
  Serial.print(rightDistance);
  Serial.println("cm");
  // PID
  Serial.print("turnCount: ");
  Serial.println(turnCount);
  Serial.print("Setpoint: ");
  Serial.println(setpoint);
  Serial.print("input: ");
  Serial.println(input);
  Serial.print("lastInput: ");
  Serial.println(lastInput);
  Serial.print("error: ");
  Serial.println(error);
  Serial.print("errSum: ");
  Serial.println(errSum);
  Serial.print("output: ");
  Serial.println(output);
  Serial.print("sign: ");
  Serial.println(sign);
  // Set values
  Serial.print("Speed: ");
  Serial.println(Speed);
  Serial.print("Angle: ");
  Serial.println(Angle);
  if (Angle < 90)
    Serial.println("RIGHT turn");
  else 
    Serial.println("LEFT turn");
  Serial.println("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  AUXILIARY FUNCTIONS    AUXILIARY FUNCTIONS    AUXILIARY FUNCTIONS    AUXILIARY FUNCTIONS  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void SetHall()
{
  if (minHallWidthInFt != 0)
   minHallWidth = int(minHallWidthInFt / 0.032808);
  else if (minHallWidthInFt == 0){
    Serial.println("Looking at lidar distances to determine hall width.");
    PollLidars();
    Serial.print("Left: ");
    Serial.print(leftDistance);
    Serial.print("cm       ");
    Serial.print("Right: ");
    Serial.print(rightDistance);
    Serial.println("cm");
    Serial.println((leftDistance + rightDistance + 5) / 2);
    
    minHallWidth = (leftDistance + rightDistance + 5) / 2;
    // hardcode for now
    minHallWidth = 87;
  }
  else 
    Serial.println("\nDEBUG\n");
}

void signMultiplier()
{
    char m = minSide();
    if (m == 'L')
      sign = -1;
    else
      sign = 1; 
}

char minSide() 
{
  if (leftDistance < rightDistance)
    return 'L';
   else
    return 'R';
}

int farWalls() 
{
  if ((leftDistance > 200) && (rightDistance > 200))
    return 3;
  else if ((leftDistance > 150) && (rightDistance > 150))
    return 2;
  else if ((leftDistance > 100) && (rightDistance > 100))
    return 1;
  else 
    return 0;
}


bool all_are(char* i_begin, size_t sz, char x)
{
  for (int i = 0; i < queueSize; i++) {
    if (i_begin[i] != x)
      return false;
  }
  return true;

  //  const int* i_end = i_begin + sz;
 //   for(; i_begin != i_end; ++i_begin)
 //       if(*i_begin != x) return false;
//    return true;
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  SETPOINT/INPUT/SPEED  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AdjustSetpoint() 
{


  if (!elevator) 
    setpoint = 75;

   
    

/*
  if (leftDistance > 150) { // corner turn
    esc.write(90);
    setpoint = 25.55; 
  }
   // no walls
  else if ((leftDistance >= 150) && (rightDistance >= 150)) 
    setpoint = 0;
  // two walls (center)
  else if ((leftDistance < 150) && (rightDistance < 150))    
    setpoint = (leftDistance+rightDistance)/2; // middle distance
  // one wall (follow wall)
  else 
    setpoint = (minHallWidth + padding) / 2; // cm

  */
}

void AdjustInput()
{
  
  
   if (((rightDistance > 100) || (rightDistance <= 1)) && (turnCount == 1)) {
    input = leftDistance;
    turnCount++; // testingthis
    Serial.println("\n\nSWITCHING FROM RIGHT WALL!\n\n");
   }
   else if (turnCount == 1) {
    input = rightDistance;
    Serial.println("\ninput is rightDistance\n");
   }
   else if (leftDistance <= 1)
    input = 1000;
   else 
    input = leftDistance;

/*
  if (setpoint == 0)
    input = 0;
  // one wall
  else if (setpoint == (minHallWidth + padding) / 2) {
    // set input to shorter side
    char s = minSide();
    if (s == 'L')
      input = leftDistance;
    else
      input = rightDistance;
  }
  // two walls
  else if (setpoint == (leftDistance+rightDistance)/2) {
        char s = minSide();
    if (s == 'L')
      input = leftDistance;
    else
      input = rightDistance; 
  }
  */
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID    PID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetTunings(double Kp, double Ki, double Kd) 
{
   double sampleTimeInSec = ((double)sampleTime)/1000;
   kp = Kp;
   ki = Ki * sampleTimeInSec;
   kd = Kd / sampleTimeInSec;
}

void SetsampleTime(int NewsampleTime) 
{
   if (NewsampleTime > 0)
   {
      double ratio  = (double)NewsampleTime / (double)sampleTime;
      ki *= ratio;
      kd /= ratio;
      sampleTime = (unsigned long)NewsampleTime;
   }
}

void Compute() 
{
   unsigned long now = millis();
   int timeChange = (now - lastTime);
   if(timeChange>=sampleTime)
   {
      /*Compute all the working error variables*/
      error = setpoint - input;

      /*
      Serial.print("debug: setpoint: ");
      Serial.println(setpoint);
      Serial.print("debug: input: ");
      Serial.println(input);
      Serial.print("debug: error: ");
      Serial.println(error);
      */
      
      errSum += error;
      double dInput = (input - lastInput);
 
      /*Compute PID output*/
      output = kp * error + ki * errSum - kd * dInput;
      if ((input == 0) && (setpoint == 0)) // no walls, go straight
        output = 0;
 
      /*Remember some variables for next time*/
      lastInput = input;
      lastTime = now;
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE   MOVE  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Move() {
  double limitedOutput;
  //signMultiplier();

  
  if (abs(output) >= 85)
    limitedOutput = 85 * ((output > 0) - (output < 0));
  else limitedOutput = output;     

  //Angle = 90 + sign*limitedOutput;

    if ((input == leftDistance) || (input == 1000))
      Angle = 90 - limitedOutput;
    else
      Angle = 90 + limitedOutput;



  if (elevator)
    wheels.write(90);
  else if (((leftDistance > 350) || (leftDistance <= 1)) && (input == leftDistance)) {
    turnCount++;
    Serial.println("\nFIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!");
    Serial.println("FIRST TURN!!!!!!!!!\n");
    TurnCorner();
      
    
    //wheels.write(180);
    }
  else
    wheels.write(Angle);
  
  if (!objectDetected) 
    Forward(); 
    /*
  else // try this out
  {
    
    Angle = -Angle;
    wheels.write(Angle);
    esc.write(110);
    delay(2000);
  } */
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FORWARD/REVERSE   FORWARD/REVERSE   FORWARD/REVERSE   FORWARD/REVERSE   FORWARD/REVERSE   FORWARD/REVERSE  

void Forward() 
{
  /*
  if (error < 10)
    Speed = 60;
  else if (error < 20)
    Speed = 65;
  else if (error < 30) 
    Speed = 70;
  else
    Speed = 75;
  */
  Speed = 69;   //71
  esc.write(Speed);

  /*
  // change this a bit later
   if (setpoint == 25.55) {
     Speed = 66;
   }

   else if ((Angle > 70) && (Angle < 110) && (leftDistance > 48) && (rightDistance > 48))
    Speed = 55; // 
   else
    Speed = 58;    // 58
  esc.write(Speed);
  */
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS    LIDARS  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PollLidars()
{
  lidar_L = pulseIn(L_LIDAR_MON, HIGH) / 10; // 10usec = 1 cm of distance for LIDAR-Lite
  lidar_R = pulseIn(R_LIDAR_MON, HIGH) / 10;
  leftDistance = double(lidar_L);
  rightDistance = double(lidar_R);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  ULTRASONIC    ULTRASONIC    ULTRASONIC    ULTRASONIC    ULTRASONIC    ULTRASONIC    ULTRASONIC    ULTRASONIC  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PollUltrasonic() 
{
  if(digitalRead(ULTRA_LEFT) && digitalRead(ULTRA_RIGHT)) {
    esc.write(90);
    objectDetected = 1;
    Serial.println("\n\n  STOPPING!\n  STOPPING!\n  STOPPING!\n\n");
  }  
  else
    objectDetected = 0;  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF    ON/OFF  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CheckOn() 
{
  char r;
  String incomingData;
  if (XBee.available()) {
  do {
    r = XBee.read();
    incomingData += r;   
  } 
  while (r != -1);
  incomingData = incomingData.substring(0,incomingData.length() - 1);
  }
  
  // Check data for server shutdown signal while awaiting handshake
  for (int i=0;i<incomingData.length();i++) {
    // Quit command received
    if (incomingData[i] == '1') {
      Serial.println("Remote ON received. Calibrating ESC.");
      Start = 1;
    }
  }
}

void CheckSignals() 
{
  char r;
  String incomingData;

  do {
    r = XBee.read();
    incomingData += r;   
  } 
  while (r != -1);
  incomingData = incomingData.substring(0,incomingData.length() - 1);
  
  
  // Check data for server shutdown signal while awaiting handshake
  for (int i=0;i<incomingData.length();i++) {
    // Quit command received
    if (incomingData[i] == 'Q') {
      Serial.println();
      Serial.println("Remote OFF received. Exiting Loop.");
      Serial.println();
      esc.write(90);
      Start = 0;
      objectDetected = 0;
      binNum = 0;
      driveMode = 0; 
      stopToggle = 0; 
      manualSpeed = 90;
      manualAngle = 90;  
      turnCount = 0;
      delay(250);
      setup();
    }
    else if (incomingData[i] == manualToggle) {
      driveMode = !driveMode;
      manualSpeed = 90;
      manualAngle = 90;
      stopToggle = 0;
      Serial.print("\nToggling auto/manual modes. Current mode: ");
      Serial.println(driveMode);
      Serial.println();
    }
    else if (incomingData[i] == manualStopToggle) {
        stopToggle = !stopToggle;
        Serial.print("\nToggling start/stop. Current mode: ");
        Serial.println(stopToggle);
        Serial.println();
    }
    else if (incomingData[i] == manualIncreaseSpeed) {
        manualSpeed -= 5;
        Serial.print("\nIncreasing speed. Current speed: ");
        Serial.println(manualSpeed);
        Serial.println();
    }
    else if (incomingData[i] == manualDecreaseSpeed) {
        manualSpeed += 5;
        Serial.print("\nDecreasing speed. Current speed: ");
        Serial.println(manualSpeed);
        Serial.println();
    }  
    else if (incomingData[i] == manualLeftTurn) {
        manualAngle += 15;
        Serial.print("\nIncreasing left turn. Current angle: ");
        Serial.println(manualAngle);
        Serial.println();
    }    
    else if (incomingData[i] == manualRightTurn) {
        manualAngle -= 15;
        Serial.print("\nIncreasing right turn. Current angle: ");
        Serial.println(manualAngle);
        Serial.println();
    }
    else if (incomingData[i] == manualCenter) {
        manualAngle = 90;
        Serial.print("\nCentering wheels. Current angle: ");
        Serial.println(manualAngle);
        Serial.println();
    }          
   
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  CORNERS    CORNERS    CORNERS    CORNERS    CORNERS    CORNERS    CORNERS    CORNERS    CORNERS    CORNERS  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int CheckCorners()
{
  int inCorner;
  if ((binNum != cornerBins[0]) && (binNum != cornerBins[1]) 
      && (binNum != cornerBins[2]) && (binNum != cornerBins[3]))
    inCorner = 0;
  else
    inCorner = 1;
  return inCorner; 
}
*/
void TurnCorner() {

  wheels.write(175);
  esc.write(69);
  delay(3000);
  
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
  // Serial monitor
  Serial.begin(9600);

  // Xbee start
  XBee.begin(9600);
  
  // Servo attach
  esc.attach(ESC_PIN);
  wheels.attach(WHEEL_PIN);

  // Remote start
  for (int i = 0; i < 100; i++)
  Serial.println();
  Serial.println("Arduino on. Waiting for remote start.\n");

  // Servo calibration
  //delay(100);
  esc.write(90); // neutral
  delay(500);
  
  //Left lidar
  pinMode(L_LIDAR_TRIG, OUTPUT);
  pinMode(L_LIDAR_MON, INPUT);
  pinMode(L_LIDAR_ENABLE, OUTPUT);
  digitalWrite(L_LIDAR_ENABLE, HIGH); //Turn sensor on
  digitalWrite(L_LIDAR_TRIG, LOW); // Set trigger LOW for continuous read
  
  // Right lidar
  pinMode(R_LIDAR_TRIG, OUTPUT);
  pinMode(R_LIDAR_MON, INPUT);
  pinMode(R_LIDAR_ENABLE, OUTPUT);
  digitalWrite(R_LIDAR_ENABLE, HIGH); //Turn sensor on
  digitalWrite(R_LIDAR_TRIG, LOW); // Set trigger LOW for continuous read

  // Ultrasonics
  pinMode(ULTRA_LEFT, INPUT);
  pinMode(ULTRA_RIGHT, INPUT);

  // initialize PID variables
  SetTunings(0.65,0.0,0.02);
  SetsampleTime(10); 

    while (!Start) {
    CheckOn();
  }  
  delay(500);
    
  // Corresponds to follow distance if not two walls
  // Should probably add option for dynamic adjustment in beginning
  //SetHall();

  Serial.print("Minimum hall width: ");
  Serial.print(minHallWidth);
  Serial.println("cm");
  Serial.println("Starting...");
  Serial.println("\n");
  delay(1000);
}
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() 
{
  
  // incoming data
  if (XBee.available()) 
    CheckSignals();
  else
  {  
      // autonomous driving
      if (driveMode == 0) {
        // forward collision detection
         PollUltrasonic();
          // Moving
          PollLidars();
          AdjustSetpoint(); 
          AdjustInput();  
          Compute();
          Move();
          // Serial Monitor
          Print();
        
      }
      // manual driving
      else // driveMode == 1
      {
        if (!stopToggle) {
          esc.write(manualSpeed);
          wheels.write(manualAngle);   
        }
        else 
          esc.write(90);
        
      }

  }
}

