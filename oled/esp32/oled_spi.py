from machine import Pin, SPI
import ssd1306

hspi = SPI(1)  # sck=14 (scl), mosi=13 (sda), miso=12 (unused)

dc = Pin(4)    # data/command
rst = Pin(5)   # reset
cs = Pin(15)   # chip select, some modules do not have a pin for this

#OLED: GND, VCC, D0, D1, RES, DC, CS
#esp32:GND, 3v3, D14, D13, D5, D4, D15


display = ssd1306.SSD1306_SPI(128, 64, hspi, dc, rst, cs)
display.text('ADC:000', 0, 0, 1)
#display.text('Hello, World!', 0, 0, 3)
display.draw_chinese('我爱你祖国',1,3)
display.show()