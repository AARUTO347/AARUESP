/*
  DeepSleep — AARUESP V1.2 example
  Demonstrates DeepSleepModule (deep sleep + wake reason).
*/
#include <AARUESP_MODULES.h>

using namespace aru;

DeepSleepModule deepSleepMod;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Deep Sleep Example — V1.2"));

  deepSleepMod.init();

  Serial.print(F("Wake reason: "));
  Serial.println(deepSleepMod.wakeReason());

  Serial.println(F("Entering deep sleep for 10 seconds..."));
  Serial.flush();
  delay(100);
  deepSleepMod.sleepSeconds(10);
}

void loop() {
  // deep sleep never returns
}