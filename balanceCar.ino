#define PWMA 10

#define PWMB 9
#define AIN1 12
#define AIN2 13
#define BIN1 7
#define BIN2 6
#include "GetSpeed.ino"
void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop() {
  digitalWrite(AIN1, HIGH); // 设置电机A的方向
  digitalWrite(AIN2, LOW);  // 设置电机A的方向
  digitalWrite(BIN1, HIGH); // 设置电机A的方向
  digitalWrite(BIN2, LOW);  // 设置电机A的方向
  unsigned long leftspd = get_speed_left();
  analogWrite(PWMA, 128); // 设置电机A的速度，128是一半速度
  analogWrite(PWMB, 128);

}
