#include "GPSModule.h"
#include <Arduino.h>

#if defined(ESP32)
#include <HardwareSerial.h>
#define AARUESP_GPS_SERIAL Serial2
#elif defined(ESP8266)
#include <SoftwareSerial.h>
#endif

GPSModule::GPSModule(uint8_t rxPin, uint8_t txPin, uint32_t baud)
    : rxPin_(rxPin), txPin_(txPin), baud_(baud) {}

bool GPSModule::init() {
#if defined(ESP32)
    AARUESP_GPS_SERIAL.begin(baud_, SERIAL_8N1, rxPin_, txPin_);
#elif defined(ESP8266)
    // ESP8266 has a single hardware UART (Serial, used by the USB bridge).
    // Swap it so the GPS module can use it on the requested pins.
    Serial.swap();
    Serial.begin(baud_);
#endif
    initialized_ = true;
    return true;
}

void GPSModule::update() {
    if (!initialized_) return;
#if defined(ESP32)
    while (AARUESP_GPS_SERIAL.available()) {
        char c = AARUESP_GPS_SERIAL.read();
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
#elif defined(ESP8266)
    while (Serial.available()) {
        char c = Serial.read();
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
#endif
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