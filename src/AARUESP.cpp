// ============================================================
//  AARUESP v1.0.0 — Universal Arduino Library
//  MADE BY AARUTO
// ============================================================
#include "AARUESP.h"

#if defined(ARDUINO)
#include <Arduino.h>
#endif

// ---- Construction ----
AaruespClass::AaruespClass() {}

// ---- Core ----
void AaruespClass::begin() {
    if (_begun) return;
    _i2c.begin();
    _pulse.beginFreqCount(2); // default freq count pin (non-blocking setup)
    _begun = true;
    _err = AARUESP_OK;
}

void AaruespClass::update() {
    // Non-blocking updates for drivers needing polling
    // IR remote, GPS, pulse counting handled in read/interrupt paths
}

void AaruespClass::dbg(const char* msg) {
    if (_dbg) _dbg->println(msg);
}

const char* AaruespClass::errorString() const {
    return aaruespErrorString(_err);
}

const char* AaruespClass::errorString(AaruespError e) {
    return aaruespErrorString(e);
}

AaruespFamily AaruespClass::boardFamily() const {
    return aaruespGetBoardFamily();
}

const char* AaruespClass::boardName() const {
    return aaruespGetBoardName();
}

// ---- Ultrasonic ----
AaruespError AaruespClass::ultrasonic(uint8_t trig_pin, uint8_t echo_pin) {
    AaruespError e = aaruespValidateDigitalPin(trig_pin, true);
    if (e != AARUESP_OK) return setErr(e);
    e = aaruespValidateDigitalPin(echo_pin, false);
    if (e != AARUESP_OK) return setErr(e);
    return _sonic.begin(trig_pin, echo_pin);
}

AaruespError AaruespClass::setUltrasonicTimeout(unsigned long timeout_us) {
    _sonic.setTimeoutUs(timeout_us);
    return AARUESP_OK;
}

float AaruespClass::readUltrasonic() {
    _err = _sonic.lastError();
    return _sonic.readCm();
}

bool AaruespClass::readUltrasonic(float& cm) {
    cm = _sonic.readCm();
    _err = _sonic.lastError();
    return !isnan(cm);
}

float AaruespClass::readUltrasonicInches() {
    _err = _sonic.lastError();
    return _sonic.readInches();
}

// ---- DHT ----
AaruespError AaruespClass::dht11(uint8_t pin) { return dht(pin, AARU_DHT11); }
AaruespError AaruespClass::dht22(uint8_t pin) { return dht(pin, AARU_DHT22); }

AaruespError AaruespClass::dht(uint8_t pin, AaruDHTType type) {
    AaruespError e = aaruespValidateDigitalPin(pin, true);
    if (e != AARUESP_OK) return setErr(e);
    return _dht.begin(pin, type);
}

float AaruespClass::readTemperature() { _err = _dht.lastError(); return _dht.readTemperature(); }
float AaruespClass::readHumidity() { _err = _dht.lastError(); return _dht.readHumidity(); }
float AaruespClass::readTemperatureF() { _err = _dht.lastError(); return _dht.readTemperatureF(); }

bool AaruespClass::readDHT(float& temp_c, float& hum_pct) {
    bool ok = _dht.read(temp_c, hum_pct);
    _err = _dht.lastError();
    return ok;
}

bool AaruespClass::dhtFresh() const { return _dht.fresh(); }
unsigned long AaruespClass::dhtAgeMs() const { return _dht.ageMs(); }

// ---- Analog Engine ----
AaruespError AaruespClass::analogSensor(uint8_t pin, AaruAnalogKind kind) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    return _aeng.begin(pin, kind);
}

AaruespError AaruespClass::ldr(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_LDR); }
AaruespError AaruespClass::potentiometer(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_POTENTIOMETER); }
AaruespError AaruespClass::lm35(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_LM35); }
AaruespError AaruespClass::tmp36(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_TMP36); }

AaruespError AaruespClass::thermistor(uint8_t pin, float series_r, float beta, float r0, float t0_c) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    return _aeng.beginWithPreset(pin, AARU_AN_KIND_NTC_BETA, series_r, beta, r0, t0_c);
}

