// ============================================================
//  AARUESP MAX7219 Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_MAX7219_H
#define AARUESP_MAX7219_H

#include "AARUESPTypes.h"
#include "engines/AaruSPIEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define MAX7219_NOOP        0x00
#define MAX7219_DIGIT0      0x01
#define MAX7219_DIGIT1      0x02
#define MAX7219_DIGIT2      0x03
#define MAX7219_DIGIT3      0x04
#define MAX7219_DIGIT4      0x05
#define MAX7219_DIGIT5      0x06
#define MAX7219_DIGIT6      0x07
#define MAX7219_DIGIT7      0x08
#define MAX7219_DECODEMODE  0x09
#define MAX7219_INTENSITY   0x0A
#define MAX7219_SCANLIMIT   0x0B
#define MAX7219_SHUTDOWN    0x0C
#define MAX7219_DISPLAYTEST 0x0F

class AaruMAX7219 {
public:
    AaruMAX7219() = default;

    AaruespError begin(uint8_t cs_pin, uint8_t num_devices);
    AaruespError begin(class AaruSPIEngine* spi, uint8_t cs_pin, uint8_t num_devices);

    AaruespError shutdown(bool off);
    AaruespError setIntensity(uint8_t intensity);
    AaruespError setScanLimit(uint8_t limit);
    AaruespError setDecodeMode(uint8_t mode);

    AaruespError setDigit(uint8_t device, uint8_t digit, uint8_t value, bool dp);
    AaruespError setDigits(uint8_t device, const uint8_t* values, uint8_t count, bool dp);
    AaruespError printNumber(uint8_t device, long num, bool leading_zeros);
    AaruespError printFloat(uint8_t device, float num, uint8_t decimals);
    AaruespError clear(uint8_t device);

    AaruespError setLed(uint8_t device, uint8_t row, uint8_t col, bool on);
    AaruespError setRow(uint8_t device, uint8_t row, uint8_t val);
    AaruespError setColumn(uint8_t device, uint8_t col, uint8_t val);
    AaruespError setMatrix(uint8_t device, const uint8_t* rows);

    uint8_t numDevices() const;
    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _cs;
    uint8_t _num_devices;
    class AaruSPIEngine* _spi;
    bool _own_spi;
    AaruespError _err;

    AaruespError write(uint8_t device, uint8_t reg, uint8_t data);
};

#endif // AARUESP_MAX7219_H
