/*
  PSRAM_Memory — AARUESP V2.2 example
  Demonstrates PSRAMModule for memory management.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

PSRAMModule psram;
StorageManager storage;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP PSRAM + Storage Example — V2.2"));

  psram.init();
  storage.init();

  Serial.print(F("PSRAM available: "));
  Serial.println(psram.isAvailable() ? "YES" : "NO");
  Serial.print(F("PSRAM size: "));
  Serial.println(psram.getSize());
  Serial.print(F("PSRAM free: "));
  Serial.println(psram.getFreeSize());

  // Allocate large buffer in PSRAM
  if (psram.isAvailable()) {
    void* buf = psram.allocate(100000);  // 100KB
    if (buf) {
      Serial.println(F("Allocated 100KB in PSRAM"));
      psram.deallocate(buf);
    }
  }

  // Storage test
  storage.mountSPIFFS();
  storage.writeFile("/test.txt", "Hello from AARUESP!");
  String content = storage.readFile("/test.txt");
  Serial.print(F("File content: "));
  Serial.println(content);
  Serial.print(F("Free space: "));
  Serial.println(storage.getFreeSpace());
}

void loop() {
  delay(1000);
}