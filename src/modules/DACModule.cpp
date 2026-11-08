#include "DACModule.h"
#include <Arduino.h>

DACModule::DACModule(uint8_t dacPin) : dacPin_(dacPin) {}

bool DACModule::init() {
#if defined(ESP32)
    if (dacPin_ != 25 && dacPin_ != 26) return false;
    initialized_ = true;
    return true;
#else
    return false;
#endif
}

void DACModule::update() {}

void DACModule::write(uint8_t value) {
#if defined(ESP32)
    dacWrite(dacPin_, value);
    currentValue_ = value;
#endif
}

void DACModule::writeVoltage(float volts) {
    uint8_t value = (uint8_t)((volts / 3.3f) * 255.0f);
    write(value);
}