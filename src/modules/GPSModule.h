#pragma once

#include <AaruEspModule.h>

class GPSModule : public aru::Module {
public:
    GPSModule(uint8_t rxPin, uint8_t txPin, uint32_t baud = 9600);
    bool init() override;
    void update() override;
    float readLatitude();
    float readLongitude();
    float readAltitude();
    float readSpeedKnots();
    uint8_t readSatellites();
    bool hasFix() const { return fix_; }
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override;

private:
    void parseNMEA(const char* sentence);
    uint8_t rxPin_;
    uint8_t txPin_;
    uint32_t baud_;
    std::string type_ = "uart.gps";
    float latitude_{0};
    float longitude_{0};
    float altitude_{0};
    float speedKnots_{0};
    uint8_t satellites_{0};
    bool fix_{false};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    static constexpr unsigned long READ_INTERVAL_{1000};
};