// ============================================================
//  AARUESP MAX7219 Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.max7219(5, 1);
  AARUESP.displayClear();
}

void loop() {
  static long count = 0;
  AARUESP.displayPrint(count++);
  delay(100);
}