/****************************************************************************
   作者：lzn,tpl,azq
   产品名称：ArduinoCar
****************************************************************************/
#include "GetSpeed.h"
#include "Move.h"
#include "PID.h"
int speed = 1;
int direction = 0;

void setup() {
  Serial.begin(9600);
  //setupSpeedTest();
  //Stop();
  //motorInit();
  //PID_setup();
}



void loop() {
  while(Serial.available()){
    char Receive_Data = Serial.read();
    //Serial.print(Receive_Data);
    if(Receive_Data=='a'){
      Serial.println("1RUN");
      direction = 0;
    }else if (Receive_Data=='b'){
      Serial.println("2BACK");
      direction = 1;
    }else if (Receive_Data=='c'){
      Serial.println("3LEFT");
      direction = 2;
    }else if (Receive_Data=='d'){
      Serial.println("4RIGHT");
      direction = 3;
    }else if (Receive_Data=='e'){
      Serial.println("5STOP");
      direction = 4;
    }else if (Receive_Data=='i'){
      Serial.println("6 SPEED-1");
      if(speed = 80 + speed*10>0){
      speed = speed - 1;
      }else{speed = -8;}
      //初值90,每次加10,最低0,则可以减9次,防溢出
    }else if (Receive_Data=='j'){
      Serial.println("7 SPEED+1");
      if(speed = 80 + speed*10<250){
      speed = speed + 1;}
      else{speed = 16;}
      //初值90，每次加10，最高255，则可以加16次,防溢出
    }
    move(direction,speed,0);
    //getSpeed();
  }
}




/*
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
    case 119:
      direction = 0;
      //forward:input w 
      break;
    case 115:
      direction = 1;
      //backward input s
      break;
    case 100:
      direction = 3;
      // right: input d 
      break;
    case 97:
      direction = 2;
      //right: input a 
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
  }*/
