#pragma once

#include <AaruEspModule.h>

/**
 * @brief Capacitive Touch Sensor Module (ESP32 only)
 * Reads touch pad values and detects touch events.
 */
class TouchModule : public aru::Module {
public:
    TouchModule(uint8_t touchPin, uint16_t threshold = 40);
    bool init() override;
    void update() override;

    uint16_t readRaw();
    bool isTouched() const { return touched_; }
    void setThreshold(uint16_t threshold) { threshold_ = threshold; }
    uint16_t getThreshold() const { return threshold_; }

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    uint8_t touchPin_;
    uint16_t threshold_;
    uint16_t rawValue_{0};
    bool touched_{false};
    bool initialized_{false};
    bool healthy_{false};
    unsigned long lastRead_{0};
    std::string type_ = "special.touch";
    static constexpr unsigned long READ_INTERVAL_{50};
};