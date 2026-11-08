#pragma once

#include <AaruEspModule.h>

class EEPROMModule : public aru::Module {
public:
    EEPROMModule(size_t size = 512);
    bool init() override;
    void update() override;
    bool writeUInt32(const char* key, uint32_t value);
    uint32_t readUInt32(const char* key, uint32_t defaultValue = 0);
    bool writeString(const char* key, const char* value);
    bool readString(const char* key, char* buf, size_t bufSize, const char* defaultValue = "");
    bool commit();
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    size_t size_;
    bool initialized_{false};
    std::string type_ = "storage.eeprom";
};