#pragma once

#include <AaruEspModule.h>
#include <WiFi.h>

#if defined(ESP32) || defined(ESP8266)
#if __has_include(<PubSubClient.h>)
#include <PubSubClient.h>
#define AARUESP_HAS_PUBSUBCLIENT 1
#else
#define AARUESP_HAS_PUBSUBCLIENT 0
#endif
#endif

/**
 * @brief MQTT Client Module
 * Supports pub/sub messaging with QoS levels.
 */
class MQTTModule : public aru::Module {
public:
    MQTTModule(const char* broker, uint16_t port = 1883);
    bool init() override;
    void update() override;

    bool connect(const char* clientId, const char* user = nullptr, const char* pass = nullptr);
    bool publish(const char* topic, const char* payload, bool retained = false);
    bool subscribe(const char* topic);
    bool unsubscribe(const char* topic);
    bool isConnected() const;
    void setCallback(void (*callback)(char*, uint8_t*, unsigned int));

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_ && isConnected(); }

private:
    const char* broker_;
    uint16_t port_;
    std::string type_ = "comm.mqtt";
    bool initialized_{false};
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    WiFiClient wifiClient_;
    PubSubClient client_;
#endif
#endif
};