// ============================================================
//  AARUESP Class-Module OLED Example
//  Uses the class-module API (modules/OLEDModule.h).
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>
#include <modules/OLEDModule.h>

OLEDModule display(21, 22, 0x3C);   // SDA=21, SCL=22, SSD1306 addr

void setup() {
  Serial.begin(115200);
  delay(300);
  AARUESP.begin();                  // singleton: board detection + drivers

  if (!display.init()) {
    Serial.println("OLED not found at 0x3C — check wiring (SDA=21, SCL=22)");
  }
  display.clear();
  display.print(0, 0, "AARUESP", 2);
  display.println(2, "Class modules");
  display.println(3, "MADE BY AARUTO");
  display.println(5, "ESP boards: 200+");
  display.display();
}

void loop() {
  AARUESP.update();
  display.update();
}