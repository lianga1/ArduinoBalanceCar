


#include "SpeedModify.h"
#include "move.h"
#include "PID.h"
/*
A是右轮
B是左轮更弱
*/



void setup() {
  // put your setup code here, to run once:
  setupSpeedTest();
  Serial.begin(9600);
  motorInit();
  PID_setup();
}
/*
[REC]119 w


[REC]115 s 


[REC]100 d 


[REC]97 a

*/
int speed = 3;
int direction = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  //static unsigned char Receive_Data;
  int Receive_Data;
  unsigned long currentTime,startTime;
  Serial.print(leftSpeed);
  Serial.print(",");
  Serial.println(rightSpeed);
  
  while(Serial.available()){
    int inByte = Serial.read();
    
    //Receive_Data = (char)inByte;
    Receive_Data = inByte;
//    Serial.println(Receive_Data);
    //if (Receive_Data==(char)'w'){
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
      direction = 3;
      /* right: input d */
      break;
    case 97:
      direction = 2;
      /* right: input a */
      break;
    default:
      Serial.println("wrong input");
      break;
    }
 
   }
//   else if(Receive_Data>=48 && Receive_Data<58){
//      speed = Receive_Data-48;
//   }
   move(direction,speed,0);//move the car with the direction and speed forever

 }
  if ((direction ==0 ||direction == 1)&& speed != 0){
    adjustSpeed();//adjust the speed of the car only if the command is to move forward or backward
  }
  else if(direction = 2){
    adjustTurnLeft();
  }
  else if(direction = 3){
    adjustTurnRight();
  }
}
