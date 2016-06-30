#include <Arduino.h>
#include <Servo.h>

Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;

void setup() {
  MotorFL.writeMicroseconds(60);
  MotorFR.writeMicroseconds(60);
  MotorBL.writeMicroseconds(60);
  MotorBR.writeMicroseconds(60); //ARMS
  MotorFL.attach(13);
  MotorFR.attach(11);
  MotorBL.attach(9);
  MotorBR.attach(7);
  delay(60000)
  MotorFL.write(70);
  MotorFR.write(70);
  MotorBL.write(70);
  MotorBR.write(70);
  delay(30000)
  MotorFL.write(80);
  MotorFR.write(80);
  MotorBL.write(80);
  MotorBR.write(80);
  delay(30000)
  MotorFL.write(90);
  MotorFR.write(90);
  MotorBL.write(90);
  MotorBR.write(90);
  delay(30000)
  MotorFL.write(100);
  MotorFR.write(100);
  MotorBL.write(100);
  MotorBR.write(100);
  delay(30000)
  MotorFL.write(110);
  MotorFR.write(110);
  MotorBL.write(110);
  MotorBR.write(110);
  delay(30000)
  MotorFL.write(120);
  MotorFR.write(120);
  MotorBL.write(120);
  MotorBR.write(120);
  delay(10000)
  MotorFL.write(140);
  MotorFR.write(140);
  MotorBL.write(140);
  MotorBR.write(140);
  delay(10000)
  MotorFL.write(160);
  MotorFR.write(160);
  MotorBL.write(160);
  MotorBR.write(160);
  delay(10000)
  MotorFL.write(180);
  MotorFR.write(180);
  MotorBL.write(180);
  MotorBR.write(180);
}

void loop() {

}
