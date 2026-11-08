#include "VL53L0XModule.h"
#include <Arduino.h>

VL53L0XModule::VL53L0XModule(uint8_t sda, uint8_t scl, uint8_t addr)
    : sda_(sda), scl_(scl), addr_(addr) {}

bool VL53L0XModule::init() {
    Wire.begin(sda_, scl_);
    Wire.beginTransmission(addr_);
    if (Wire.endTransmission() != 0) {
        sensorPresent_ = false;
        initialized_ = true;
        return false;
    }
    sensorPresent_ = true;
    initialized_ = true;
    healthy_ = true;
    return true;
}

void VL53L0XModule::update() {
    if (!initialized_ || (millis() - lastRead_ < READ_INTERVAL_)) return;
    Wire.beginTransmission(addr_);
    Wire.write(0x14);
    Wire.endTransmission(false);
    Wire.requestFrom(addr_, 2);
    if (Wire.available() >= 2) {
        distanceMm_ = (Wire.read() << 8) | Wire.read();
        healthy_ = true;
    }
    lastRead_ = millis();
}

uint16_t VL53L0XModule::readDistanceMM() { return distanceMm_; }
float VL53L0XModule::readDistanceCM() { return distanceMm_ / 10.0f; }

bool VL53L0XModule::isHealthy() const {
    return initialized_ && healthy_ && sensorPresent_;
}