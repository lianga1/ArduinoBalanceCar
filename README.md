# ArduinoBalanceCar
an balance dual-wheel car driven by arduino uno
# Current Progress
## Modules
- [x] Motor Driver
- [x] Speed Monitor
- [x] UART Communication
- [x] Bluetooth Controller
- [x] PID Control for speed
- [x] OLED (arduino or esp32)
- [ ] PID Control for balance
- [ ] trace the line
## Motor Driver
packaged with a function move that takes a speed , a direction and a time as parameters
## main loop
Can input with bluetooth controller or serial monitor, input wasd for direction and 0-9 for speed (0 for stop), Duty ratio of PWM is from 100-190(Maximum 255)
## Speed Monitor
Can output the speed of the motor to serial monitor.
What's more , you can get the speed by the variable 'rightSpeed' and 'leftSpeed'.
## Speed Monitor
display with 'oled and arduino' or 'oled and esp32' 
# Required Libraries
* MsTimer2
* PinChangeInterrupt
* PID_v1
* Adafruit_GFX
* Adafruit_SSD1306
* ssd1306.py (esp32)
