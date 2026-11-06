// ============================================================
//  AARUESP BH1750 Driver
//  MADE BY AARUTO
// ============================================================
#include "AaruBH1750.h"

AaruespError AaruBH1750::begin(uint8_t addr) {
    return begin(nullptr, addr);
}
AaruespError AaruBH1750::begin(AaruI2CEngine* i2c, uint8_t addr) {
    _addr = addr; _i2c = i2c; _configured = true; _err = AARUESP_OK;
    return _err;
}

bool AaruBH1750::read(float& lux) {
    _err = AARUESP_OK;
    lux = 0;
    return false;
}
float AaruBH1750::readLux() {
    _err = AARUESP_OK;
    return NAN;
}

AaruespError AaruBH1750::setMode(BH1750Mode mode) {
    _mode = mode; _err = AARUESP_OK; return _err;
}
AaruespError AaruBH1750::setMTreg(uint8_t mtreg) {
    _err = AARUESP_OK; return _err;
}

AaruespError AaruBH1750::powerOn() { _err = AARUESP_OK; return _err; }
AaruespError AaruBH1750::powerOff() { _err = AARUESP_OK; return _err; }
AaruespError AaruBH1750::reset() { _err = AARUESP_OK; return _err; }

bool AaruBH1750::isConfigured() const { return _configured; }
AaruespError AaruBH1750::lastError() const { return _err; }
const char* AaruBH1750::errorString() const { return aaruespErrorString(_err); }

AaruespError AaruBH1750::writeCmd(uint8_t cmd) {
    if (!_i2c) { _err = AARUESP_NOT_INITIALIZED; return _err; }
    return _i2c->write8(_addr, cmd, 0);
}
