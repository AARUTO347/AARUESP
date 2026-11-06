// ============================================================
//  AARUESP BH1750 Light Sensor Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_BH1750_H
#define AARUESP_BH1750_H

#include "AARUESPTypes.h"
#include "engines/AaruI2CEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define BH1750_ADDR_LOW   0x23
#define BH1750_ADDR_HIGH  0x5C

typedef enum {
    BH1750_CONT_H_RES   = 0x10,
    BH1750_CONT_H_RES2  = 0x11,
    BH1750_CONT_L_RES   = 0x13,
    BH1750_ONE_H_RES    = 0x20,
    BH1750_ONE_H_RES2   = 0x21,
    BH1750_ONE_L_RES    = 0x23,
} BH1750Mode;

class AaruBH1750 {
public:
    AaruBH1750() = default;

    AaruespError begin(uint8_t addr);
    AaruespError begin(class AaruI2CEngine* i2c, uint8_t addr);

    bool read(float& lux);
    float readLux();

    AaruespError setMode(BH1750Mode mode);
    AaruespError setMTreg(uint8_t mtreg);

    AaruespError powerOn();
    AaruespError powerOff();
    AaruespError reset();

    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _addr;
    class AaruI2CEngine* _i2c;
    bool _own_i2c;
    int _mode;
    AaruespError _err;

    AaruespError writeCmd(uint8_t cmd);
};

#endif // AARUESP_BH1750_H
