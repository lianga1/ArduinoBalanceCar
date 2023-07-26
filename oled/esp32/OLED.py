from machine import Pin, SPI
import ssd1306

hspi = SPI(1)  # sck=14 (scl), mosi=13 (sda), miso=12 (unused)

dc = Pin(4)    # data/command
rst = Pin(5)   # reset
cs = Pin(15)   # chip select, some modules do not have a pin for this

display = ssd1306.SSD1306_SPI(128, 64, hspi, dc, rst, cs)
display.text('ADC:000', 0, 0, 1)
#display.text('Hello, World!', 0, 0, 3)
display.show()