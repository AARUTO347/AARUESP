// ============================================================
//  AARUESP v1.0.0 — Universal Arduino Library
//  MADE BY AARUTO
//  1000+ modules, one API.
// ============================================================
#ifndef AARUESP_H
#define AARUESP_H

#include "AARUESPTypes.h"
#include "AARUESPConfig.h"
#include "AARUESPBoard.h"
#include "engines/AaruAnalogEngine.h"
#include "engines/AaruDigitalEngine.h"
#include "engines/AaruPWMEngine.h"
#include "engines/AaruI2CEngine.h"
#include "engines/AaruSPIEngine.h"
#include "engines/AaruUARTEngine.h"
#include "engines/AaruOneWireEngine.h"
#include "engines/AaruPulseEngine.h"
#include "drivers/AaruHCSR04.h"
#include "drivers/AaruDHT.h"
#include "drivers/AaruMPU6050.h"
#include "drivers/AaruDS18B20.h"
#include "drivers/AaruDS3231.h"
#include "drivers/AaruBME280.h"
#include "drivers/AaruBH1750.h"
#include "drivers/AaruSSD1306.h"
#include "drivers/AaruLCD.h"
#include "drivers/AaruMAX7219.h"
#include "drivers/AaruTM1637.h"
#include "drivers/AaruWS2812.h"
#include "drivers/AaruGPS.h"
#include "drivers/AaruIRRemote.h"
#include "drivers/AaruStepper.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
class Stream {
public:
    virtual size_t print(const char*) { return 0; }
    virtual size_t println(const char*) { return 0; }
    virtual size_t write(uint8_t) { return 0; }
};
#endif

class AaruespClass {
public:
    AaruespClass();

    // ---- Core ----
    void begin();
    void update();
    void setDebugStream(Stream* s) { _dbg = s; }
    const char* version() const { return AARUESP_VERSION_STRING; }
    const char* madeBy() const { return "MADE BY AARUTO"; }
    const char* credits() const { return "AARUESP v" AARUESP_VERSION_STRING " — MADE BY AARUTO"; }
    AaruespFamily boardFamily() const;
    const char* boardName() const;
    AaruespError lastError() const { return _err; }
    void clearError() { _err = AARUESP_OK; }
    const char* errorString() const;
    static const char* errorString(AaruespError e);

    // ---- Ultrasonic ----
    AaruespError ultrasonic(uint8_t trig_pin, uint8_t echo_pin);
    AaruespError setUltrasonicTimeout(unsigned long timeout_us);
    float readUltrasonic();
    bool readUltrasonic(float& cm);
    float readUltrasonicInches();

    // ---- DHT ----
    AaruespError dht11(uint8_t pin);
    AaruespError dht22(uint8_t pin);
    AaruespError dht(uint8_t pin, AaruDHTType type);
    float readTemperature();
    float readHumidity();
    float readTemperatureF();
    bool readDHT(float& temp_c, float& hum_pct);
    bool dhtFresh() const;
    unsigned long dhtAgeMs() const;

    // ---- Analog engine ----
    AaruespError analogSensor(uint8_t pin, AaruAnalogKind kind);
    AaruespError ldr(uint8_t pin);
    AaruespError potentiometer(uint8_t pin);
    AaruespError lm35(uint8_t pin);
    AaruespError tmp36(uint8_t pin);
    AaruespError thermistor(uint8_t pin, float series_r, float beta, float r0, float t0_c);
    AaruespError soilMoisture(uint8_t pin);
    AaruespError rainSensor(uint8_t pin);
    AaruespError waterLevel(uint8_t pin);
    AaruespError soundSensor(uint8_t pin);
    AaruespError forceSensor(uint8_t pin);
    AaruespError flameAnalog(uint8_t pin);
    // MQ Gas sensors
    AaruespError mq2(uint8_t pin); AaruespError mq3(uint8_t pin);
    AaruespError mq4(uint8_t pin); AaruespError mq5(uint8_t pin);
    AaruespError mq6(uint8_t pin); AaruespError mq7(uint8_t pin);
    AaruespError mq8(uint8_t pin); AaruespError mq9(uint8_t pin);
    AaruespError mq131(uint8_t pin); AaruespError mq135(uint8_t pin);
    AaruespError mq136(uint8_t pin); AaruespError mq137(uint8_t pin);
    AaruespError mq138(uint8_t pin);
    AaruespError genericMQ(uint8_t pin, float r0, float a, float b);
    // Current / voltage
    AaruespError acs712_5A(uint8_t pin); AaruespError acs712_20A(uint8_t pin);
    AaruespError acs712_30A(uint8_t pin);
    AaruespError acs712(uint8_t pin, float mv_per_amp, float zero_mv);
    AaruespError voltageDivider(uint8_t pin, float ratio);
    AaruespError acVoltageZMPT101B(uint8_t pin);
    // Read helpers
    int readAnalogRaw();
    float readAnalogPercent();
    float readAnalogVoltage();
    float readAnalogValue();
    int readLDR();
    int readPotentiometer();
    float readTemperatureAnalog();
    float readGas();
    float readCurrent();
    float readSoil();
    float readRain();
    float readWaterLevel();
    float readSound();
    float readForce();
    float readFlameAnalog();
    int readAnalogPin(uint8_t pin);
    float readVoltagePin(uint8_t pin, float divider = 1.0f);

