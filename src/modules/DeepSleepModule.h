#pragma once

#include <AaruEspModule.h>

class DeepSleepModule : public aru::Module {
public:
    DeepSleepModule();
    bool init() override;
    void update() override;
    const char* wakeReason();
    void sleepSeconds(uint32_t seconds);
    void sleepMicroseconds(uint64_t microseconds);
    void enableTimerWakeup(uint64_t microseconds);
    void enableExt0Wakeup(uint8_t gpio, uint8_t level);
    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    std::string type_ = "special.deepsleep";
    bool initialized_{false};
};