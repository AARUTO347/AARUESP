// ============================================================
//  AARUESP MPU6050 Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_MPU6050_H
#define AARUESP_MPU6050_H

#include "AARUESPTypes.h"
#include "engines/AaruI2CEngine.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

#define MPU6050_ADDR        0x68
#define MPU6050_WHO_AM_I    0x75
#define MPU6050_PWR_MGMT_1  0x6B
#define MPU6050_ACCEL_XOUT  0x3B
#define MPU6050_GYRO_XOUT   0x43
#define MPU6050_TEMP_OUT    0x41
#define MPU6050_ACCEL_CFG   0x1C
#define MPU6050_GYRO_CFG    0x1B

typedef enum {
    MPU6050_ACCEL_2G  = 0,
    MPU6050_ACCEL_4G  = 1,
    MPU6050_ACCEL_8G  = 2,
    MPU6050_ACCEL_16G = 3
} MPU6050AccelRange;

typedef enum {
    MPU6050_GYRO_250  = 0,
    MPU6050_GYRO_500  = 1,
    MPU6050_GYRO_1000 = 2,
    MPU6050_GYRO_2000 = 3
} MPU6050GyroRange;

class AaruMPU6050 {
public:
    AaruMPU6050() = default;

    AaruespError begin(uint8_t addr);
    AaruespError begin(class AaruI2CEngine* i2c, uint8_t addr);

    AaruespError setAccelRange(MPU6050AccelRange range);
    AaruespError setGyroRange(MPU6050GyroRange range);
    AaruespError setDLPF(uint8_t dlpf);
    AaruespError setSampleRate(uint8_t div);

    bool readAccel(float& x, float& y, float& z);
    bool readGyro(float& x, float& y, float& z);
    float readTemp();

    float readAccelX();
    float readAccelY();
    float readAccelZ();
    float readGyroX();
    float readGyroY();
    float readGyroZ();

    void calibrateAccel(int samples);
    void calibrateGyro(int samples);
    void setAccelOffset(float x, float y, float z);
    void setGyroOffset(float x, float y, float z);

    AaruespError sleep();
    AaruespError wake();

    uint8_t addr() const;
    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _addr;
    class AaruI2CEngine* _i2c;
    bool _own_i2c;
    float _accel_scale;
    float _gyro_scale;
    float _accel_off[3];
    float _gyro_off[3];
    AaruespError _err;

    AaruespError writeReg(uint8_t reg, uint8_t val);
    AaruespError readRegs(uint8_t reg, uint8_t* buf, uint8_t len);
};

#endif // AARUESP_MPU6050_H