    // Analog param overrides
    void setThermistorParams(float series_r, float beta, float r0, float t0_c);
    void setCurrentParams(float mv_per_amp, float zero_mv);
    void setMQParams(float r0, float a, float b);
    void setAnalogSamples(uint8_t n) { _aeng.setSamples(n); }
    void setAnalogSettleUs(uint16_t us) { _aeng.setSettleUs(us); }

    // ---- Digital engine ----
    AaruespError digitalSensor(uint8_t pin, AaruDigitalKind kind, bool active_low = false, bool pullup = false);
    AaruespError button(uint8_t pin, bool active_low = true, bool pullup = true);
    AaruespError pir(uint8_t pin);
    AaruespError radarRCWL(uint8_t pin);
    AaruespError irObstacle(uint8_t pin);
    AaruespError lineFollower(uint8_t pin);
    AaruespError flameSensor(uint8_t pin);
    AaruespError smokeDigital(uint8_t pin);
    AaruespError touchTTP223(uint8_t pin);
    AaruespError hallDigital(uint8_t pin);
    AaruespError reedSwitch(uint8_t pin);
    AaruespError limitSwitch(uint8_t pin, bool pullup = true, bool active_low = true);
    AaruespError vibrationSW420(uint8_t pin);
    AaruespError tiltSwitch(uint8_t pin);
    AaruespError shockSW18010(uint8_t pin);
    AaruespError pulseCounter(uint8_t pin);
    AaruespError flowSensor(uint8_t pin, float pulses_per_litre);
    AaruespError tachometer(uint8_t pin, float pulses_per_rev);
    AaruespError keypad4x4(uint8_t r0, uint8_t r1, uint8_t r2, uint8_t r3,
                               uint8_t c0, uint8_t c1, uint8_t c2, uint8_t c3);
    AaruespError irReceiver(uint8_t pin, IRProtocol proto = IR_PROTO_NEC);

    bool readDigitalSensor();
    bool readPIR();
    bool readRadar();
    bool readIR();
    bool readLine();
    bool readFlame();
    bool readSmoke();
    bool readTouch();
    bool readHall();
    bool readReed();
    bool readLimit();
    bool readVibration();
    bool readTilt();
    bool readShock();
    int readButton();
    bool buttonPressed();
    bool buttonRose();
    bool buttonFell();
    unsigned long pulseCount();
    void resetPulseCount();
    float readFrequencyHz();
    float readFlowRateLmin();
    uint32_t readIRNEC();
    bool irDataReady();
    char readKey();

    // ---- Rotary Encoder ----
    AaruespError rotaryEncoder(uint8_t clk, uint8_t dt, int sw_pin = -1);
    long encoderCount();
    void encoderReset();
    int8_t encoderDirection();
    bool encoderButton();

    // ---- Joystick ----
    AaruespError joystick(uint8_t x_pin, uint8_t y_pin, int sw_pin = -1);
    int readJoyX();
    int readJoyY();
    bool readJoyButton();

    // ---- MPU6050 ----
    AaruespError mpu6050(uint8_t addr = 0x68);
    bool readAccel(float& x, float& y, float& z);
    bool readGyro(float& x, float& y, float& z);
    float readIMUTemp();
    float readAccelX(); float readAccelY(); float readAccelZ();
    float readGyroX();  float readGyroY();  float readGyroZ();
    void calibrateAccel(int samples = 200);
    void calibrateGyro(int samples = 200);
    AaruespError mpuSleep();
    AaruespError mpuWake();

