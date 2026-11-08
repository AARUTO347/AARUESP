#include "ConfigManager.h"
#include <Arduino.h>

ConfigManager::ConfigManager(const char* configPath) : configPath_(configPath) {}

bool ConfigManager::init() {
    initialized_ = true;
    return load();
}

void ConfigManager::update() {}

bool ConfigManager::load() {
    if (!SPIFFS.begin(true)) return false;
    File f = SPIFFS.open(configPath_, "r");
    if (!f) {
        loaded_ = false;
        return false;
    }
    values_.clear();
    while (f.available()) {
        String line = f.readStringUntil('\n');
        line.trim();
        if (line.length() == 0 || line.startsWith("#")) continue;
        int eq = line.indexOf('=');
        if (eq > 0) {
            String key = line.substring(0, eq);
            String val = line.substring(eq + 1);
            key.trim();
            val.trim();
            values_[key.c_str()] = val.c_str();
        }
    }
    f.close();
    loaded_ = true;
    return true;
}

bool ConfigManager::save() {
    File f = SPIFFS.open(configPath_, "w");
    if (!f) return false;
    for (auto& kv : values_) {
        f.print(kv.first.c_str());
        f.print("=");
        f.println(kv.second.c_str());
    }
    f.close();
    return true;
}

bool ConfigManager::exists() const {
    return SPIFFS.exists(configPath_);
}

String ConfigManager::getString(const char* key, const char* defaultValue) {
    auto it = values_.find(key);
    if (it != values_.end()) return String(it->second.c_str());
    return String(defaultValue);
}

int ConfigManager::getInt(const char* key, int defaultValue) {
    auto it = values_.find(key);
    if (it != values_.end()) return atoi(it->second.c_str());
    return defaultValue;
}

float ConfigManager::getFloat(const char* key, float defaultValue) {
    auto it = values_.find(key);
    if (it != values_.end()) return atof(it->second.c_str());
    return defaultValue;
}

bool ConfigManager::getBool(const char* key, bool defaultValue) {
    auto it = values_.find(key);
    if (it != values_.end()) {
        String val = it->second.c_str();
        val.toLowerCase();
        return val == "true" || val == "1" || val == "yes";
    }
    return defaultValue;
}

void ConfigManager::setString(const char* key, const char* value) {
    values_[key] = value;
}

void ConfigManager::setInt(const char* key, int value) {
    values_[key] = String(value).c_str();
}

void ConfigManager::setFloat(const char* key, float value) {
    values_[key] = String(value).c_str();
}

void ConfigManager::setBool(const char* key, bool value) {
    values_[key] = value ? "true" : "false";
}