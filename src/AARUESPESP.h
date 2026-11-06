// ============================================================
//  AARUESP ESP Companion — ESP32 / ESP8266 Specific Superpowers
//  MADE BY AARUTO
//
//  AARUESP (= AARUARDUINO's ESP twin) covers 1000+ universal modules;
//  this header exposes the things ONLY an ESP can do:
//  WiFi, deep sleep, chip info, DAC, touch pins, power management.
//
//  Use it alongside AARUESP.h:
//      #include <AARUESP.h>
//      AARUESP.begin();
//      #include <AARUESPESP.h>
//      aaruesp_esp::wifiBegin("SSID", "pass");
// ============================================================
#ifndef AARUESP_ESP_H
#define AARUESP_ESP_H

#if !defined(ESP32) && !defined(ESP8266) && !defined(ARDUINO_ARCH_ESP32) && !defined(ARDUINO_ARCH_ESP8266)
  #warning "AARUESPESP.h is for ESP32/ESP8266 only. Every function is a no-op/stub on other CPUs."
#endif

#include <Arduino.h>
#include <stdint.h>
#include <string.h>

// ---- WiFi ----
#if defined(ESP32) || defined(ESP8266) || defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_ESP8266)
  #if __has_include(<WiFi.h>)
    #define AARUESP_ESP_HAS_WIFI 1
  #else
    #define AARUESP_ESP_HAS_WIFI 0
  #endif
#else
  #define AARUESP_ESP_HAS_WIFI 0
#endif

namespace aaruesp_esp {

/** Connect to a WiFi network (STA mode). Returns true if connected within timeout. */
bool wifiBegin(const char* ssid, const char* password, uint32_t timeout_ms = 20000);

/** True if WiFi is connected right now */
bool isWiFiConnected();

/** RSSI of the connected network (dBm), negative number when connected, 0 otherwise */
int wifiRssi();

/** Local IP address as String, "" when not connected */
String localIP();

/** MAC address of the WiFi interface */
String macAddress();

/** Number of visible networks around (simple scan), -1 if failed */
int wifiScanCount(int timeout_ms = 10000);

/** Names of scanned networks (index 0 .. wifiScanCount-1), "" if out of range */
String wifiScanSSID(int index);

// ---- Power / deep sleep ----
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  /** Enter deep sleep for `us` micro-seconds (~0 mA). Never returns. */
  void deepSleep(uint64_t us);

  /** Cause string of the last wake: "unknown","ext0","ext1","timer","touch","uart","ulp","gpio" */
  const char* wakeReason();

  /** Set CPU clock in MHz (works for 80/160/240). Returns resulting clock. */
  uint32_t setCpuFrequencyMhz(uint32_t mhz);

  /** Current CPU clock in MHz */
  uint32_t cpuFrequencyMhz();
#elif defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
  /** Enter deep sleep for `us` microseconds (GPIO16 to RST required). Never returns. */
  void deepSleep(uint32_t us);

  /** Cause of wake: "DEEP_SLEEP_WAKE_RF_CAL","DEEP_SLEEP_WAKE_NO_INIT","DEEP_SLEEP_WAKE_MAX" */
  const char* wakeReason();

  /** Set/Get CPU clock in MHz (80 or 160) */
  uint32_t setCpuFrequencyMhz(uint32_t mhz);
  uint32_t cpuFrequencyMhz();
#else
  inline void deepSleep(uint64_t) {}
  inline const char* wakeReason() { return "unknown"; }
  inline uint32_t setCpuFrequencyMhz(uint32_t) { return 0; }
  inline uint32_t cpuFrequencyMhz() { return 0; }
#endif

// ---- Chip info ----
/** Unique chip ID as hex string (ESP32: MAC-based, ESP8266: chip id) */
uint32_t chipId();

/** Chip model string, e.g. "ESP32","ESP32-S3","ESP32-C3","ESP8266EX" */
const char* chipModel();

/** Free heap in bytes */
uint32_t freeHeap();

/** Total flash size in bytes */
uint32_t flashSize();

/** Total PSRAM in bytes (0 if none) */
uint32_t psramSize();

// ---- Restart ----
/** Restart the ESP */
void restart();

// ---- ESP32-only extras ----
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  /** Read hall sensor (sensor present in ESP32; removed on ESP32-S2/S3/C3) */
  int hall();

  /** Read a touch pin (GPIO 0,2,4,12..15,27,32,33 on ESP32) */
  uint16_t touch(uint8_t pin);

  /** Write 8-bit value to the DAC on GPIO 25/26 (ESP32; removed on variants) */
  void dac(uint8_t pin, uint8_t val);
#else
  inline int hall() { return 0; }
  inline uint16_t touch(uint8_t) { return 0; }
  inline void dac(uint8_t, uint8_t) {}
#endif

} // namespace aaruesp_esp

#endif // AARUESP_ESP_H