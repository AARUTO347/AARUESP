// ============================================================
//  AARUESP TM1637 Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.tm1637(2, 3);
  AARUESP.setBrightness(7);
}

void loop() {
  static int count = 0;
  AARUESP.printNumber(count++);
  delay(100);
}