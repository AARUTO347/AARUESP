#pragma once

#include <AaruEspModule.h>
#include <Wire.h>

class SHT30Module : public aru::Module {
public:
    SHT30Module(uint8_t sda = 21, uint8_t scl = 22, uint8_t addr = 0x44);
    bool init() override;
    void update() override;
    float readTemperature();
    float readHumidity();
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override;

private:
    bool readMeasurement(float& temp, float& hum);
    uint8_t crc8(const uint8_t* data, uint8_t len);

    uint8_t sda_;
    uint8_t scl_;
    uint8_t addr_;
    std::string type_ = "sensor.sht30";
    float temperature_{0};
    float humidity_{0};
    bool sensorPresent_{false};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    static constexpr unsigned long READ_INTERVAL_{1000};
};