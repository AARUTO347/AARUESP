#pragma once

#include <AaruEspModule.h>

#if defined(ESP32)
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#endif

/**
 * @brief BLE (Bluetooth Low Energy) Module for ESP32
 * Supports peripheral mode with sensor data broadcasting.
 */
class BLEModule : public aru::Module {
public:
    BLEModule(const char* deviceName = "AARUESP");
    bool init() override;
    void update() override;

    void setServiceUUID(const char* uuid);
    void setCharacteristicUUID(const char* uuid);
    void setValue(const char* value);
    void notify();
    bool isConnected() const;

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    const char* deviceName_;
    std::string type_ = "radio.ble";
    bool initialized_{false};
#if defined(ESP32)
    BLEServer* server_{nullptr};
    BLECharacteristic* characteristic_{nullptr};
    bool connected_{false};
#endif
};