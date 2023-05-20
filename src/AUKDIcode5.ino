#include <SoftwareSerial.h>

const int blueTx = 2;
const int blueRx = 3;
SoftwareSerial mySerial(blueTx, blueRx);

const int ENA = 6;  // PWM pin for controlling speed of motor A
const int IN1 = 12;  // direction pin 1 for motor A
const int IN2 = 11;  // direction pin 2 for motor A
const int ENB = 5;  // PWM pin for controlling speed of motor B
const int IN3 = 9;  // direction pin 1 for motor B
const int IN4 = 10;  // direction pin 2 for motor B

void setup() {
  // Bluetooth Setup
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // Set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.println("Arduino Bluetooth Car is ready to start");
}

void moveMotors(int speedA, int speedB, bool dirA, bool dirB) {
  digitalWrite(IN1, dirA ? HIGH : LOW);
  digitalWrite(IN2, dirA ? LOW : HIGH);
  digitalWrite(IN3, dirB ? HIGH : LOW);
  digitalWrite(IN4, dirB ? LOW : HIGH);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void Forward() {
  moveMotors(250, 250, true, true);
}

void Backward() {
  moveMotors(250, 250, false, false);
}

void Right() {
  moveMotors(0, 180, true, false);
}

void Left() {
  moveMotors(180, 0, false, true);
}

void Stop() {
  moveMotors(0, 0, true, true);
}

void loop() {
  while (mySerial.available()) {
    char value = mySerial.read();
    Serial.print(value);
    
    switch (value) {
      case 'q':
        Forward();
        break;
      case 'b':
        Backward();
        break;
      case 'w':
        Right();
        break;
      case 'd':
        Left();
        break;
      case 's':
        Stop();
        break;
    }
  }
}