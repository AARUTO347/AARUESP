// ============================================================
//  AARUESP GPS Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.gps(16, 17, 9600);
}

void loop() {
  AARUESP.gpsUpdate();
  if (AARUESP.gpsFix()) {
    Serial.print("Lat: ");
    Serial.print(AARUESP.gpsLat(), 6);
    Serial.print(", Lon: ");
    Serial.print(AARUESP.gpsLon(), 6);
    Serial.print(", Alt: ");
    Serial.print(AARUESP.gpsAlt(), 1);
    Serial.print("m, Sats: ");
    Serial.println(AARUESP.gpsSats());
  } else {
    Serial.println("Waiting for GPS fix...");
  }
  delay(1000);
}