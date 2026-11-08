/*
  V21_Test — AARUESP V2.1 compile test
  Tests all new V2.1 modules compile correctly.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

OTAModule ota;
WebServerModule webServer(80);
BLEModule ble("AARUESP");
ESPNowModule espNow;
MQTTModule mqtt("mqtt.example.com");
TouchModule touch(4);
DACModule dac(25);
PSRAMModule psram;
StorageManager storage;
ConfigManager config;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP V2.1 Test"));

  ota.init();
  webServer.init();
  ble.init();
  espNow.init();
  mqtt.init("broker.example.com");
  touch.init();
  dac.init();
  psram.init();
  storage.init();
  config.init();

  Serial.println(F("All modules initialized"));
  Serial.print(F("PSRAM available: "));
  Serial.println(psram.isAvailable() ? "YES" : "NO");
  Serial.print(F("PSRAM size: "));
  Serial.println(psram.getSize());
}

void loop() {
  webServer.update();
  mqtt.update();
  touch.update();
  dac.write(128);
  delay(100);
}