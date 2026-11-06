// ============================================================
//  AARUESP DHT11/DHT22 Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.dht11(2);
}

void loop() {
  float temp, hum;
  if (AARUESP.readDHT(temp, hum)) {
    Serial.print("Temp: ");
    Serial.print(temp, 1);
    Serial.print(" C / ");
    Serial.print(AARUESP.readTemperatureF(), 1);
    Serial.print(" F, Humidity: ");
    Serial.print(hum, 1);
    Serial.println(" %");
  } else {
    Serial.print("DHT Error: ");
    Serial.println(AARUESP.errorString());
  }
  delay(2000);
}