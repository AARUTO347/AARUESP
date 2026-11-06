#include "AaruEspModule.h"

namespace aru {

Module::Module() : initialized_(false), healthy_(false) {}

Module::~Module() = default;

const std::string& Module::getName() const {
    return name_;
}

void Module::setName(const std::string& name) {
    name_ = name;
}

bool Module::isInitialized() const {
    return initialized_;
}

bool Module::isHealthy() const {
    return healthy_;
}

} // namespace aru