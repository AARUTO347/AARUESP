#pragma once

#include <AaruEspModule.h>
#include <SPIFFS.h>
#include <LittleFS.h>
#include <SD.h>
#include <Preferences.h>

/**
 * @brief Storage Manager Module
 * Unified interface for SPIFFS, LittleFS, SD, NVS, and EEPROM.
 */
class StorageManager : public aru::Module {
public:
    StorageManager();
    bool init() override;
    void update() override;

    bool mountSPIFFS();
    bool mountLittleFS();
    bool mountSD(uint8_t csPin);
    bool mountNVS(const char* ns);

    bool writeFile(const char* path, const char* content);
    String readFile(const char* path);
    bool deleteFile(const char* path);
    bool exists(const char* path);
    size_t getFileSize(const char* path);
    size_t getTotalSpace();
    size_t getUsedSpace();
    size_t getFreeSpace();

    // NVS (Preferences)
    bool nvsWrite(const char* key, const char* value);
    String nvsRead(const char* key, const char* defaultValue = "");
    bool nvsWriteInt(const char* key, int value);
    int nvsReadInt(const char* key, int defaultValue = 0);

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    std::string type_ = "storage.manager";
    bool initialized_{false};
    bool spiffsMounted_{false};
    bool littlefsMounted_{false};
    bool sdMounted_{false};
    Preferences prefs_;
};