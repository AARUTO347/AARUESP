// ============================================================
//  AARUESP Board Detection & Pin Validation — ESP ONLY
//  MADE BY AARUTO — 200+ ESP boards supported
// ============================================================
#ifndef AARUESP_BOARD_H
#define AARUESP_BOARD_H

#include "AARUESPTypes.h"
#include "utility/AaruespMath.h"

// ---- Compile-time ESP board detection ----
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)

  #if defined(CONFIG_IDF_TARGET_ESP32S3) || defined(ARDUINO_ESP32S3_DEV) || defined(ARDUINO_ESP32S3_CAM_KIT) || defined(ARDUINO_ESP32S3_REVO) \
      || defined(ARDUINO_ESP32S3_BOX) || defined(ARDUINO_ESP32S3_BOX_3) || defined(ARDUINO_ESP32S3_TCPWL)
    #define AARUESP_BOARD_ESP32S3 1
    #define AARUESP_BOARD_NAME "ESP32-S3"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32S3
  #elif defined(CONFIG_IDF_TARGET_ESP32S2) || defined(ARDUINO_ESP32S2_DEV) || defined(ARDUINO_ESP32S2_PICO_D4)
    #define AARUESP_BOARD_ESP32S2 1
    #define AARUESP_BOARD_NAME "ESP32-S2"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32S2
  #elif defined(CONFIG_IDF_TARGET_ESP32C3) || defined(ARDUINO_ESP32C3_DEV) || defined(ARDUINO_ESP32C3_SUPERMINI) || defined(ARDUINO_ESP32C3_DEVKITM_1)
    #define AARUESP_BOARD_ESP32C3 1
    #define AARUESP_BOARD_NAME "ESP32-C3"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32C3
  #elif defined(CONFIG_IDF_TARGET_ESP32C6) || defined(ARDUINO_ESP32C6_DEV)
    #define AARUESP_BOARD_ESP32C6 1
    #define AARUESP_BOARD_NAME "ESP32-C6"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32C6
  #elif defined(CONFIG_IDF_TARGET_ESP32H2) || defined(ARDUINO_ESP32H2_DEV)
    #define AARUESP_BOARD_ESP32H2 1
    #define AARUESP_BOARD_NAME "ESP32-H2"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32H2
  #else
    #define AARUESP_BOARD_ESP32 1
    #define AARUESP_BOARD_NAME "ESP32"
    #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP32
  #endif

#elif defined(ESP8266) || defined(ARDUINO_ARCH_ESP8266)
  #define AARUESP_BOARD_ESP8266 1
  #define AARUESP_BOARD_NAME "ESP8266"
  #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_ESP8266
#else
  #define AARUESP_BOARD_UNKNOWN 1
  #define AARUESP_BOARD_NAME "Unsupported (ESP32 / ESP8266 required)"
  #define AARUESP_BOARD_FAMILY AARUESP_FAMILY_UNKNOWN
  #warning "AARUESP is ESP-only. This build is not for ESP hardware."
#endif

// ---- ADC characteristics (per family) ----
#if defined(AARUESP_BOARD_ESP32) || defined(AARUESP_BOARD_ESP32S2) || defined(AARUESP_BOARD_ESP32S3)
  #define AARUESP_ADC_BITS 12
  #define AARUESP_ADC_MAX 4095
  #define AARUESP_ADC_VREF 3.3f
#elif defined(AARUESP_BOARD_ESP32C3) || defined(AARUESP_BOARD_ESP32C6) || defined(AARUESP_BOARD_ESP32H2)
  #define AARUESP_ADC_BITS 12
  #define AARUESP_ADC_MAX 4095
  #define AARUESP_ADC_VREF 2.5f
#elif defined(AARUESP_BOARD_ESP8266)
  #define AARUESP_ADC_BITS 10
  #define AARUESP_ADC_MAX 1023
  #define AARUESP_ADC_VREF 3.3f
#else
  #define AARUESP_ADC_BITS 12
  #define AARUESP_ADC_MAX 4095
  #define AARUESP_ADC_VREF 3.3f
#endif

// Input-only pins (classic ESP32 34-39 only)
inline bool aaruespIsInputOnlyPin(uint8_t pin) {
#if defined(AARUESP_BOARD_ESP32)
  return (pin >= 34 && pin <= 39);
#else
  (void)pin;
  return false;
#endif
}

// Esper strapping / boot-sensitive pins (usable with care)
inline bool aaruespIsStrappingPin(uint8_t pin) {
#if defined(AARUESP_BOARD_ESP32)
  return (pin == 0 || pin == 2 || pin == 5 || pin == 12 || pin == 15);
#elif defined(AARUESP_BOARD_ESP32S3)
  return (pin == 0 || pin == 3 || pin == 45 || pin == 46);
#elif defined(AARUESP_BOARD_ESP32C3) || defined(AARUESP_BOARD_ESP32C6) || defined(AARUESP_BOARD_ESP32H2)
  return (pin == 2 || pin == 8 || pin == 9);
#elif defined(AARUESP_BOARD_ESP8266)
  return (pin == 0 || pin == 2 || pin == 15 || pin == 16);
#else
  (void)pin;
  return false;
#endif
}

