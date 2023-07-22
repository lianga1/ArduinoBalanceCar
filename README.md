# ArduinoBalanceCar
an balance dual-wheel car driven by arduino uno
# Current Progress
## Modules
- [x] Motor Driver
- [x] Speed Monitor
- [ ] UART Communication
- [x] Bluetooth Controller
- [ ] PID Control
## Motor Driver
packaged with a function move that takes a speed , a direction and a time as parameters
## main loop
Can input with bluetooth controller or serial monitor, input wasd for direction and 0-9 for speed (0 for stop), Duty ratio of PWM is from 100-190(Maximum 255)
## Speed Monitor
Can output the speed of the motor to serial monitor.
What's more , you can get the speed by the variable 'rightSpeed' and 'leftSpeed'.
# Required Libraries
* MsTimer2
* PinChangeInterrupt
* PID_v1
