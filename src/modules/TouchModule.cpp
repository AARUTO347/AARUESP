#include "TouchModule.h"
#include <Arduino.h>

TouchModule::TouchModule(uint8_t touchPin, uint16_t threshold)
    : touchPin_(touchPin), threshold_(threshold) {}

bool TouchModule::init() {
#if defined(ESP32)
    initialized_ = true;
    return true;
#else
    return false;
#endif
}

void TouchModule::update() {
    if (!initialized_) return;
#if defined(ESP32)
    rawValue_ = touchRead(touchPin_);
    touched_ = (rawValue_ < threshold_);
#endif
    lastRead_ = millis();
    healthy_ = true;
}

uint16_t TouchModule::readRaw() { return rawValue_; }