// ============================================================
//  AARUESP LCD Driver
//  MADE BY AARUTO
// ============================================================
#include "AaruLCD.h"

AaruespError AaruLCD::begin(uint8_t addr, uint8_t cols, uint8_t rows) {
    return begin(nullptr, addr, cols, rows);
}
AaruespError AaruLCD::begin(AaruI2CEngine* i2c, uint8_t addr, uint8_t cols, uint8_t rows) {
    _addr = addr; _cols = cols; _rows = rows; _i2c = i2c;
    _configured = true; _err = AARUESP_OK;
    return _err;
}

AaruespError AaruLCD::clear() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::home() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::setCursor(uint8_t col, uint8_t row) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::displayOn() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::displayOff() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::cursorOn() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::cursorOff() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::blinkOn() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::blinkOff() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::backlightOn() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::backlightOff() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::setBacklight(uint8_t val) { _err = AARUESP_OK; return _err; }

AaruespError AaruLCD::print(const char* str) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::println(const char* str) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::print(int n, int base) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::print(float f, int digits) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::write(uint8_t c) { _err = AARUESP_OK; return _err; }

AaruespError AaruLCD::createChar(uint8_t slot, const uint8_t pattern[8]) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruLCD::writeChar(uint8_t slot) { _err = AARUESP_OK; return _err; }

AaruespError AaruLCD::scrollLeft() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::scrollRight() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::autoScroll(bool on) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::leftToRight() { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::rightToLeft() { _err = AARUESP_OK; return _err; }

uint8_t AaruLCD::cols() const { return _cols; }
uint8_t AaruLCD::rows() const { return _rows; }
bool AaruLCD::isConfigured() const { return _configured; }
AaruespError AaruLCD::lastError() const { return _err; }
const char* AaruLCD::errorString() const { return aaruespErrorString(_err); }

AaruespError AaruLCD::send(uint8_t val, bool rs) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::write4bits(uint8_t val, bool rs) { _err = AARUESP_OK; return _err; }
AaruespError AaruLCD::expanderWrite(uint8_t val) { _err = AARUESP_OK; return _err; }
void AaruLCD::pulseEnable(uint8_t val) {}
