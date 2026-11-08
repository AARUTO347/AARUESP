/*
  Touch_DAC — AARUESP V2.2 example
  Demonstrates TouchModule and DACModule (ESP32 only).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

TouchModule touch(4, 40);
DACModule dac(25);

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Touch + DAC Example — V2.2"));

#if defined(ESP32)
  touch.init();
  dac.init();
  Serial.println(F("Touch + DAC initialized"));
#else
  Serial.println(F("This example requires ESP32"));
#endif
}

void loop() {
#if defined(ESP32)
  touch.update();
  if (touch.isTouched()) {
    Serial.println(F("Touch detected!"));
    dac.write(255);  // Full output
  } else {
    dac.write(0);    // No output
  }
  Serial.print(F("Touch raw: "));
  Serial.println(touch.readRaw());
#endif
  delay(100);
}