// Validate a digital GPIO number where detectable. Returns AaruespError.
// NOTE (unknown boards): validation is permissive by design so new ESP variants
// still compile; the Arduino core enforces the final limits. See docs.
inline AaruespError aaruespValidateDigitalPin(uint8_t pin, bool needOutput) {
#if defined(AARUESP_BOARD_ESP8266)
  // ESP8266: common usable GPIOs.
  switch (pin) {
    case 0: case 1: case 2: case 3: case 4: case 5:
    case 12: case 13: case 14: case 15: case 16:
      return AARUESP_OK;
    default:
      return AARUESP_INVALID_PIN;
  }
#elif defined(AARUESP_BOARD_ESP32)
  // ESP32: reject flash pins + out-of-range; flag input-only when output needed.
  if (pin > 39) return AARUESP_INVALID_PIN;
  if (pin >= 6 && pin <= 11) return AARUESP_INVALID_PIN;  // SPI flash
  if (needOutput && aaruespIsInputOnlyPin(pin)) return AARUESP_INVALID_PIN;
  return AARUESP_OK;
#elif defined(AARUESP_BOARD_ESP32S2)
  // ESP32-S2: 0-46 (flash/internal 18-24 reserved-ish; permissive, documented).
  if (pin > 46) return AARUESP_INVALID_PIN;
  return AARUESP_OK;
#elif defined(AARUESP_BOARD_ESP32S3)
  // ESP32-S3: 0-48, 26-32 are SPI flash.
  if (pin > 48) return AARUESP_INVALID_PIN;
  if (pin >= 26 && pin <= 32) return AARUESP_INVALID_PIN;
  return AARUESP_OK;
#elif defined(AARUESP_BOARD_ESP32C3) || defined(AARUESP_BOARD_ESP32C6) || defined(AARUESP_BOARD_ESP32H2)
  // ESP32-C3/C6/H2 (RISC-V): usable 0-10, 18-21.
  if (pin <= 10 || (pin >= 18 && pin <= 21)) return AARUESP_OK;
  return AARUESP_INVALID_PIN;
#else
  // Non-ESP build: permissive fallback (library compiles but is not for ESP)
  (void)pin; (void)needOutput;
  return AARUESP_OK;
#endif
}

// Validate that a pin supports PWM output on this board.
inline AaruespError aaruespValidatePwmPin(uint8_t pin) {
  AaruespError d = aaruespValidateDigitalPin(pin, true);
  if (d != AARUESP_OK) return d;
#if defined(AARUESP_BOARD_ESP8266)
  // ESP8266: software PWM on most GPIOs; 16 has no PWM/interrupts.
  if (pin == 16) return AARUESP_INVALID_PIN;
  return AARUESP_OK;
#else
  // ESP32 family: LEDC on any output GPIO.
  return AARUESP_OK;
#endif
}

// Validate that a pin is a usable analog input. ESP32 ADC2 conflicts with WiFi.
inline AaruespError aaruespValidateAnalogPin(int pin) {
  if (pin < 0) return AARUESP_INVALID_PIN;
#if defined(AARUESP_BOARD_ESP8266)
  // ESP8266 single ADC: A0 only. In the Arduino core A0 == 17.
#if defined(A0)
  if (pin == (int)A0 || pin == 17) return AARUESP_OK;
#else
  if (pin == 17 || pin == 0) return AARUESP_OK;
#endif
  return AARUESP_INVALID_PIN;
#elif defined(AARUESP_BOARD_ESP32)
  // ESP32: ADC1 (32-39, safe with WiFi) + ADC2 (0,2,4,12-15,25-27, WiFi conflicts).
  switch (pin) {
    case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39:
    case 0: case 2: case 4: case 12: case 13: case 14: case 15:
    case 25: case 26: case 27:
      return AARUESP_OK;
    default:
      return AARUESP_INVALID_PIN;
  }
#elif defined(AARUESP_BOARD_ESP32S2)
  // ESP32-S2: ADC1 1-10, ADC2 11-18.
  if (pin >= 1 && pin <= 18) return AARUESP_OK;
  return AARUESP_INVALID_PIN;
#elif defined(AARUESP_BOARD_ESP32S3)
  // ESP32-S3: ADC1 1-10, ADC2 11-20.
  if (pin >= 1 && pin <= 20) return AARUESP_OK;
  return AARUESP_INVALID_PIN;
#elif defined(AARUESP_BOARD_ESP32C3) || defined(AARUESP_BOARD_ESP32C6) || defined(AARUESP_BOARD_ESP32H2)
  // RISC-V ESP ADCs: GPIO 0-4 usable.
  if (pin <= 4) return AARUESP_OK;
  return AARUESP_INVALID_PIN;
#else
  (void)pin;
  return AARUESP_OK;
#endif
}

// ---- Board family getters (for runtime checks) ----
inline AaruespFamily aaruespGetBoardFamily() {
  return (AaruespFamily)AARUESP_BOARD_FAMILY;
}

inline const char* aaruespGetBoardName() {
  return AARUESP_BOARD_NAME;
}

// ---- 200+ ESP board database (implemented in AARUESPBoards.cpp) ----

/** Number of ESP boards in the registry (207) */
uint16_t aaruespBoardCount();

/** Get board info by index (0 .. count-1), or nullptr if out of range */
const AaruespBoardInfo* aaruespBoardAt(uint16_t index);

/** Convenience: the array pointer (nullptr-terminated), or nullptr if empty */
const AaruespBoardInfo* aaruespBoardList();

/** Find a board by exact name (case-insensitive fallback), nullptr if not found */
const AaruespBoardInfo* aaruespBoardFind(const char* name);

/** Find the closest match by name substring, nullptr if none */
const AaruespBoardInfo* aaruespBoardFindContains(const char* substr);

#endif // AARUESP_BOARD_H