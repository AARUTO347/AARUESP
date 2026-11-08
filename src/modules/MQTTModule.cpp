#include "MQTTModule.h"
#include <Arduino.h>

MQTTModule::MQTTModule(const char* broker, uint16_t port)
    : broker_(broker), port_(port) {}

bool MQTTModule::init() {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    client_.setServer(broker_, port_);
    client_.setClient(wifiClient_);
    initialized_ = true;
    return true;
#else
    // PubSubClient not available - MQTT disabled
    initialized_ = false;
    return false;
#endif
#else
    return false;
#endif
}

void MQTTModule::update() {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    if (client_.connected()) {
        client_.loop();
    }
#endif
#endif
}

bool MQTTModule::connect(const char* clientId, const char* user, const char* pass) {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    if (user && pass) {
        return client_.connect(clientId, user, pass);
    }
    return client_.connect(clientId);
#else
    return false;
#endif
#else
    return false;
#endif
}

bool MQTTModule::publish(const char* topic, const char* payload, bool retained) {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    return client_.publish(topic, payload, retained);
#else
    return false;
#endif
#else
    return false;
#endif
}

bool MQTTModule::subscribe(const char* topic) {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    return client_.subscribe(topic);
#else
    return false;
#endif
#else
    return false;
#endif
}

bool MQTTModule::unsubscribe(const char* topic) {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    return client_.unsubscribe(topic);
#else
    return false;
#endif
#else
    return false;
#endif
}

bool MQTTModule::isConnected() const {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    return client_.connected();
#else
    return false;
#endif
#else
    return false;
#endif
}

void MQTTModule::setCallback(void (*callback)(char*, uint8_t*, unsigned int)) {
#if defined(ESP32) || defined(ESP8266)
#if AARUESP_HAS_PUBSUBCLIENT
    client_.setCallback(callback);
#endif
#endif
}