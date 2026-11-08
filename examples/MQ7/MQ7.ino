/*
  MQ7 — AARUESP V1.2 example
  Demonstrates MQ7Module (CO gas sensor, analog).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

MQ7Module mq7(34, 3.3f);  // analog pin 34, 3.3V reference

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP MQ7 CO Sensor Example — V1.2"));

  mq7.init();
}

void loop() {
  mq7.update();
  Serial.print(F("CO: "));
  Serial.print(mq7.readCOppm());
  Serial.println(F(" ppm"));
  delay(1000);
}