AaruespError AaruespClass::soilMoisture(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_SOIL_MOISTURE); }
AaruespError AaruespClass::rainSensor(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_RAIN_SENSOR); }
AaruespError AaruespClass::waterLevel(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_WATER_LEVEL); }
AaruespError AaruespClass::soundSensor(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_SOUND_SENSOR); }
AaruespError AaruespClass::forceSensor(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_FSR); }
AaruespError AaruespClass::flameAnalog(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_FLAME_ANALOG); }

AaruespError AaruespClass::mq2(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ2); }
AaruespError AaruespClass::mq3(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ3); }
AaruespError AaruespClass::mq4(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ4); }
AaruespError AaruespClass::mq5(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ5); }
AaruespError AaruespClass::mq6(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ6); }
AaruespError AaruespClass::mq7(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ7); }
AaruespError AaruespClass::mq8(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ8); }
AaruespError AaruespClass::mq9(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ9); }
AaruespError AaruespClass::mq131(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ131); }
AaruespError AaruespClass::mq135(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ135); }
AaruespError AaruespClass::mq136(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ136); }
AaruespError AaruespClass::mq137(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ137); }
AaruespError AaruespClass::mq138(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_MQ138); }

AaruespError AaruespClass::genericMQ(uint8_t pin, float r0, float a, float b) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    e = _aeng.beginWithPreset(pin, AARU_AN_KIND_GENERIC_MQ, r0, a, b);
    if (e == AARUESP_OK) _aeng.setParams(r0, a, b);
    return e;
}

AaruespError AaruespClass::acs712_5A(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_ACS712_5A); }
AaruespError AaruespClass::acs712_20A(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_ACS712_20A); }
AaruespError AaruespClass::acs712_30A(uint8_t pin) { return cfgAnalog(pin, AARU_AN_KIND_ACS712_30A); }

AaruespError AaruespClass::acs712(uint8_t pin, float mv_per_amp, float zero_mv) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    e = _aeng.beginWithPreset(pin, AARU_AN_KIND_ACS712_5A, mv_per_amp, zero_mv);
    if (e == AARUESP_OK) _aeng.setParams(mv_per_amp, zero_mv);
    return e;
}

AaruespError AaruespClass::voltageDivider(uint8_t pin, float ratio) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    e = _aeng.beginWithPreset(pin, AARU_AN_KIND_VOLTAGE_DIVIDER, ratio);
    if (e == AARUESP_OK) _aeng.setDividerRatio(ratio);
    return e;
}

AaruespError AaruespClass::acVoltageZMPT101B(uint8_t pin) {
    return cfgAnalog(pin, AARU_AN_KIND_AC_VOLTAGE_ZMPT101B);
}

int AaruespClass::readAnalogRaw() { _err = _aeng.lastError(); return _aeng.readRaw(); }
float AaruespClass::readAnalogPercent() { _err = _aeng.lastError(); return _aeng.readPercent(); }
float AaruespClass::readAnalogVoltage() { _err = _aeng.lastError(); return _aeng.readVoltage(); }
float AaruespClass::readAnalogValue() { _err = _aeng.lastError(); return _aeng.readValue(); }
int AaruespClass::readLDR() { _err = _aeng.lastError(); return _aeng.readRaw(); }
int AaruespClass::readPotentiometer() { _err = _aeng.lastError(); return _aeng.readRaw(); }
float AaruespClass::readTemperatureAnalog() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readGas() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readCurrent() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readSoil() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readRain() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readWaterLevel() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readSound() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readForce() { _err = _aeng.lastError(); return _aeng.readValue(); }
float AaruespClass::readFlameAnalog() { _err = _aeng.lastError(); return _aeng.readValue(); }

int AaruespClass::readAnalogPin(uint8_t pin) { _err = _aeng.lastError(); return _aeng.readRawPin(pin); }
float AaruespClass::readVoltagePin(uint8_t pin, float divider) {
    _err = _aeng.lastError(); return _aeng.readVoltagePin(pin, divider);
}

