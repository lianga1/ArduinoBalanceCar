#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_MOSI   11
#define OLED_CLK   13
#define OLED_DC    9
#define OLED_CS    10
#define OLED_RESET 8
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
 
void setup()   {              
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(1000);
}
 
void loop() {
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("- LEO -");
  display.display();
  delay(200);
  display.clearDisplay();
}