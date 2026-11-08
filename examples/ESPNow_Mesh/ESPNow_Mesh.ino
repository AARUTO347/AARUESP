/*
  ESPNow_Mesh — AARUESP V2.2 example
  Demonstrates ESPNowModule for peer-to-peer communication.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

ESPNowModule espNow;
uint8_t peerMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP ESP-NOW Mesh Example — V2.2"));

  if (!espNow.init()) {
    Serial.println(F("ESP-NOW init failed"));
    return;
  }

  espNow.addPeer(peerMac);
  Serial.println(F("ESP-NOW initialized"));
}

void loop() {
  // Broadcast sensor data
  uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
  espNow.broadcast(data, sizeof(data));

  // Check for received data
  if (espNow.hasReceived()) {
    uint8_t buf[250];
    size_t len = espNow.getReceivedData(buf, sizeof(buf));
    Serial.print(F("Received "));
    Serial.print(len);
    Serial.println(F(" bytes"));
  }

  delay(1000);
}