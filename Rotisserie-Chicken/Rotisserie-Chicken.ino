const int motorDirectionPin = 13; // for motor A
const int motorSpeedPin = 11; // for motor A
const int motorBrakePin = 9; // for motor A

const int CW  = HIGH;
const int CCW = LOW;

int motorSpeed = 255;
int initMotorSpeed = 255;

void setup() {
  // motor A pin assignment
  pinMode(motorDirectionPin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  pinMode(motorBrakePin, OUTPUT);

  digitalWrite(motorDirectionPin, CW);// set direction
  analogWrite(motorSpeedPin, initMotorSpeed);// set speed at maximum
  delay(100);
 
  
  Serial.begin(9600);//  seial monitor initialized 

}

void loop() {

  
  digitalWrite(motorDirectionPin, CW);// set direction
  analogWrite(motorSpeedPin, motorSpeed);// set speed at maximum
  //delay(100);
  //analogWrite(motorSpeedPin, motorSpeed);// set speed at maximum
  //analogWrite(motorSpeedPin, 0);// set speed at maximum
  //delay(10000);
 
}// loop end
