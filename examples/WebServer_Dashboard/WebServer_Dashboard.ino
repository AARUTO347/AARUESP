/*
  WebServer_Dashboard — AARUESP V2.2 example
  Demonstrates WebServerModule with REST API for sensor dashboard.
*/
#include <AARUESP_MODULES.h>
#include <WiFi.h>

using namespace aru;

WebServerModule webServer(80);
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

float temperature = 25.0;
float humidity = 60.0;

void handleRoot() {
  String html = "<html><head><title>AARUESP Dashboard</title></head><body>";
  html += "<h1>AARUESP Sensor Dashboard</h1>";
  html += "<p>Temperature: " + String(temperature) + " C</p>";
  html += "<p>Humidity: " + String(humidity) + " %</p>";
  html += "</body></html>";
  webServer.send(200, "text/html", html.c_str());
}

void handleAPI() {
  String json = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
  webServer.sendJSON(json.c_str());
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP Web Server Dashboard — V2.2"));

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println();
  Serial.print(F("IP: "));
  Serial.println(WiFi.localIP());

  webServer.init();
  webServer.on("/", handleRoot);
  webServer.on("/api", handleAPI);

  Serial.println(F("Web server started"));
  Serial.print(F("Open http://"));
  Serial.println(WiFi.localIP());
}

void loop() {
  webServer.update();
  // Simulate sensor readings
  temperature = 20.0 + (random(0, 100) / 10.0);
  humidity = 50.0 + (random(0, 200) / 10.0);
  delay(2000);
}