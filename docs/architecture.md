# AARUESP Architecture
## MADE BY AARUTO
## ESP32 / ESP8266 Only

- `src/AARUESP.h/.cpp` — public singleton `AARUESP`, delegates to engines/drivers.
- `src/AARUESPTypes.h` — errors, ESP board families, version, categories, `AaruespBoardInfo`.
- `src/AARUESPConfig.h` — timeouts, debounce, opt-out macros.
- `src/AARUESPBoard.h` — compile-time ESP family detection (ESP32/S2/S3/C3/C6/H2/ESP8266) + pin validation.
- `src/AARUESPBoards.cpp` — **207-board database** (`aaruespBoardCount/At/Find/Contains`).
- `src/AARUESPESP.h/.cpp` — ESP companion: WiFi, deep sleep, chip info, CPU frequency, DAC/touch/hall (ESP32).
- `src/engines/` — shared backends (Analog, Digital, PWM, I2C, SPI, UART, OneWire, Pulse).
- `src/drivers/` — per-device drivers (HCSR04, DHT, MPU6050, SSD1306, etc.).
- `src/AaruEspModule.h` — base for the class-module API (`aru::Module`, `isInitialized()/isHealthy()`).
- `src/modules/` — class-module instances (`BME280Module sensor(21, 22);`) — the hybrid API.
- `src/AARUESP_MODULES.h` — pulls in singleton + every class module.
- `src/utility/AaruespMath.h` — pure header math, host-testable.
- `registry/modules.csv` — source of truth for the 1146-module list (`validate_registry.py`, id A0001..+E? rows).
- `tools/` — registry generator, validator, keywords/docs generators.
- `tests/` — host tests (Python) + structure validator.
- `examples/` — one sketch per major module family + ESP-specific sketches (BoardInfo, WiFi, DeepSleep, Hybrid, Class_OLED).

## Two ways to use it (both are first-class)

1. **Singleton** (`AARUESP.h`): `AARUESP.ultrasonic(5, 18); AARUESP.readUltrasonic();` — 1146 registered modules.
2. **Class modules** (`AARUESP_MODULES.h`): `BME280Module sensor(21, 22); sensor.init(); sensor.update();` — your own instances.

Rules: no heap in core paths, no blocking in `update()`, headers idempotent, never fake data (failures return NaN/-1/false + error code), optional deps guarded with `__has_include`.
