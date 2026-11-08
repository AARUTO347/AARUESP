#include "StorageManager.h"
#include <Arduino.h>

StorageManager::StorageManager() {}

bool StorageManager::init() {
    initialized_ = true;
    return true;
}

void StorageManager::update() {}

bool StorageManager::mountSPIFFS() {
#if defined(ESP32) || defined(ESP8266)
    spiffsMounted_ = SPIFFS.begin(true);
    return spiffsMounted_;
#else
    return false;
#endif
}

bool StorageManager::mountLittleFS() {
#if defined(ESP32) || defined(ESP8266)
    littlefsMounted_ = LittleFS.begin(true);
    return littlefsMounted_;
#else
    return false;
#endif
}

bool StorageManager::mountSD(uint8_t csPin) {
    sdMounted_ = SD.begin(csPin);
    return sdMounted_;
}

bool StorageManager::mountNVS(const char* ns) {
    return prefs_.begin(ns, false);
}

bool StorageManager::writeFile(const char* path, const char* content) {
    File f = SPIFFS.open(path, "w");
    if (!f) return false;
    f.print(content);
    f.close();
    return true;
}

String StorageManager::readFile(const char* path) {
    File f = SPIFFS.open(path, "r");
    if (!f) return "";
    String content = f.readString();
    f.close();
    return content;
}

bool StorageManager::deleteFile(const char* path) {
    return SPIFFS.remove(path);
}

bool StorageManager::exists(const char* path) {
    return SPIFFS.exists(path);
}

size_t StorageManager::getFileSize(const char* path) {
    File f = SPIFFS.open(path, "r");
    if (!f) return 0;
    size_t size = f.size();
    f.close();
    return size;
}

size_t StorageManager::getTotalSpace() {
#if defined(ESP32)
    return SPIFFS.totalBytes();
#else
    return 0;
#endif
}

size_t StorageManager::getUsedSpace() {
#if defined(ESP32)
    return SPIFFS.usedBytes();
#else
    return 0;
#endif
}

size_t StorageManager::getFreeSpace() {
    return getTotalSpace() - getUsedSpace();
}

bool StorageManager::nvsWrite(const char* key, const char* value) {
    prefs_.putString(key, value);
    return true;
}

String StorageManager::nvsRead(const char* key, const char* defaultValue) {
    return prefs_.getString(key, defaultValue);
}

bool StorageManager::nvsWriteInt(const char* key, int value) {
    prefs_.putInt(key, value);
    return true;
}

int StorageManager::nvsReadInt(const char* key, int defaultValue) {
    return prefs_.getInt(key, defaultValue);
}