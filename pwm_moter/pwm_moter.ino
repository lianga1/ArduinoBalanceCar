#define AIN1 12   //TB6612FNG驱动模块控制信号 共6个
#define AIN2 13

#define BIN1 7
#define BIN2 6

#define PWMA 10
#define PWMB 9
uint8_t PWMValA=100;
uint8_t PWMValB=100;
#include "GetSpeed.h"
/*
A是右轮
B是左轮更弱
*/

void Azheng(){
  digitalWrite(AIN1, 1);         
  digitalWrite(AIN2, 0);        
  //analogWrite(PWMA, PWMVal); 
}

void Afan(){
  digitalWrite(AIN1, 0);         
  digitalWrite(AIN2, 1);         
  //analogWrite(PWMA, PWMVal); 
}

void Astop(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  //analogWrite(PWMA, PWMVal);
}

void Bzheng(){
  digitalWrite(BIN1, 0);        
  digitalWrite(BIN2, 1);  
  //analogWrite(PWMB, PWMVal);
}

void Bfan(){
  digitalWrite(BIN1, 1);        
  digitalWrite(BIN2, 0);  
  //analogWrite(PWMB, PWMVal);
}

void Bstop(){
  digitalWrite(BIN1, 1);        
  digitalWrite(BIN2, 1);  
  //analogWrite(PWMB, PWMVal); 
}

void forward1(){
  void Azheng();
  void Bzheng();
}

void back1(){
  void Afan();
  void Bfan();
}

void left1(){
  void Azheng();
  void Bstop();
}

void right1(){
  void Astop();
  void Bzheng();
}

void stop(){
  void Astop();
  void Bstop();
}


void setup() {
  // put your setup code here, to run once:
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT); 
  Serial.begin(9600);
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
    unsigned long leftFrequency = get_speed_left();
    Serial.print("leftFrequency:");
    Serial.print(leftFrequency);
    Serial.println("");
    unsigned long rightFrequency = get_speed_right();
    Serial.print("rightFrequency:");
    Serial.println(rightFrequency);
    Serial.println("");
    if(leftFrequency>rightFrequency){
      Azheng();
      Bzheng();
      PWMValA = PWMValA*leftFrequency/rightFrequency;//the right wheel will be faster, as the PWMA multiplies a factor
  } 
    else if(leftFrequency<rightFrequency){
      Azheng();
      Bzheng();
      PWMValB += PWMValB*rightFrequency/leftFrequency;
    }
}
}
