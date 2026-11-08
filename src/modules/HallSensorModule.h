#pragma once

#include <AaruEspModule.h>

class HallSensorModule : public aru::Module {
public:
    HallSensorModule();
    bool init() override;
    void update() override;
    int16_t readRaw();
    float readGauss();
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override;

private:
    std::string type_ = "special.hall";
    int16_t rawValue_{0};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    static constexpr unsigned long READ_INTERVAL_{100};
};