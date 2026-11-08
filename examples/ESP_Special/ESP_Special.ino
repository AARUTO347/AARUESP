/*
  ESP_Special — AARUESP ESP Companion API example

  Demonstrates WiFi, deep sleep, chip info, restart, and other ESP-only features.
*/
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.println(F("AARUESP ESP Special Example — V1.1"));

  // Chip info
  Serial.print(F("Chip model: "));
  Serial.println(AARUESP.chipModel());

  Serial.print(F("Chip revision: "));
  Serial.println(AARUESP.chipRevision());

  Serial.print(F("CPU freq MHz: "));
  Serial.println(AARUESP.cpuFreqMHz());

  Serial.print(F("Flash size MB: "));
  Serial.println(AARUESP.flashSizeMB());

  Serial.print(F("Free heap: "));
  Serial.println(AARUESP.freeHeap());

  // WiFi scan (if companion available)
  Serial.println(F("Scanning WiFi..."));
  int n = AARUESP.wifiScan();
  Serial.print(F("Networks found: "));
  Serial.println(n);

  Serial.println(F("Entering deep sleep in 5s..."));
  delay(5000);
  AARUESP.deepSleep(10e6);  // 10 seconds
}

void loop() {
  // deepSleep never returns
}
