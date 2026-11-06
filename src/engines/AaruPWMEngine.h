// ============================================================
//  AARUESP PWM Engine
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_PWM_ENGINE_H
#define AARUESP_PWM_ENGINE_H

#include "AARUESPTypes.h"
#include "AARUESPBoard.h"

#if defined(ARDUINO)
#include <Arduino.h>
#if __has_include(<Servo.h>)
  #include <Servo.h>
  #define AARUESP_HAS_SERVO 1
#else
  #define AARUESP_HAS_SERVO 0
#endif
#else
#include <stdint.h>
#define AARUESP_HAS_SERVO 0
#endif

class AaruPWMEngine {
public:
    AaruPWMEngine() = default;

    AaruespError begin(uint8_t pin);
    AaruespError write(uint8_t value);
    AaruespError writePercent(float pct);
    AaruespError writeUs(uint16_t microseconds);

    AaruespError setFrequency(uint32_t hz);
    AaruespError setResolution(uint8_t bits);

    AaruespError beginRGB(uint8_t r, uint8_t g, uint8_t b);
    AaruespError setRGB(uint8_t r, uint8_t g, uint8_t b);
    AaruespError setRGBPercent(float r, float g, float b);
    AaruespError setHSV(uint16_t h, uint8_t s, uint8_t v);
    AaruespError rgbOff();

    AaruespError beginBuzzer(uint8_t pin);
    AaruespError tone(uint16_t freq_hz, unsigned long duration_ms);
    AaruespError noTone();

    AaruespError beginServo(uint8_t pin, int min_us, int max_us);
    AaruespError servoWrite(int angle);
    AaruespError servoWriteUs(uint16_t us);
    AaruespError servoDetach();

    AaruespError beginMotor(uint8_t in1, uint8_t in2, int en_pin);
    AaruespError motorSpeed(int speed);
    AaruespError motorBrake();
    AaruespError motorCoast();

    bool isConfigured() const;
    uint8_t getPin() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _pin;
    uint8_t _mode;
    AaruespError _err;

    uint8_t _rgb_pins[3];
    uint8_t _buzzer_pin;

    uint8_t _motor_in1, _motor_in2, _motor_en;
    bool _motor_en_pwm;
    int _motor_speed;

#if defined(ARDUINO) && AARUESP_HAS_SERVO
    class Servo _servo;
#endif
    uint8_t _servo_pin;
    int _servo_min_us;
    int _servo_max_us;
    int _servo_angle;
    bool _servo_attached;
};

#endif // AARUESP_PWM_ENGINE_H
