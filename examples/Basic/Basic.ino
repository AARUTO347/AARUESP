// ============================================================
//  AARUESP Basic Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.ultrasonic(5, 18);
  AARUESP.led(2);           // onboard LED on most ESP32 dev boards
  AARUESP.buzzer(4);
  AARUESP.lcdI2C(0x27, 16, 2);
  AARUESP.displayText("AARUESP Ready");
  delay(1000);
}

void loop() {
  AARUESP.update();
  float cm = AARUESP.readUltrasonic();
  if (AARUESP.lastError() != AARUESP_OK) return;
  if (cm > 0 && cm < 20) {
    AARUESP.setLED(true);
    AARUESP.beep(2000, 100);
    AARUESP.displayText("Object Close!");
  } else {
    AARUESP.setLED(false);
    AARUESP.displayText("Monitoring...");
  }
  delay(100);
}