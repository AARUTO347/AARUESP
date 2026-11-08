#include "PSRAMModule.h"
#include <Arduino.h>

PSRAMModule::PSRAMModule() {}

bool PSRAMModule::init() {
#if defined(ESP32)
    psramAvailable_ = psramFound();
    if (psramAvailable_) {
        psramSize_ = ESP.getPsramSize();
    }
    initialized_ = true;
    return true;
#else
    return false;
#endif
}

void PSRAMModule::update() {}

bool PSRAMModule::isAvailable() const { return psramAvailable_; }
size_t PSRAMModule::getSize() const { return psramSize_; }
size_t PSRAMModule::getFreeSize() const {
#if defined(ESP32)
    return ESP.getFreePsram();
#else
    return 0;
#endif
}
size_t PSRAMModule::getUsedSize() const {
    return psramSize_ - getFreeSize();
}

void* PSRAMModule::allocate(size_t size) {
#if defined(ESP32)
    if (psramAvailable_) {
        return ps_malloc(size);
    }
#endif
    return malloc(size);
}

void PSRAMModule::deallocate(void* ptr) {
    free(ptr);
}