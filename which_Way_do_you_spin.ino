#include <Arduino.h>
#include <Servo.h>

Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;

void setup() {
  MotorFL.attach(24);
  MotorFR.attach(26);
  MotorBL.attach(28);
  MotorBR.attach(30);
  delay(60000);
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
  delay(1000);
  MotorFL.write(10);
  MotorFR.write(10);
  MotorBL.write(10);
  MotorBR.write(10);
  delay(60000);
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
}

void loop() {

}
