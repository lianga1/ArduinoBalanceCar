飞行时间TOF（Tlme of Flight）:传感器发出经过调制的近红外光，遇到物体后反射，传感器通过计算光线发射和反射时间差或相位差，来换算被测量物体的距离。

传感器发出经过调制的近红外光，遇到物体后反射，传感器通过计算光线发射和反射时间差或相位差，来换算被测量物体的距离。

1.VL53L0X_arduino.ino


VL5310X: VIN, GND, SCL, SDA

arduino: 3.3V, GND, SCL, SDA

可以在Arduino串口绘图仪显示测距图像，经过延时100ms后图像更加清晰易辨认

require library:
https://github.com/DFRobot/DFRobot_VL53L0X
or download from arduino library by searching DFRobot_VL53L0X

ref: https://cloud.tencent.com/developer/article/1761137

2.stm32: https://blog.csdn.net/tiramisu_L/article/details/89502121

