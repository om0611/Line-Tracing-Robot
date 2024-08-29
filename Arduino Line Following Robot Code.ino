// define pins 2 and 3 as the IR sensor pins
const int IR_SENSOR_RIGHT = 2;
const int IR_SENSOR_LEFT = 3;

// define pins 5, 6, 9, 10 as the motor pins
const int LMotor_pin1 = 5;
const int LMotor_pin2 = 6;
const int RMotor_pin1 = 10;
const int RMotor_pin2 = 9;


void setup() {
  
  // set the IR sensor pins as input
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  
  // set the motor pins as output
  pinMode(LMotor_pin1, OUTPUT);
  pinMode(LMotor_pin2, OUTPUT);
  pinMode(RMotor_pin1, OUTPUT);
  pinMode(RMotor_pin2, OUTPUT);
}

void loop() {
  
  // read the IR sensors
  int R_IRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int L_IRSensorValue = digitalRead(IR_SENSOR_LEFT);
  
  // if none of the IR sensors detect the black line, then go straight
  if (R_IRSensorValue == LOW && L_IRSensorValue == LOW) {
    analogWrite(LMotor_pin1, 245); 
    analogWrite(LMotor_pin2, 0);
    
    analogWrite(RMotor_pin1, 245);
    analogWrite(RMotor_pin2, 0);
  }
  
  // if the right IR sensor detects the black line, then turn right slightly
  else if (R_IRSensorValue == HIGH && L_IRSensorValue == LOW) {
    analogWrite(LMotor_pin1, 255); 
    analogWrite(LMotor_pin2, 0);
    
    analogWrite(RMotor_pin1, 0);
    analogWrite(RMotor_pin2, 255);
  }
  
  // if the left IR sensor detects the black line, then turn left slightly
  else if (R_IRSensorValue == LOW && L_IRSensorValue == HIGH) {
    analogWrite(LMotor_pin1, 0); 
    analogWrite(LMotor_pin2, 255);
    
    analogWrite(RMotor_pin1, 255);
    analogWrite(RMotor_pin2, 0);
    
  }
  
  // if both IR sensors detect the black line, stop
  else if (R_IRSensorValue == HIGH && L_IRSensorValue == HIGH) {
    analogWrite(LMotor_pin1, 0); 
    analogWrite(LMotor_pin2, 0);
    
    analogWrite(RMotor_pin1, 0);
    analogWrite(RMotor_pin2, 0);
    delay(500);
  }

}