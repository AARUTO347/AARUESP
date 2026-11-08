#include "GPSModule.h"
#include <Arduino.h>

GPSModule::GPSModule(uint8_t rxPin, uint8_t txPin, uint32_t baud)
    : rxPin_(rxPin), txPin_(txPin), baud_(baud) {}

bool GPSModule::init() {
    Serial2.begin(baud_, SERIAL_8N1, rxPin_, txPin_);
    initialized_ = true;
    return true;
}

void GPSModule::update() {
    if (!initialized_) return;
    while (Serial2.available()) {
        char c = Serial2.read();
        static char buf[100];
        static int idx = 0;
        if (c == '$') idx = 0;
        if (idx < 99) buf[idx++] = c;
        if (c == '\n' && idx > 0) {
            buf[idx] = 0;
            if (strstr(buf, "GPGGA") || strstr(buf, "GNGGA")) parseNMEA(buf);
            idx = 0;
        }
    }
    lastRead_ = millis();
    healthy_ = true;
}

float GPSModule::readLatitude() { return latitude_; }
float GPSModule::readLongitude() { return longitude_; }
float GPSModule::readAltitude() { return altitude_; }
float GPSModule::readSpeedKnots() { return speedKnots_; }
uint8_t GPSModule::readSatellites() { return satellites_; }

void GPSModule::parseNMEA(const char* sentence) {
    fix_ = strstr(sentence, ",1,") != nullptr || strstr(sentence, ",2,") != nullptr;
}

bool GPSModule::isHealthy() const {
    return initialized_ && healthy_;
}