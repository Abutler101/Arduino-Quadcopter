#include <Arduino.h>
#include <Servo.h>

Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;

void setup() {
  MotorFL.attach(13);
  MotorFR.attach(11);
  MotorBL.attach(9);
  MotorBR.attach(7);
  delay(60000);
  MotorFL.write(60);
  MotorFR.write(60);
  MotorBL.write(60);
  MotorBR.write(60);
  delay(1000);
  MotorFL.write(70);
  MotorFR.write(70);
  MotorBL.write(70);
  MotorBR.write(70);
  delay(60000);
  MotorFL.write(60);
  MotorFR.write(60);
  MotorBL.write(60);
  MotorBR.write(60);
}

void loop() {

}
