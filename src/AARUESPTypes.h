// ============================================================
//  AARUESP Types — ESP-Only Board Families & Error Codes
//  MADE BY AARUTO
//  1000+ modules, one API. ESP32 family + ESP8266.
// ============================================================
#ifndef AARUESP_TYPES_H
#define AARUESP_TYPES_H

#include <stdint.h>

// ---- Version ----
#define AARUESP_VERSION_MAJOR 1
#define AARUESP_VERSION_MINOR 0
#define AARUESP_VERSION_PATCH 0
#define AARUESP_VERSION_STRING "1.0.0"

// ---- Board family enum (ESP ONLY) ----
// Values kept stable with AARUARDUINO where possible.
typedef enum {
    AARUESP_FAMILY_UNKNOWN       = 0,
    // (reserved 1..9 for AARUARDUINO compatibility)
    AARUESP_FAMILY_ESP32         = 10,
    AARUESP_FAMILY_ESP8266       = 11,
    AARUESP_FAMILY_ESP32S2       = 12,
    AARUESP_FAMILY_ESP32S3       = 13,
    AARUESP_FAMILY_ESP32C3       = 14,
    AARUESP_FAMILY_ESP32C6       = 15,
    AARUESP_FAMILY_ESP32H2       = 16
} AaruespFamily;

// ---- Error codes ----
typedef enum {
    AARUESP_OK               = 0,
    AARUESP_ERROR            = 1,
    AARUESP_INVALID_PIN      = 2,
    AARUESP_INVALID_CONFIG   = 3,
    AARUESP_TIMEOUT          = 4,
    AARUESP_READ_FAIL        = 5,
    AARUESP_WRITE_FAIL       = 6,
    AARUESP_UNSUPPORTED      = 7,
    AARUESP_MISSING_DEP      = 8,
    AARUESP_INIT_FAIL        = 9,
    AARUESP_NOT_INITIALIZED  = 10,
    AARUESP_BUSY             = 11,
    AARUESP_BUFFER_OVERFLOW  = 12,
    AARUESP_CRC_ERROR        = 13,
    AARUESP_NOT_FOUND        = 14
} AaruespError;

// ---- Module categories ----
typedef enum {
    AARUESP_CAT_ANALOG      = 1,
    AARUESP_CAT_DIGITAL     = 2,
    AARUESP_CAT_I2C         = 3,
    AARUESP_CAT_SPI         = 4,
    AARUESP_CAT_UART        = 5,
    AARUESP_CAT_ONEWIRE     = 6,
    AARUESP_CAT_PWM         = 7,
    AARUESP_CAT_DISPLAY     = 8,
    AARUESP_CAT_ACTUATOR    = 9,
    AARUESP_CAT_RADIO       = 10,
    AARUESP_CAT_STORAGE     = 11,
    AARUESP_CAT_SPECIAL     = 12
} AaruespCategory;

// ---- Module status ----
typedef enum {
    AARUESP_MOD_IMPLEMENTED   = 1,
    AARUESP_MOD_STUB          = 2,
    AARUESP_MOD_PLANNED       = 3
} AaruespModuleStatus;

// ---- Board database entry (ESP ONLY) ----
typedef enum {
    AARUESP_BOARD_FAMILY_ESP32    = 0,
    AARUESP_BOARD_FAMILY_ESP32S2  = 1,
    AARUESP_BOARD_FAMILY_ESP32S3  = 2,
    AARUESP_BOARD_FAMILY_ESP32C3  = 3,
    AARUESP_BOARD_FAMILY_ESP32C6  = 4,
    AARUESP_BOARD_FAMILY_ESP32H2  = 5,
    AARUESP_BOARD_FAMILY_ESP8266  = 6
} AaruespBoardFamily;

typedef struct {
    const char* name;
    uint8_t family;         // AaruespBoardFamily
    uint8_t gpio_count;
    uint32_t flash_bytes;
    float v_min;
    float v_max;
    float current_ma;
    const char* upload_port;
} AaruespBoardInfo;

// ---- Forward decl for singleton ----
class AaruespClass;

#endif // AARUESP_TYPES_H