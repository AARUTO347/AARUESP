#include "ESPNowModule.h"
#include <Arduino.h>

ESPNowModule::ESPNowModule() {}

bool ESPNowModule::init() {
#if defined(ESP32) || defined(ESP8266)
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) return false;
    initialized_ = true;
    return true;
#else
    return false;
#endif
}

void ESPNowModule::update() {}

bool ESPNowModule::addPeer(const uint8_t* mac) {
#if defined(ESP32) || defined(ESP8266)
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, mac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    return esp_now_add_peer(&peerInfo) == ESP_OK;
#else
    return false;
#endif
}

bool ESPNowModule::removePeer(const uint8_t* mac) {
#if defined(ESP32) || defined(ESP8266)
    return esp_now_del_peer(mac) == ESP_OK;
#else
    return false;
#endif
}

bool ESPNowModule::send(const uint8_t* mac, const uint8_t* data, size_t len) {
#if defined(ESP32) || defined(ESP8266)
    return esp_now_send(mac, data, len) == ESP_OK;
#else
    return false;
#endif
}

bool ESPNowModule::broadcast(const uint8_t* data, size_t len) {
    uint8_t broadcastAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    return send(broadcastAddr, data, len);
}

size_t ESPNowModule::getReceivedData(uint8_t* buf, size_t maxLen) {
    if (!received_) return 0;
    size_t len = (rxLen_ < maxLen) ? rxLen_ : maxLen;
    memcpy(buf, rxBuffer_, len);
    received_ = false;
    return len;
}