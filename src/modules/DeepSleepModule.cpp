#include "DeepSleepModule.h"
#include <Arduino.h>

DeepSleepModule::DeepSleepModule() {}

bool DeepSleepModule::init() {
    initialized_ = true;
    return true;
}

void DeepSleepModule::update() {}

const char* DeepSleepModule::wakeReason() {
#if defined(ESP32)
    esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();
    switch (cause) {
        case ESP_SLEEP_WAKEUP_TIMER: return "timer";
        case ESP_SLEEP_WAKEUP_EXT0: return "ext0";
        case ESP_SLEEP_WAKEUP_EXT1: return "ext1";
        case ESP_SLEEP_WAKEUP_TOUCHPAD: return "touch";
        case ESP_SLEEP_WAKEUP_UNDEFINED: return "undefined";
        default: return "unknown";
    }
#elif defined(ESP8266)
    return "reset";
#else
    return "unknown";
#endif
}

void DeepSleepModule::sleepSeconds(uint32_t seconds) {
    sleepMicroseconds((uint64_t)seconds * 1000000ULL);
}

void DeepSleepModule::sleepMicroseconds(uint64_t microseconds) {
#if defined(ESP32)
    esp_sleep_enable_timer_wakeup(microseconds);
    esp_deep_sleep_start();
#elif defined(ESP8266)
    ESP.deepSleep(microseconds);
#endif
}

void DeepSleepModule::enableTimerWakeup(uint64_t microseconds) {
#if defined(ESP32)
    esp_sleep_enable_timer_wakeup(microseconds);
#endif
}

void DeepSleepModule::enableExt0Wakeup(uint8_t gpio, uint8_t level) {
#if defined(ESP32)
    esp_sleep_enable_ext0_wakeup((gpio_num_t)gpio, level);
#endif
}