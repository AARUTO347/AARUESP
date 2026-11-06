// ============================================================
//  AARUESP DS18B20 Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.ds18b20(2);
  Serial.print("Found ");
  Serial.print(AARUESP.ds18b20Count());
  Serial.println(" DS18B20 sensor(s)");
}

void loop() {
  for (int i = 0; i < AARUESP.ds18b20Count(); i++) {
    float c = AARUESP.readDS18B20(i);
    float f = AARUESP.readDS18B20F(i);
    if (!isnan(c)) {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(c, 2);
      Serial.print(" C / ");
      Serial.print(f, 2);
      Serial.println(" F");
    }
  }
  Serial.println("---");
  delay(1000);
}