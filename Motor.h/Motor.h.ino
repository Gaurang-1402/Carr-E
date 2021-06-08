// Motor A connections
int enA = 13;
int in1 = 12;
int in2 = 11;

// Motor B connections
int enB = 8;
int in3 = 10;
int in4 = 9;

void zoom();
void spin360();

void setup() {
  delay(5000);
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  zoom();
//  spin360();
  delay(1000);
}

void zoom () {
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

//  delay(4000);
//
//  // Turn off motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
}

void spin360 () {
  analogWrite(enA, 125);
  analogWrite(enB, 125);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}
