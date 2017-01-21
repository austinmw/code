#include <SoftwareSerial.h>

int redLED = 11;
int greenLED = 12;
int blueLED = 13;

SoftwareSerial XBee(2,3); // RX, TX

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  
  XBee.begin(9600);
  for (int i=0; i<100; i++) 
    Serial.print("\n"); 
  // Random ID
  Serial.println("Listening...");
}

// MAIN LOOP
void loop() {
  char r;
      if (XBee.available()) {
         r = XBee.read();
        //XBee.print("Listening...");
        //XBee.write("\n"); 
      }
        if (r == 'Q') {
          Serial.println(r);
          Serial.println();
          Serial.println("Turning LED OFF.");
          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, LOW);
          digitalWrite(blueLED, LOW);
          Serial.println();
          XBee.print("F");
          XBee.write("\n");
        }
       if (r == '1') {
          Serial.println(r);
          Serial.println();

          Serial.println("Turning red LED on.");
          digitalWrite(redLED, HIGH);
          digitalWrite(greenLED, LOW);
          digitalWrite(blueLED, LOW);
          Serial.println();
          XBee.print("R");
          XBee.write("\n");
        }   
        else if (r == '2') {
          Serial.println(r);
          Serial.println();
          Serial.println("Turning green LED on.");
          digitalWrite(greenLED, HIGH);
          digitalWrite(redLED, LOW);
          digitalWrite(blueLED, LOW);
          Serial.println(); 
          XBee.print("G");
          XBee.write("\n"); 
        }
        else if (r == '3') {
          Serial.println(r);
          Serial.println();
          Serial.println("Turning blued LED on.");
          digitalWrite(blueLED, HIGH);
          digitalWrite(greenLED, LOW);
          digitalWrite(redLED, LOW);
          Serial.println(); 
          XBee.print("B");
          XBee.write("\n"); 
        }       
}
