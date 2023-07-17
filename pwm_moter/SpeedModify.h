#ifndef GETSPEED_H
#define GETSPEED_H
volatile unsigned long rightCount = 0;
volatile unsigned long leftCount = 0;
volatile unsigned long rightSpeed = 0;
volatile unsigned long leftSpeed = 0;
unsigned long currentTime = 0;
unsigned long startTime = 0;
unsigned long DisplayTime = 0;
#define LEFTSPD 2
#define RIGHTSPD 3

/*definations of the constants for the wheel and the encoder*/
#define WHEEL_DIAMETER 6.5 // centimeters
#define PI 3
#define PULSES_PER_REVOLUTION 585


void checkCurrentSpeed(){
  currentTime = millis();
  
  if(currentTime - startTime > 40){
    int timeDelta = currentTime - startTime;
    unsigned long leftFrequency = leftCount/timeDelta *1000;
    unsigned long rightFrequency = rightCount/timeDelta *1000;
    int revolsPerSecLeft = leftFrequency/PULSES_PER_REVOLUTION;
    int revolsPerSecRight = rightFrequency/PULSES_PER_REVOLUTION;
    leftSpeed = revolsPerSecLeft * PI * WHEEL_DIAMETER;
    rightSpeed = revolsPerSecRight * PI * WHEEL_DIAMETER;
    /*centimeter per second*/
    leftCount = 0;
    rightCount = 0;
    if(currentTime - DisplayTime > 1000){
      Serial.print("left speed: ");
      Serial.print(leftSpeed);
      Serial.println(" cm/s");
      Serial.print("right speed: ");
      Serial.print(rightSpeed);
      Serial.println(" cm/s");
      DisplayTime = currentTime;
    }
    startTime = currentTime;
  }


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
  attachInterrupt(digitalPinToInterrupt(LEFTSPD), countLeftPulses, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHTSPD), countRightPulses, RISING);
  startTime = currentTime = DisplayTime= millis();
}
#endif