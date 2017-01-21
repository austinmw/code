/* Two ultrasonic sensors for collision detection
Angled on front sides

Checks for object and sends digital high if distance is less than set threshold
(ran out of pwm pins on main arduino)
*/
#include <SharpIR.h>

// sharp
#define SHARP_LEFT 2
#define SHARP_RIGHT 3
#define LEFT_OUTPUT 3 
#define RIGHT_OUTPUT 2 

// distance to stop
int stopThreshold = 60; 

// vars
int disLeft, disRight;
int model = 20150;

void setup()
{
    // Serial monitor
  Serial.begin(9600);
  // pins
  pinMode(LEFT_OUTPUT, OUTPUT);
  pinMode(RIGHT_OUTPUT, OUTPUT); 
}

void loop()
{
  delay(50);
  
  // sharp
  SharpIR sharpLeft(SHARP_LEFT, 25, 93, model);
  SharpIR sharpRight(SHARP_RIGHT, 25, 93, model);
  disLeft = sharpLeft.distance();
  disRight = sharpRight.distance();

  if (disLeft < 0)
    disLeft = 100;
  if (disRight < 0)
    disRight = 100;
  

   // print distances
  Serial.print("\n\nLeft distance: ");
  Serial.println(disLeft);
  Serial.print("Right distance: ");
  Serial.println(disRight);


  // set output pins high on detection, print detection messages
  if (disLeft < stopThreshold) {
    digitalWrite(LEFT_OUTPUT, HIGH); 
    Serial.println("  LEFT object detected!");
  }    
  else
    digitalWrite(LEFT_OUTPUT, LOW);

  if (disRight < stopThreshold) {
    digitalWrite(RIGHT_OUTPUT, HIGH);
    Serial.println("  RIGHT object detected!");
  }
  else
    digitalWrite(RIGHT_OUTPUT, LOW);

 
}

