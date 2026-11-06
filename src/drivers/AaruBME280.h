// ============================================================
//  AARUESP BME280/BMP280 Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_BME280_H
#define AARUESP_BME280_H

#include "AARUESPTypes.h"
#include "engines/AaruI2CEngine.h"
#include "engines/AaruSPIEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define BME280_ADDR_PRIM  0x76
#define BME280_ADDR_SEC   0x77
#define BMP280_ADDR_PRIM  0x76
#define BMP280_ADDR_SEC   0x77

#define BME280_CHIP_ID    0x60
#define BMP280_CHIP_ID    0x58

typedef enum {
    BME280_MODE_SLEEP  = 0,
    BME280_MODE_FORCED = 1,
    BME280_MODE_NORMAL = 3
} BME280Mode;

typedef enum {
    BME280_OS_NONE = 0,
    BME280_OS_1X   = 1,
    BME280_OS_2X   = 2,
    BME280_OS_4X   = 3,
    BME280_OS_8X   = 4,
    BME280_OS_16X  = 5
} BME280Oversampling;

typedef enum {
    BME280_FILTER_OFF = 0,
    BME280_FILTER_2   = 1,
    BME280_FILTER_4   = 2,
    BME280_FILTER_8   = 3,
    BME280_FILTER_16  = 4
} BME280Filter;

struct AaruBME280Data {
    float temperature;
    float humidity;
    float pressure;
    float altitude;
};

class AaruBME280 {
public:
    AaruBME280() = default;

    AaruespError beginI2C(uint8_t addr);
    AaruespError beginI2C(class AaruI2CEngine* i2c, uint8_t addr);
    AaruespError beginSPI(uint8_t cs_pin);
    AaruespError beginSPI(class AaruSPIEngine* spi, uint8_t cs_pin);

    AaruespError setMode(BME280Mode mode);
    AaruespError setOversampling(BME280Oversampling temp, BME280Oversampling press, BME280Oversampling hum);
    AaruespError setFilter(BME280Filter filter);
    AaruespError setStandby(uint8_t ms);

    bool read(struct AaruBME280Data& data);
    float readTemp();
    float readHumidity();
    float readPressure();
    float readAltitude(float sea_level_hpa);

    AaruespError takeForcedMeasurement();
    float seaLevelForAltitude(float altitude_m, float pressure_hpa);

    bool isBME280() const;
    bool isConfigured() const;
    uint8_t addr() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    bool _is_bme280;
    bool _use_i2c;
    uint8_t _addr;
    uint8_t _cs;
    class AaruI2CEngine* _i2c;
    class AaruSPIEngine* _spi;
    bool _own_i2c, _own_spi;

    struct {
        uint16_t dig_T1; int16_t dig_T2, dig_T3;
        uint16_t dig_P1; int16_t dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
        uint8_t dig_H1; int16_t dig_H2; uint8_t dig_H3; int16_t dig_H4, dig_H5; int8_t dig_H6;
    } _cal;

    int32_t _t_fine;
    AaruespError _err;

    AaruespError readCalibration();
    int32_t compensateTemp(int32_t adc_T);
    uint32_t compensatePress(int32_t adc_P);
    uint32_t compensateHum(int32_t adc_H);
    AaruespError readRaw(int32_t* t, int32_t* p, int32_t* h);
    AaruespError writeReg(uint8_t reg, uint8_t val);
    AaruespError readReg(uint8_t reg, uint8_t* val);
    AaruespError readRegs(uint8_t reg, uint8_t* buf, uint8_t len);
};

#endif // AARUESP_BME280_H
