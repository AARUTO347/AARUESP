// ============================================================
//  AARUESP Stepper Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.stepper(12, 14);
  AARUESP.stepperSetRpm(60);
  AARUESP.stepperMove(200);
}

void loop() {
  if (AARUESP.stepperRun()) {
    // still moving
  } else {
    delay(1000);
    AARUESP.stepperMove(-200);
  }
}