// ============================================================
//  AARUESP TM1637 Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_TM1637_H
#define AARUESP_TM1637_H

#include "AARUESPTypes.h"
#include "AARUESPBoard.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define TM1637_CMD_DATA     0x40
#define TM1637_CMD_ADDR     0xC0
#define TM1637_CMD_DISP     0x80

class AaruTM1637 {
public:
    AaruTM1637() = default;

    AaruespError begin(uint8_t clk, uint8_t dio);
    void setBrightness(uint8_t brightness);
    void setColon(bool on);

    AaruespError display(uint8_t pos, uint8_t digit);
    AaruespError displayRaw(uint8_t pos, uint8_t segments);
    AaruespError clear();
    AaruespError printNumber(int num, bool leading_zeros);
    AaruespError printFloat(float num, uint8_t decimals);
    AaruespError printTime(uint8_t hour, uint8_t min, bool colon);

    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _clk, _dio;
    uint8_t _brightness;
    bool _colon;
    AaruespError _err;

    void start();
    void stop();
    bool writeByte(uint8_t b);
    void sendCommand(uint8_t cmd);
    static uint8_t encodeDigit(uint8_t d);
};

#endif // AARUESP_TM1637_H
