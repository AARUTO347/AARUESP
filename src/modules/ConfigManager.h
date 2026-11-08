#pragma once

#include <AaruEspModule.h>
#include <SPIFFS.h>
#include <map>
#include <string>

/**
 * @brief Configuration Manager Module
 * Simple key=value config file management on SPIFFS/LittleFS.
 * No external dependencies.
 */
class ConfigManager : public aru::Module {
public:
    ConfigManager(const char* configPath = "/config.txt");
    bool init() override;
    void update() override;

    bool load();
    bool save();
    bool exists() const;

    // Getters
    String getString(const char* key, const char* defaultValue = "");
    int getInt(const char* key, int defaultValue = 0);
    float getFloat(const char* key, float defaultValue = 0.0f);
    bool getBool(const char* key, bool defaultValue = false);

    // Setters
    void setString(const char* key, const char* value);
    void setInt(const char* key, int value);
    void setFloat(const char* key, float value);
    void setBool(const char* key, bool value);

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_ && loaded_; }

private:
    const char* configPath_;
    std::string type_ = "special.config";
    bool initialized_{false};
    bool loaded_{false};
    std::map<std::string, std::string> values_;
};