/*
  RF24_Radio — AARUESP radio module example

  Demonstrates the RF24Module (nRF24L01+) via AARUESP hybrid API.
  Supports both singleton style (AARUESP.begin...) and class-instance style.
*/
#include <AARUESP.h>
#include <AARUESP_MODULES.h>

using namespace aru;

RF24Module radio(CE_PIN, CSN_PIN);  // class-instance style

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.println(F("AARUESP RF24 Radio Example — V1.1"));

  if (!radio.init()) {
    Serial.println(F("RF24 init failed — check wiring"));
    return;
  }

  radio.setChannel(76);
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.openReadingPipe(1, 0xF0F0F0F0D2LL);
  radio.startListening();

  Serial.println(F("RF24 initialized"));
}

void loop() {
  if (radio.available()) {
    char text[32] = {0};
    radio.read(text, sizeof(text));
    Serial.print(F("Received: "));
    Serial.println(text);
  }
  delay(100);
}
