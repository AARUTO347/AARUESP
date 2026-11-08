#pragma once

#include <AaruEspModule.h>

/**
 * @brief PSRAM (SPI RAM) Module for ESP32
 * Detects and manages external SPI RAM (PSRAM).
 */
class PSRAMModule : public aru::Module {
public:
    PSRAMModule();
    bool init() override;
    void update() override;

    bool isAvailable() const;
    size_t getSize() const;
    size_t getFreeSize() const;
    size_t getUsedSize() const;
    void* allocate(size_t size);
    void deallocate(void* ptr);

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    std::string type_ = "special.psram";
    bool initialized_{false};
    bool psramAvailable_{false};
    size_t psramSize_{0};
};