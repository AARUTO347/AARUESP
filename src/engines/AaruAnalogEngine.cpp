// ============================================================
//  AARUESP Analog Engine
//  MADE BY AARUTO
// ============================================================
#include "AaruAnalogEngine.h"

AaruespError AaruAnalogEngine::begin(uint8_t pin, AaruAnalogKind kind) {
    _pin = pin; _kind = kind; _err = AARUESP_OK;
#if defined(ARDUINO)
    pinMode(pin, INPUT);
#endif
    return _err;
}

AaruespError AaruAnalogEngine::beginWithPreset(uint8_t pin, AaruAnalogKind kind,
                                                    float p1, float p2, float p3, float p4) {
    _pin = pin; _kind = kind; _p1 = p1; _p2 = p2; _p3 = p3; _p4 = p4; _err = AARUESP_OK;
#if defined(ARDUINO)
    pinMode(pin, INPUT);
#endif
    return _err;
}

int AaruAnalogEngine::readRaw() {
    if (_kind == AARU_AN_KIND_NONE) { _err = AARUESP_NOT_INITIALIZED; return -1; }
#if defined(ARDUINO)
    long sum = 0;
    for (uint8_t i = 0; i < _samples; i++) {
        sum += analogRead(_pin);
        delayMicroseconds(_settle_us);
    }
    _err = AARUESP_OK;
    return sum / _samples;
#else
    _err = AARUESP_UNSUPPORTED;
    return -1;
#endif
}

float AaruAnalogEngine::readPercent() {
    int raw = readRaw();
    if (_err != AARUESP_OK) return NAN;
    return aaruespPercent(raw, _adc_max);
}

float AaruAnalogEngine::readVoltage(float divider_ratio) {
    int raw = readRaw();
    if (_err != AARUESP_OK) return NAN;
    int mv = aaruespAdcToMv(raw, _adc_max, _vref, divider_ratio);
    if (mv < 0) { _err = AARUESP_READ_FAIL; return NAN; }
    return mv / 1000.0f;
}

float AaruAnalogEngine::readValue() {
    int raw = readRaw();
    if (_err != AARUESP_OK) return NAN;
    return convertRawToValue(raw);
}

int AaruAnalogEngine::readRawPin(uint8_t pin) {
#if defined(ARDUINO)
    return analogRead(pin);
#else
    return -1;
#endif
}

float AaruAnalogEngine::readVoltagePin(uint8_t pin, float divider_ratio) {
#if defined(ARDUINO)
    int raw = analogRead(pin);
    int mv = aaruespAdcToMv(raw, _adc_max, _vref, divider_ratio);
    return mv / 1000.0f;
#else
    return NAN;
#endif
}

float AaruAnalogEngine::convertRawToValue(int raw) {
    switch (_kind) {
        case AARU_AN_KIND_LM35: {
            int mv = aaruespAdcToMv(raw, _adc_max, _vref, _divider);
            return aaruespLm35C(mv);
        }
        case AARU_AN_KIND_TMP36: {
            int mv = aaruespAdcToMv(raw, _adc_max, _vref, _divider);
            return aaruespTmp36C(mv);
        }
        case AARU_AN_KIND_NTC_BETA:
            return aaruespNtcBetaC(raw, _adc_max, _p1, _p2, _p3, _p4);
        case AARU_AN_KIND_ACS712_5A:
        case AARU_AN_KIND_ACS712_20A:
        case AARU_AN_KIND_ACS712_30A:
            return aaruespAcs712A(
                aaruespAdcToMv(raw, _adc_max, _vref, _divider), _p1, _p2);
        case AARU_AN_KIND_MQ2:
        case AARU_AN_KIND_MQ3:
        case AARU_AN_KIND_MQ4:
        case AARU_AN_KIND_MQ5:
        case AARU_AN_KIND_MQ6:
        case AARU_AN_KIND_MQ7:
        case AARU_AN_KIND_MQ8:
        case AARU_AN_KIND_MQ9:
        case AARU_AN_KIND_MQ131:
        case AARU_AN_KIND_MQ135:
        case AARU_AN_KIND_MQ136:
        case AARU_AN_KIND_MQ137:
        case AARU_AN_KIND_MQ138:
        case AARU_AN_KIND_GENERIC_MQ: {
            float ratio = aaruespMqRatio(raw, _adc_max);
            return aaruespMqPpm(ratio, _p1, _p2, _p3);
        }
        default:
            return aaruespPercent(raw, _adc_max);
    }
}

const char* AaruAnalogEngine::kindName() const {
    switch (_kind) {
        case AARU_AN_KIND_LDR: return "LDR";
        case AARU_AN_KIND_LM35: return "LM35";
        case AARU_AN_KIND_TMP36: return "TMP36";
        case AARU_AN_KIND_NTC_BETA: return "NTC Thermistor (Beta)";
        case AARU_AN_KIND_MQ2: return "MQ-2";
        case AARU_AN_KIND_MQ135: return "MQ-135";
        default: return "Unknown";
    }
}

const char* AaruAnalogEngine::kindUnit() const {
    switch (_kind) {
        case AARU_AN_KIND_LDR: return "%";
        case AARU_AN_KIND_LM35: return "C";
        case AARU_AN_KIND_MQ2: return "ratio";
        default: return "";
    }
}

const char* AaruAnalogEngine::presetName(AaruAnalogKind kind) const { return ""; }
const char* AaruAnalogEngine::presetUnit(AaruAnalogKind kind) const { return ""; }
