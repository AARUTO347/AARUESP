// ============================================================
//  AARUESP LCD I2C Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.lcdI2C(0x27, 16, 2);
  AARUESP.displayClear();
  AARUESP.displayText("AARUESP");
  AARUESP.displayTextAt(1, 0, "LCD 16x2 I2C");
  delay(2000);
}

void loop() {
  AARUESP.displayClear();
  AARUESP.displayText("Time:");
  AARUESP.displayTextAt(1, 0, "Sec: ");
  AARUESP.displayPrint(millis() / 1000);
  delay(1000);
}