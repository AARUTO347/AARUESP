#include "MQ7Module.h"
#include <Arduino.h>
#include <math.h>

MQ7Module::MQ7Module(uint8_t analogPin, float vRef)
    : analogPin_(analogPin), vRef_(vRef) {}

bool MQ7Module::init() {
    pinMode(analogPin_, INPUT);
    initialized_ = true;
    healthy_ = true;
    lastRead_ = millis();
    return true;
}

void MQ7Module::update() {
    if (!initialized_ || (millis() - lastRead_ < READ_INTERVAL_)) return;
    int raw = analogRead(analogPin_);
    float voltage = (raw / 1023.0f) * vRef_;
    float rs = ((vRef_ - voltage) / voltage) * 10000.0f;
    float ratio = rs / ro_;
    coPpm_ = 100.0f * powf(ratio, -1.5f);
    if (coPpm_ < 0) coPpm_ = 0;
    if (coPpm_ > 10000) coPpm_ = 10000;
    lastRead_ = millis();
    healthy_ = true;
}

float MQ7Module::readCOppm() { return coPpm_; }
float MQ7Module::readRaw() { return analogRead(analogPin_); }
float MQ7Module::readVoltage() { return (analogRead(analogPin_) / 1023.0f) * vRef_; }

bool MQ7Module::isHealthy() const {
    return initialized_ && healthy_;
}