void AaruespClass::setThermistorParams(float series_r, float beta, float r0, float t0_c) {
    _aeng.setParams(series_r, beta, r0, t0_c);
}
void AaruespClass::setCurrentParams(float mv_per_amp, float zero_mv) {
    _aeng.setParams(mv_per_amp, zero_mv);
}
void AaruespClass::setMQParams(float r0, float a, float b) {
    _aeng.setParams(r0, a, b);
}

// ---- Digital Engine ----
AaruespError AaruespClass::digitalSensor(uint8_t pin, AaruDigitalKind kind,
                                                 bool active_low, bool pullup) {
    return cfgDigital(pin, kind, active_low, pullup);
}

AaruespError AaruespClass::button(uint8_t pin, bool active_low, bool pullup) {
    return cfgDigital(pin, AARU_DIG_KIND_BUTTON, active_low, pullup);
}
AaruespError AaruespClass::pir(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_PIR); }
AaruespError AaruespClass::radarRCWL(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_RADAR_RCWL); }
AaruespError AaruespClass::irObstacle(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_IR_OBSTACLE, true); }
AaruespError AaruespClass::lineFollower(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_IR_LINE, true); }
AaruespError AaruespClass::flameSensor(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_FLAME_DIGITAL, true); }
AaruespError AaruespClass::smokeDigital(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_SMOKE_DIGITAL); }
AaruespError AaruespClass::touchTTP223(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_TOUCH_TTP223, false, false); }
AaruespError AaruespClass::hallDigital(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_HALL_DIGITAL, true); }
AaruespError AaruespClass::reedSwitch(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_REED_SWITCH, false, true); }
AaruespError AaruespClass::limitSwitch(uint8_t pin, bool pullup, bool active_low) {
    return cfgDigital(pin, AARU_DIG_KIND_LIMIT_SWITCH, active_low, pullup);
}
AaruespError AaruespClass::vibrationSW420(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_VIBRATION_SW420, false); }
AaruespError AaruespClass::tiltSwitch(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_TILT_SWITCH); }
AaruespError AaruespClass::shockSW18010(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_SHOCK_SW18010); }
AaruespError AaruespClass::pulseCounter(uint8_t pin) { return cfgDigital(pin, AARU_DIG_KIND_PULSE_COUNTER); }

AaruespError AaruespClass::flowSensor(uint8_t pin, float pulses_per_litre) {
    AaruespError e = cfgDigital(pin, AARU_DIG_KIND_FLOW_SENSOR);
    // flow-sensor config stored in digital engine not exposed; keep simple
    return e;
}

AaruespError AaruespClass::tachometer(uint8_t pin, float pulses_per_rev) {
    return cfgDigital(pin, AARU_DIG_KIND_TACHOMETER);
}

AaruespError AaruespClass::keypad4x4(uint8_t r0, uint8_t r1, uint8_t r2, uint8_t r3,
                                            uint8_t c0, uint8_t c1, uint8_t c2, uint8_t c3) {
    uint8_t pins[8] = {r0, r1, r2, r3, c0, c1, c2, c3};
    for (int i = 0; i < 8; i++) {
        AaruespError e = aaruespValidateDigitalPin(pins[i], i >= 4);
        if (e != AARUESP_OK) return setErr(e);
    }
    return setErr(AARUESP_INIT_FAIL);
}

AaruespError AaruespClass::irReceiver(uint8_t pin, IRProtocol proto) {
    return _ir.begin(pin, proto);
}

bool AaruespClass::readDigitalSensor() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readPIR() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readRadar() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readIR() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readLine() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readFlame() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readSmoke() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readTouch() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readHall() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readReed() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readLimit() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readVibration() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readTilt() { _err = _deng.lastError(); return _deng.readState(); }
bool AaruespClass::readShock() { _err = _deng.lastError(); return _deng.readState(); }

int AaruespClass::readButton() { _err = _deng.lastError(); return _deng.readButton(); }
bool AaruespClass::buttonPressed() { _err = _deng.lastError(); return _deng.pressed(); }
bool AaruespClass::buttonRose() { _err = _deng.lastError(); return _deng.rose(); }
bool AaruespClass::buttonFell() { _err = _deng.lastError(); return _deng.fell(); }

