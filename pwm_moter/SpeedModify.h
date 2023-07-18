#ifndef GETSPEED_H
#define GETSPEED_H
#include <MsTimer2.h>

#include <PinChangeInterrupt.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptSettings.h>


volatile unsigned long rightCount = 0;
volatile unsigned long leftCount = 0;
volatile unsigned long rightSpeed = 0;
volatile unsigned long leftSpeed = 0;
#define LEFTSPD 2
#define RIGHTSPD 3

/*definations of the constants for the wheel and the encoder*/
#define WHEEL_DIAMETER 6.5 // centimeters
#define PI 3
#define PULSES_PER_REVOLUTION 585

void getSpeed()
{
  rightSpeed = rightCount*10/PULSES_PER_REVOLUTION*PI*WHEEL_DIAMETER;
  leftSpeed = leftCount*10/PULSES_PER_REVOLUTION*PI*WHEEL_DIAMETER;
  rightCount = 0;
  leftCount = 0;
  Serial.print("leftSpeed:");
  Serial.print(leftSpeed);
  Serial.println("cm/s");
  Serial.print("rightSpeed:");
  Serial.print(rightSpeed);
  Serial.println("cm/s");
  Serial.print("leftCount:");
  Serial.println(leftCount);
  Serial.print("rightCount:");
  Serial.println(rightCount);

}


void countLeftPulses() {
  leftCount++;
}

void countRightPulses() {
  rightCount++;
}

void setupSpeedTest() {
  pinMode(LEFTSPD, INPUT);
  pinMode(RIGHTSPD, INPUT);
  attachPCINT(digitalPinToPCINT(RIGHTSPD), countRightPulses, RISING);
  attachPCINT(digitalPinToPCINT(LEFTSPD), countLeftPulses, RISING);

  
  // MsTimer2::set(100, getSpeed);//set the timer interrupt, 100ms
  // MsTimer2::start();//start the timer
}
#endif