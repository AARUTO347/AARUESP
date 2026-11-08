#include "SHT30Module.h"
#include <Arduino.h>

SHT30Module::SHT30Module(uint8_t sda, uint8_t scl, uint8_t addr)
    : sda_(sda), scl_(scl), addr_(addr) {}

bool SHT30Module::init() {
    Wire.begin(sda_, scl_);
    Wire.beginTransmission(addr_);
    Wire.write(0x30);
    Wire.write(0x2A);
    Wire.endTransmission();
    delay(10);
    initialized_ = true;
    healthy_ = true;
    sensorPresent_ = true;
    return true;
}

void SHT30Module::update() {
    if (!initialized_ || (millis() - lastRead_ < READ_INTERVAL_)) return;
    if (readMeasurement(temperature_, humidity_)) {
        healthy_ = true;
        sensorPresent_ = true;
    } else {
        healthy_ = false;
        sensorPresent_ = false;
    }
    lastRead_ = millis();
}

float SHT30Module::readTemperature() { return temperature_; }
float SHT30Module::readHumidity() { return humidity_; }

bool SHT30Module::readMeasurement(float& temp, float& hum) {
    Wire.beginTransmission(addr_);
    Wire.write(0x2C);
    Wire.write(0x06);
    if (Wire.endTransmission() != 0) return false;
    delay(50);
    Wire.requestFrom(addr_, 6);
    if (Wire.available() < 6) return false;
    uint8_t data[6];
    for (int i = 0; i < 6; i++) data[i] = Wire.read();
    uint16_t rawT = ((uint16_t)data[0] << 8) | data[1];
    if (crc8(&data[0], 2) != data[2]) return false;
    temp = -45.0f + 175.0f * (rawT / 65535.0f);
    uint16_t rawH = ((uint16_t)data[3] << 8) | data[4];
    if (crc8(&data[3], 2) != data[5]) return false;
    hum = 100.0f * (rawH / 65535.0f);
    return true;
}

uint8_t SHT30Module::crc8(const uint8_t* data, uint8_t len) {
    uint8_t crc = 0xFF;
    for (uint8_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t bit = 8; bit > 0; bit--) {
            if (crc & 0x80) crc = (crc << 1) ^ 0x31;
            else crc = (crc << 1);
        }
    }
    return crc;
}

bool SHT30Module::isHealthy() const {
    return initialized_ && healthy_ && sensorPresent_;
}