unsigned long AaruespClass::pulseCount() { _err = _deng.lastError(); return _deng.pulseCount(); }
void AaruespClass::resetPulseCount() { _deng.resetPulseCount(); }
float AaruespClass::readFrequencyHz() { _err = _deng.lastError(); return _deng.readFrequencyHz(); }
float AaruespClass::readFlowRateLmin() { _err = _deng.lastError(); return _deng.readFlowRateLmin(); }

uint32_t AaruespClass::readIRNEC() { _err = _deng.lastError(); return _deng.readIRNEC(); }
bool AaruespClass::irDataReady() { return _deng.irDataReady(); }
char AaruespClass::readKey() { return 0; }

// ---- Rotary Encoder ----
AaruespError AaruespClass::rotaryEncoder(uint8_t clk, uint8_t dt, int sw_pin) {
    return _pulse.beginEncoder(clk, dt, sw_pin);
}
long AaruespClass::encoderCount() { return _pulse.encoderCount(); }
void AaruespClass::encoderReset() { _pulse.encoderReset(); }
int8_t AaruespClass::encoderDirection() { return _pulse.encoderDirection(); }
bool AaruespClass::encoderButton() { return _pulse.encoderButton(); }

// ---- Joystick ----
AaruespError AaruespClass::joystick(uint8_t x_pin, uint8_t y_pin, int sw_pin) {
    AaruespError e = aaruespValidateAnalogPin(x_pin);
    if (e != AARUESP_OK) return setErr(e);
    e = aaruespValidateAnalogPin(y_pin);
    if (e != AARUESP_OK) return setErr(e);
    if (sw_pin >= 0) {
        e = aaruespValidateDigitalPin(sw_pin, false);
        if (e != AARUESP_OK) return setErr(e);
    }
    _aeng.begin(x_pin, AARU_AN_KIND_RAW);
    return AARUESP_OK;
}

int AaruespClass::readJoyX() { return _aeng.readRaw(); }
int AaruespClass::readJoyY() { return _aeng.readRawPin(255); }
bool AaruespClass::readJoyButton() { return false; }

// ---- MPU6050 ----
AaruespError AaruespClass::mpu6050(uint8_t addr) { return _mpu.begin(&_i2c, addr); }
bool AaruespClass::readAccel(float& x, float& y, float& z) {
    _err = _mpu.lastError(); return _mpu.readAccel(x, y, z);
}
bool AaruespClass::readGyro(float& x, float& y, float& z) {
    _err = _mpu.lastError(); return _mpu.readGyro(x, y, z);
}
float AaruespClass::readIMUTemp() { _err = _mpu.lastError(); return _mpu.readTemp(); }
float AaruespClass::readAccelX() { _err = _mpu.lastError(); return _mpu.readAccelX(); }
float AaruespClass::readAccelY() { _err = _mpu.lastError(); return _mpu.readAccelY(); }
float AaruespClass::readAccelZ() { _err = _mpu.lastError(); return _mpu.readAccelZ(); }
float AaruespClass::readGyroX() { _err = _mpu.lastError(); return _mpu.readGyroX(); }
float AaruespClass::readGyroY() { _err = _mpu.lastError(); return _mpu.readGyroY(); }
float AaruespClass::readGyroZ() { _err = _mpu.lastError(); return _mpu.readGyroZ(); }
void AaruespClass::calibrateAccel(int samples) { _mpu.calibrateAccel(samples); }
void AaruespClass::calibrateGyro(int samples) { _mpu.calibrateGyro(samples); }
AaruespError AaruespClass::mpuSleep() { return _mpu.sleep(); }
AaruespError AaruespClass::mpuWake() { return _mpu.wake(); }

// ---- DS18B20 ----
AaruespError AaruespClass::ds18b20(uint8_t pin) { return _ds.begin(pin); }
int AaruespClass::ds18b20Count() { return _ds.deviceCount(); }
float AaruespClass::readDS18B20(int index) { _err = _ds.lastError(); return _ds.readTempC(index); }
float AaruespClass::readDS18B20F(int index) { _err = _ds.lastError(); return _ds.readTempF(index); }
AaruespError AaruespClass::ds18b20Request() { return _ds.requestTemperatures(); }
bool AaruespClass::ds18b20Ready() { return _ds.conversionReady(); }
float AaruespClass::readDS18B20Async(int index) { return _ds.readTempC(index); }
AaruespError AaruespClass::ds18b20SetResolution(int index, uint8_t bits) {
    return _ds.setResolution(index, bits);
}

