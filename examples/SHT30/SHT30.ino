/*
  SHT30 — AARUESP V1.2 example
  Demonstrates SHT30Module (temperature/humidity, I2C).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

SHT30Module sht30(21, 22);  // SDA=21, SCL=22

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP SHT30 Example — V1.2"));

  if (!sht30.init()) {
    Serial.println(F("SHT30 init failed — check wiring"));
    return;
  }
  Serial.println(F("SHT30 initialized"));
}

void loop() {
  sht30.update();
  if (sht30.isHealthy()) {
    Serial.print(F("Temp: "));
    Serial.print(sht30.readTemperature());
    Serial.print(F(" C | Hum: "));
    Serial.print(sht30.readHumidity());
    Serial.println(F(" %RH"));
  }
  delay(1000);
}