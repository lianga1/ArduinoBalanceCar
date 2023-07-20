#include "move.h"
#include "PID.h"
#include "SpeedModify.h"

void setup() {
  // put your setup code here, to run once:
  setupSpeedTest();
  Serial.begin(9600);
  motorInit();
  PID_setup();
}

int direction = 0;
int speed = 3;

void loop(){
    Serial.print(leftSpeed);
    Serial.print(",");
    Serial.println(rightSpeed);
    while(Serial.available()){
    int inByte = Serial.read();
    int Receive_Data = inByte;
    //Serial.println(Receive_Data);
    if(Receive_Data>90){
      switch (Receive_Data)
      {
      case 119/* constant-expression */:
        direction = 0;
        /* forward:input w */
        break;
      case 115:
        direction = 1;
        /* backward input s */
        break;
      case 100:
        direction = 2;
        /* right input d */
        break;
      case 97:
        direction = 3;
        /* left input a */
        break;
      default:
       
        break;
      }
    }
    else if (Receive_Data>=48 &&Receive_Data<58){
      speed = Receive_Data-48;
    }
    move(direction,speed,0);
    }
    if((direction ==0|| direction ==1) && speed!=0){
      adjustSpeed();
    }
    
}
