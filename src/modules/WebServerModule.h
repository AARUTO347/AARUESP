#pragma once

#include <AaruEspModule.h>
#include <WiFi.h>
#include <WebServer.h>

/**
 * @brief Web Server Module for ESP32/ESP8266
 * HTTP server with REST API, WebSocket, and file serving.
 */
class WebServerModule : public aru::Module {
public:
    WebServerModule(uint16_t port = 80);
    bool init() override;
    void update() override;

    void handleClient();
    void on(const char* uri, std::function<void()> handler);
    void send(int code, const char* contentType, const char* content);
    void sendJSON(const char* json);
    const char* getIP() const;

    const std::string& getType() const override { return type_; }
    bool isHealthy() const override { return initialized_; }

private:
    WebServer server_;
    uint16_t port_;
    std::string type_ = "special.webserver";
    bool initialized_{false};
};