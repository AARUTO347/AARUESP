// ============================================================
//  AARUESP ESP WiFi Scan
//  Lists nearby WiFi networks. AARUESPESP companion demo.
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>
#include <AARUESPESP.h>

void setup() {
  Serial.begin(115200);
  delay(500);
  AARUESP.begin();
  Serial.printf("Chip: %s | MAC: %s\n", aaruesp_esp::chipModel(), aaruesp_esp::macAddress().c_str());
  Serial.println("Scanning...");
}

void loop() {
  AARUESP.update();
  int n = aaruesp_esp::wifiScanCount(8000);
  if (n < 0) {
    Serial.println("Scan failed");
  } else {
    Serial.printf("Found %d networks\n", n);
    for (int i = 0; i < n && i < 20; i++) {
      Serial.printf("  %d: %-32s\n", i, aaruesp_esp::wifiScanSSID(i).c_str());
    }
  }
  delay(10000);
}