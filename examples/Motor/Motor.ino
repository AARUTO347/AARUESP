// ============================================================
//  AARUESP Motor Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.motor(12, 14, 27);
}

void loop() {
  AARUESP.motorSpeed(200);
  delay(2000);
  AARUESP.motorSpeed(0);
  delay(500);
  AARUESP.motorSpeed(-200);
  delay(2000);
  AARUESP.motorBrake();
  delay(500);
}