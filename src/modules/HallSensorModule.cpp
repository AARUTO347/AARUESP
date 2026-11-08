#include "HallSensorModule.h"
#include <Arduino.h>

HallSensorModule::HallSensorModule() {}

bool HallSensorModule::init() {
#if defined(ESP32)
    initialized_ = true;
    return true;
#else
    return false;
#endif
}

void HallSensorModule::update() {
    if (!initialized_) return;
#if defined(ESP32)
    // ESP32 internal Hall sensor (available on most ESP32 variants)
    #if defined(hallRead)
    rawValue_ = hallRead();
    #else
    // Fallback: Hall sensor not available on this core variant
    rawValue_ = 0;
    #endif
#endif
    lastRead_ = millis();
    healthy_ = true;
}

int16_t HallSensorModule::readRaw() { return rawValue_; }
float HallSensorModule::readGauss() {
    return rawValue_ * 0.1f;
}

bool HallSensorModule::isHealthy() const {
    return initialized_ && healthy_;
}