// ---- DS3231 RTC ----
AaruespError AaruespClass::rtcDS3231(uint8_t addr) { return _rtc.begin(&_i2c, addr); }
AaruespError AaruespClass::rtcSet(int year, int month, int day, int hour, int min, int sec) {
    AaruDateTime dt = {(uint16_t)year, (uint8_t)month, (uint8_t)day, (uint8_t)hour, (uint8_t)min, (uint8_t)sec, 1};
    return _rtc.setDateTime(dt);
}
AaruespError AaruespClass::rtcGet(int& year, int& month, int& day, int& hour, int& min, int& sec) {
    AaruDateTime dt;
    AaruespError e = _rtc.getDateTime(dt);
    if (e == AARUESP_OK) {
        year = dt.year; month = dt.month; day = dt.day;
        hour = dt.hour; min = dt.minute; sec = dt.second;
    }
    return e;
}
uint32_t AaruespClass::rtcUnixTime() { return _rtc.getUnixTime(); }
float AaruespClass::rtcTemp() { return _rtc.readTempC(); }
AaruespError AaruespClass::rtcAlarm1(int sec, int min, int hour, int day, bool dow) {
    return _rtc.setAlarm1(sec, min, hour, day, dow);
}
AaruespError AaruespClass::rtcAlarm2(int min, int hour, int day, bool dow) {
    return _rtc.setAlarm2(min, hour, day, dow);
}
bool AaruespClass::rtcAlarmTriggered(int alarm_num) { return _rtc.alarmTriggered(alarm_num); }
AaruespError AaruespClass::rtcSquareWave(uint8_t freq) { return _rtc.setSquareWave(freq); }

// ---- BME280/BMP280 ----
AaruespError AaruespClass::bme280(uint8_t addr) { return _bme.beginI2C(&_i2c, addr); }
AaruespError AaruespClass::bmp280(uint8_t addr) { return _bme.beginI2C(&_i2c, addr); }
bool AaruespClass::readBME(float& temp, float& hum, float& press) {
    AaruBME280Data data;
    bool ok = _bme.read(data);
    temp = data.temperature; hum = data.humidity; press = data.pressure;
    _err = _bme.lastError();
    return ok;
}
float AaruespClass::readBMEtemp() { _err = _bme.lastError(); return _bme.readTemp(); }
float AaruespClass::readBMEhumidity() { _err = _bme.lastError(); return _bme.readHumidity(); }
float AaruespClass::readBMEpressure() { _err = _bme.lastError(); return _bme.readPressure(); }
float AaruespClass::readBMEaltitude(float sea_level) { _err = _bme.lastError(); return _bme.readAltitude(sea_level); }

// ---- BH1750 ----
AaruespError AaruespClass::bh1750(uint8_t addr) { return _bh.begin(&_i2c, addr); }
float AaruespClass::readLux() {
    _err = _bh.lastError();
    float lux = 0;
    _bh.read(lux);
    return lux;
}

// ---- Displays ----
AaruespError AaruespClass::oled(uint8_t addr, uint8_t w, uint8_t h) {
    return _oled.beginI2C(&_i2c, addr, w, h);
}
AaruespError AaruespClass::lcdI2C(uint8_t addr, uint8_t cols, uint8_t rows) {
    return _lcd.begin(&_i2c, addr, cols, rows);
}
AaruespError AaruespClass::lcd(uint8_t addr, uint8_t cols, uint8_t rows) {
    return lcdI2C(addr, cols, rows);
}
AaruespError AaruespClass::max7219(uint8_t cs, uint8_t devices) {
    return _max7219.begin(&_spi, cs, devices);
}
AaruespError AaruespClass::tm1637(uint8_t clk, uint8_t dio) {
    return _tm1637.begin(clk, dio);
}
AaruespError AaruespClass::ws2812(uint8_t pin, uint16_t num_leds) {
    return _ws2812.begin(pin, num_leds);
}

