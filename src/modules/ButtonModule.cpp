#include "ButtonModule.h"

ButtonModule::ButtonModule(uint8_t gpioPin, PullMode pull, uint16_t debounceMs, uint16_t holdMs)
    : gpioPin_(gpioPin), pull_(pull), debounceMs_(debounceMs), holdMs_(holdMs) {}

bool ButtonModule::init() {
    // Set up pin based on pull mode
    switch (pull_) {
        case PullMode::PULL_UP:
            pinMode(gpioPin_, INPUT_PULLUP);
            lastState_ = HIGH;
            lastDebounced_ = HIGH;
            break;
        case PullMode::PULL_DOWN:
            pinMode(gpioPin_, INPUT_PULLDOWN);
            lastState_ = LOW;
            lastDebounced_ = LOW;
            break;
        case PullMode::FLOATING:
        default:
            pinMode(gpioPin_, INPUT);
            lastState_ = digitalRead(gpioPin_);
            lastDebounced_ = lastState_;
            break;
    }

    initialized_ = true;
    healthy_ = true;
    AARUESP_DEBUG_PRINTLN("[Button] Module initialized on GPIO " + String(gpioPin_));
    return true;
}

void ButtonModule::update() {
    if (!initialized_) return;

    bool rawState;
    switch (pull_) {
        case PullMode::PULL_UP:
            rawState = digitalRead(gpioPin_);
            break;
        case PullMode::PULL_DOWN:
            rawState = !digitalRead(gpioPin_); // Invert for PULL_DOWN
            break;
        case PullMode::FLOATING:
        default:
            rawState = digitalRead(gpioPin_);
            break;
    }

    unsigned long now = millis();

    // Debouncing
    if (rawState != lastDebounced_) {
        if (now - lastChange_ > debounceMs_) {
            lastDebounced_ = rawState;
            lastChange_ = now;

            // State changed
            if (rawState != lastState_) {
                lastState_ = rawState;

                // Falling edge (button pressed for PULL_UP, released for PULL_DOWN)
                bool pressed = (pull_ == PullMode::PULL_UP) ? (rawState == LOW) : (rawState == HIGH);

                if (pressed) {
                    pressStart_ = now;
                    justPressed_ = true;
                    justReleased_ = false;
                } else {
                    justReleased_ = true;
                    justPressed_ = false;

                    // Check for hold
                    if (holdStart_ > 0 && (now - holdStart_ > holdMs_)) {
                        // Trigger HOLD event
                        holdStart_ = 0;
                    }
                }
            }
        }
    }

    // Hold detection
    if (lastState_ == (pull_ == PullMode::PULL_UP ? LOW : HIGH) && holdStart_ == 0) {
        holdStart_ = now;
    } else if (lastState_ != (pull_ == PullMode::PULL_UP ? LOW : HIGH) && holdStart_ > 0) {
        holdStart_ = 0;
    }

    // Click detection
    if (justPressed_) {
        justPressed_ = false;
    }
    if (justReleased_) {
        justReleased_ = false;
        // Check for double/triple click
        if (now - lastClick_ < 500) { // Double-click window
            clickCount_++;
        } else {
            // Single click
            clickCount_ = 1;
        }
        lastClick_ = now;
    }
}

ButtonModule::ButtonState ButtonModule::getState() const {
    return ButtonState::RELEASED; // Simplified - full impl would track all states
}

bool ButtonModule::wasPressed() {
    bool result = justPressed_;
    justPressed_ = false;
    return result;
}

bool ButtonModule::wasReleased() {
    bool result = justReleased_;
    justReleased_ = false;
    return result;
}

bool ButtonModule::isHeld() const {
    return false; // Simplified hold check
}

int ButtonModule::getClicks() {
    int result = clickCount_;
    clickCount_ = 0;
    return result;
}

void ButtonModule::resetClicks() {
    clickCount_ = 0;
}

bool ButtonModule::isHealthy() const {
    return initialized_;
}
