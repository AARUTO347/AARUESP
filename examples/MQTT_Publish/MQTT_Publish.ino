/*
  MQTT_Publish — AARUESP V2.2 example
  Demonstrates MQTTModule for publishing sensor data.
*/
#include <AARUESP_MODULES.h>

using namespace aru;

MQTTModule mqtt("mqtt.example.com", 1883);
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println(F("AARUESP MQTT Publish Example — V2.2"));

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println();

  mqtt.init("mqtt.example.com");
  mqtt.connect("AARUESP_Client");

  mqtt.subscribe("aaruesp/commands");
  Serial.println(F("MQTT connected"));
}

void loop() {
  mqtt.update();

  if (mqtt.isConnected()) {
    float temp = 20.0 + (random(0, 100) / 10.0);
    char buf[32];
    snprintf(buf, sizeof(buf), "{\"temperature\":%.1f}", temp);
    mqtt.publish("aaruesp/sensors", buf);
    Serial.print(F("Published: "));
    Serial.println(buf);
  }

  delay(5000);
}