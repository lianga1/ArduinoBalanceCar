#include "move.h"



/*
Description: a move function
@param: direction: 0:forward 1:backward 2:left 3:right
@param: speed: 0~50
@param: time: 0~255,if time=0, then move forever
*/
void move(uint8_t direction,uint8_t speed, uint8_t time){
    speed = (speed*5)%255;
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
            stop();
            break;
    }
    if(time!=0){
        delay(time);
        stop();
    }

}

void motorInit(){
    pinMode(PWMLeft,OUTPUT);
    pinMode(PWMRight,OUTPUT);
    pinMode(LeftIn1,OUTPUT);
    pinMode(LeftIn2,OUTPUT);
    pinMode(RightIn1,OUTPUT);
    pinMode(RightIn2,OUTPUT);
    stop();
}