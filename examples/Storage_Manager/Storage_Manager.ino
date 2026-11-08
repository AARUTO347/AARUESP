/*
  Storage_Manager — AARUESP V2.2 example
  Demonstrates StorageManager for file system operations.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

StorageManager storage;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Storage Manager Example — V2.2"));

  storage.init();
  storage.mountSPIFFS();

  // Write a file
  storage.writeFile("/data.txt", "Hello from AARUESP V2.2!");

  // Read it back
  String content = storage.readFile("/data.txt");
  Serial.print(F("File content: "));
  Serial.println(content);

  // Check file info
  Serial.print(F("File exists: "));
  Serial.println(storage.exists("/data.txt") ? "YES" : "NO");
  Serial.print(F("File size: "));
  Serial.println(storage.getFileSize("/data.txt"));
  Serial.print(F("Total space: "));
  Serial.println(storage.getTotalSpace());
  Serial.print(F("Used space: "));
  Serial.println(storage.getUsedSpace());
  Serial.print(F("Free space: "));
  Serial.println(storage.getFreeSpace());

  // NVS storage
  storage.mountNVS("aaruesp");
  storage.nvsWrite("device_name", "AARUESP_Node");
  storage.nvsWriteInt("boot_count", 42);
  Serial.print(F("Device: "));
  Serial.println(storage.nvsRead("device_name", "unknown"));
  Serial.print(F("Boot count: "));
  Serial.println(storage.nvsReadInt("boot_count", 0));
}

void loop() {
  delay(1000);
}