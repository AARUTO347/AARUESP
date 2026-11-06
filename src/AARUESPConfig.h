// ============================================================
//  AARUESP Configuration
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_CONFIG_H
#define AARUESP_CONFIG_H

// ---- Feature opt-out macros (define before including AARUESP.h to save flash/RAM) ----
// #define AARUESP_NO_ANALOG
// #define AARUESP_NO_DIGITAL
// #define AARUESP_NO_I2C
// #define AARUESP_NO_SPI
// #define AARUESP_NO_UART
// #define AARUESP_NO_ONEWIRE
// #define AARUESP_NO_PWM
// #define AARUESP_NO_DISPLAYS
// #define AARUESP_NO_ACTUATORS
// #define AARUESP_NO_RADIO
// #define AARUESP_NO_STORAGE
// #define AARUESP_NO_SPECIAL

// ---- Timing defaults ----
#define AARUESP_DEFAULT_ULTRASONIC_TIMEOUT_US   30000UL
#define AARUESP_DEFAULT_I2C_TIMEOUT_MS          100
#define AARUESP_DEFAULT_SPI_SPEED_HZ            4000000UL
#define AARUESP_DEFAULT_UART_TIMEOUT_MS         1000
#define AARUESP_DEFAULT_ONEWIRE_TIMEOUT_US      250000UL
#define AARUESP_DEFAULT_PULSE_TIMEOUT_US        1000000UL

// ---- Debounce ----
#define AARUESP_DEFAULT_DEBOUNCE_MS             50

// ---- Analog engine ----
#define AARUESP_ANALOG_SAMPLES                  8
#define AARUESP_ANALOG_SETTLE_US                10

// ---- Display ----
#define AARUESP_DISPLAY_DEFAULT_I2C_ADDR        0x3C
#define AARUESP_LCD_DEFAULT_I2C_ADDR            0x27

// ---- DHT ----
#define AARUESP_DHT_MIN_INTERVAL_MS             2000

// ---- Debug ----
// #define AARUESP_DEBUG 1

#ifndef AARUESP_ASSERT
  #define AARUESP_ASSERT(cond) ((void)0)
#endif

#endif // AARUESP_CONFIG_H