AaruespError AaruespClass::displayClear() {
    _err = _oled.lastError();
    _oled.clear(); _oled.display();
    return _err;
}
AaruespError AaruespClass::displayText(const char* line) {
    _err = _oled.lastError();
    _oled.clear(); _oled.setCursor(0, 0); _oled.print(line); _oled.display();
    return _err;
}
AaruespError AaruespClass::displayText(int row, const char* line) {
    _err = _oled.lastError();
    _oled.setCursor(0, row * 8); _oled.print(line); _oled.display();
    return _err;
}
AaruespError AaruespClass::displayTextAt(int row, int col, const char* line) {
    _err = _oled.lastError();
    _oled.setCursor(col * 6, row * 8); _oled.print(line); _oled.display();
    return _err;
}
AaruespError AaruespClass::displayBacklight(bool on) {
    _err = _lcd.lastError();
    if (on) _lcd.backlightOn(); else _lcd.backlightOff();
    return _err;
}
AaruespError AaruespClass::displayPrint(int n, int base) {
    _oled.print(n, base); _oled.display(); return AARUESP_OK;
}
AaruespError AaruespClass::displayPrint(float f, int digits) {
    _oled.print(f, digits); _oled.display(); return AARUESP_OK;
}
AaruespError AaruespClass::displaySetCursor(int col, int row) {
    _oled.setCursor(col * 6, row * 8); return AARUESP_OK;
}
AaruespError AaruespClass::displayContrast(uint8_t val) { return _oled.setContrast(val); }
AaruespError AaruespClass::displayInvert(bool inv) { return _oled.invert(inv); }

// ---- Actuators ----
AaruespError AaruespClass::led(uint8_t pin) {
    AaruespError e = aaruespValidatePwmPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    _led_pin = pin;
    e = _pwm.begin(pin);
    if (e == AARUESP_OK) _pwm.write(0);
    return e;
}
AaruespError AaruespClass::setLED(bool on) {
    _led_state = on;
    return _pwm.write(on ? 255 : 0);
}
AaruespError AaruespClass::toggleLED() { return setLED(!_led_state); }
AaruespError AaruespClass::setBrightness(uint8_t val) { return _pwm.write(val); }

AaruespError AaruespClass::buzzer(uint8_t pin) {
    AaruespError e = aaruespValidatePwmPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    _buzzer_pin = pin;
    return _pwm.beginBuzzer(pin);
}
AaruespError AaruespClass::beep(unsigned long duration_ms) {
    return _pwm.tone(2000, duration_ms);
}
AaruespError AaruespClass::beep(uint16_t freq_hz, unsigned long duration_ms) {
    return _pwm.tone(freq_hz, duration_ms);
}
AaruespError AaruespClass::tone(uint16_t freq_hz, unsigned long duration_ms) {
    return _pwm.tone(freq_hz, duration_ms);
}
AaruespError AaruespClass::noTone() { return _pwm.noTone(); }
AaruespError AaruespClass::buzzerOff() { return _pwm.noTone(); }

AaruespError AaruespClass::relay(uint8_t pin, bool active_high) {
    AaruespError e = aaruespValidateDigitalPin(pin, true);
    if (e != AARUESP_OK) return setErr(e);
    _relay_pin = pin; _relay_active_high = active_high;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, active_high ? LOW : HIGH);
    _relay_state = false;
    return AARUESP_OK;
}
AaruespError AaruespClass::setRelay(bool on) {
    _relay_state = on;
    digitalWrite(_relay_pin, (_relay_active_high == on) ? HIGH : LOW);
    return AARUESP_OK;
}
AaruespError AaruespClass::toggleRelay() { return setRelay(!_relay_state); }

AaruespError AaruespClass::solenoid(uint8_t pin, bool active_high) {
    return relay(pin, active_high);
}
AaruespError AaruespClass::setSolenoid(bool on) { return setRelay(on); }

AaruespError AaruespClass::laser(uint8_t pin) {
    AaruespError e = aaruespValidateDigitalPin(pin, true);
    if (e != AARUESP_OK) return setErr(e);
    _laser_pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    return AARUESP_OK;
}
AaruespError AaruespClass::setLaser(bool on) {
    digitalWrite(_laser_pin, on ? HIGH : LOW);
    return AARUESP_OK;
}

