/*
  Config_Manager — AARUESP V2.2 example
  Demonstrates ConfigManager for persistent configuration.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

ConfigManager config("/config.txt");

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Config Manager Example — V2.2"));

  config.init();

  // Set some config values
  config.setString("wifi_ssid", "MyNetwork");
  config.setString("wifi_pass", "MyPassword");
  config.setInt("sample_rate", 1000);
  config.setFloat("threshold", 25.5);
  config.setBool("debug", true);
  config.save();

  // Read them back
  Serial.print(F("SSID: "));
  Serial.println(config.getString("wifi_ssid", "none"));
  Serial.print(F("Sample rate: "));
  Serial.println(config.getInt("sample_rate", 0));
  Serial.print(F("Threshold: "));
  Serial.println(config.getFloat("threshold", 0));
  Serial.print(F("Debug: "));
  Serial.println(config.getBool("debug", false) ? "true" : "false");
  Serial.print(F("Config exists: "));
  Serial.println(config.exists() ? "YES" : "NO");
}

void loop() {
  delay(1000);
}