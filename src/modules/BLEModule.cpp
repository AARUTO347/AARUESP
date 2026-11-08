#include "BLEModule.h"
#include <Arduino.h>

BLEModule::BLEModule(const char* deviceName) : deviceName_(deviceName) {}

bool BLEModule::init() {
#if defined(ESP32)
    BLEDevice::init(deviceName_);
    // Create server, service, characteristic
    initialized_ = true;
    return true;
#else
    return false; // BLE not available on ESP8266
#endif
}

void BLEModule::update() {
#if defined(ESP32)
    // Handle BLE events
#endif
}

void BLEModule::setServiceUUID(const char* uuid) {}
void BLEModule::setCharacteristicUUID(const char* uuid) {}
void BLEModule::setValue(const char* value) {}
void BLEModule::notify() {}
bool BLEModule::isConnected() const { return false; }