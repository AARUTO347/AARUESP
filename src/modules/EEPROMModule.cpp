#include "EEPROMModule.h"
#include <EEPROM.h>
#include <Arduino.h>

EEPROMModule::EEPROMModule(size_t size) : size_(size) {}

bool EEPROMModule::init() {
#if defined(ESP32)
    if (!EEPROM.begin(size_)) return false;
#elif defined(ESP8266)
    EEPROM.begin(size_);
#endif
    initialized_ = true;
    return true;
}

void EEPROMModule::update() {}

bool EEPROMModule::writeUInt32(const char* key, uint32_t value) {
    if (!initialized_) return false;
    uint16_t addr = 0;
    for (const char* p = key; *p; p++) addr = (addr * 31 + *p) % (size_ - 4);
    for (int i = 0; i < 4; i++) EEPROM.write(addr + i, (value >> (i * 8)) & 0xFF);
    return true;
}

uint32_t EEPROMModule::readUInt32(const char* key, uint32_t defaultValue) {
    if (!initialized_) return defaultValue;
    uint16_t addr = 0;
    for (const char* p = key; *p; p++) addr = (addr * 31 + *p) % (size_ - 4);
    uint32_t value = 0;
    for (int i = 0; i < 4; i++) value |= ((uint32_t)EEPROM.read(addr + i) << (i * 8));
    return value;
}

bool EEPROMModule::writeString(const char* key, const char* value) {
    if (!initialized_) return false;
    uint16_t addr = 0;
    for (const char* p = key; *p; p++) addr = (addr * 31 + *p) % (size_ - 16);
    size_t len = strlen(value);
    if (addr + len + 1 > size_) return false;
    EEPROM.write(addr, len);
    for (size_t i = 0; i < len; i++) EEPROM.write(addr + 1 + i, value[i]);
    EEPROM.write(addr + 1 + len, 0);
    return true;
}

bool EEPROMModule::readString(const char* key, char* buf, size_t bufSize, const char* defaultValue) {
    if (!initialized_) { strncpy(buf, defaultValue, bufSize - 1); buf[bufSize - 1] = 0; return false; }
    uint16_t addr = 0;
    for (const char* p = key; *p; p++) addr = (addr * 31 + *p) % (size_ - 16);
    size_t len = EEPROM.read(addr);
    if (len >= bufSize) len = bufSize - 1;
    for (size_t i = 0; i < len; i++) buf[i] = EEPROM.read(addr + 1 + i);
    buf[len] = 0;
    return true;
}

bool EEPROMModule::commit() {
#if defined(ESP32)
    return EEPROM.commit();
#elif defined(ESP8266)
    return EEPROM.commit();
#else
    return true;
#endif
}