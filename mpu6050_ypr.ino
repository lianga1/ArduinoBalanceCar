/*
   DMP
   MPU6050姿态解算
   
   接线如下
   uno：   3.3V    GND   A4    A5
   mpu6050：VCC    GND   SDA   SCL

   参考http://t.csdn.cn/amefG
   库来源https://gitcode.net/mirrors/jrowberg/i2cdevlib?utm_source=csdn_github_accelerator
*/

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

MPU6050 mpu;
uint8_t fifoBuffer[64];
Quaternion q;
VectorFloat gravity;
float ypr[3];

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  while (!Serial); // Leonardo: wait for Serial Monitor
  Serial.println("\nI2C Scanner");

  mpu.initialize();
  mpu.dmpInitialize();
  mpu.CalibrateAccel(6);
  mpu.CalibrateGyro(6);
  mpu.PrintActiveOffsets();
  mpu.setDMPEnabled(true);
}

void loop()
{
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer))
  {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
 
    float yaw = ypr[0] * 180 / M_PI;  //将弧度转换为角度
    float pitch = ypr[1] * 180 / M_PI;
    float roll = ypr[2] * 180 / M_PI;
  
    Serial.print("Yaw: ");
    Serial.print(",");
    Serial.print(String(yaw));
    Serial.print(",");
    Serial.print(" Pitch: ");
    Serial.print(",");
    Serial.print(String(pitch));
    Serial.print(",");
    Serial.print(" Roll: ");
    Serial.print(",");
    Serial.println(String(roll));

  }
  delay(500);
}
