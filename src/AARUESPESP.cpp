// ============================================================
//  AARUESP ESP Companion Implementation
//  MADE BY AARUTO — ESP32 / ESP8266 specific functions
// ============================================================
#include "AARUESPESP.h"

#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  #include <esp_sleep.h>
  #include <esp_chip_info.h>
#endif
#if AARUESP_ESP_HAS_WIFI
  #include <WiFi.h>
#endif
#if defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
  #include <ESP8266WiFi.h>
#endif

// Hall effect sensor exists ONLY on the original ESP32 (not on S2/S3/C3/C6/H2)
#if defined(CONFIG_IDF_TARGET_ESP32) && __has_include(<driver/hall_sensor.h>)
  #include <driver/hall_sensor.h>
  #define AARUESP_ESP_HAS_HALL 1
#else
  #define AARUESP_ESP_HAS_HALL 0
#endif

// Touch pins exist on ESP32 / ESP32-S2 / ESP32-S3 (not on RISC-V C3/C6/H2)
#if defined(CONFIG_IDF_TARGET_ESP32) || defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
  #define AARUESP_ESP_HAS_TOUCH 1
#else
  #define AARUESP_ESP_HAS_TOUCH 0
#endif

namespace aaruesp_esp {

// ---- WiFi ----
bool wifiBegin(const char* ssid, const char* password, uint32_t timeout_ms) {
#if AARUESP_ESP_HAS_WIFI
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - start) < timeout_ms) {
    delay(200);
  }
  return WiFi.status() == WL_CONNECTED;
#else
  (void)ssid; (void)password; (void)timeout_ms;
  return false;
#endif
}

bool isWiFiConnected() {
#if AARUESP_ESP_HAS_WIFI
  return WiFi.status() == WL_CONNECTED;
#else
  return false;
#endif
}

int wifiRssi() {
#if AARUESP_ESP_HAS_WIFI
  return (WiFi.status() == WL_CONNECTED) ? WiFi.RSSI() : 0;
#else
  return 0;
#endif
}

String localIP() {
#if AARUESP_ESP_HAS_WIFI
  return (WiFi.status() == WL_CONNECTED) ? WiFi.localIP().toString() : String("");
#else
  return String("");
#endif
}

String macAddress() {
#if AARUESP_ESP_HAS_WIFI
  return WiFi.macAddress();
#else
  return String("");
#endif
}

int wifiScanCount(int timeout_ms) {
#if AARUESP_ESP_HAS_WIFI
  return WiFi.scanNetworks(false, false, 0, (uint32_t)timeout_ms);
#else
  (void)timeout_ms;
  return -1;
#endif
}

String wifiScanSSID(int index) {
#if AARUESP_ESP_HAS_WIFI
  if (index < 0) return String("");
  int n = WiFi.scanComplete();
  if (index >= n) return String("");
  return WiFi.SSID((uint8_t)index);
#else
  (void)index;
  return String("");
#endif
}

// ---- Power / deep sleep ----
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
void deepSleep(uint64_t us) {
  esp_sleep_enable_timer_wakeup(us);
  esp_deep_sleep_start();
}

const char* wakeReason() {
  switch (esp_sleep_get_wakeup_cause()) {
    case ESP_SLEEP_WAKEUP_EXT0: return "ext0";
    case ESP_SLEEP_WAKEUP_EXT1: return "ext1";
    case ESP_SLEEP_WAKEUP_TIMER: return "timer";
    case ESP_SLEEP_WAKEUP_TOUCHPAD: return "touch";
    case ESP_SLEEP_WAKEUP_ULP: return "ulp";
    default: return "unknown";
  }
}

uint32_t setCpuFrequencyMhz(uint32_t mhz) {
  return (uint32_t)::setCpuFrequencyMhz((int)mhz);
}

uint32_t cpuFrequencyMhz() {
  return (uint32_t)::getCpuFrequencyMhz();
}
#elif defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
void deepSleep(uint32_t us) {
  ESP.deepSleep(us);
}

const char* wakeReason() {
  return ESP.getResetReason().c_str();
}

uint32_t setCpuFrequencyMhz(uint32_t mhz) {
  // ESP8266 supports 80 or 160 MHz only
  ::setCpuFrequencyMhz((mhz <= 80) ? 80 : 160);
  return (uint32_t)::getCpuFrequencyMhz();
}

uint32_t cpuFrequencyMhz() {
  return (uint32_t)::getCpuFrequencyMhz();
}
#endif

// ---- Chip info ----
uint32_t chipId() {
#if defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
  return (uint32_t)ESP.getChipId();
#elif defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  uint64_t mac = ESP.getEfuseMac();
  return (uint32_t)(mac & 0xFFFFFFFFUL);
#else
  return 0;
#endif
}

const char* chipModel() {
#if defined(CONFIG_IDF_TARGET_ESP32S3)
  return "ESP32-S3";
#elif defined(CONFIG_IDF_TARGET_ESP32S2)
  return "ESP32-S2";
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
  return "ESP32-C3";
#elif defined(CONFIG_IDF_TARGET_ESP32C6)
  return "ESP32-C6";
#elif defined(CONFIG_IDF_TARGET_ESP32H2)
  return "ESP32-H2";
#elif defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
  return "ESP8266EX";
#else
  return "ESP32";
#endif
}

uint32_t freeHeap() {
  return (uint32_t)ESP.getFreeHeap();
}

uint32_t flashSize() {
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  return (uint32_t)ESP.getFlashChipSize();
#else
  // ESP8266: flash size not exposed uniformly; report typical 4MB
  return 4194304UL;
#endif
}

uint32_t psramSize() {
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  return (uint32_t)ESP.getPsramSize();
#else
  return 0;
#endif
}

// ---- Restart ----
void restart() {
  ESP.restart();
}

// ---- ESP32-only extras ----
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
int hall() {
#if AARUESP_ESP_HAS_HALL
  return (int)hall_sensor_read();
#else
  return 0; // Hall sensor does not exist on S2/S3/C3/C6/H2
#endif
}

uint16_t touch(uint8_t pin) {
#if AARUESP_ESP_HAS_TOUCH
  return (uint16_t)::touchRead(pin);
#else
  (void)pin;
  return 0;
#endif
}

void dac(uint8_t pin, uint8_t val) {
#if defined(CONFIG_IDF_TARGET_ESP32)
  ::dacWrite(pin, val);
#else
  (void)pin; (void)val; // DAC removed on S2/S3/C3/C6
#endif
}
#endif

} // namespace aaruesp_esp