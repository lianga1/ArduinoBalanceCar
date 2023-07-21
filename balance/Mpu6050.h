#include <Adafruit_MPU6050.h>
#include <Adafruit_sensor.h>
#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

Adafruit_MPU6050 mpu;
MPU6050 mpu2;

  Quaternion q;
  VectorFloat gravity;
  float ypr[3];
  uint8_t fifoBuffer[64];

void Mpu2setup()
{
  mpu2.initialize();
  mpu2.dmpInitialize();
  mpu2.setXGyroOffset(220);
  mpu2.setYGyroOffset(76);
  mpu2.setZGyroOffset(-85);
  mpu2.setZAccelOffset(1788);
  mpu2.setDMPEnabled(true);
}


void Mpusetup() {

  // initialize mpu
  if (!mpu.begin()) {
    Serial.println("Failed to start MPU6050");
  } else {
    Serial.println("Start MPU6050");
  }

//  mpu2.initialize();
//  mpu2.dmpInitialize();
//  mpu2.CalibrateAccel(6);
//  mpu2.CalibrateGyro(6);
//  mpu2.PrintActiveOffsets();
//  mpu2.setDMPEnabled(true);


  // display MPU6050 settings
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
}


void displayReadings() {
  // get new sensor events with the readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // print out the values
  // acceleration values
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  //Serial.print(",");
  Serial.print(a.acceleration.y);
  //Serial.print(",");
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  //rotation values
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  //Serial.print(",");
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  //Serial.print(",");
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  // temperature values
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
}
void yprget()
{
  if (mpu2.dmpGetCurrentFIFOPacket(fifoBuffer))
  {
      mpu2.dmpGetQuaternion(&q, fifoBuffer);
      mpu2.dmpGetGravity(&gravity, &q);
      mpu2.dmpGetYawPitchRoll(ypr, &q, &gravity);
    
      float yaw = ypr[0] * 180 / M_PI;  //将弧度转换为角度
      float pitch = ypr[1] * 180 / M_PI;
      float roll = ypr[2] * 180 / M_PI;
    
      Serial.print("Yaw: ");
      Serial.print(yaw);
      Serial.print(" Pitch: ");
      Serial.print(pitch);
      Serial.print(" Roll: ");
      Serial.println(roll);
    
      yaw=pitch=roll=0;
  }
  else  Serial.println("Wrong ypr");

  
}
