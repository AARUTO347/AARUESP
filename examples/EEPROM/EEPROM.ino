/*
  EEPROM — AARUESP V1.2 example
  Demonstrates EEPROMModule (key-value persistent storage).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

EEPROMModule eeprom(512);

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP EEPROM Example — V1.2"));

  eeprom.init();

  eeprom.writeUInt32("boot_count", 42);
  eeprom.writeString("device_name", "AARUESP_NODE");
  eeprom.commit();

  uint32_t count = eeprom.readUInt32("boot_count", 0);
  char name[32];
  eeprom.readString("device_name", name, sizeof(name), "UNKNOWN");

  Serial.print(F("Boot count: "));
  Serial.println(count);
  Serial.print(F("Device name: "));
  Serial.println(name);
}

void loop() {
  delay(1000);
}