#include "move.h"
#include "GetSpeed.h"
#include "PID.h"

void setup(){
    Serial.begin(9600);
    Serial.setTimeout(20);
    motorInit();
    setupSpeedTest();
    PID_setup();
}
/*
function: get the signal from the serial port and control the car,
There are 7 commands:
a:forward
b:turn left
c:turn right
d:turn around
e:stop
q:navigate to the left
r:navigate to the right

all move functions are in the move.h
move will got a direction, from 1 to 7.
speed is currently not used.

*/
uint8_t direction=0;
void loop()
{
    while(Serial.available())
    {
        String str = Serial.readString();
        char Receive_Data = str[0];
        switch (Receive_Data)
        {
            case 'a':
                Serial.println("1RUN");
                direction = 1;
                move(1,1,0);
                break;
            case 'b':
                Serial.println("2LEFT");
                direction = 2;
                move(2,1,1000);
                break;
            case 'c':
                Serial.println("3RIGHT");
                direction = 3;
                move(3,1,1000);
                break;
            case 'd':
                Serial.println("4AROUND");
                direction = 4;

                move(4,1,500);
                Stop();
                delay(500);
                move(4,1,500);
                break;
            case 'e':
                Serial.println("5STOP");
                direction = 5;
                move(5,1,0);
                break;
            case 'q':
                Serial.println("6left");
                direction = 6;
                move(6,1,100);
                break;
            case 'r':
                Serial.println("7right");
                direction = 7;
                move(7,1,100);
                break;
 
        }
    }
        if(direction == 1)adjustSpeed();
        if(direction == 5)adjustStop();
        // else if (Receive_Data=='i'){
        //     Serial.println("6 SPEED-1");
        //     if(speed>-8){
        //         speed = speed - 1;
        //     }else{speed = -8;}
        //     //初值80+10*1,每次减10,最低0,则可以减9次,防溢出
        // }else if (Receive_Data=='j'){
        //     Serial.println("7 SPEED+1");
        //     if(speed<16){
        //         speed = speed + 1;}
        //     else{speed = 16;}
        //     //初值90，每次加10，最高255，则可以加16次,防溢出

        // move(direction,speed,0);
        //getSpeed();
}