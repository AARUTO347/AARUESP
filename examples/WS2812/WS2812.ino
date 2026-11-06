// ============================================================
//  AARUESP WS2812 NeoPixel Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.ws2812(4, 10);
  AARUESP.setBrightness(50);
}

void loop() {
  AARUESP.rainbow();
  AARUESP.show();
  delay(50);
}