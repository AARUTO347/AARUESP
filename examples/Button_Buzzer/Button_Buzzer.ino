/*
  Button_Buzzer — AARUESP actuator/digital module example

  Demonstrates ButtonModule and BuzzerModule via AARUESP class-module API.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

ButtonModule btn(BUTTON_PIN, INPUT_PULLUP);
BuzzerModule buzz(BUZZER_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.println(F("AARUESP Button + Buzzer Example — V1.1"));

  btn.init();
  buzz.init();
}

void loop() {
  btn.update();
  if (btn.wasPressed()) {
    Serial.println(F("Button pressed!"));
    buzz.tone(1000, 200);
  }
  delay(50);
}
