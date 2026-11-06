// ============================================================
//  AARUESP Pulse Engine
//  MADE BY AARUTO
// ============================================================
#include "AaruPulseEngine.h"

unsigned long AaruPulseEngine::pulseIn(uint8_t pin, uint8_t state, unsigned long timeout_us) {
#if defined(ARDUINO)
    return ::pulseIn(pin, state, timeout_us);
#else
    return 0;
#endif
}

unsigned long AaruPulseEngine::pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout_us) {
#if defined(ARDUINO)
    return ::pulseIn(pin, state, timeout_us);
#else
    return 0;
#endif
}

AaruespError AaruPulseEngine::beginFreqCount(uint8_t pin, unsigned long sample_ms) {
    _err = AARUESP_OK; return _err;
}
float AaruPulseEngine::readFrequencyHz() { return 0; }
void AaruPulseEngine::endFreqCount() {}

AaruespError AaruPulseEngine::beginPulseCount(uint8_t pin, bool active_high, uint16_t debounce_us) {
    _err = AARUESP_OK; return _err;
}
unsigned long AaruPulseEngine::pulseCount() { return _pulse_count; }
void AaruPulseEngine::resetPulseCount() { _pulse_count = 0; }
float AaruPulseEngine::readRateHz() { return 0; }
float AaruPulseEngine::readFlowRateLmin(float pulses_per_litre) { return 0; }

AaruespError AaruPulseEngine::beginEncoder(uint8_t clk, uint8_t dt, int sw_pin) {
    _enc_clk = clk; _enc_dt = dt; _enc_sw = (uint8_t)sw_pin; _err = AARUESP_OK;
#if defined(ARDUINO)
    pinMode(clk, INPUT);
    pinMode(dt, INPUT);
    if (sw_pin >= 0) pinMode(sw_pin, INPUT_PULLUP);
#endif
    return _err;
}
long AaruPulseEngine::encoderCount() { return _enc_count; }
void AaruPulseEngine::encoderReset() { _enc_count = 0; }
int8_t AaruPulseEngine::encoderDirection() { return _enc_dir; }
bool AaruPulseEngine::encoderButton() { return false; }

AaruespError AaruPulseEngine::beginPwmIn(uint8_t pin) { _err = AARUESP_OK; return _err; }
float AaruPulseEngine::readPwmDutyCycle() { return 0; }
float AaruPulseEngine::readPwmFrequencyHz() { return 0; }
void AaruPulseEngine::endPwmIn() {}
