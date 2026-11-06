// ============================================================
//  AARUESP RGB LED Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.rgb(25, 26, 27);
}

void loop() {
  AARUESP.setRGB(255, 0, 0); delay(500);
  AARUESP.setRGB(0, 255, 0); delay(500);
  AARUESP.setRGB(0, 0, 255); delay(500);
  AARUESP.setRGB(255, 255, 0); delay(500);
  AARUESP.setRGB(0, 255, 255); delay(500);
  AARUESP.setRGB(255, 0, 255); delay(500);
  AARUESP.setRGB(255, 255, 255); delay(500);
  AARUESP.rgbOff(); delay(500);
}