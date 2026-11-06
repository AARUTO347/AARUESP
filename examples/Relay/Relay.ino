// ============================================================
//  AARUESP Relay Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.relay(4, true);
}

void loop() {
  AARUESP.setRelay(true);
  Serial.println("Relay ON");
  delay(1000);
  AARUESP.setRelay(false);
  Serial.println("Relay OFF");
  delay(1000);
}