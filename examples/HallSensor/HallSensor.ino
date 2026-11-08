/*
  HallSensor — AARUESP V1.2 example
  Demonstrates HallSensorModule (ESP32 internal Hall sensor).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

HallSensorModule hall;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Hall Sensor Example — V1.2"));

#if defined(ESP32)
  if (!hall.init()) {
    Serial.println(F("Hall sensor init failed"));
    return;
  }
  Serial.println(F("Hall sensor initialized"));
#else
  Serial.println(F("Hall sensor only available on ESP32"));
#endif
}

void loop() {
#if defined(ESP32)
  hall.update();
  Serial.print(F("Raw: "));
  Serial.print(hall.readRaw());
  Serial.print(F(" | Gauss: "));
  Serial.println(hall.readGauss());
#endif
  delay(500);
}