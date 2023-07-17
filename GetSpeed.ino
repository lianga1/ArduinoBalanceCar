volatile unsigned long rightCount = 0;
volatile unsigned long leftCount = 0;
unsigned long lastTime = 0;
#define LEFTSPD 2
#define RIGHTSPD 3
unsigned long get_speed_left(){
    pinMode(LEFTSPD, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(LEFTSPD), countLeftPulses, RISING);
    unsigned long currentTime = lastTime = millis();
    while (currentTime - lastTime < 40) {
      currentTime = millis();
    }
    unsigned long leftFrequency = leftCount / (currentTime - lastTime);
    leftCount = 0;
    return leftFrequency;

}
unsigned long get_speed_right(){
    pinMode(RIGHTSPD, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(RIGHTSPD), countRightPulses, RISING);
    unsigned long currentTime = lastTime = millis();
    while (currentTime - lastTime < 40) {
      currentTime = millis();
    }
    unsigned long rightFrequency = rightCount / (currentTime - lastTime);
    rightCount = 0;
    return rightFrequency;
}



void countLeftPulses() {
  leftCount++;
}

void countRightPulses() {
  rightCount++;
}