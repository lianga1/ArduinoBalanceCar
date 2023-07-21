#include "move.h"
#include "PID.h"
#include "SpeedModify.h"


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("hello world");
    motorInit();
    PID_setup();
    //TODO:添加I2C初始化，从上位机接收巡线信号

}

void loop() {

}