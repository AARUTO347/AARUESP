#pragma once

#include <AaruEspModule.h>
#include <Wire.h>

class VL53L0XModule : public aru::Module {
public:
    VL53L0XModule(uint8_t sda = 21, uint8_t scl = 22, uint8_t addr = 0x29);
    bool init() override;
    void update() override;
    uint16_t readDistanceMM();
    float readDistanceCM();
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override;

private:
    uint8_t sda_;
    uint8_t scl_;
    uint8_t addr_;
    std::string type_ = "sensor.vl53l0x";
    uint16_t distanceMm_{0};
    bool sensorPresent_{false};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    static constexpr unsigned long READ_INTERVAL_{100};
};