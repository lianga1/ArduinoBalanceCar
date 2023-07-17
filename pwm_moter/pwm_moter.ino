
uint8_t PWMValA=100;
uint8_t PWMValB=100;
#include "GetSpeed.h"
/*
A是右轮
B是左轮更弱
*/



void setup() {
  // put your setup code here, to run once:
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT); 
  setupSpeedTest();
  Serial.begin(9600);
  //TODO: modulize the initilization of the motor
}
/*
[REC]119 w


[REC]115 s 


[REC]100 d 


[REC]97 a

*/

void loop() {
  // put your main code here, to run repeatedly:  
  //static unsigned char Receive_Data;
  int Receive_Data;
  while(Serial.available()){
    int inByte = Serial.read();
    //Receive_Data = (char)inByte;
    Receive_Data = inByte;
    Serial.println(Receive_Data);
    //if (Receive_Data==(char)'w'){
    if (Receive_Data==119){
      //Serial.println(Receive_Data);
      Azheng();
      Bzheng();
      analogWrite(PWMA, PWMValA); 
      analogWrite(PWMB, PWMValB); 
    //}else if(Receive_Data==(char)'s'){
    }else if(Receive_Data==115){
      //Serial.println(Receive_Data);
      Afan();
      Bfan();
      analogWrite(PWMA, PWMValA); 
      analogWrite(PWMB, PWMValB); 
  //}else if(Receive_Data==(char)'d'){  
    }else if(Receive_Data==100){

      //Serial.println(Receive_Data);
      Azheng();
      Bstop();
      analogWrite(PWMA, PWMValA); 
      analogWrite(PWMB, PWMValB); 
    
    //}else if(Receive_Data==(char)'a'){
    }else if(Receive_Data==97){
      //Serial.println(Receive_Data);
      Astop();
      Bzheng();
      analogWrite(PWMA, PWMValA); 
      analogWrite(PWMB, PWMValB); 
    }else{
      Serial.println(Receive_Data);
      stop();
      analogWrite(PWMA, PWMValA); 
      analogWrite(PWMB, PWMValB); 
    }
    if(leftFrequency>rightFrequency){
      Azheng();
      Bzheng();
      PWMValA = (PWMValA*(leftFrequency+1)/(rightFrequency+1))%255;//the right wheel will be faster, as the PWMA multiplies a factor
  } 
    else if(leftFrequency<rightFrequency){
      Azheng();
      Bzheng();
      PWMValB = (PWMValB*(rightFrequency+1)/(leftFrequency+1))%255;
    }
 }
}
