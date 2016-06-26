// use .write(0 -> 180) 

#include <Servo.h>
// Define Motors  
Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;
void setup()
{
  delay(60000);
  MotorFL.attach(13);
  MotorFR.attach(11);
  MotorBL.attach(9);
  MotorBR.attach(7);
  ARM();
  MotorFL.write(70);
  MotorFR.write(70);
  MotorBL.write(70);
  MotorBR.write(70);
  delay(2000);
  MotorFL.write(80);
  MotorFR.write(80);
  MotorBL.write(80);
  MotorBR.write(80);
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
  MotorFL.write(60);
  MotorFR.write(60);
  MotorBL.write(60);
  MotorBR.write(60);
}








