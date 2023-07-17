volatile unsigned long rightCount = 0;
volatile unsigned long leftCount = 0;
unsigned long lastTime = 0;
#define LEFTSPD 2
#define RIGHTSPD 3

void countLeftPulses() {
  leftCount++;
}

void countRightPulses() {
  rightCount++;
}
unsigned long get_speed_left(){
    pinMode(LEFTSPD, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(LEFTSPD), countLeftPulses, RISING);
    leftCount = 0;
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
    rightCount = 0;
    unsigned long currentTime = lastTime = millis();
    while (currentTime - lastTime < 40) {
      currentTime = millis();
    }
    unsigned long rightFrequency = rightCount / (currentTime - lastTime);
    rightCount = 0;
    return rightFrequency;
}
