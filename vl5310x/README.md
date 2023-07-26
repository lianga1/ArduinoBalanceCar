VL53L0X最远测距的距离是2m，精度可以是2mm

原理:发射激光到反射物，激光折射回来给接收元件，然后VL53L0X内部计算出时间和距离后打印

1.Vl53L0X_arduino.ino

可以在Arduino串口绘图仪显示测距图像，经过延时100ms后图像更加清晰易辨认

require library:
https://github.com/DFRobot/DFRobot_VL53L0X
or download from arduino library by searching DFRobot_VL53L0X

ref: https://cloud.tencent.com/developer/article/1761137

2.stm32: https://blog.csdn.net/tiramisu_L/article/details/89502121

