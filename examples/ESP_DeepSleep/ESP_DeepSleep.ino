// ============================================================
//  AARUESP ESP Deep Sleep Demo
//  ESP32 wakes every 30 seconds; ESP8266 needs GPIO16 -> RST.
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>
#include <AARUESPESP.h>

#define SLEEP_US (30ULL * 1000000ULL)   // 30 seconds

void setup() {
  Serial.begin(115200);
  delay(300);
  AARUESP.begin();

  Serial.printf("Wake reason: %s\n", aaruesp_esp::wakeReason());
  Serial.printf("Free heap: %u bytes\n", aaruesp_esp::freeHeap());
  Serial.printf("Going to sleep for %is...\n", (int)(SLEEP_US / 1000000ULL));
  Serial.flush();
  delay(100);

  aaruesp_esp::deepSleep(SLEEP_US);    // never returns
}

void loop() {
  AARUESP.update();
}