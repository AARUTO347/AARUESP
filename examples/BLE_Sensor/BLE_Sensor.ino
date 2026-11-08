/*
  BLE_Sensor — AARUESP V2.2 example
  Demonstrates BLEModule for broadcasting sensor data.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

BLEModule ble("AARUESP_Sensor");
float temperature = 25.0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP BLE Sensor Example — V2.2"));

  if (!ble.init()) {
    Serial.println(F("BLE init failed"));
    return;
  }

  ble.setServiceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
  ble.setCharacteristicUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

  Serial.println(F("BLE initialized — advertising"));
}

void loop() {
  temperature = 20.0 + (random(0, 100) / 10.0);
  char buf[32];
  snprintf(buf, sizeof(buf), "%.1f", temperature);
  ble.setValue(buf);
  ble.notify();

  Serial.print(F("BLE value: "));
  Serial.println(buf);
  delay(2000);
}