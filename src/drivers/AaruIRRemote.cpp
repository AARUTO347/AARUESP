// ============================================================
//  AARUESP IR Remote Driver
//  MADE BY AARUTO
// ============================================================
#include "AaruIRRemote.h"

AaruespError AaruIRRemote::begin(uint8_t recv_pin) {
    return begin(recv_pin, IR_PROTO_NEC);
}
AaruespError AaruIRRemote::begin(uint8_t recv_pin, IRProtocol proto) {
    _recv_pin = recv_pin; _proto = proto; _configured = true; _err = AARUESP_OK;
    return _err;
}

bool AaruIRRemote::decode(AaruIRResult* result) {
    result->protocol = IR_PROTO_UNKNOWN;
    result->value = 0;
    return false;
}
void AaruIRRemote::resume() {}
bool AaruIRRemote::waitDecode(AaruIRResult* result, unsigned long timeout_ms) {
    return false;
}

AaruespError AaruIRRemote::beginSend(uint8_t send_pin) {
    _send_pin = send_pin; _err = AARUESP_OK; return _err;
}
AaruespError AaruIRRemote::sendNEC(uint32_t data, uint8_t nbits) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruIRRemote::sendSony(uint32_t data, uint8_t nbits) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruIRRemote::sendRC5(uint16_t data, uint8_t nbits) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruIRRemote::sendRC6(uint32_t data, uint8_t nbits) {
    _err = AARUESP_OK; return _err;
}
AaruespError AaruIRRemote::sendRaw(const uint16_t* buf, uint16_t len, uint16_t freq_khz) {
    _err = AARUESP_OK; return _err;
}

bool AaruIRRemote::isConfigured() const { return _configured; }
AaruespError AaruIRRemote::lastError() const { return _err; }
const char* AaruIRRemote::errorString() const { return aaruespErrorString(_err); }

bool AaruIRRemote::decodeNEC(AaruIRResult* r) { return false; }
bool AaruIRRemote::decodeSony(AaruIRResult* r) { return false; }
bool AaruIRRemote::decodeRC5(AaruIRResult* r) { return false; }
bool AaruIRRemote::decodeRC6(AaruIRResult* r) { return false; }
void AaruIRRemote::sendMark(uint16_t us) {}
void AaruIRRemote::sendSpace(uint16_t us) {}
void AaruIRRemote::sendPulse(uint16_t mark, uint16_t space) {}
