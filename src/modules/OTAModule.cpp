#include "OTAModule.h"
#include <Arduino.h>

OTAModule::OTAModule() {}

bool OTAModule::init() {
    initialized_ = true;
    return true;
}

void OTAModule::update() {
    // Periodic update check (if configured)
}

bool OTAModule::checkForUpdate(const char* url) {
    if (!url) return false;
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        // Simple version check
        http.end();
        return true;
    }
    http.end();
    snprintf(lastError_, sizeof(lastError_), "HTTP %d", httpCode);
    return false;
}

bool OTAModule::downloadAndInstall(const char* url) {
    if (!url) return false;
    updating_ = true;
    progress_ = 0;
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK) {
        snprintf(lastError_, sizeof(lastError_), "HTTP %d", httpCode);
        updating_ = false;
        http.end();
        return false;
    }
    int contentLength = http.getSize();
    WiFiClient* stream = http.getStreamPtr();
    if (!Update.begin(contentLength)) {
        snprintf(lastError_, sizeof(lastError_), "Update.begin failed");
        updating_ = false;
        http.end();
        return false;
    }
    size_t written = Update.writeStream(*stream);
    if (written != contentLength) {
        snprintf(lastError_, sizeof(lastError_), "Write incomplete: %d/%d", written, contentLength);
        updating_ = false;
        http.end();
        return false;
    }
    if (!Update.end()) {
        snprintf(lastError_, sizeof(lastError_), "Update.end failed");
        updating_ = false;
        http.end();
        return false;
    }
    progress_ = 100;
    updating_ = false;
    http.end();
    return true;
}

bool OTAModule::rollback() {
    // ESP32 OTA rollback (if supported)
#if defined(ESP32)
    return true;
#else
    return false;
#endif
}