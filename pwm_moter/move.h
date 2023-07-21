#ifndef _MOVE_H
#define _MOVE_H
#include <stdint.h>
#define PWMLeft 9
#define PWMRight 10
#define RightIn1 7
#define RightIn2 6
#define LeftIn1 12
#define LeftIn2 13

#define HIGH 1
#define LOW 0
#define OUTPUT 1
//definations of the fuctions to control the motors
#define LeftForward() digitalWrite(LeftIn1,LOW);digitalWrite(LeftIn2,HIGH)
#define LeftBackward() digitalWrite(LeftIn1,HIGH);digitalWrite(LeftIn2,LOW)
#define RightForward() digitalWrite(RightIn1,LOW);digitalWrite(RightIn2,HIGH)
#define RightBackward() digitalWrite(RightIn1,HIGH);digitalWrite(RightIn2,LOW)
#define LeftStop() digitalWrite(LeftIn1,LOW);digitalWrite(LeftIn2,LOW)
#define RightStop() digitalWrite(RightIn1,LOW);digitalWrite(RightIn2,LOW)
//definations of the fuctions to control the car
#define Stop() LeftStop();RightStop()
#define forward(speed) LeftForward();RightForward();analogWrite(PWMLeft,speed);analogWrite(PWMRight,speed)
#define backward(speed) LeftBackward();RightBackward();analogWrite(PWMLeft,speed);analogWrite(PWMRight,speed)
#define left(speed) LeftStop();RightForward();analogWrite(PWMRight,speed)
#define right(speed) LeftForward();RightStop();analogWrite(PWMLeft,speed)


void move(uint8_t direction,uint8_t speed, uint8_t time);
void motorInit();
/*
Description: a move function
@param: direction: 0:forward 1:backward 2:left 3:right
@param: speed: 0~50
@param: time: 0~255,if time=0, then move forever
*/
void move(uint8_t direction,uint8_t speed, uint8_t time){
    if (speed ==0){
        Stop();
        return;
    }
    speed = 90 + speed*10;
    Serial.print('hello');
    switch(direction){
        case 0:
            forward(speed);
            break;
        case 1:
            backward(speed);
            break;
        case 2:
            left(speed);
            break;
        case 3:
            right(speed);
            break;
        default:
            Stop();
            break;
    }
    if(time!=0){
        delay(time);
        Stop();
    }

}

void motorInit(){
    pinMode(PWMLeft,OUTPUT);
    pinMode(PWMRight,OUTPUT);
    pinMode(LeftIn1,OUTPUT);
    pinMode(LeftIn2,OUTPUT);
    pinMode(RightIn1,OUTPUT);
    pinMode(RightIn2,OUTPUT);
    Stop();
}
#endif
