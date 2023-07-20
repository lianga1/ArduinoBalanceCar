#include <PID_v1.h>
#include "SpeedModify.h"

double Setpoint=100;
double InputRight, InputLeft;
double OutputRight, OutputLeft;
double Kp=2, Ki=5, Kd=1;
PID myPIDRight(&InputRight, &OutputRight, &Setpoint, Kp, Ki, Kd, DIRECT);
PID myPIDLeft(&InputLeft, &OutputLeft, &Setpoint, Kp, Ki, Kd, DIRECT);
/*setup the pid interface*/
void PID_setup()
{
    myPIDLeft.SetMode(AUTOMATIC);
    myPIDRight.SetMode(AUTOMATIC);
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
    analogWrite(9, OutputRight);
    analogWrite(10, OutputLeft);
}