    // ---- DS18B20 ----
    AaruespError ds18b20(uint8_t pin);
    int ds18b20Count();
    float readDS18B20(int index = 0);
    float readDS18B20F(int index = 0);
    AaruespError ds18b20Request();
    bool ds18b20Ready();
    float readDS18B20Async(int index);
    AaruespError ds18b20SetResolution(int index, uint8_t bits);

    // ---- DS3231 RTC ----
    AaruespError rtcDS3231(uint8_t addr = 0x68);
    AaruespError rtcSet(int year, int month, int day, int hour, int min, int sec);
    AaruespError rtcGet(int& year, int& month, int& day, int& hour, int& min, int& sec);
    uint32_t rtcUnixTime();
    float rtcTemp();
    AaruespError rtcAlarm1(int sec, int min, int hour, int day, bool dow);
    AaruespError rtcAlarm2(int min, int hour, int day, bool dow);
    bool rtcAlarmTriggered(int alarm_num);
    AaruespError rtcSquareWave(uint8_t freq);

    // ---- BME280/BMP280 ----
    AaruespError bme280(uint8_t addr = 0x76);
    AaruespError bmp280(uint8_t addr = 0x76);
    bool readBME(float& temp, float& hum, float& press);
    float readBMEtemp();
    float readBMEhumidity();
    float readBMEpressure();
    float readBMEaltitude(float sea_level = 1013.25f);

    // ---- BH1750 ----
    AaruespError bh1750(uint8_t addr = 0x23);
    float readLux();

    // ---- Displays ----
    AaruespError oled(uint8_t addr = 0x3C, uint8_t w = 128, uint8_t h = 64);
    AaruespError lcdI2C(uint8_t addr = 0x27, uint8_t cols = 16, uint8_t rows = 2);
    AaruespError lcd(uint8_t addr, uint8_t cols, uint8_t rows);
    AaruespError max7219(uint8_t cs, uint8_t devices = 1);
    AaruespError tm1637(uint8_t clk, uint8_t dio);
    AaruespError ws2812(uint8_t pin, uint16_t num_leds);

    AaruespError displayClear();
    AaruespError displayText(const char* line);
    AaruespError displayText(int row, const char* line);
    AaruespError displayTextAt(int row, int col, const char* line);
    AaruespError displayBacklight(bool on);
    AaruespError displayPrint(int n, int base = 10);
    AaruespError displayPrint(float f, int digits = 2);
    AaruespError displaySetCursor(int col, int row);
    AaruespError displayContrast(uint8_t val);
    AaruespError displayInvert(bool inv);

    // ---- Actuators ----
    AaruespError led(uint8_t pin);
    AaruespError setLED(bool on);
    AaruespError toggleLED();
    AaruespError setBrightness(uint8_t val);

    AaruespError buzzer(uint8_t pin);
    AaruespError beep(unsigned long duration_ms);
    AaruespError beep(uint16_t freq_hz, unsigned long duration_ms);
    AaruespError tone(uint16_t freq_hz, unsigned long duration_ms = 0);
    AaruespError noTone();
    AaruespError buzzerOff();

    AaruespError relay(uint8_t pin, bool active_high = true);
    AaruespError setRelay(bool on);
    AaruespError toggleRelay();
    AaruespError solenoid(uint8_t pin, bool active_high = true);
    AaruespError setSolenoid(bool on);

    AaruespError laser(uint8_t pin);
    AaruespError setLaser(bool on);

    AaruespError rgb(uint8_t r, uint8_t g, uint8_t b);
    AaruespError setRGB(uint8_t r, uint8_t g, uint8_t b);
    AaruespError setRGBHSV(uint16_t h, uint8_t s, uint8_t v);
    AaruespError rgbOff();

    AaruespError pwmOut(uint8_t pin);
    AaruespError writePWM(uint8_t val);
    AaruespError writePWMPercent(float pct);

    AaruespError motor(uint8_t in1, uint8_t in2, int en_pin = -1);
    AaruespError motorSpeed(int speed);
    AaruespError motorBrake();
    AaruespError motorCoast();

