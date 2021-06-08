# Carr-e

Carr-E is an autonomous luggage cart that connects with a user’s mobile phone via bluetooth to follow them at the airport. The user can mount their luggage onto Carr-E before connecting their phone to the device via Bluetooth. Once connected, Carr-E will trace the coordinates of the mobile phone, placed in the user’s pocket, and follow the user around the airport.

To carry out Carr-E’s functions, Arduino IDE was used to compile and upload code to an Arduino microcontroller. Arduino was chosen due to our familiarity with its functions as well as its similar syntax to C++.

To receive instructions, Carr-E is fitted with a Bluetooth module that can be paired with the user’s smartphone. Once paired, the user can send instructions as well as their GPS coordinates to Carr-E through the Blynk App.

A GPS module will be used to determine Carr-E’s location, and a compass will be used to track its heading angle with respect to the north pole. By determining these two properties along with the user’s GPS location, a direction and distance can be determined to allow Carr-E to follow the user. Moreover, the TinyGPS, SoftwareSerial, and BlynkSimpleSerialBLE libraries will be used to program the sensors.

Aside from the compass, Bluetooth module, and GPS module, other external electrical components include a motor driver, two motors, and a 12V battery.

There are many other requirements specific to this project. The motor drivers must be programmed to rotate the axles on the motors. Additionally, Carr-E must continuously update itself every half-second and redetermine its GPS location, the user’s GPS location, and the heading angle.

To determine if the heading angle and GPS locations were accurate, the values were printed and displayed into the Arduino Serial. Print statements were added into the code at various locations such that in the event where the code failed, we could accurately pinpoint the specific line(s) of code that resulted in a compilation or runtime error. 
For instance, if we were successfully able to connect to the user’s device via bluetooth, a success statement would be displayed on the serial console. In the event where the bluetooth failed to connect, we would display an error statement in the serial.


