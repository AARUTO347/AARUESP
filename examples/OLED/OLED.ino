// ============================================================
//  AARUESP SSD1306 OLED Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.oled(0x3C, 128, 64);
  AARUESP.displayClear();
  AARUESP.displayText("AARUESP");
  AARUESP.displayTextAt(1, 0, "SSD1306 OLED");
  AARUESP.displayTextAt(2, 0, "MADE BY AARUTO");
  delay(2000);
}

void loop() {
  AARUESP.displayClear();
  AARUESP.displayText("Counter:");
  AARUESP.displayTextAt(1, 0, "Value: ");
  static int count = 0;
  AARUESP.displayPrint(count++);
  delay(500);
}