1.arduino

OLED: GND, VCC, D0, D1, RES, DC, CS

arduino:GND, 3v3, 13, 11, 8, 9,10

ref: https://www.cnblogs.com/gooutlook/p/11773966.html

spi require library:

Adafruit_SSD1306

Adafruit_GFX

①oled.ino 显示-LEO-

②oled_a_piece_of_cake.ino 显示中文"小菜一碟"

require: PCtoLCD2002 取模生成汉字 ref: https://blog.csdn.net/smallredhat01/article/details/128283957

code ref: https://blog.csdn.net/a_52hz/article/details/100136496

2.esp32

OLED: GND, VCC, D0, D1, RES, DC, CS

esp32:GND, 3v3, D14, D13, D5, D4, D15

code ref: http://micropython.com.cn/en/latet/esp8266/tutorial/ssd1306.html

硬spi

require: ss1306.py

