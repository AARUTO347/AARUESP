// ============================================================
//  AARUESP — Class-Style Module Base (Module Instance API)
//  MADE BY AARUTO
//
//  The class-style module API is the "modern instance" counterpart
//  to the AARUESP singleton API. Include AARUESP_MODULES.h to get both.
//
//    #include <AARUESP_MODULES.h>
//    BME280Module bme(21, 22);   // your own sensor instance
//    bme.init();
//    bme.update();
//
//  aru::Module is the base class for all class-style modules.
// ============================================================
#ifndef AARUESP_ESP_MODULE_H
#define AARUESP_ESP_MODULE_H

#include <Arduino.h>
#include <Wire.h>
#include <string>
#include <map>
#include <vector>
#include <functional>

// ---- Debug macros (independent from the singleton core) ----
#ifndef AARUESP_DEBUG
#define AARUESP_DEBUG 0
#endif

#if AARUESP_DEBUG
#define AARUESP_DEBUG_PRINT(x) Serial.print(x)
#define AARUESP_DEBUG_PRINTLN(x) Serial.println(x)
#else
#define AARUESP_DEBUG_PRINT(x)
#define AARUESP_DEBUG_PRINTLN(x)
#endif

namespace aru {

class Module {
public:
    Module();
    virtual ~Module();

    /** Initialize the module */
    virtual bool init() = 0;

    /** Update module state periodically */
    virtual void update() = 0;

    /** Get the internal module name */
    const std::string& getName() const;

    /** Set internal module name */
    void setName(const std::string& name);

    /** Type identifier string, e.g. "sensor.bme280" */
    virtual const std::string& getType() const = 0;

    /** True once init() has succeeded */
    bool isInitialized() const;

    /** True if module is operating normally */
    virtual bool isHealthy() const;

protected:
    std::string name_;
    bool initialized_;
    bool healthy_;
};

} // namespace aru

#endif // AARUESP_ESP_MODULE_H