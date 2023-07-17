#ifndef GETSPEED_H
#define GETSPEED_H
volatile unsigned long rightCount = 0;
volatile unsigned long leftCount = 0;
volatile unsigned long rightFrequency = 0;
volatile unsigned long leftFrequency = 0;
unsigned long lastTime = 0;
#define LEFTSPD 2
#define RIGHTSPD 3

/*definations of the constants for the wheel and the encoder*/
#define WHEEL_DIAMETER 6.5 // centimeters
#define PI 3
#define PULSES_PER_REVOLUTION 585


ISR(TIMER1_COMPA_vect) {
  // 访问脉冲数量并清零
  leftFrequency = leftCount*100;
  leftCount = 0;
  rightFrequency = rightCount*100;
  rightCount = 0;
  // 计算脉冲频率
  uint8_t leftSpeed = leftFrequency *

  // 在这里可以对脉冲频率进行处理或输出
  Serial.print("LSpeed: ");
  Serial.print(leftFrequency);
  Serial.println(" Hz");
  Serial.print("RFrequency: ");
  Serial.print(rightFrequency);
  Serial.println(" Hz");

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
  cli();
  // 设置定时器1
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // 设置比较寄存器
  OCR1A = 15624; // = 16000000 / (1 * 1024) - 1 (must be <65536)
  // 设置预分频器
  TCCR1B |= (1 << CS10); // no prescaler
  TCCR1B |= (1 << CS12); // 1024 prescaler
  // 启用比较A匹配中断
  TIMSK1 |= (1 << OCIE1A);
  sei();
}
#endif