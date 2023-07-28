#define POST_FLAG 0x50 // 假设POST标志为0x50
#define SERVO1_PIN 9   // 舵机1连接的引脚
#define SERVO2_PIN 10  // 舵机2连接的引脚

#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600); // 初始化串口通信，波特率为9600
  servo1.attach(SERVO1_PIN); // 将舵机对象连接到对应的引脚
  servo2.attach(SERVO2_PIN);
}

void loop() {
  if (Serial.available() > 0) { // 检查是否有数据可读
    if (Serial.read() == POST_FLAG) { // 如果收到POST标志
      if (Serial.available() >= 3) { // 确保有足够的数据可读
        int command = Serial.read(); // 读取运动指令
        int servo1Pos = Serial.read(); // 读取舵机1的位置
        int servo2Pos = Serial.read(); // 读取舵机2的位置

        executeCommand(command, servo1Pos, servo2Pos); // 执行指令
        sendSpeedData(); // 发送速度数据 
        delay(100); // 等待100ms
      }
    }
  }
}

void executeCommand(int command, int servo1Pos, int servo2Pos) {
  // 在这里添加你的代码以执行运动指令
  // 例如，你可能会根据指令调整舵机的位置
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
}

void sendSpeedData() {
  // 在这里添加你的代码以发送速度数据
  // 例如，你可能会发送一个随机数作为速度数据
  int speedData = random(0, 255);
  Serial.write(speedData);
}
