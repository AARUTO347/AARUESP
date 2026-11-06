// ============================================================
//  AARUESP DS3231 Driver
//  MADE BY AARUTO
// ============================================================
#include "AaruDS3231.h"

AaruespError AaruDS3231::begin(uint8_t addr) {
    return begin(nullptr, addr);
}
AaruespError AaruDS3231::begin(AaruI2CEngine* i2c, uint8_t addr) {
    _addr = addr; _i2c = i2c; _configured = true; _err = AARUESP_OK;
    return _err;
}

AaruespError AaruDS3231::setDateTime(const AaruDateTime& dt) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::getDateTime(AaruDateTime& dt) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::setUnixTime(uint32_t epoch) { _err = AARUESP_OK; return _err; }
uint32_t AaruDS3231::getUnixTime() { return 0; }

float AaruDS3231::readTempC() { return NAN; }

AaruespError AaruDS3231::setAlarm1(uint8_t sec, uint8_t min, uint8_t hour, uint8_t day, bool match_dow) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::setAlarm2(uint8_t min, uint8_t hour, uint8_t day, bool match_dow) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::clearAlarm(uint8_t alarm_num) {
    _err = AARUESP_OK; return _err;
}
bool AaruDS3231::alarmTriggered(uint8_t alarm_num) { return false; }
AaruespError AaruDS3231::setSquareWave(uint8_t freq) {
    _err = AARUESP_OK; return _err;
}

AaruespError AaruDS3231::setAgingOffset(int8_t offset) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::writeSRAM(uint8_t offset, const uint8_t* data, uint8_t len) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruDS3231::readSRAM(uint8_t offset, uint8_t* data, uint8_t len) {
    _err = AARUESP_OK; return _err;
}

bool AaruDS3231::isConfigured() const { return _configured; }
AaruespError AaruDS3231::lastError() const { return _err; }
const char* AaruDS3231::errorString() const { return aaruespErrorString(_err); }

AaruespError AaruDS3231::writeReg(uint8_t reg, uint8_t val) {
    if (!_i2c) { _err = AARUESP_NOT_INITIALIZED; return _err; }
    return _i2c->write8(_addr, reg, val);
}
AaruespError AaruDS3231::readReg(uint8_t reg, uint8_t* val) {
    if (!_i2c) { _err = AARUESP_NOT_INITIALIZED; return _err; }
    return _i2c->read8(_addr, reg, val);
}
AaruespError AaruDS3231::readRegs(uint8_t reg, uint8_t* buf, uint8_t len) {
    if (!_i2c) { _err = AARUESP_NOT_INITIALIZED; return _err; }
    return _i2c->readBytes(_addr, reg, buf, len);
}
