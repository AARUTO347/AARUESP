#include "WebServerModule.h"
#include <Arduino.h>

WebServerModule::WebServerModule(uint16_t port) : server_(port), port_(port) {}

bool WebServerModule::init() {
    server_.begin();
    initialized_ = true;
    return true;
}

void WebServerModule::update() {
    server_.handleClient();
}

void WebServerModule::handleClient() {
    server_.handleClient();
}

void WebServerModule::on(const char* uri, std::function<void()> handler) {
    server_.on(uri, handler);
}

void WebServerModule::send(int code, const char* contentType, const char* content) {
    server_.send(code, contentType, content);
}

void WebServerModule::sendJSON(const char* json) {
    server_.send(200, "application/json", json);
}

const char* WebServerModule::getIP() const {
    return WiFi.localIP().toString().c_str();
}