// ============================================================
//  AARUESP Buzzer Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.buzzer(4);
}

void loop() {
  AARUESP.beep(1000, 200);
  delay(300);
  AARUESP.beep(1500, 200);
  delay(300);
  AARUESP.beep(2000, 200);
  delay(1000);
}