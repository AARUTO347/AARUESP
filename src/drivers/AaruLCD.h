// ============================================================
//  AARUESP HD44780 LCD Driver (I2C via PCF8574)
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_LCD_H
#define AARUESP_LCD_H

#include "AARUESPTypes.h"
#include "engines/AaruI2CEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define LCD_DEFAULT_ADDR 0x27
#define LCD_DEFAULT_ADDR2 0x3F

class AaruLCD {
public:
    AaruLCD() = default;

    AaruespError begin(uint8_t addr, uint8_t cols, uint8_t rows);
    AaruespError begin(class AaruI2CEngine* i2c, uint8_t addr, uint8_t cols, uint8_t rows);

    AaruespError clear();
    AaruespError home();
    AaruespError setCursor(uint8_t col, uint8_t row);
    AaruespError displayOn();
    AaruespError displayOff();
    AaruespError cursorOn();
    AaruespError cursorOff();
    AaruespError blinkOn();
    AaruespError blinkOff();
    AaruespError backlightOn();
    AaruespError backlightOff();
    AaruespError setBacklight(uint8_t val);

    AaruespError print(const char* str);
    AaruespError println(const char* str);
    AaruespError print(int n, int base);
    AaruespError print(float f, int digits);
    AaruespError write(uint8_t c);

    AaruespError createChar(uint8_t slot, const uint8_t pattern[8]);
    AaruespError writeChar(uint8_t slot);

    AaruespError scrollLeft();
    AaruespError scrollRight();
    AaruespError autoScroll(bool on);
    AaruespError leftToRight();
    AaruespError rightToLeft();

    uint8_t cols() const;
    uint8_t rows() const;
    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _addr;
    uint8_t _cols, _rows;
    uint8_t _backlight_val;
    class AaruI2CEngine* _i2c;
    bool _own_i2c;
    AaruespError _err;

    enum {
        LCD_CLEAR = 0x01,
        LCD_HOME = 0x02,
        LCD_ENTRY_MODE = 0x04,
        LCD_DISPLAY_CTRL = 0x08,
        LCD_CURSOR_SHIFT = 0x10,
        LCD_FUNCTION_SET = 0x20,
        LCD_SET_CGRAM = 0x40,
        LCD_SET_DDRAM = 0x80,
    };

    AaruespError send(uint8_t val, bool rs);
    AaruespError write4bits(uint8_t val, bool rs);
    AaruespError expanderWrite(uint8_t val);
    void pulseEnable(uint8_t val);
};

#endif // AARUESP_LCD_H
