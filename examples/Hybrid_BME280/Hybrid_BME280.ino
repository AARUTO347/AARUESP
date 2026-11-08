/*
  Hybrid_BME280 — AARUESP hybrid API example

  Shows both singleton and class-module usage side by side.
*/
#include <AARUESP.h>
#include <AARUESP_MODULES.h>

using namespace aru;

BME280Module bme(SDA_PIN, SCL_PIN);  // class-instance style

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.println(F("AARUESP Hybrid BME280 Example — V1.1"));

  // Class-module path
  if (!bme.init()) {
    Serial.println(F("BME280 class init failed"));
  } else {
    Serial.println(F("BME280 class-module initialized"));
  }

  // Singleton path (if singleton supports BME280)
  if (AARUESP.begin()) {
    Serial.println(F("AARUESP singleton begin OK"));
  }
}

void loop() {
  if (bme.isHealthy()) {
    float temp = bme.readTemperature();
    float hum = bme.readHumidity();
    float pres = bme.readPressure() / 100.0f;

    Serial.print(F("Temp: ")); Serial.print(temp); Serial.println(F(" C"));
    Serial.print(F("Hum: "));  Serial.print(hum);  Serial.println(F(" %"));
    Serial.print(F("Pres: ")); Serial.print(pres); Serial.println(F(" hPa"));
  }
  delay(2000);
}
