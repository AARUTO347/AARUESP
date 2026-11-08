/*
  SD_Storage — AARUESP storage module example

  Demonstrates SDCardModule via AARUESP hybrid API.
*/
#include <AARUESP.h>
#include <AARUESP_MODULES.h>

using namespace aru;

SDCardModule sd(SD_CS_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.println(F("AARUESP SD Storage Example — V1.1"));

  if (!sd.init()) {
    Serial.println(F("SD init failed — check CS pin and card"));
    return;
  }

  File f = sd.open("test.txt", FILE_WRITE);
  if (f) {
    f.println("Hello from AARUESP V1.1");
    f.close();
    Serial.println(F("Written test.txt"));
  }

  f = sd.open("test.txt", FILE_READ);
  if (f) {
    Serial.println(F("Reading test.txt:"));
    while (f.available()) {
      Serial.write(f.read());
    }
    f.close();
  }
}

void loop() {
  delay(1000);
}
