// ============================================================
//  AARUESP GPS Driver
//  MADE BY AARUTO
// ============================================================
#include "AaruGPS.h"

AaruespError AaruGPS::begin(AaruUARTEngine* uart) {
    _uart = uart; _configured = true; _err = AARUESP_OK;
    return _err;
}
AaruespError AaruGPS::begin(int rx, int tx, uint32_t baud) {
    _configured = true; _err = AARUESP_OK;
    return _err;
}

void AaruGPS::update() {}

const AaruGPSSatellite* AaruGPS::sat(int idx) const {
    if (idx < _sat_count) return &_sats[idx];
    return nullptr;
}

void AaruGPS::onGGA(void (*cb)(const AaruGPSFix&)) { _cb_gga = cb; }
void AaruGPS::onRMC(void (*cb)(const AaruGPSFix&)) { _cb_rmc = cb; }
void AaruGPS::onGSV(void (*cb)(const AaruGPSSatellite*, int)) { _cb_gsv = cb; }
void AaruGPS::onRaw(void (*cb)(const char*)) { _cb_raw = cb; }

AaruespError AaruGPS::setRateHz(uint8_t hz) { _err = AARUESP_OK; return _err; }
AaruespError AaruGPS::setBaud(uint32_t baud) { _err = AARUESP_OK; return _err; }
AaruespError AaruGPS::enableNMEA(uint8_t mask) { _err = AARUESP_OK; return _err; }
AaruespError AaruGPS::sleep() { _err = AARUESP_OK; return _err; }
AaruespError AaruGPS::wake() { _err = AARUESP_OK; return _err; }

bool AaruGPS::isConfigured() const { return _configured; }
AaruespError AaruGPS::lastError() const { return _err; }
const char* AaruGPS::errorString() const { return aaruespErrorString(_err); }

void AaruGPS::parseSentence(const char* sentence) {}
bool AaruGPS::parseGGA(const char* s) { return false; }
bool AaruGPS::parseRMC(const char* s) { return false; }
bool AaruGPS::parseGSV(const char* s) { return false; }
bool AaruGPS::parseVTG(const char* s) { return false; }
uint8_t AaruGPS::nmeaChecksum(const char* s) { return 0; }
