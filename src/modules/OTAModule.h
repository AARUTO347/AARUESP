#pragma once

#include <AaruEspModule.h>
#include <WiFi.h>
#include <Update.h>
#include <HTTPClient.h>

/**
 * @brief OTA (Over-The-Air) Firmware Update Module
 * Supports HTTP-based firmware updates with rollback.
 */
class OTAModule : public aru::Module {
public:
    OTAModule();
    bool init() override;
    void update() override;

    bool checkForUpdate(const char* url);
    bool downloadAndInstall(const char* url);
    bool rollback();
    const char* getLastError() const { return lastError_; }
    float getProgress() const { return progress_; }
    bool isUpdating() const { return updating_; }

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    std::string type_ = "special.ota";
    bool initialized_{false};
    bool updating_{false};
    float progress_{0};
    char lastError_[128] = {0};
    unsigned long lastCheck_{0};
    static constexpr unsigned long CHECK_INTERVAL_{3600000}; // 1 hour
};