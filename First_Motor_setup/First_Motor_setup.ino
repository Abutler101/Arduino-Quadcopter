// use .write(0 -> 180) 

#include <Servo.h>
// Define Motors  
Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;
void setup()
{
  MotorFL.attach(24);
  MotorFR.attach(26);
  MotorBL.attach(28);
  MotorBR.attach(30);
  ARM();
  MotorFL.write(10);
  MotorFR.write(10);
  MotorBL.write(10);
  MotorBR.write(10);
  delay(2000);
  MotorFL.write(20);
  MotorFR.write(20);
  MotorBL.write(20);
  MotorBR.write(20);
  delay(2000);
  MotorFL.write(40);
  MotorFR.write(40);
  MotorBL.write(40);
  MotorBR.write(40);
  delay(2000);
  MotorFL.write(90);
  MotorFR.write(90);
  MotorBL.write(90);
  MotorBR.write(90);
  delay(2000);
  MotorFL.write(180);
  MotorFR.write(180);
  MotorBL.write(180);
  MotorBR.write(180);
  delay(2000);
}

// Define arming of ESC
void ARM()
{
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
}








