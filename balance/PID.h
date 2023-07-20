#include <PID_v1.h>
#include "SpeedModify.h"

double Setpoint=100;
double InputRight, InputLeft;
double OutputRight, OutputLeft;
double Kp=1, Ki=0.006, Kd=0.01;
PID myPIDRight(&InputRight, &OutputRight, &Setpoint, Kp, Ki, Kd, DIRECT);
PID myPIDLeft(&InputLeft, &OutputLeft, &Setpoint, Kp, Ki, Kd, DIRECT);
/*setup the pid interface*/
void PID_setup()
{
    myPIDLeft.SetMode(AUTOMATIC);
    myPIDRight.SetMode(AUTOMATIC);
    myPIDRight.SetSampleTime(100);
    myPIDLeft.SetSampleTime(100);
    myPIDLeft.SetOutputLimits(0, 255);
    myPIDRight.SetOutputLimits(0, 255);
}
/*adjust the speed with the current speed tested by encoder*/
void adjustSpeed()
{
    InputRight = rightSpeed;
    InputLeft = leftSpeed;

    // 计算PID控制器的输出
    myPIDRight.Compute();
    myPIDLeft.Compute();

    // 输出到PWM
//    Serial.print(InputRight);
//    Serial.print(",");
//    Serial.println(InputLeft);
//    Serial.print(",");
//    Serial.print(OutputRight);
//    Serial.print(",");
//    Serial.println(OutputLeft);
 
    analogWrite(9, OutputRight);
    analogWrite(10, OutputLeft);
}
