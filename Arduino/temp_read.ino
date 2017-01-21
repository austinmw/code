#include <SoftwareSerial.h>
#include <math.h>

/*
VERY ACCURATE TEMPERATURE READINGS
----------------------------------
Better voltage reading:
  Used A2 pin (less jumpy)
  Got two measurements each pull, discarded the first
Better R_therm reading:
  Measured V_source accurately
  measured R1 accurately
Better temperature reading:
  Used accurate temperature sensor to get 3 data points
  Solved resulting system of equations for Steinhart-Hart coefficients
  Base conversion (needed base-2 instead of base-10)
  (temp slightly rising at start due to current self-heating unavoidable with thermistor)
*/

// Global variables
int AnalogPin = A2; // has much less jumpy readings than A0 (maybe A0 slightly damage from overuse)
float V_source = 4.90; // measured
SoftwareSerial XBee(2,3); // RX, TX
// used in main loop but need to initialize here
String randID = "";
int handshake = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////

// Calculate thermistor voltage
float Voltage(float RawADC) {
  float meter_calibration = 0; // don't seem to need, matches my multimeter exactly
  float V_therm = (V_source * RawADC) / 1024.0;
  V_therm += meter_calibration;
  return V_therm;
}
// Calculate thermistor resistance
// sometimes a bit off what voltage divider eq says it should be (probably due to input impedance of ADC)
float Thermistor(float V_therm) {
  float resistance_calibration = 25; // possibly small breadboard/wires resistance
  float R_known = 560 + resistance_calibration; // measured (1% tol resistor)
  float R_therm =  ((R_known * V_therm) / (V_source - V_therm));
  return R_therm;
}
// Base conversion
float log2(float num) {
  return (log(num) / log(2));
}
// Calculate temperature
float Temperature(float R_therm) {
  float A = -0.000857348;
  float B = 0.000275445;
  float C = 0.000000234994;
  float temp_K = 1 / (A + B*log2(R_therm) + C*pow(log2(R_therm),3));
  return temp_K;
}
// Convert to Celsius or Fahrenheit
float ConvertTemp(float temp_K, char T) {
  if (T == 'C')  
    return (temp_K - 273.15);
  else if (T == 'F') 
    return (temp_K * 1.8 - 459.67);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(AnalogPin, INPUT);
  XBee.begin(9600);
  for (int i=0; i<100; i++) 
    Serial.print("\n"); 
  // Random ID
  handshake = 0;
  randomSeed(analogRead(0));
  long randNumber = random(1000000);
  randID = String(randNumber);
  randID = "#" + randID;
  // Broadcast ID
  Serial.print("Sending ");
  Serial.println(randID);
  XBee.print(randID); // ascii text
  XBee.write("\n");  // binary data
}

// MAIN LOOP
void loop() {
  char r;
  String incomingData;
  // Allow data reception while waiting for handshake confirmation
  while (!handshake) { 
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
        if (incomingData[i] == 'Q') {
          Serial.println();
          Serial.println("Quit command received: Stopping broadcast. Push reset on node to reconnect.");
          Serial.println();
          delay(1000);
          handshake = 0;
          exit(0);
        }
      }    
      // Proper handshake confirmation received
      if (incomingData == randID) {
        Serial.println("Handshake established! Preparing to send data.");
        Serial.println();
        handshake = 1;
      }
  }
  // Handshake established, node is member of server's connectedNodes array
  while (handshake) {
  
      // Check for quit signal while connection is established
      if (XBee.available()) { 
        char r;
        String incomingData;
        do {
          r = XBee.read();
          incomingData += r;   
        } 
        while (r != -1);
        incomingData = incomingData.substring(0,incomingData.length() - 1);
        // Print received data when it's finished streaming in
        //Serial.print("incomingData: "); // DELETE LATER
        //Serial.println(incomingData);   // DELETE LATER 
        // Check data for server shutdown signal while awaiting handshake
        for (int i=0;i<incomingData.length();i++) {
          // Quit command received
          if (incomingData[i] == 'Q') {
            Serial.println();
            Serial.println("Quit command received: Stopping broadcast. Push reset on node to reconnect.");
            Serial.println();
            handshake = 0;
          }
        }  
      }       
    else {
      // ~~~~~~~~~ DATA CALCULATION AND BROADCASTING ~~~~~~~~~ 
      // Only send data if server is not broadcasting
      if (!XBee.available()) {    
        // ADC and V_therm values
        // give multiplexed analog pins time to settle by discarding first reading and averaging 2nd,3rd
        float RawADC_1 = analogRead(AnalogPin); // toss 1
        float RawADC_2 = analogRead(AnalogPin); // average 2,3
        float RawADC_3 = analogRead(AnalogPin);
        float RawADC_avg = (RawADC_2 + RawADC_3) / 2.00;
        Serial.print("Raw ADC value: ");
        Serial.println(RawADC_avg);
        float V_therm = Voltage(RawADC_avg);
        Serial.print("Voltage across thermistor: ");
        Serial.println(V_therm);
        
        // Thermistor resistance
        float R_therm = Thermistor(V_therm);    
        Serial.print("Resistance of thermistor: ");
        Serial.println(R_therm);
      
        // Temperature in Kelvin, Celsius, Fahrenheit
        float temp_K = Temperature(R_therm);
        Serial.print(temp_K);
        Serial.print("K   ");
        float temp_C = ConvertTemp(temp_K, 'C');
        float temp_F = ConvertTemp(temp_K, 'F');
        Serial.print(temp_C);
        Serial.print("C   ");
        Serial.print(temp_F);
        Serial.println("F   ");

        // Send XBee data
        String sendData = (randID + "   " + String(temp_F));
        XBee.print(sendData); // ascii text
        XBee.write("\n");  // binary data
        Serial.print("Message sent to XBee: ");
        Serial.println(sendData);
        Serial.println();
        delay(2000); // 2s interval
      }
    }
  } // end handshake loop  
} // end main loop
