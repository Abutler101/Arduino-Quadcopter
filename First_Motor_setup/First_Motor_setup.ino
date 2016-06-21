// use .write(0 -> 180) 

#include <Servo.h>
// Define Motors  
void setup()
{
  Servo MotorFL;
  Servo MotorFR;
  Servo MotorBL;
  Servo MotorBR;
  MotorFL.attach(24);
  MotorFR.attach(26);
  MotorBL.attach(28);
  MotorBR.attach(30);
  ARM();
  
}

// Define arming of ESC
void ARM()
{
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
}








