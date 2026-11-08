#pragma once

#include <AaruEspModule.h>

class MQ7Module : public aru::Module {
public:
    MQ7Module(uint8_t analogPin, float vRef = 3.3f);
    bool init() override;
    void update() override;
    float readCOppm();
    float readRaw();
    float readVoltage();
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override;

private:
    uint8_t analogPin_;
    float vRef_;
    float ro_{10000.0f};
    float coPpm_{0};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    std::string type_ = "sensor.mq7";
    static constexpr unsigned long READ_INTERVAL_{1000};
};