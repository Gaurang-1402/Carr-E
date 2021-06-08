// Import libraries
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

#define BLYNK_PRINT Serial

// Blynk Authentification Code
char auth[] = "Ud3tV2uChZarJXs2JKmRYtRHj4Pb-EYM";

// TX and RX pins
int BLUETOOTH_TX_PIN = 6;
int BLUETOOTH_RX_PIN = 5;

// Initialize SoftwareSerial object
SoftwareSerial SerialBLE(BLUETOOTH_TX_PIN, BLUETOOTH_RX_PIN);

void setupBluetooth();

void setup() {
  Serial.begin(9600); 
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
}

void loop() {
   Blynk.run();
}

BLYNK_WRITE(V0) {
  Serial.print("trying to get phone gps ");
  GpsParam gps(param);
  
  Serial.println("Received Mobile Phone GPS: ");
  
  // Print 7 decimal places for Lat
  Serial.print(gps.getLat(), 7); Serial.print(", "); Serial.println(gps.getLon(), 7);
}
