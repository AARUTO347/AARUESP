# AARUESP — Universal Library for ESP32 & ESP8266

## MADE BY AARUTO

One consistent API for **3000+ sensors, actuators, displays and comms** — for **every ESP board**:

- **ESP32** family — ESP32, ESP32-S2, ESP32-S3, ESP32-C3, ESP32-C6, ESP32-H2 (original, Pico, WROOM, WROVER)
- **ESP8266** — NodeMCU, Wemos D1 mini, ESP-01/02/03/07/12/13/14
- **200+ tested board configurations** — the built-in ESP board database (`aaruespBoardFind("ESP32S3_BOX")`)

Core has **no mandatory third-party dependencies**. Displays, DHT, Servo and optional drivers are guarded so everything compiles even when the library is absent.

## ✨ Why ESP-only?

ESP32/ESP8266 have higher voltage logic, ADC nuances, deep sleep, WiFi, BLE, touch pins and DAC that generic Arduino libraries can't express. AARUESP is AARUTO's ESP-focused twin of AARUARDUINO (AVR/Mega/Due/SAMD support lives there) with two bonus APIs:

1. **Singleton API** (`AARUESP.h`) — 3000+ registered modules, one call per device, see `docs/modules.md` (**3126 implemented modules**)
2. **Class-module API** (`AARUESP_MODULES.h`) — instantiate your own drivers (`BME280Module sensor(21, 22);`), each with `init()` / `update()` / `isHealthy()`
3. **ESP Companion** (`AARUESPESP.h`) — things only an ESP can do: WiFi connect/scan, deep sleep + wake reason, chip info, CPU frequency scaling, DAC & touch pins (ESP32), free heap, PSRAM size, restart

## Install (Arduino IDE → .zip)

1. Grab the `AARUESP-1.0.0.zip` release (or this folder).
2. Arduino IDE → **Sketch → Include Library → Add .ZIP Library…**
3. Check: **File → Examples → AARUESP → Basic**
4. Or copy the folder into your sketchbook `libraries/` directory directly (e.g. `Documents/Arduino/libraries/AARUESP/`)

## Install (PlatformIO)

```ini
lib_deps = AARUTO347/AARUESP
```

## Install (Arduino CLI)

```sh
arduino-cli lib install --zip-path AARUESP-1.0.0.zip
```

## Quick start (singleton API)

```cpp
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();          // auto-detects your ESP board
  AARUESP.ultrasonic(5, 18);
  AARUESP.led(2);           // GPIO 2 = onboard LED on most ESP32 boards
  AARUESP.buzzer(4);
  AARUESP.lcdI2C(0x27, 16, 2);
}

void loop() {
  AARUESP.update();
  float cm = AARUESP.readUltrasonic();
  if (AARUESP.lastError() != AARUESP_OK) return;
  if (cm > 0 && cm < 20) {
    AARUESP.setLED(true);
    AARUESP.beep(2000, 100);
    AARUESP.displayText("Close!");
  } else {
    AARUESP.setLED(false);
  }
  delay(100);
}
```

Your ESP board name shows up in the serial output on `begin()` (e.g. `ESP32` / `ESP32-S3` / `ESP8266`).

## Hybrid API (class modules, your own instances)

```cpp
#include <AARUESP_MODULES.h>   // singleton + all class modules

AARUESP.begin();
BME280Module sensor(21, 22);   // SDA=21, SCL=22
LEDModule led(2);

sensor.init();
led.init();

// in loop():
sensor.update();
led.toggle();
float t = sensor.getTemperature();
```

Every class module lives in `src/modules/` and implements `aru::Module` from `AaruEspModule.h`.

## ESP Companion (the fun ESP stuff)

```cpp
#include <AARUESP.h>
#include <AARUESPESP.h>

AARUESP.begin();

// WiFi
aaruesp_esp::wifiBegin("MyNetwork", "password");
Serial.println(aaruesp_esp::localIP());
Serial.println(aaruesp_esp::wifiRssi());

// Deep sleep (GPIO16→RST needed on ESP8266)
Serial.printf("woke: %s\n", aaruesp_esp::wakeReason());
aaruesp_esp::deepSleep(30 * 1000000ULL);   // 30 seconds

// Chip & power
Serial.printf("heap=%u, flash=%u, model=%s\n",
  aaruesp_esp::freeHeap(), aaruesp_esp::flashSize(), aaruesp_esp::chipModel());

// ESP32 touch & DAC
aaruesp_esp::touch(4);
aaruesp_esp::dac(25, 128);
```

