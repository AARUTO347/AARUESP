# AARUESP V1.1 Release Notes

## What's New in V1.1

### 5 New Example Sketches
- **RF24_Radio** — nRF24L01+ radio module example (class-module API)
- **SD_Storage** — SD card storage module example (class-module API)
- **ESP_Special** — ESP Companion API demo: chip info, WiFi scan, deep sleep, restart (singleton API)
- **Hybrid_BME280** — Side-by-side singleton + class-module usage for BME280 sensor
- **Button_Buzzer** — Button and Buzzer actuator modules example (class-module API)

Total examples: **15** (was 10)

### Version Bump
- library.properties: 1.0.0 → **1.1.0**

### All Compile Tests Passed
- ESP32 (esp32:esp32:esp32 3.3.10): all 15 examples ✅
- ESP8266 (esp8266:esp8266:nodemcuv2): all 15 examples ✅

### Lint Clean
- arduino-lint: 0 errors, 0 warnings across library + all examples

## Included Features
- 1146+ modules across 10 categories (analog, digital, I²C, SPI, UART, display, actuator, radio, storage, special)
- 207 ESP board definitions with auto-detection
- Singleton API: `AARUESP.begin()/update()/readX()`
- Class-module API: `AARUESP_MODULES.h`
- ESP Companion: WiFi, deep sleep, chip info, DAC/touch/hall (ESP32), restart
- Zero mandatory third-party dependencies
- Installable as Arduino .zip library and via Arduino Library Manager

## Installation
- **Arduino IDE**: Tools → Manage Libraries → search "AARUESP"
- **ZIP**: Download from GitHub releases → Sketch → Include Library → Add .ZIP Library
- **GitHub**: https://github.com/AARUTO347/AARUESP
