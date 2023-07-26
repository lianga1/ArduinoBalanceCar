#include <PID_v1.h>
#include "GetSpeed.h"
#include "move.h"
double Setpoint=90;
double Setstop = 0;
double InputRight, InputLeft;
double OutputRight, OutputLeft;
double Kp=1, Ki=0.0, Kd=0.01;
PID myPIDRight(&InputRight, &OutputRight, &Setpoint, Kp, Ki, Kd, DIRECT);
PID myPIDLeft(&InputLeft, &OutputLeft, &Setpoint, Kp, Ki, Kd, DIRECT);
/*setup the pid interface*/
PID myStopRight(&InputRight, &OutputRight, &Setstop, Kp, Ki, Kd, DIRECT);
PID myStopLeft(&InputLeft, &OutputLeft, &Setstop, Kp, Ki, Kd, DIRECT);
void PID_setup()
{
    myPIDLeft.SetMode(AUTOMATIC);
    myPIDRight.SetMode(AUTOMATIC);
    myPIDLeft.SetSampleTime(10);
    myPIDRight.SetSampleTime(10);
    myPIDLeft.SetOutputLimits(0, 255);
    myPIDRight.SetOutputLimits(0, 255);
    myStopLeft.SetMode(AUTOMATIC);
    myStopRight.SetMode(AUTOMATIC);
    myStopLeft.SetSampleTime(10);
    myStopRight.SetSampleTime(10);
    myStopLeft.SetOutputLimits(-128, 127);
    myStopRight.SetOutputLimits(-128, 127);

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
    analogWrite(9, (uint8_t)OutputLeft);
    analogWrite(10,(uint8_t)OutputRight);
}
void adjustTurnLeft(){
    InputRight = rightSpeed;

    // 计算PID控制器的输出
    myPIDRight.Compute();

    // 输出到PWM
    analogWrite(10,(uint8_t)OutputRight);

}
void adjustTurnRight(){
    InputLeft = leftSpeed;
    myPIDLeft.Compute();
    analogWrite(9, (uint8_t)OutputLeft);

}
void adjustStop(){
    InputLeft = leftSpeed;
    InputRight = rightSpeed;
    myStopLeft.Compute();
    myStopRight.Compute();
    LeftBackward();
    RightBackward();
    if(OutputLeft>0)
        analogWrite(9, 0);
    else
        analogWrite(9, (uint8_t)(-OutputLeft));
    if(OutputRight>0)
        analogWrite(10, 0);
    else
        analogWrite(10, (uint8_t)(-OutputRight));
    
}