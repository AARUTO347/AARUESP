// ============================================================
//  AARUESP HC-SR04 Ultrasonic Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.ultrasonic(5, 18);
  AARUESP.setUltrasonicTimeout(30000);
}

void loop() {
  float cm = AARUESP.readUltrasonic();
  if (AARUESP.lastError() == AARUESP_OK) {
    Serial.print("Distance: ");
    Serial.print(cm, 1);
    Serial.print(" cm / ");
    Serial.print(AARUESP.readUltrasonicInches(), 1);
    Serial.println(" in");
  } else {
    Serial.print("Error: ");
    Serial.println(AARUESP.errorString());
  }
  delay(200);
}