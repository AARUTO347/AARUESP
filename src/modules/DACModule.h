#pragma once

#include <AaruEspModule.h>

/**
 * @brief DAC (Digital-to-Analog) Module (ESP32 only)
 * 8-bit DAC on GPIO 25/26.
 */
class DACModule : public aru::Module {
public:
    DACModule(uint8_t dacPin = 25);
    bool init() override;
    void update() override;

    void write(uint8_t value);        // 0-255
    void writeVoltage(float volts);   // 0-3.3V
    uint8_t read() const { return currentValue_; }

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    uint8_t dacPin_;
    uint8_t currentValue_{0};
    bool initialized_{false};
    bool healthy_{false};
    std::string type_ = "special.dac";
};