// ============================================================
//  AARUESP DS18B20 Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_DS18B20_H
#define AARUESP_DS18B20_H

#include "AARUESPTypes.h"
#include "engines/AaruOneWireEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

class AaruDS18B20 {
public:
    AaruDS18B20() = default;

    AaruespError begin(uint8_t pin);
    AaruespError begin(AaruOneWireEngine* ow, uint8_t pin);

    int discover();
    float readTempC(int index);
    float readTempC(const AaruOneWireROM* rom);
    float readTempF(int index);

    AaruespError requestTemperatures();
    bool conversionReady();
    float readTempCAsync(int index);

    AaruespError setResolution(int index, uint8_t bits);
    AaruespError setResolution(const AaruOneWireROM* rom, uint8_t bits);

    int alarmSearch(AaruOneWireROM* roms, int max);

    int deviceCount() const;
    const AaruOneWireROM* getROM(int index) const;
    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    AaruOneWireEngine* _ow;
    bool _own_ow;
    AaruOneWireROM _roms[16];
    int _count;
    unsigned long _last_convert;
    AaruespError _err;
};

#endif // AARUESP_DS18B20_H