    AaruespError servo(uint8_t pin, int min_us = 544, int max_us = 2400);
    AaruespError servoWrite(int angle);
    AaruespError servoWriteUs(uint16_t us);
    AaruespError servoDetach();

    AaruespError stepper(uint8_t step, uint8_t dir, int en = -1);
    AaruespError stepper4Wire(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    AaruespError stepperSetRpm(double rpm);
    AaruespError stepperStep(long steps);
    AaruespError stepperMove(long steps);
    AaruespError stepperMoveTo(long pos);
    bool stepperRun();
    void stepperStop();
    AaruespError stepperRelease();

    // ---- GPS ----
    AaruespError gps(int rx, int tx, uint32_t baud = 9600);
    void gpsUpdate();
    bool gpsFix();
    float gpsLat();
    float gpsLon();
    float gpsAlt();
    float gpsSpeedKmph();
    float gpsCourse();
    uint8_t gpsSats();
    uint32_t gpsDate();
    uint32_t gpsTime();

    // ---- IR Remote ----
    AaruespError irRecv(uint8_t pin, IRProtocol proto = IR_PROTO_NEC);
    AaruespError irSend(uint8_t pin);
    bool irDecode(AaruIRResult* result);
    void irResume();
    AaruespError irSendNEC(uint32_t data, uint8_t nbits = 32);
    AaruespError irSendSony(uint32_t data, uint8_t nbits = 12);
    AaruespError irSendRaw(const uint16_t* buf, uint16_t len, uint16_t freq_khz = 38);

    // ---- Pin Helpers ----
    bool isValidDigitalPin(uint8_t pin, bool need_output = false);
    bool isValidAnalogPin(int pin);
    bool isValidPwmPin(uint8_t pin);
    AaruespError i2cScan(uint8_t* addrs, uint8_t max_addrs);
    uint8_t i2cScanCount();

private:
    void dbg(const char* msg);
    AaruespError setErr(AaruespError e) { _err = e; return e; }
    AaruespError cfgAnalog(uint8_t pin, AaruAnalogKind kind);
    AaruespError cfgDigital(uint8_t pin, AaruDigitalKind kind, bool active_low = false, bool pullup = false);

    bool _begun = false;
    AaruespError _err = AARUESP_OK;
    Stream* _dbg = nullptr;

    AaruAnalogEngine _aeng;
    AaruDigitalEngine _deng;
    AaruPWMEngine _pwm;
    AaruI2CEngine _i2c;
    AaruSPIEngine _spi;
    AaruUARTEngine _uart;
    AaruOneWireEngine _ow;
    AaruPulseEngine _pulse;

    AaruHCSR04 _sonic;
    AaruDHT _dht;
    AaruMPU6050 _mpu;
    AaruDS18B20 _ds;
    AaruDS3231 _rtc;
    AaruBME280 _bme;
    AaruBH1750 _bh;
    AaruSSD1306 _oled;
    AaruLCD _lcd;
    AaruMAX7219 _max7219;
    AaruTM1637 _tm1637;
    AaruWS2812 _ws2812;
    AaruGPS _gps;
    AaruIRRemote _ir;
    AaruStepper _stepper;

    int _led_pin = -1;
    int _buzzer_pin = -1;
    int _relay_pin = -1;
    int _solenoid_pin = -1;
    int _laser_pin = -1;
    int _pwm_pin = -1;
    int _motor_in1 = -1, _motor_in2 = -1, _motor_en = -1;
    int _servo_pin = -1;
    uint8_t _rgb_pins[3] = {255, 255, 255};
    bool _relay_active_high = true;
    bool _solenoid_active_high = true;
    bool _led_state = false;
    bool _relay_state = false;
    bool _solenoid_state = false;
    bool _rgb_setup = false;

    bool _gps_setup = false;
    bool _ir_send_setup = false;
};

extern AaruespClass AARUESP;

// ---- Board-specific aliases ----
AaruespError ultrasonic_uno(uint8_t trig, uint8_t echo);
float ultrasonic_uno();
AaruespError ultrasonic_esp32(uint8_t trig, uint8_t echo);
float ultrasonic_esp32();
AaruespError ultrasonic_esp8266(uint8_t trig, uint8_t echo);
float ultrasonic_esp8266();

#endif // AARUESP_H
