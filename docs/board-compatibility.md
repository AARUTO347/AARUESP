# AARUESP Board Compatibility
## MADE BY AARUTO
## ESP32 & ESP8266 Only

| Board | Family | ADC | PWM pins | I²C | SPI | UART | Notes |
|---|---|---|---|---|---|---|---|
| ESP32 (classic) | ESP-WROOM-32, WROVER, Pico | 12-bit, 3.3 V | any output GPIO | any GPIO | any GPIO | 3 | 3.3 V, NOT 5 V tolerant |
| ESP32-S2 | ESP32-S2 (Saola, etc.) | 12-bit, 3.3 V | any output GPIO | any GPIO | any GPIO | 2 | No BLE, USB-OTG |
| ESP32-S3 | ESP32-S3 (box, etc.) | 12-bit, 3.3 V | any output GPIO | any GPIO | any GPIO | 3 | WiFi + BLE 5.0, vector instructions |
| ESP32-C3 | RISC-V, S2-class | 12-bit, 3.3/2.5 V | any output GPIO | any GPIO | any GPIO | 1-2 | Single-core RISC-V, WiFi+BLE 5.0 |
| ESP32-C6 | RISC-V, WiFi 6 | 12-bit, 2.5 V | any output GPIO | any GPIO | any GPIO | 1-2 | WiFi 6 + BLE 5.3 + 802.15.4 (Thread/Zigbee) |
| ESP32-H2 | RISC-V, Zigbee/Thread | 12-bit, 2.5 V | any output GPIO | any GPIO | any GPIO | 1 | BLE 5.2 + 802.15.4, no WiFi |
| ESP8266 (EX/8285) | ESP-12F, NodeMCU, Wemos | 10-bit, 3.3 V | most (except 16) | any GPIO | any GPIO | 1 | single ADC (A0), GPIO 16 cannot do PWM |

Full **207-board database** with per-board GPIO counts, flash sizes, voltage ranges and upload ports: see `src/AARUESPBoards.cpp` and query it at runtime (`aaruespBoardFind("ESP32S3_BOX")`).

## Per-family pin rules (used by `isValidDigitalPin()` etc.)

### ESP32 (classic)
- Usable digital: 0–39 **except GPIO 6–11** (SPI flash, never use)
- **GPIO 34–39 are input-only** (no output driver)
- ADC pins: ADC1 (32–39, WiFi-safe) + ADC2 (0, 2, 4, 12–15, 25–27, conflicts with WiFi)

### ESP32-S2
- Usable digital: 0–46, ADC1 1–10, ADC2 11–18

### ESP32-S3
- Usable digital: 0–48, **26–32 reserved** (SPI flash/psram), ADC1 1–10, ADC2 11–20

### ESP32-C3 / C6 / H2 (RISC-V)
- Usable digital: GPIO 0–10 and 18–21, ADC on GPIO 0–4

### ESP8266
- Usable digital: GPIO 0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16
- GPIO 16 cannot do PWM, interrupts, I²C, or SPI — only simple input/output and deep-sleep wake (wire GPIO16→RST for deep sleep wake)
- A0 is the **only** analog pin (10-bit, 0–1.0 V bare / 0–3.3 V with divider)

## Voltage safety

- ESP boards are **3.3 V logic, not 5 V tolerant**. HC-SR04 echo (5 V) needs a voltage divider (1k/2k) or level shifter. Software cannot fix wiring.
- Never drive motors, relays, servos or high-current loads directly from GPIO. Use driver modules + external power.
- GPIO 0/2/15 are boot-strapping pins — devices wired here can prevent flashing.

## Pin validation

`AARUESP.isValidDigitalPin(pin)`, `isValidAnalogPin(pin)`, `isValidPwmPin(pin)` perform runtime validation per detected ESP family. Invalid pins return `AARUESP_INVALID_PIN`.