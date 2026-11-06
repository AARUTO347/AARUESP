// ============================================================
//  AARUESP Hybrid Demo — BOTH APIs in one sketch
//  MADE BY AARUTO
//
//  singleton API  -> AARUESP.bme280(0x76);  (drivers shared, registered)
//  class-module   -> BME280Module sensor(21, 22);  (your own instance)
// ============================================================
#include <AARUESP.h>
#include <AARUESP_MODULES.h>   // singleton core + all class modules

BME280Module sensor(21, 22);   // class-module instance, I2C on SDA=21 / SCL=22
LEDModule led(2);              // class-module instance, onboard LED

void setup() {
  Serial.begin(115200);
  delay(500);
  AARUESP.begin();             // singleton: catalog init + ESP board detection

  sensor.init();               // class-module init
  led.init();

  // Singleton registers the shared BME280 driver too
  AARUESP.bme280(0x76);
}

void loop() {
  AARUESP.update();            // singleton drivers tick here
  sensor.update();             // class-module driver ticks independently

  if (sensor.isHealthy()) {
    led.on();
    Serial.printf("[class] T=%.1f C  RH=%.1f%%  P=%.1f hPa\n",
                  sensor.getTemperature(), sensor.getHumidity(), sensor.getPressure());
  } else {
    led.off();
    Serial.println("[class] BME280 not present (running simulation)");
  }

  float t = AARUESP.readBMEtemp();   // singleton API read
  if (AARUESP.lastError() == AARUESP_OK) {
    Serial.printf("[single] BME280 temp via singleton: %.1f C\n", t);
  }

  delay(1000);
}