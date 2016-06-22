#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
MPU6050 mpu;
#define OUTPUT_READABLE_YAWPITCHROLL
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

//DEFINE MOTOR CONTROLS
#include <Servo.h>
// Define Motors  
  Servo MotorFL;
  Servo MotorFR;
  Servo MotorBL;
  Servo MotorBR;
  
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

//END MOTOR CONTROL DEFINE



// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
    MotorFL.attach(24);
    MotorFR.attach(26);
    MotorBL.attach(28);
    MotorBR.attach(30);
    pinMode(16,OUTPUT);
    pinMode(17,OUTPUT);
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    Serial.begin(115200);
    mpu.initialize();
    // load and configure the DMP
    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1688);
    if (devStatus == 0) {
        mpu.setDMPEnabled(true);
        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    } 
    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
// The motors are set to 50%    
    MotorFL.write(90);
    MotorFR.write(90);
    MotorBL.write(90);
    MotorBR.write(90);
// Gyro starts
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
        #endif
// USE MOTOR LVLING HERE FOR STABLE FLIGHT!!!
        if ((ypr[1]* 180/M_PI) < -5 or (ypr[1]* 180/M_PI) > 5 or (ypr[2]* 180/M_PI) < -4 or (ypr[2]* 180/M_PI) > 4)
        {
          digitalWrite(17,LOW);
          digitalWrite(16,HIGH);
        }

        if ((ypr[1]* 180/M_PI) > -5 and (ypr[1]* 180/M_PI) < 5 and (ypr[2]* 180/M_PI) > -4 and (ypr[2]* 180/M_PI) < 4)
        {
          digitalWrite(16,LOW);
          digitalWrite(17,HIGH);
        }
        
        if ((ypr[1]* 180/M_PI) < -5)
        {
          //Correct with rear pair
            MotorBL.write(110);
            MotorBR.write(110);
            delay(250);
            MotorBL.write(90);
            MotorBR.write(90);
        }
        
        if ((ypr[1]* 180/M_PI) > 5)
        {
          //Correct with front pair
            MotorFL.write(110);
            MotorFR.write(110);
            delay(250);
            MotorFL.write(90);
            MotorFR.write(90);
        }
        
        if ((ypr[2]* 180/M_PI) < -4)
        {
          //Correct with Left pair
            MotorFL.write(110);
            MotorBL.write(110);
            delay(250);
            MotorFL.write(90);
            MotorBL.write(90);
          
        }
        
        if ((ypr[2]* 180/M_PI) > 4)
        {
          //Correct with Right pair
            MotorFR.write(110);
            MotorBR.write(110);
            delay(250);
            MotorFR.write(90);
            MotorBR.write(90);
        }
        
        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
