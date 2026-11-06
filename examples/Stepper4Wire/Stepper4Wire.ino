// ============================================================
//  AARUESP 28BYJ-48 Stepper Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.stepper4Wire(13, 12, 14, 27);
  AARUESP.stepperSetRpm(10);
  AARUESP.stepperMove(4096);
}

void loop() {
  if (AARUESP.stepperRun()) {
    // moving
  } else {
    delay(1000);
    AARUESP.stepperMove(-4096);
  }
}