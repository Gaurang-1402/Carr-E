#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>

// Compass
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

Adafruit_LSM9DS1 compass = Adafruit_LSM9DS1();                   // Compass

void setupCompass();
float getHeading();

void setup() {
  Serial.begin(9600);
  setupCompass();
}

void loop() {
  // Compass - Get Heading Angle
  float heading = getHeading();
  Serial.print("Heading: "); Serial.println(heading);

  delay(1000);
}

// Defined functions
void setupCompass() {
  compass.begin();
  
  // 1.) Set the accelerometer range
  compass.setupAccel(compass.LSM9DS1_ACCELRANGE_2G);
  
  // 2.) Set the magnetometer sensitivity
  compass.setupMag(compass.LSM9DS1_MAGGAIN_4GAUSS);

  // 3.) Setup the gyroscope
  compass.setupGyro(compass.LSM9DS1_GYROSCALE_245DPS);

  Serial.println("Compass set up");
}

float getHeading() {
    compass.read();
    sensors_event_t a, m, g, temp;
    compass.getEvent(&a, &m, &g, &temp);

    float x, y, z, heading;
    x = m.magnetic.x;
    y = m.magnetic.y;
    z = m.magnetic.z;

//    Serial.print(x); Serial.print(", "); Serial.print(y); Serial.print(", "); Serial.println(z);
    
//    
//    if (y > 0) {
//        heading = 90 - atan2(m.magnetic.x, m.magnetic.y) * 180 / PI;
//    } else if (y < 0) {
//        heading = 270 - atan2(m.magnetic.x, m.magnetic.y) * 180 / PI;
//    } else if (y == 0) {
//        if (x < 0) {
//            heading = 180;
//        } else if (x > 0) {
//            heading = 0;
//        }
//    }

    heading = atan2(m.magnetic.y, m.magnetic.x) * 180 / PI;
//    heading += 13; // -13 is declination angle in New York
    
    return heading;
}
