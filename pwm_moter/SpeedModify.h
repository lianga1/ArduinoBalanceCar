#include <PID_v1.h>

#include <MPU6050.h>

#ifndef GETSPEED_H
#define GETSPEED_H
#include "move.h"
#include <MsTimer2.h>

#include <PinChangeInterrupt.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptSettings.h>

#include <PID_v1.h>

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
  // rightSpeed = rightCount*10/PULSES_PER_REVOLUTION*PI*WHEEL_DIAMETER;
  // leftSpeed = leftCount*10/PULSES_PER_REVOLUTION*PI*WHEEL_DIAMETER;
  leftSpeed = leftCount;
  rightSpeed = rightCount;

  Serial.print("leftSpeed:");
  Serial.print(leftCount);
  Serial.println("pulses");
  Serial.print("rightSpeed:");
  Serial.print(rightCount);
  Serial.println("pulses");
  rightCount = 0;
  leftCount = 0;

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
  
   MsTimer2::set(100, getSpeed);//set the timer interrupt, 100ms
   MsTimer2::start();//start the timer
  attachInterrupt(digitalPinToInterrupt(LEFTSPD), countLeftPulses, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHTSPD), countRightPulses, RISING);

}


#endif