AaruespError AaruespClass::rgb(uint8_t r, uint8_t g, uint8_t b) {
    AaruespError e = aaruespValidatePwmPin(r);
    if (e != AARUESP_OK) return setErr(e);
    e = aaruespValidatePwmPin(g);
    if (e != AARUESP_OK) return setErr(e);
    e = aaruespValidatePwmPin(b);
    if (e != AARUESP_OK) return setErr(e);
    _rgb_pins[0] = r; _rgb_pins[1] = g; _rgb_pins[2] = b;
    _rgb_setup = true;
    return _pwm.beginRGB(r, g, b);
}
AaruespError AaruespClass::setRGB(uint8_t r, uint8_t g, uint8_t b) {
    return _pwm.setRGB(r, g, b);
}
AaruespError AaruespClass::setRGBHSV(uint16_t h, uint8_t s, uint8_t v) {
    return _pwm.setHSV(h, s, v);
}
AaruespError AaruespClass::rgbOff() { return _pwm.rgbOff(); }

AaruespError AaruespClass::pwmOut(uint8_t pin) {
    AaruespError e = aaruespValidatePwmPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    _pwm_pin = pin;
    return _pwm.begin(pin);
}
AaruespError AaruespClass::writePWM(uint8_t val) { return _pwm.write(val); }
AaruespError AaruespClass::writePWMPercent(float pct) { return _pwm.writePercent(pct); }

AaruespError AaruespClass::motor(uint8_t in1, uint8_t in2, int en_pin) {
    AaruespError e = aaruespValidateDigitalPin(in1, true);
    if (e != AARUESP_OK) return setErr(e);
    e = aaruespValidateDigitalPin(in2, true);
    if (e != AARUESP_OK) return setErr(e);
    if (en_pin >= 0) {
        e = aaruespValidatePwmPin(en_pin);
        if (e != AARUESP_OK) return setErr(e);
    }
    _motor_in1 = in1; _motor_in2 = in2; _motor_en = en_pin;
    pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
    if (en_pin >= 0) pinMode(en_pin, OUTPUT);
    return _pwm.beginMotor(in1, in2, en_pin);
}
AaruespError AaruespClass::motorSpeed(int speed) { return _pwm.motorSpeed(speed); }
AaruespError AaruespClass::motorBrake() { return _pwm.motorBrake(); }
AaruespError AaruespClass::motorCoast() { return _pwm.motorCoast(); }

AaruespError AaruespClass::servo(uint8_t pin, int min_us, int max_us) {
    AaruespError e = aaruespValidateDigitalPin(pin, true);
    if (e != AARUESP_OK) return setErr(e);
    _servo_pin = pin;
    return _pwm.beginServo(pin, min_us, max_us);
}
AaruespError AaruespClass::servoWrite(int angle) { return _pwm.servoWrite(angle); }
AaruespError AaruespClass::servoWriteUs(uint16_t us) { return _pwm.servoWriteUs(us); }
AaruespError AaruespClass::servoDetach() { return _pwm.servoDetach(); }

AaruespError AaruespClass::stepper(uint8_t step, uint8_t dir, int en) {
    return _stepper.begin(step, dir, en);
}
AaruespError AaruespClass::stepper4Wire(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) {
    return _stepper.begin4Wire(in1, in2, in3, in4);
}
AaruespError AaruespClass::stepperSetRpm(double rpm) {
    _stepper.setRpm(rpm);
    return AARUESP_OK;
}
AaruespError AaruespClass::stepperStep(long steps) { return _stepper.step(steps); }
AaruespError AaruespClass::stepperMove(long steps) { _stepper.move(steps); return AARUESP_OK; }
AaruespError AaruespClass::stepperMoveTo(long pos) { _stepper.moveTo(pos); return AARUESP_OK; }
bool AaruespClass::stepperRun() { return _stepper.run(); }
void AaruespClass::stepperStop() { _stepper.stop(); }
AaruespError AaruespClass::stepperRelease() { _stepper.disable(); return AARUESP_OK; }

