#include <Wire.h>
#include "move.h"
void receiveEvent();

void I2C_Setup(uint8_t addr)
{
    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
}

void receiveEvent(int howMany)
{
    uint8_t direction;
    while (Wire.available())
    {
        char c = Wire.read();
        Serial.print(c);
    if(c>90){
        switch (c)
        {
        case 119/* constant-expression */:
        direction = 0;
        move(direction, 0);
        /* forward:input w */
        break;
        case 115:
        direction = 1;
        /* backward input s */
        break;
        case 100:
        direction = 3;
        
        /* right: input d */
        break;
        case 97:
        direction = 2;
        /* right: input a */
        break;
        case 113:
            Stop();
        default:
        Serial.println("wrong input");
        break;
        }
    }
}