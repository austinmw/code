
/* Four bit counter 
Aleks Zosuls Boston University 2015
This outputs a four bit binary count on Analog pins A0:A3
Good for testing DACs in EK307 labs.
As of 9 March 2015 this is untested code use at your own risk
*/

int i =0;  //counter increment
byte toPort;  //counter value cast as a byte
const int LED = 13;  //Built in Arduino Uno LED

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);  //set LED pin as an output
  DDRC = DDRC | B00001111;    //set analog pins 0-3 as digital outputs
}  //end of setup function

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);  
  for(i=0; i<16; i++){
      toPort = byte(i);  //cast byte as binary
      PORTC = B00001111 & toPort; //write lower nibble on portc use mask to protect high nibble
      delay(20);
    }  //end of for loop
  digitalWrite(LED, LOW);
  delay(100);
}  //end of main loop
