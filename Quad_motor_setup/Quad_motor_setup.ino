//*****************************************************
// use .write(0 -> 180)                               |
// USE THE FOLLOWING FOR MOTOR FUNCTIONS:             |
//  Servo MotorFL;                                    |
//  Servo MotorFR;                                    |
//  Servo MotorBL;                                    |
//  Servo MotorBR;                                    |
//  MotorFL.attach(24);                               |
//  MotorFR.attach(26);                               |
//  MotorBL.attach(28);                               |
//  MotorBR.attach(30);                               |
//    CURRENT COMMANDS:                               |
//        ALLMOTORS() - Set throttle for all motors   |
//        ARM() - Arm Esc                             |
//        Hover() - Set throttle mode to Hover        |
//        LeftBank() - Roll left                      |
//        RightBank() - Roll right                    |
//        FrontPitch - Roll forward                   |
//        BackPitch() - Roll back                     |
//        RbankTurn() - Right Bank and Yank turn      |
//        LbankTurn() - Left Bank and Yank turn       |
//                                                    |
//*****************************************************

#include <Servo.h>
// Define Motors  
Servo MotorFL;
Servo MotorFR;
Servo MotorBL;
Servo MotorBR;

MotorFL.attach(24);
MotorFR.attach(26);
MotorBL.attach(28);
MotorBR.attach(30);


//Define control of all motors
void ALLMOTORS(int A)
{
  MotorFL.write(A);
  MotorFR.write(A);
  MotorBL.write(A);
  MotorBR.write(A);
}

// Define arming of ESC
void ARM()
{
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
  delay(500);
  MotorFL.write(10);
  MotorFR.write(10);
  MotorBL.write(10);
  MotorBR.write(10);
  delay(500);
  MotorFL.write(0);
  MotorFR.write(0);
  MotorBL.write(0);
  MotorBR.write(0);
}

// Define Hover mode
// 50% throttle is place holder
void Hover()
{
  MotorFL.write(90);
  MotorFR.write(90);
  MotorBL.write(90);
  MotorBR.write(90);
  delay(5000);
}

//Define Bank Left procedure
//11% throttle increase is place holder
void LeftBank()
{
  MotorFR.write(110);
  MotorBR.write(110);
  delay(500);
  MotorFR.write(90);
  MotorBR.write(90);
  MotorFL.write(110);
  MotorBL.write(110);
  delay(500);
  MotorFL.write(90);
  MotorBL.write(90);
}

//Define Bank Right procedure
//11% throttle increase is place holder
void RightBank()
{
  MotorFL.write(110);
  MotorBL.write(110);
  delay(500);
  MotorFL.write(90);
  MotorBL.write(90);
  MotorFR.write(110);
  MotorBR.write(110);
  delay(500);
  MotorFR.write(90);
  MotorBR.write(90);
}

//Define Pitch Forward procedure
//11% throttle increase is place holder
void FrontPitch()
{
  MotorBL.write(110);
  MotorBR.write(110);
  delay(500);
  MotorBL.write(90);
  MotorBR.write(90);
  MotorFL.write(110);
  MotorFR.write(110);
  delay(500);
  MotorFL.write(90);
  MotorFR.write(90);
}

//Define Pitch Rearwards procedure
//11% throttle increase is place holder
void BackPitch()
{
  MotorFL.write(110);
  MotorFR.write(110);
  delay(500);
  MotorFL.write(90);
  MotorFR.write(90);
  MotorBL.write(110);
  MotorBR.write(110);
  delay(500);
  MotorBL.write(90);
  MotorBR.write(90);
}

//Define Right Bank turn
//100% throttle for turn is place holder
void RbankTurn()
{
  MotorFL.write(110);
  MotorBL.write(110);
  delay(500);
  MotorFL.write(90);
  MotorBL.write(90);
  ALLMOTORS(180);
  delay(500);
  ALLMOTORS(90);
  MotorFR.write(110);
  MotorBR.write(110);
  delay(500);
  MotorFR.write(90);
  MotorBR.write(90);
}

//Define Right Bank turn
//100% throttle for turn is place holder
void LbankTurn()
{
  MotorFR.write(110);
  MotorBR.write(110);
  delay(500);
  MotorFR.write(90);
  MotorBR.write(90);
  ALLMOTORS(180);
  delay(500);
  ALLMOTORS(90);
  MotorFL.write(110);
  MotorBL.write(110);
  delay(500);
  MotorFL.write(90);
  MotorBL.write(90);
}



// Execute once on startup
// Currently used to run control tests
void setup()
{
  ARM();
  Hover();
}






