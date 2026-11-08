// ============================================================
//  AARUESP_MODULES — Hybrid Master Header
//  MADE BY AARUTO
//
//  Combines BOTH APIs in one library:
//
//  1) AARUESP singleton (AARUESP.h)
//     AARUESP.begin(); AARUESP.update(); AARUESP.ultrasonic(5, 18);
//     → 1000+ registered modules, see registry/modules.csv
//
//  2) Class-style module instances (modules/*.h)
//     BME280Module sensor(21, 22); sensor.init(); sensor.update();
//     → instantiate your own sensors with full control
//
//  Include this when you want everything:
//      #include <AARUESP_MODULES.h>
// ============================================================
#ifndef AARUESP_ALL_MODULES_H
#define AARUESP_ALL_MODULES_H

// ---- 1) Singleton core (1000+ modules) ----
#include <AARUESP.h>

// ---- 2) Class-style module framework ----
#include <AaruEspModule.h>

// Sensors
#include <modules/BME280Module.h>     // Temperature / humidity / pressure (I2C)
#include <modules/BMP180Module.h>     // Pressure / temperature (I2C)
#include <modules/DHT22Module.h>      // Temperature / humidity (data pin)
#include <modules/BH1750Module.h>     // Ambient light (lux)
#include <modules/MPU6050Module.h>    // 6-axis IMU (accel + gyro)
#include <modules/HCSR04Module.h>     // Ultrasonic distance
#include <modules/HCSR501Module.h>    // PIR motion sensor
#include <modules/MQ2Module.h>        // Gas / smoke
#include <modules/MQ7Module.h>        // CO gas sensor (analog)
#include <modules/SHT30Module.h>      // Temperature / humidity (I2C)
#include <modules/ACS712Module.h>     // Current (5A/20A/30A)
#include <modules/SoilMoistureModule.h>
#include <modules/PotentiometerModule.h>
#include <modules/VL53L0XModule.h>    // Time-of-flight distance (I2C)

// Actuators
#include <modules/LEDModule.h>        // Single LED
#include <modules/RGBLEDModule.h>     // RGB LED (PWM, HSV)
#include <modules/RelayModule.h>      // Relay control
#include <modules/ServoModule.h>      // Servo (0-180°)
#include <modules/BuzzerModule.h>     // Buzzer / tones
#include <modules/StepperModule.h>    // Stepper motor

// Displays
#include <modules/OLEDModule.h>       // SSD1306 OLED 128x64 (built-in driver)

// Communication
#include <modules/UARTModule.h>       // UART passthrough (GPS/BT/serial)
#include <modules/WiFiModule.h>       // WiFi connection manager
#include <modules/GPSModule.h>        // GPS NEO-6M/NEO-7M (UART)

// Input
#include <modules/ButtonModule.h>     // Debounced button (clicks & hold)
#include <modules/EncoderModule.h>    // Rotary encoder + push button

// Storage
#include <modules/EEPROMModule.h>     // EEPROM key-value storage
#include <modules/StorageManager.h>   // SPIFFS/LittleFS/SD/NVS manager
#include <modules/ConfigManager.h>    // JSON config file management

// Special
#include <modules/HallSensorModule.h> // ESP32 Hall sensor
#include <modules/DeepSleepModule.h>  // Deep sleep management
#include <modules/TouchModule.h>      // Capacitive touch (ESP32)
#include <modules/DACModule.h>        // 8-bit DAC (ESP32)
#include <modules/PSRAMModule.h>      // PSRAM detection & management
#include <modules/OTAModule.h>        // Over-The-Air updates
#include <modules/WebServerModule.h>  // HTTP server + REST API
#include <modules/BLEModule.h>        // Bluetooth Low Energy
#include <modules/ESPNowModule.h>     // ESP-NOW peer-to-peer
#include <modules/MQTTModule.h>       // MQTT client

#endif // AARUESP_ALL_MODULES_H