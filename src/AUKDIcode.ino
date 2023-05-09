#include <SoftwareSerial.h>

int blueTx = 2;
int blueRx = 3;
SoftwareSerial mySerial(blueTx, blueRx);

char value;

const int ENA = 6;  // PWM pin for controlling speed of motor A
const int IN1 = 12;  // direction pin 1 for motor A
const int IN2 = 11;  // direction pin 2 for motor A
const int ENB = 5;  // PWM pin for controlling speed of motor B
const int IN3 = 9;  // direction pin 1 for motor B
const int IN4 = 10;  // direction pin 2 for motor B

void setup() {
  // BlueTooth Set
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

void Forward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 250);
  analogWrite(ENB, 250);
}

void Backward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 250);
  analogWrite(ENB, 250);
}

void Right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 0);
  analogWrite(ENB, 250);
}

void Left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 250);
  analogWrite(ENB, 0);
}

void Stop(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 250);
  analogWrite(ENB, 200);
}

void loop() {
  while(mySerial.available())  //mySerial에 전송된 값이 있으면
  {
    value = mySerial.read(); //전송값 읽음
    Serial.print(value);

    if(value == 'q'){
      Forward();
    }
    if(value == 'b'){
      Backward();
    }
    if(value == 'w'){
      Right();
    }
    if(value == 'd'){
      Left();
    }
    if(value == 's'){
      Stop();
    }
  }
  
}
