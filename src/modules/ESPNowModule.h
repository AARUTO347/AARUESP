#pragma once

#include <AaruEspModule.h>

#if defined(ESP32) || defined(ESP8266)
#include <esp_now.h>
#include <WiFi.h>
#endif

/**
 * @brief ESP-NOW Peer-to-Peer Communication Module
 * Supports broadcast and unicast messaging between ESP devices.
 */
class ESPNowModule : public aru::Module {
public:
    ESPNowModule();
    bool init() override;
    void update() override;

    bool addPeer(const uint8_t* mac);
    bool removePeer(const uint8_t* mac);
    bool send(const uint8_t* mac, const uint8_t* data, size_t len);
    bool broadcast(const uint8_t* data, size_t len);
    bool hasReceived() const { return received_; }
    size_t getReceivedData(uint8_t* buf, size_t maxLen);

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    std::string type_ = "radio.espnow";
    bool initialized_{false};
    bool received_{false};
    uint8_t rxBuffer_[250];
    size_t rxLen_{0};
};