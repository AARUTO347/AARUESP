# Changelog

## v1.0.0 — ESP Edition — 2026-11-06
- **AARUESP is now ESP32 / ESP8266 only** (Uno/Mega/etc. live in the sister library AARUARDUINO)
- **207 ESP boards** in the built-in board database (`aaruespBoardFind("ESP32S3_BOX")`) — ESP32, S2, S3, C3, C6, H2, ESP8266, incl. Wemos/Lolin/SparkFun/AARUTO custom boards
- **Hybrid API**: singleton (`AARUESP.begin()` — same as AARUARDUINO) **+** class-module instances (`#include <AARUESP_MODULES.h>`)
- **ESP Companion** (`AARUESPESP.h`): WiFi connect/scan, deep sleep + wake reason, chip info/model, free heap, flash & PSRAM size, CPU frequency scaling, DAC (ESP32), touch pins (ESP32/S2/S3), hall (classic ESP32), restart
- Full ESP32-family pin validation: input-only pins 34–39, flash pins 6–11 rejected, C3/C6/H2 RISC-V pin ranges
- **1146 modules** across all categories (10 ESP-specific modules added)
- ESP examples: ESP_BoardInfo, ESP_WiFiScan, ESP_DeepSleep, Hybrid_BME280, Class_OLED (plus the full example set, pins adapted for ESP32)
- MIT license

## v1.0.0 — Initial — 2026-11-05
- Initial release of AARUESP by AARUTO (based on the AARUESP engine architecture)
- Singleton API: `AARUESP.begin()/update()/readX()`
- 8 shared engines: Analog, Digital, PWM, I²C, SPI, UART, 1-Wire, Pulse
- 15 drivers: HC-SR04, DHT11/22, MPU6050, DS18B20, DS3231, BME280/BMP280, BH1750, SSD1306, LCD1602, MAX7219, TM1637, WS2812, GPS/NMEA, IR Remote, Stepper
- No mandatory third-party dependencies; optional deps guarded
- Host tests (Python), registry validator, keywords/docs generators, structure validator
- MIT license
