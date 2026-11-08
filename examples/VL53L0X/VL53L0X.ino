/*
  VL53L0X — AARUESP V1.2 example
  Demonstrates VL53L0XModule (Time-of-Flight distance sensor).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

VL53L0XModule tof(21, 22);  // SDA=21, SCL=22

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP VL53L0X Example — V1.2"));

  if (!tof.init()) {
    Serial.println(F("VL53L0X init failed — check wiring"));
    return;
  }
  Serial.println(F("VL53L0X initialized"));
}

void loop() {
  tof.update();
  if (tof.isHealthy()) {
    Serial.print(F("Distance: "));
    Serial.print(tof.readDistanceMM());
    Serial.print(F(" mm | "));
    Serial.print(tof.readDistanceCM());
    Serial.println(F(" cm"));
  }
  delay(200);
}