// ============================================================
//  AARUESP ESP Board Info + 207-Board Database
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>
#include <AARUESPESP.h>

void setup() {
  Serial.begin(115200);
  delay(500);
  AARUESP.begin();

  Serial.printf("Board detected: %s\n", AARUESP.boardName());
  Serial.printf("Family ID: %d\n", (int)AARUESP.boardFamily());
  Serial.printf("Chip model: %s\n", aaruesp_esp::chipModel());
  Serial.printf("Chip ID: 0x%08lX\n", aaruesp_esp::chipId());
  Serial.printf("Free heap: %u bytes\n", aaruesp_esp::freeHeap());
  Serial.printf("Flash size: %u bytes\n", aaruesp_esp::flashSize());
  Serial.printf("PSRAM size: %u bytes\n", aaruesp_esp::psramSize());
  Serial.printf("CPU freq: %u MHz\n", aaruesp_esp::cpuFrequencyMhz());

  Serial.printf("\nBoard database holds %u ESP boards. Example lookups:\n", aaruespBoardCount());
  const char* names[] = { "ESP32S3_BOX", "ESP32_WROOM_32", "ESP32C3_LOLIN_C3", "ESP8266_NODEMCU_V3", "ESP32C6_DevKitC_1", "ARU_ESP32_AARUTO_PRO" };
  for (size_t i = 0; i < 6; i++) {
    const AaruespBoardInfo* b = aaruespBoardFind(names[i]);
    if (b) {
      Serial.printf("  %-26s GPIOs=%d flash=%uMB\n", b->name, b->gpio_count, b->flash_bytes >> 20);
    } else {
      Serial.printf("  %-26s NOT FOUND\n", names[i]);
    }
  }
}

void loop() {
  AARUESP.update();
}