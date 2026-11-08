#pragma once

#include <AaruEspModule.h>

class StepperModule : public aru::Module {
public:
    StepperModule(uint8_t stepPin, uint8_t dirPin, uint8_t enablePin = 255);
    bool init() override;
    void update() override;
    void setStepsPerRevolution(uint16_t steps);
    void setSpeedRPM(float rpm);
    void moveSteps(int32_t steps);
    void moveTo(int32_t absolutePos);
    void stop();
    int32_t getCurrentPosition() const { return currentPos_; }
    bool isMoving() const;
    bool isHealthy() const override { return initialized_; }
    const std::string& getType() const override { return type_; }

private:
    uint8_t stepPin_;
    uint8_t dirPin_;
    uint8_t enablePin_;
    uint16_t stepsPerRev_{200};
    float speedRPM_{60.0f};
    int32_t targetPos_{0};
    int32_t currentPos_{0};
    bool moving_{false};
    bool initialized_{false};
    unsigned long lastStep_{0};
    unsigned long stepInterval_{0};
    std::string type_ = "actuator.stepper";
};