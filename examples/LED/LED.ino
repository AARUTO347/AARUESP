// ============================================================
//  AARUESP LED PWM Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.led(2);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    AARUESP.setBrightness(i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    AARUESP.setBrightness(i);
    delay(5);
  }
}