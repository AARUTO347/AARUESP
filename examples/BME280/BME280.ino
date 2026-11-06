// ============================================================
//  AARUESP BME280 Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.bme280(0x76);
}

void loop() {
  float temp, hum, press;
  if (AARUESP.readBME(temp, hum, press)) {
    Serial.print("Temp: ");
    Serial.print(temp, 2);
    Serial.print(" C, Humidity: ");
    Serial.print(hum, 1);
    Serial.print(" %, Pressure: ");
    Serial.print(press, 1);
    Serial.print(" hPa, Altitude: ");
    Serial.print(AARUESP.readBMEaltitude(1013.25), 1);
    Serial.println(" m");
  } else {
    Serial.print("BME Error: ");
    Serial.println(AARUESP.errorString());
  }
  delay(2000);
}