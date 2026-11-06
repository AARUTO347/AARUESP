// ============================================================
//  AARUESP 1-Wire Engine
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_ONEWIRE_ENGINE_H
#define AARUESP_ONEWIRE_ENGINE_H

#include "AARUESPTypes.h"
#include "AARUESPBoard.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

typedef struct {
    uint8_t family;
    uint8_t serial[6];
    uint8_t crc;
} AaruOneWireROM;

typedef struct {
    uint8_t last_discrepancy;
    uint8_t last_family_discrepancy;
    bool last_device_flag;
} AaruOneWireSearchState;

class AaruOneWireEngine {
public:
    AaruOneWireEngine() = default;

    AaruespError begin(uint8_t pin);
    void setTimeoutUs(uint32_t us);

    bool reset();
    bool resetSearch();

    AaruespError readROM(AaruOneWireROM* rom);
    AaruespError matchROM(const AaruOneWireROM* rom);
    AaruespError skipROM();
    AaruespError searchROM(AaruOneWireROM* rom, AaruOneWireSearchState* state);

    uint8_t readByte();
    void writeByte(uint8_t byte);
    void readBytes(uint8_t* buf, uint16_t len);
    void writeBytes(const uint8_t* buf, uint16_t len);

    uint8_t readBit();
    void writeBit(uint8_t bit);

    static uint8_t crc8(const uint8_t* data, uint8_t len);
    static bool checkCRC(const AaruOneWireROM* rom);

    int discover(AaruOneWireROM* roms, int max_devices);

    AaruespError ds18b20Convert(const AaruOneWireROM* rom);
    AaruespError ds18b20ReadScratchpad(const AaruOneWireROM* rom, uint8_t* scratchpad);
    float ds18b20ReadTempC(const AaruOneWireROM* rom);
    AaruespError ds18b20SetResolution(const AaruOneWireROM* rom, uint8_t resolution);
    AaruespError ds18b20SetAlarms(const AaruOneWireROM* rom, int8_t th, int8_t tl);

    bool isBegun() const;
    uint8_t getPin() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _begun;
    uint8_t _pin;
    uint32_t _timeout_us;
    AaruespError _err;

    void write1();
    void write0();
    uint8_t readBitRaw();
    void delayUs(uint32_t us);
};

#endif // AARUESP_ONEWIRE_ENGINE_H
