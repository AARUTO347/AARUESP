#include "StepperModule.h"
#include <Arduino.h>

StepperModule::StepperModule(uint8_t stepPin, uint8_t dirPin, uint8_t enablePin)
    : stepPin_(stepPin), dirPin_(dirPin), enablePin_(enablePin) {}

bool StepperModule::init() {
    pinMode(stepPin_, OUTPUT);
    pinMode(dirPin_, OUTPUT);
    if (enablePin_ != 255) pinMode(enablePin_, OUTPUT);
    digitalWrite(stepPin_, LOW);
    digitalWrite(dirPin_, LOW);
    if (enablePin_ != 255) digitalWrite(enablePin_, HIGH);
    initialized_ = true;
    return true;
}

void StepperModule::update() {
    if (!initialized_ || !moving_) return;
    if (currentPos_ == targetPos_) {
        moving_ = false;
        return;
    }
    unsigned long now = millis();
    if (now - lastStep_ < stepInterval_) return;
    bool forward = targetPos_ > currentPos_;
    digitalWrite(dirPin_, forward ? HIGH : LOW);
    digitalWrite(stepPin_, HIGH);
    delayMicroseconds(50);
    digitalWrite(stepPin_, LOW);
    currentPos_ += forward ? 1 : -1;
    lastStep_ = now;
}

void StepperModule::setStepsPerRevolution(uint16_t steps) { stepsPerRev_ = steps; }
void StepperModule::setSpeedRPM(float rpm) {
    speedRPM_ = rpm;
    float stepsPerSec = rpm * stepsPerRev_ / 60.0f;
    stepInterval_ = stepsPerSec > 0 ? (unsigned long)(1000000.0f / stepsPerSec) : 1000;
}
void StepperModule::moveSteps(int32_t steps) {
    targetPos_ = currentPos_ + steps;
    moving_ = true;
    if (enablePin_ != 255) digitalWrite(enablePin_, LOW);
}
void StepperModule::moveTo(int32_t absolutePos) {
    targetPos_ = absolutePos;
    moving_ = true;
    if (enablePin_ != 255) digitalWrite(enablePin_, LOW);
}
void StepperModule::stop() { moving_ = false; }
bool StepperModule::isMoving() const { return moving_; }