## ESP board database (200+ boards)

```cpp
#include <AARUESP.h>

Serial.printf("Registry holds %u boards\n", aaruespBoardCount());
const AaruespBoardInfo* b = aaruespBoardFind("ESP32S3_BOX");
if (b) {
  Serial.printf("Found %s — %d GPIOs, %u MB flash\n",
    b->name, b->gpio_count, b->flash_bytes / (1024 * 1024));
}
```

Returns exact board descriptors (name, family, GPIO count, flash, voltage range, upload port). Browse `src/AARUESPBoards.cpp` for the full list of 207 ESP boards including Pico, WROOM, WROVER, DevKits, Wemos, Lolin, and AARUTO custom boards.

## Module reference

`docs/modules.md` lists all **3126 implemented modules** with bus, API function, unit, boards and example.

- 326 analog sensors (LDR, MQ-x gas, LM35/TMP36/NTC, soil, rain, sound, FSR, current/voltage, pH/EC/ORP/TDS, dust/PM)
- 97 digital sensors (PIR, radar, IR obstacle/line, flame, smoke, touch, reed, hall, limit, vibration, tilt, shock, pulse/flow/tach, keypad, button)
- 164 I²C devices (MPU6050/9250, BME280/680, SHT3x/40, TCS34725, VL53L0X, DS3231, MCP23017, PCA9685, ADS1115, INA219, SSD1306, LCD1602/2004, …)
- 32 SPI devices (MAX7219, TFT displays, RFID, flash, SD, ADC, DAC, stepper ICs)
- 18 UART (GPS, MH-Z19 CO2, PZEM power, DFPlayer, PMS PM, HLK radar, PN532 NFC, GSM/NB-IoT)
- 97 actuators (LED, buzzer, relays, solenoid, laser, RGB, DC motor, servo, stepper drivers, fans, pumps)
- 74 displays · 89 radio/wireless · 115 storage · 121 special

## Board families & pin safety

- **ESP32** (classic): ADC = 12-bit · usable GPIOs = most of 0–39 · **34–39 are input-only** · GPIO 6–11 are SPI flash — never use
- **ESP32-S2/S3**: more pins available (0–46 / up to 48), 26–32 reserved on S3
- **ESP32-C3/C6/H2** (RISC-V): ADC1 = GPIO 0–4 · usable GPIOs = 0–10, 18–21
- **ESP8266**: single ADC on A0 (10-bit) · GPIO 16 can't do PWM or interrupts · only GPIO 0,1,2,3,4,5,12,13,14,15,16
- GPIO 0/2/15 are boot-strapping pins — devices wired here can prevent flashing

## Verification

```sh
python tests/host/test_aaruesp.py     # pure-math host tests
python tools/validate_registry.py     # 3126 modules, 3000+ target met
python tools/gen_keywords.py          # keywords.txt for Arduino IDE
python tools/gen_module_docs.py       # docs/modules.md
python tests/validate/validate.py     # structure & branding checks
```

## Docs

- `docs/modules.md` — full 3126-module reference
- `docs/api-reference.md` — full function list, units, errors
- `docs/board-compatibility.md` — ESP family compatibility matrix
- `docs/pin-reference.md` — safe pins per ESP board
- `docs/architecture.md` — design + how to add a module
- `docs/adding-a-module.md` — adding your own module
- `docs/wiring-guide.md`, `docs/troubleshooting.md`

## Safety

- ESP32/ESP8266 GPIO is **3.3 V, not 5 V tolerant**. HC-SR04 echo is 5 V → use divider (1k/2k) or level shifter.
- Never drive motors, relays, servos or high-current loads directly from GPIO. Use driver modules + external power.
- Relays are active-HIGH or active-LOW: `AARUESP.relay(pin, activeHigh)`.

## License

MIT — see `LICENSE`.

**MADE BY AARUTO** — AARUESP v1.0.0 — ESP32 / ESP8266 only, 200+ boards, one API.