// ---- GPS ----
AaruespError AaruespClass::gps(int rx, int tx, uint32_t baud) {
    _gps_setup = true;
    return _gps.begin(rx, tx, baud);
}
void AaruespClass::gpsUpdate() { if (_gps_setup) _gps.update(); }
bool AaruespClass::gpsFix() { return _gps.hasFix(); }
float AaruespClass::gpsLat() { return _gps.lat(); }
float AaruespClass::gpsLon() { return _gps.lon(); }
float AaruespClass::gpsAlt() { return _gps.alt(); }
float AaruespClass::gpsSpeedKmph() { return _gps.speedKmph(); }
float AaruespClass::gpsCourse() { return _gps.course(); }
uint8_t AaruespClass::gpsSats() { return _gps.sats(); }
uint32_t AaruespClass::gpsDate() { return _gps.date(); }
uint32_t AaruespClass::gpsTime() { return _gps.time(); }

// ---- IR Remote ----
AaruespError AaruespClass::irRecv(uint8_t pin, IRProtocol proto) { return _ir.begin(pin, proto); }
AaruespError AaruespClass::irSend(uint8_t pin) {
    _ir_send_setup = true;
    return _ir.beginSend(pin);
}
bool AaruespClass::irDecode(AaruIRResult* result) { return _ir.decode(result); }
void AaruespClass::irResume() { _ir.resume(); }
AaruespError AaruespClass::irSendNEC(uint32_t data, uint8_t nbits) { return _ir.sendNEC(data, nbits); }
AaruespError AaruespClass::irSendSony(uint32_t data, uint8_t nbits) { return _ir.sendSony(data, nbits); }
AaruespError AaruespClass::irSendRaw(const uint16_t* buf, uint16_t len, uint16_t freq_khz) {
    return _ir.sendRaw(buf, len, freq_khz);
}

// ---- Pin Helpers ----
bool AaruespClass::isValidDigitalPin(uint8_t pin, bool need_output) {
    return aaruespValidateDigitalPin(pin, need_output) == AARUESP_OK;
}
bool AaruespClass::isValidAnalogPin(int pin) {
    return aaruespValidateAnalogPin(pin) == AARUESP_OK;
}
bool AaruespClass::isValidPwmPin(uint8_t pin) {
    return aaruespValidatePwmPin(pin) == AARUESP_OK;
}
AaruespError AaruespClass::i2cScan(uint8_t* addrs, uint8_t max_addrs) {
    if (!_i2c.isBegun()) _i2c.begin();
    return _i2c.scanList(addrs, max_addrs) ? AARUESP_OK : AARUESP_ERROR;
}
uint8_t AaruespClass::i2cScanCount() {
    if (!_i2c.isBegun()) _i2c.begin();
    return _i2c.scanCount();
}

// ---- Private helpers ----
AaruespError AaruespClass::cfgAnalog(uint8_t pin, AaruAnalogKind kind) {
    AaruespError e = aaruespValidateAnalogPin(pin);
    if (e != AARUESP_OK) return setErr(e);
    return _aeng.begin(pin, kind);
}
AaruespError AaruespClass::cfgDigital(uint8_t pin, AaruDigitalKind kind, bool active_low, bool pullup) {
    AaruespError e = aaruespValidateDigitalPin(pin, false);
    if (e != AARUESP_OK) return setErr(e);
    return _deng.begin(pin, kind, active_low, pullup);
}

// ---- Global singleton ----
AaruespClass AARUESP;

// ---- Board-specific aliases ----
AaruespError ultrasonic_uno(uint8_t trig, uint8_t echo) { return AARUESP.ultrasonic(trig, echo); }
float ultrasonic_uno() { return AARUESP.readUltrasonic(); }
AaruespError ultrasonic_esp32(uint8_t trig, uint8_t echo) { return AARUESP.ultrasonic(trig, echo); }
float ultrasonic_esp32() { return AARUESP.readUltrasonic(); }
AaruespError ultrasonic_esp8266(uint8_t trig, uint8_t echo) { return AARUESP.ultrasonic(trig, echo); }
float ultrasonic_esp8266() { return AARUESP.readUltrasonic(); }