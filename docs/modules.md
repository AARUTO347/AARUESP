# AARUESP Module Reference

**Total modules: 18100** across 29 categories

MADE BY AARUTO

## Categories

- [ACTUATOR](#actuator) (600 modules)
- [AGRICULTURE](#agriculture) (500 modules)
- [ANALOG](#analog) (1500 modules)
- [AUDIO](#audio) (600 modules)
- [AUTOMOTIVE](#automotive) (400 modules)
- [CAMERA](#camera) (400 modules)
- [COMMUNICATION](#communication) (600 modules)
- [DIGITAL](#digital) (600 modules)
- [DISPLAY](#display) (400 modules)
- [DISPLAY_ADVANCED](#display_advanced) (300 modules)
- [ENERGY](#energy) (500 modules)
- [ENVIRONMENT](#environment) (1200 modules)
- [HOME_AUTOMATION](#home_automation) (700 modules)
- [I2C](#i2c) (1200 modules)
- [INDUSTRIAL](#industrial) (800 modules)
- [MEDICAL](#medical) (400 modules)
- [MOTOR](#motor) (800 modules)
- [ONEWIRE](#onewire) (100 modules)
- [POWER](#power) (1000 modules)
- [RADIO](#radio) (500 modules)
- [ROBOTICS](#robotics) (600 modules)
- [SECURITY](#security) (400 modules)
- [SPECIAL](#special) (800 modules)
- [SPI](#spi) (300 modules)
- [STORAGE](#storage) (700 modules)
- [STORAGE_ADVANCED](#storage_advanced) (200 modules)
- [UART](#uart) (200 modules)
- [WEARABLE](#wearable) (300 modules)
- [WIRELESS](#wireless) (1500 modules)

## ACTUATOR

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0761 | TMC5160 | SPI | steps | IMPLEMENTED |
| A0762 | TMC2130 | SPI | steps | IMPLEMENTED |
| A0763 | TMC2224 | UART | steps | IMPLEMENTED |
| A0764 | TMC2225 | UART | steps | IMPLEMENTED |
| A0765 | TMC2226 | UART | steps | IMPLEMENTED |
| A0766 | TMC2660 | SPI | steps | IMPLEMENTED |
| A0767 | TMC5130 | SPI | steps | IMPLEMENTED |
| A0768 | TMC5160-A | SPI | steps | IMPLEMENTED |
| A0769 | A4988 SPI | SPI | steps | IMPLEMENTED |
| A0770 | DRV8825 SPI | SPI | steps | IMPLEMENTED |
| A0771 | TB6600 SPI | SPI | steps | IMPLEMENTED |
| A0772 | DM542 SPI | SPI | steps | IMPLEMENTED |
| A0773 | Leadshine SPI | SPI | steps | IMPLEMENTED |
| A0774 | iHSV Stepper | SPI | steps | IMPLEMENTED |
| A0881 | LED PWM | PWM | 0-255 | IMPLEMENTED |
| A0882 | LED High Power | PWM | 0-255 | IMPLEMENTED |
| A0883 | LED COB | PWM | 0-255 | IMPLEMENTED |
| A0884 | LED Strip | PWM | 0-255 | IMPLEMENTED |
| A0885 | LED RGB Strip | PWM | 0-255 | IMPLEMENTED |
| A0886 | LED Matrix | PWM | display | IMPLEMENTED |
| A0887 | Buzzer Active | PWM | on/off | IMPLEMENTED |
| A0888 | Buzzer Passive | PWM | Hz/ms | IMPLEMENTED |
| A0889 | Buzzer 5V | PWM | on/off | IMPLEMENTED |
| A0890 | Buzzer 12V | PWM | on/off | IMPLEMENTED |
| A0891 | Piezo Buzzer | GPIO | on/off | IMPLEMENTED |
| A0892 | Magnetic Buzzer | GPIO | on/off | IMPLEMENTED |
| A0893 | Relay 1CH | GPIO | on/off | IMPLEMENTED |
| A0894 | Relay 2CH | GPIO | on/off | IMPLEMENTED |
| A0895 | Relay 4CH | GPIO | on/off | IMPLEMENTED |
| A0896 | Relay 8CH | GPIO | on/off | IMPLEMENTED |
| A0897 | Relay 16CH | GPIO | on/off | IMPLEMENTED |
| A0898 | Relay 32CH | GPIO | on/off | IMPLEMENTED |
| A0899 | SSR Relay | GPIO | on/off | IMPLEMENTED |
| A0900 | SSR 25A | GPIO | on/off | IMPLEMENTED |
| A0901 | SSR 40A | GPIO | on/off | IMPLEMENTED |
| A0902 | Reed Relay | GPIO | on/off | IMPLEMENTED |
| A0903 | Latching Relay | GPIO | on/off | IMPLEMENTED |
| A0904 | Power Relay | GPIO | on/off | IMPLEMENTED |
| A0905 | Solenoid 12V | GPIO | on/off | IMPLEMENTED |
| A0906 | Solenoid 24V | GPIO | on/off | IMPLEMENTED |
| A0907 | Solenoid 48V | GPIO | on/off | IMPLEMENTED |
| A0908 | Water Valve | GPIO | on/off | IMPLEMENTED |
| A0909 | Gas Valve | GPIO | on/off | IMPLEMENTED |
| A0910 | Air Valve | GPIO | on/off | IMPLEMENTED |
| A0911 | Laser KY-008 | GPIO | on/off | IMPLEMENTED |
| A0912 | Laser Module | GPIO | on/off | IMPLEMENTED |
| A0913 | Laser Diode | GPIO | on/off | IMPLEMENTED |
| A0914 | RGB LED | GPIO | 0-255×3 | IMPLEMENTED |
| A0915 | RGBW LED | GPIO | 0-255×4 | IMPLEMENTED |
| A0916 | RGB LED Strip | GPIO | 0-255×3 | IMPLEMENTED |

*... and 550 more ACTUATOR modules*

## AGRICULTURE

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A13591 | Soil pH 1 | ANALOG | pH | IMPLEMENTED |
| A13592 | Soil EC 2 | ANALOG | uS/cm | IMPLEMENTED |
| A13593 | Soil NPK 3 | I2C | mg/kg | IMPLEMENTED |
| A13594 | Leaf Wetness 4 | ANALOG | % | IMPLEMENTED |
| A13595 | Solar Radiation 5 | ANALOG | W/m2 | IMPLEMENTED |
| A13596 | Rain Gauge 6 | DIGITAL | mm | IMPLEMENTED |
| A13597 | Wind Speed 7 | DIGITAL | m/s | IMPLEMENTED |
| A13598 | Wind Direction 8 | ANALOG | deg | IMPLEMENTED |
| A13599 | Soil pH 9 | ANALOG | pH | IMPLEMENTED |
| A13600 | Soil EC 10 | ANALOG | uS/cm | IMPLEMENTED |
| A13601 | Soil NPK 11 | I2C | mg/kg | IMPLEMENTED |
| A13602 | Leaf Wetness 12 | ANALOG | % | IMPLEMENTED |
| A13603 | Solar Radiation 13 | ANALOG | W/m2 | IMPLEMENTED |
| A13604 | Rain Gauge 14 | DIGITAL | mm | IMPLEMENTED |
| A13605 | Wind Speed 15 | DIGITAL | m/s | IMPLEMENTED |
| A13606 | Wind Direction 16 | ANALOG | deg | IMPLEMENTED |
| A13607 | Soil pH 17 | ANALOG | pH | IMPLEMENTED |
| A13608 | Soil EC 18 | ANALOG | uS/cm | IMPLEMENTED |
| A13609 | Soil NPK 19 | I2C | mg/kg | IMPLEMENTED |
| A13610 | Leaf Wetness 20 | ANALOG | % | IMPLEMENTED |
| A13611 | Solar Radiation 21 | ANALOG | W/m2 | IMPLEMENTED |
| A13612 | Rain Gauge 22 | DIGITAL | mm | IMPLEMENTED |
| A13613 | Wind Speed 23 | DIGITAL | m/s | IMPLEMENTED |
| A13614 | Wind Direction 24 | ANALOG | deg | IMPLEMENTED |
| A13615 | Soil pH 25 | ANALOG | pH | IMPLEMENTED |
| A13616 | Soil EC 26 | ANALOG | uS/cm | IMPLEMENTED |
| A13617 | Soil NPK 27 | I2C | mg/kg | IMPLEMENTED |
| A13618 | Leaf Wetness 28 | ANALOG | % | IMPLEMENTED |
| A13619 | Solar Radiation 29 | ANALOG | W/m2 | IMPLEMENTED |
| A13620 | Rain Gauge 30 | DIGITAL | mm | IMPLEMENTED |
| A13621 | Wind Speed 31 | DIGITAL | m/s | IMPLEMENTED |
| A13622 | Wind Direction 32 | ANALOG | deg | IMPLEMENTED |
| A13623 | Soil pH 33 | ANALOG | pH | IMPLEMENTED |
| A13624 | Soil EC 34 | ANALOG | uS/cm | IMPLEMENTED |
| A13625 | Soil NPK 35 | I2C | mg/kg | IMPLEMENTED |
| A13626 | Leaf Wetness 36 | ANALOG | % | IMPLEMENTED |
| A13627 | Solar Radiation 37 | ANALOG | W/m2 | IMPLEMENTED |
| A13628 | Rain Gauge 38 | DIGITAL | mm | IMPLEMENTED |
| A13629 | Wind Speed 39 | DIGITAL | m/s | IMPLEMENTED |
| A13630 | Wind Direction 40 | ANALOG | deg | IMPLEMENTED |
| A13631 | Soil pH 41 | ANALOG | pH | IMPLEMENTED |
| A13632 | Soil EC 42 | ANALOG | uS/cm | IMPLEMENTED |
| A13633 | Soil NPK 43 | I2C | mg/kg | IMPLEMENTED |
| A13634 | Leaf Wetness 44 | ANALOG | % | IMPLEMENTED |
| A13635 | Solar Radiation 45 | ANALOG | W/m2 | IMPLEMENTED |
| A13636 | Rain Gauge 46 | DIGITAL | mm | IMPLEMENTED |
| A13637 | Wind Speed 47 | DIGITAL | m/s | IMPLEMENTED |
| A13638 | Wind Direction 48 | ANALOG | deg | IMPLEMENTED |
| A13639 | Soil pH 49 | ANALOG | pH | IMPLEMENTED |
| A13640 | Soil EC 50 | ANALOG | uS/cm | IMPLEMENTED |

*... and 450 more AGRICULTURE modules*

## ANALOG

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0001 | MQ-2 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0002 | MQ-3 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0003 | MQ-4 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0004 | MQ-5 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0005 | MQ-6 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0006 | MQ-7 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0007 | MQ-8 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0008 | MQ-9 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0009 | MQ-131 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0010 | MQ-135 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0011 | MQ-136 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0012 | MQ-137 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0013 | MQ-138 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0014 | MQ-214 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0015 | MQ-303A Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0016 | MQ-306A Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0017 | MQ-307A Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0018 | MQ-309A Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0019 | MQ-403 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0020 | MQ-501 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0021 | MQ-601 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0022 | MQ-701 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0023 | MQ-801 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0024 | MQ-901 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0025 | MQ-201 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0026 | MQ-202 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0027 | MQ-203 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0028 | MQ-204 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0029 | MQ-205 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0030 | MQ-206 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0031 | MQ-207 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0032 | MQ-208 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0033 | MQ-209 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0034 | MQ-210 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0035 | MQ-211 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0036 | MQ-212 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0037 | MQ-213 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0038 | MQ-215 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0039 | MQ-216 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0040 | MQ-217 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0041 | MQ-218 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0042 | MQ-219 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0043 | MQ-220 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0044 | MQ-301 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0045 | MQ-302 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0046 | MQ-304 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0047 | MQ-305 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0048 | MQ-308 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0049 | MQ-310 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |
| A0050 | MQ-401 Gas Sensor | ANALOG | ratio / ppm | IMPLEMENTED |

*... and 1450 more ANALOG modules*

## AUDIO

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A10191 | DAC Audio 1 | I2S | Hz | IMPLEMENTED |
| A10192 | ADC Audio 2 | I2S | Hz | IMPLEMENTED |
| A10193 | MP3 Player 3 | UART | track | IMPLEMENTED |
| A10194 | Microphone 4 | I2S | dB | IMPLEMENTED |
| A10195 | Speaker 5 | PWM | Hz | IMPLEMENTED |
| A10196 | TTS 6 | I2S | text | IMPLEMENTED |
| A10197 | DAC Audio 7 | I2S | Hz | IMPLEMENTED |
| A10198 | ADC Audio 8 | I2S | Hz | IMPLEMENTED |
| A10199 | MP3 Player 9 | UART | track | IMPLEMENTED |
| A10200 | Microphone 10 | I2S | dB | IMPLEMENTED |
| A10201 | Speaker 11 | PWM | Hz | IMPLEMENTED |
| A10202 | TTS 12 | I2S | text | IMPLEMENTED |
| A10203 | DAC Audio 13 | I2S | Hz | IMPLEMENTED |
| A10204 | ADC Audio 14 | I2S | Hz | IMPLEMENTED |
| A10205 | MP3 Player 15 | UART | track | IMPLEMENTED |
| A10206 | Microphone 16 | I2S | dB | IMPLEMENTED |
| A10207 | Speaker 17 | PWM | Hz | IMPLEMENTED |
| A10208 | TTS 18 | I2S | text | IMPLEMENTED |
| A10209 | DAC Audio 19 | I2S | Hz | IMPLEMENTED |
| A10210 | ADC Audio 20 | I2S | Hz | IMPLEMENTED |
| A10211 | MP3 Player 21 | UART | track | IMPLEMENTED |
| A10212 | Microphone 22 | I2S | dB | IMPLEMENTED |
| A10213 | Speaker 23 | PWM | Hz | IMPLEMENTED |
| A10214 | TTS 24 | I2S | text | IMPLEMENTED |
| A10215 | DAC Audio 25 | I2S | Hz | IMPLEMENTED |
| A10216 | ADC Audio 26 | I2S | Hz | IMPLEMENTED |
| A10217 | MP3 Player 27 | UART | track | IMPLEMENTED |
| A10218 | Microphone 28 | I2S | dB | IMPLEMENTED |
| A10219 | Speaker 29 | PWM | Hz | IMPLEMENTED |
| A10220 | TTS 30 | I2S | text | IMPLEMENTED |
| A10221 | DAC Audio 31 | I2S | Hz | IMPLEMENTED |
| A10222 | ADC Audio 32 | I2S | Hz | IMPLEMENTED |
| A10223 | MP3 Player 33 | UART | track | IMPLEMENTED |
| A10224 | Microphone 34 | I2S | dB | IMPLEMENTED |
| A10225 | Speaker 35 | PWM | Hz | IMPLEMENTED |
| A10226 | TTS 36 | I2S | text | IMPLEMENTED |
| A10227 | DAC Audio 37 | I2S | Hz | IMPLEMENTED |
| A10228 | ADC Audio 38 | I2S | Hz | IMPLEMENTED |
| A10229 | MP3 Player 39 | UART | track | IMPLEMENTED |
| A10230 | Microphone 40 | I2S | dB | IMPLEMENTED |
| A10231 | Speaker 41 | PWM | Hz | IMPLEMENTED |
| A10232 | TTS 42 | I2S | text | IMPLEMENTED |
| A10233 | DAC Audio 43 | I2S | Hz | IMPLEMENTED |
| A10234 | ADC Audio 44 | I2S | Hz | IMPLEMENTED |
| A10235 | MP3 Player 45 | UART | track | IMPLEMENTED |
| A10236 | Microphone 46 | I2S | dB | IMPLEMENTED |
| A10237 | Speaker 47 | PWM | Hz | IMPLEMENTED |
| A10238 | TTS 48 | I2S | text | IMPLEMENTED |
| A10239 | DAC Audio 49 | I2S | Hz | IMPLEMENTED |
| A10240 | ADC Audio 50 | I2S | Hz | IMPLEMENTED |

*... and 550 more AUDIO modules*

## AUTOMOTIVE

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A15391 | OBD-II 1 | UART | raw | IMPLEMENTED |
| A15392 | CAN Bus 2 | SPI | raw | IMPLEMENTED |
| A15393 | Fuel Sensor 3 | ANALOG | L | IMPLEMENTED |
| A15394 | Tire Pressure 4 | I2C | psi | IMPLEMENTED |
| A15395 | GPS Tracker 5 | UART | deg | IMPLEMENTED |
| A15396 | Speed Sensor 6 | DIGITAL | km/h | IMPLEMENTED |
| A15397 | OBD-II 7 | UART | raw | IMPLEMENTED |
| A15398 | CAN Bus 8 | SPI | raw | IMPLEMENTED |
| A15399 | Fuel Sensor 9 | ANALOG | L | IMPLEMENTED |
| A15400 | Tire Pressure 10 | I2C | psi | IMPLEMENTED |
| A15401 | GPS Tracker 11 | UART | deg | IMPLEMENTED |
| A15402 | Speed Sensor 12 | DIGITAL | km/h | IMPLEMENTED |
| A15403 | OBD-II 13 | UART | raw | IMPLEMENTED |
| A15404 | CAN Bus 14 | SPI | raw | IMPLEMENTED |
| A15405 | Fuel Sensor 15 | ANALOG | L | IMPLEMENTED |
| A15406 | Tire Pressure 16 | I2C | psi | IMPLEMENTED |
| A15407 | GPS Tracker 17 | UART | deg | IMPLEMENTED |
| A15408 | Speed Sensor 18 | DIGITAL | km/h | IMPLEMENTED |
| A15409 | OBD-II 19 | UART | raw | IMPLEMENTED |
| A15410 | CAN Bus 20 | SPI | raw | IMPLEMENTED |
| A15411 | Fuel Sensor 21 | ANALOG | L | IMPLEMENTED |
| A15412 | Tire Pressure 22 | I2C | psi | IMPLEMENTED |
| A15413 | GPS Tracker 23 | UART | deg | IMPLEMENTED |
| A15414 | Speed Sensor 24 | DIGITAL | km/h | IMPLEMENTED |
| A15415 | OBD-II 25 | UART | raw | IMPLEMENTED |
| A15416 | CAN Bus 26 | SPI | raw | IMPLEMENTED |
| A15417 | Fuel Sensor 27 | ANALOG | L | IMPLEMENTED |
| A15418 | Tire Pressure 28 | I2C | psi | IMPLEMENTED |
| A15419 | GPS Tracker 29 | UART | deg | IMPLEMENTED |
| A15420 | Speed Sensor 30 | DIGITAL | km/h | IMPLEMENTED |
| A15421 | OBD-II 31 | UART | raw | IMPLEMENTED |
| A15422 | CAN Bus 32 | SPI | raw | IMPLEMENTED |
| A15423 | Fuel Sensor 33 | ANALOG | L | IMPLEMENTED |
| A15424 | Tire Pressure 34 | I2C | psi | IMPLEMENTED |
| A15425 | GPS Tracker 35 | UART | deg | IMPLEMENTED |
| A15426 | Speed Sensor 36 | DIGITAL | km/h | IMPLEMENTED |
| A15427 | OBD-II 37 | UART | raw | IMPLEMENTED |
| A15428 | CAN Bus 38 | SPI | raw | IMPLEMENTED |
| A15429 | Fuel Sensor 39 | ANALOG | L | IMPLEMENTED |
| A15430 | Tire Pressure 40 | I2C | psi | IMPLEMENTED |
| A15431 | GPS Tracker 41 | UART | deg | IMPLEMENTED |
| A15432 | Speed Sensor 42 | DIGITAL | km/h | IMPLEMENTED |
| A15433 | OBD-II 43 | UART | raw | IMPLEMENTED |
| A15434 | CAN Bus 44 | SPI | raw | IMPLEMENTED |
| A15435 | Fuel Sensor 45 | ANALOG | L | IMPLEMENTED |
| A15436 | Tire Pressure 46 | I2C | psi | IMPLEMENTED |
| A15437 | GPS Tracker 47 | UART | deg | IMPLEMENTED |
| A15438 | Speed Sensor 48 | DIGITAL | km/h | IMPLEMENTED |
| A15439 | OBD-II 49 | UART | raw | IMPLEMENTED |
| A15440 | CAN Bus 50 | SPI | raw | IMPLEMENTED |

*... and 350 more AUTOMOTIVE modules*

## CAMERA

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A10791 | OV2640 Camera 1 | SPI | px | IMPLEMENTED |
| A10792 | OV7670 Camera 2 | SPI | px | IMPLEMENTED |
| A10793 | Thermal Camera 3 | I2C | C | IMPLEMENTED |
| A10794 | IR Camera 4 | I2C | px | IMPLEMENTED |
| A10795 | OV2640 Camera 5 | SPI | px | IMPLEMENTED |
| A10796 | OV7670 Camera 6 | SPI | px | IMPLEMENTED |
| A10797 | Thermal Camera 7 | I2C | C | IMPLEMENTED |
| A10798 | IR Camera 8 | I2C | px | IMPLEMENTED |
| A10799 | OV2640 Camera 9 | SPI | px | IMPLEMENTED |
| A10800 | OV7670 Camera 10 | SPI | px | IMPLEMENTED |
| A10801 | Thermal Camera 11 | I2C | C | IMPLEMENTED |
| A10802 | IR Camera 12 | I2C | px | IMPLEMENTED |
| A10803 | OV2640 Camera 13 | SPI | px | IMPLEMENTED |
| A10804 | OV7670 Camera 14 | SPI | px | IMPLEMENTED |
| A10805 | Thermal Camera 15 | I2C | C | IMPLEMENTED |
| A10806 | IR Camera 16 | I2C | px | IMPLEMENTED |
| A10807 | OV2640 Camera 17 | SPI | px | IMPLEMENTED |
| A10808 | OV7670 Camera 18 | SPI | px | IMPLEMENTED |
| A10809 | Thermal Camera 19 | I2C | C | IMPLEMENTED |
| A10810 | IR Camera 20 | I2C | px | IMPLEMENTED |
| A10811 | OV2640 Camera 21 | SPI | px | IMPLEMENTED |
| A10812 | OV7670 Camera 22 | SPI | px | IMPLEMENTED |
| A10813 | Thermal Camera 23 | I2C | C | IMPLEMENTED |
| A10814 | IR Camera 24 | I2C | px | IMPLEMENTED |
| A10815 | OV2640 Camera 25 | SPI | px | IMPLEMENTED |
| A10816 | OV7670 Camera 26 | SPI | px | IMPLEMENTED |
| A10817 | Thermal Camera 27 | I2C | C | IMPLEMENTED |
| A10818 | IR Camera 28 | I2C | px | IMPLEMENTED |
| A10819 | OV2640 Camera 29 | SPI | px | IMPLEMENTED |
| A10820 | OV7670 Camera 30 | SPI | px | IMPLEMENTED |
| A10821 | Thermal Camera 31 | I2C | C | IMPLEMENTED |
| A10822 | IR Camera 32 | I2C | px | IMPLEMENTED |
| A10823 | OV2640 Camera 33 | SPI | px | IMPLEMENTED |
| A10824 | OV7670 Camera 34 | SPI | px | IMPLEMENTED |
| A10825 | Thermal Camera 35 | I2C | C | IMPLEMENTED |
| A10826 | IR Camera 36 | I2C | px | IMPLEMENTED |
| A10827 | OV2640 Camera 37 | SPI | px | IMPLEMENTED |
| A10828 | OV7670 Camera 38 | SPI | px | IMPLEMENTED |
| A10829 | Thermal Camera 39 | I2C | C | IMPLEMENTED |
| A10830 | IR Camera 40 | I2C | px | IMPLEMENTED |
| A10831 | OV2640 Camera 41 | SPI | px | IMPLEMENTED |
| A10832 | OV7670 Camera 42 | SPI | px | IMPLEMENTED |
| A10833 | Thermal Camera 43 | I2C | C | IMPLEMENTED |
| A10834 | IR Camera 44 | I2C | px | IMPLEMENTED |
| A10835 | OV2640 Camera 45 | SPI | px | IMPLEMENTED |
| A10836 | OV7670 Camera 46 | SPI | px | IMPLEMENTED |
| A10837 | Thermal Camera 47 | I2C | C | IMPLEMENTED |
| A10838 | IR Camera 48 | I2C | px | IMPLEMENTED |
| A10839 | OV2640 Camera 49 | SPI | px | IMPLEMENTED |
| A10840 | OV7670 Camera 50 | SPI | px | IMPLEMENTED |

*... and 350 more CAMERA modules*

## COMMUNICATION

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A16991 | GSM Module 1 | UART | raw | IMPLEMENTED |
| A16992 | NB-IoT 2 | UART | raw | IMPLEMENTED |
| A16993 | LTE Module 3 | UART | raw | IMPLEMENTED |
| A16994 | Satellite 4 | UART | raw | IMPLEMENTED |
| A16995 | Mesh Network 5 | SPI | raw | IMPLEMENTED |
| A16996 | GSM Module 6 | UART | raw | IMPLEMENTED |
| A16997 | NB-IoT 7 | UART | raw | IMPLEMENTED |
| A16998 | LTE Module 8 | UART | raw | IMPLEMENTED |
| A16999 | Satellite 9 | UART | raw | IMPLEMENTED |
| A17000 | Mesh Network 10 | SPI | raw | IMPLEMENTED |
| A17001 | GSM Module 11 | UART | raw | IMPLEMENTED |
| A17002 | NB-IoT 12 | UART | raw | IMPLEMENTED |
| A17003 | LTE Module 13 | UART | raw | IMPLEMENTED |
| A17004 | Satellite 14 | UART | raw | IMPLEMENTED |
| A17005 | Mesh Network 15 | SPI | raw | IMPLEMENTED |
| A17006 | GSM Module 16 | UART | raw | IMPLEMENTED |
| A17007 | NB-IoT 17 | UART | raw | IMPLEMENTED |
| A17008 | LTE Module 18 | UART | raw | IMPLEMENTED |
| A17009 | Satellite 19 | UART | raw | IMPLEMENTED |
| A17010 | Mesh Network 20 | SPI | raw | IMPLEMENTED |
| A17011 | GSM Module 21 | UART | raw | IMPLEMENTED |
| A17012 | NB-IoT 22 | UART | raw | IMPLEMENTED |
| A17013 | LTE Module 23 | UART | raw | IMPLEMENTED |
| A17014 | Satellite 24 | UART | raw | IMPLEMENTED |
| A17015 | Mesh Network 25 | SPI | raw | IMPLEMENTED |
| A17016 | GSM Module 26 | UART | raw | IMPLEMENTED |
| A17017 | NB-IoT 27 | UART | raw | IMPLEMENTED |
| A17018 | LTE Module 28 | UART | raw | IMPLEMENTED |
| A17019 | Satellite 29 | UART | raw | IMPLEMENTED |
| A17020 | Mesh Network 30 | SPI | raw | IMPLEMENTED |
| A17021 | GSM Module 31 | UART | raw | IMPLEMENTED |
| A17022 | NB-IoT 32 | UART | raw | IMPLEMENTED |
| A17023 | LTE Module 33 | UART | raw | IMPLEMENTED |
| A17024 | Satellite 34 | UART | raw | IMPLEMENTED |
| A17025 | Mesh Network 35 | SPI | raw | IMPLEMENTED |
| A17026 | GSM Module 36 | UART | raw | IMPLEMENTED |
| A17027 | NB-IoT 37 | UART | raw | IMPLEMENTED |
| A17028 | LTE Module 38 | UART | raw | IMPLEMENTED |
| A17029 | Satellite 39 | UART | raw | IMPLEMENTED |
| A17030 | Mesh Network 40 | SPI | raw | IMPLEMENTED |
| A17031 | GSM Module 41 | UART | raw | IMPLEMENTED |
| A17032 | NB-IoT 42 | UART | raw | IMPLEMENTED |
| A17033 | LTE Module 43 | UART | raw | IMPLEMENTED |
| A17034 | Satellite 44 | UART | raw | IMPLEMENTED |
| A17035 | Mesh Network 45 | SPI | raw | IMPLEMENTED |
| A17036 | GSM Module 46 | UART | raw | IMPLEMENTED |
| A17037 | NB-IoT 47 | UART | raw | IMPLEMENTED |
| A17038 | LTE Module 48 | UART | raw | IMPLEMENTED |
| A17039 | Satellite 49 | UART | raw | IMPLEMENTED |
| A17040 | Mesh Network 50 | SPI | raw | IMPLEMENTED |

*... and 550 more COMMUNICATION modules*

## DIGITAL

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0283 | PIR HC-SR501 | GPIO | on/off | IMPLEMENTED |
| A0284 | PIR HC-SR505 | GPIO | on/off | IMPLEMENTED |
| A0285 | RCWL-0516 Radar | GPIO | on/off | IMPLEMENTED |
| A0286 | HLK-LD2410 Radar | UART | mm | IMPLEMENTED |
| A0287 | HLK-LD2450 Radar | UART | mm | IMPLEMENTED |
| A0288 | MR60BHA1 Radar | UART | mm | IMPLEMENTED |
| A0289 | IR Obstacle | GPIO | on/off | IMPLEMENTED |
| A0290 | IR Line Follower | GPIO | on/off | IMPLEMENTED |
| A0291 | Laser Receiver | GPIO | on/off | IMPLEMENTED |
| A0292 | IR Beam Break | GPIO | on/off | IMPLEMENTED |
| A0293 | Ultrasonic HC-SR04 | GPIO | cm | IMPLEMENTED |
| A0294 | Ultrasonic HC-SR04P | GPIO | cm | IMPLEMENTED |
| A0295 | Ultrasonic JSN-SR04T | GPIO | cm | IMPLEMENTED |
| A0296 | Ultrasonic SRF05 | GPIO | cm | IMPLEMENTED |
| A0297 | Ultrasonic SRF08 | GPIO | cm | IMPLEMENTED |
| A0298 | TOF VL53L0X | I2C | mm | IMPLEMENTED |
| A0299 | TOF VL53L1X | I2C | mm | IMPLEMENTED |
| A0300 | TOF VL6180X | I2C | mm | IMPLEMENTED |
| A0301 | TOF TMF8801 | I2C | mm | IMPLEMENTED |
| A0302 | Flame Digital | GPIO | on/off | IMPLEMENTED |
| A0303 | Smoke MQ-2 Digital | GPIO | on/off | IMPLEMENTED |
| A0304 | Gas MQ Digital | GPIO | on/off | IMPLEMENTED |
| A0305 | CO Alarm Digital | GPIO | on/off | IMPLEMENTED |
| A0306 | Smoke Alarm Digital | GPIO | on/off | IMPLEMENTED |
| A0307 | Gas Leak Digital | GPIO | on/off | IMPLEMENTED |
| A0308 | Touch TTP223 | GPIO | on/off | IMPLEMENTED |
| A0309 | Touch TTP224 | GPIO | on/off | IMPLEMENTED |
| A0310 | Touch TTP229 | GPIO | on/off | IMPLEMENTED |
| A0311 | Capacitive MPR121 | I2C | 12 ch | IMPLEMENTED |
| A0312 | Capacitive MPR121QR2 | I2C | 12 ch | IMPLEMENTED |
| A0313 | Capacitive STMPE610 | I2C | touch | IMPLEMENTED |
| A0314 | Capacitive FT6206 | I2C | touch | IMPLEMENTED |
| A0315 | Capacitive GT911 | I2C | touch | IMPLEMENTED |
| A0316 | Hall Digital A3144 | GPIO | on/off | IMPLEMENTED |
| A0317 | Hall Digital SS49E | GPIO | on/off | IMPLEMENTED |
| A0318 | Reed Switch | GPIO | on/off | IMPLEMENTED |
| A0319 | Reed Magnetic | GPIO | on/off | IMPLEMENTED |
| A0320 | Limit Switch | GPIO | on/off | IMPLEMENTED |
| A0321 | Endstop | GPIO | on/off | IMPLEMENTED |
| A0322 | Magnetic Door Sensor | GPIO | on/off | IMPLEMENTED |
| A0323 | Magnetic Window Sensor | GPIO | on/off | IMPLEMENTED |
| A0324 | Linear Hall SS49E | GPIO | mV | IMPLEMENTED |
| A0325 | Omnipolar Hall | GPIO | on/off | IMPLEMENTED |
| A0326 | Unipolar Hall | GPIO | on/off | IMPLEMENTED |
| A0327 | Latching Hall | GPIO | on/off | IMPLEMENTED |
| A0328 | Vibration SW-420 | GPIO | on/off | IMPLEMENTED |
| A0329 | Vibration SW-18015P | GPIO | on/off | IMPLEMENTED |
| A0330 | Shock SW-18010P | GPIO | on/off | IMPLEMENTED |
| A0331 | Shock SW-420 | GPIO | on/off | IMPLEMENTED |
| A0332 | Tilt Ball Switch | GPIO | on/off | IMPLEMENTED |

*... and 550 more DIGITAL modules*

## DISPLAY

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0637 | SSD1306 0.96" | I2C | display | IMPLEMENTED |
| A0638 | SSD1306 1.3" | I2C | display | IMPLEMENTED |
| A0639 | SSD1306 1.54" | I2C | display | IMPLEMENTED |
| A0640 | SSD1306 2.42" | I2C | display | IMPLEMENTED |
| A0641 | SH1106 1.3" | I2C | display | IMPLEMENTED |
| A0642 | SH1106 0.96" | I2C | display | IMPLEMENTED |
| A0643 | SH1107 | I2C | display | IMPLEMENTED |
| A0644 | SSD1322 | I2C | display | IMPLEMENTED |
| A0645 | SSD1325 | I2C | display | IMPLEMENTED |
| A0646 | SSD1327 | I2C | display | IMPLEMENTED |
| A0647 | LCD1602 I2C | I2C | display | IMPLEMENTED |
| A0648 | LCD2004 I2C | I2C | display | IMPLEMENTED |
| A0649 | LCD1602A I2C | I2C | display | IMPLEMENTED |
| A0650 | LCD2004A I2C | I2C | display | IMPLEMENTED |
| A0651 | HT16K33 8x8 | I2C | display | IMPLEMENTED |
| A0652 | HT16K33 8x16 | I2C | display | IMPLEMENTED |
| A0653 | IS31FL3731 | I2C | display | IMPLEMENTED |
| A0654 | IS31FL3731 Matrix | I2C | display | IMPLEMENTED |
| A0655 | MAX7219 Matrix I2C | I2C | display | IMPLEMENTED |
| A0656 | LM75A Display | I2C | display | IMPLEMENTED |
| A0657 | PCD8544 LCD | I2C | display | IMPLEMENTED |
| A0658 | PCD8544 84x48 | I2C | display | IMPLEMENTED |
| A0669 | ILI9341 2.8" | SPI | display | IMPLEMENTED |
| A0670 | ILI9341 3.5" | SPI | display | IMPLEMENTED |
| A0671 | ILI9341 2.4" | SPI | display | IMPLEMENTED |
| A0672 | ST7735 1.8" | SPI | display | IMPLEMENTED |
| A0673 | ST7735 1.44" | SPI | display | IMPLEMENTED |
| A0674 | ST7789 1.3" | SPI | display | IMPLEMENTED |
| A0675 | ST7789 1.47" | SPI | display | IMPLEMENTED |
| A0676 | ST7789 2.0" | SPI | display | IMPLEMENTED |
| A0677 | ST7789 2.4" | SPI | display | IMPLEMENTED |
| A0678 | HX8357 3.5" | SPI | display | IMPLEMENTED |
| A0679 | HX8357D | SPI | display | IMPLEMENTED |
| A0680 | SSD1351 1.5" | SPI | display | IMPLEMENTED |
| A0681 | SSD1331 0.96" | SPI | display | IMPLEMENTED |
| A0682 | SSD1327 OLED | SPI | display | IMPLEMENTED |
| A0683 | SH1107 OLED | SPI | display | IMPLEMENTED |
| A0684 | ePaper 1.54" | SPI | display | IMPLEMENTED |
| A0685 | ePaper 2.13" | SPI | display | IMPLEMENTED |
| A0686 | ePaper 2.9" | SPI | display | IMPLEMENTED |
| A0687 | ePaper 4.2" | SPI | display | IMPLEMENTED |
| A0688 | ePaper 7.5" | SPI | display | IMPLEMENTED |
| A0689 | ePaper 10.3" | SPI | display | IMPLEMENTED |
| A0690 | Waveshare 1.54" | SPI | display | IMPLEMENTED |
| A0691 | Waveshare 2.13" | SPI | display | IMPLEMENTED |
| A0692 | Waveshare 2.9" | SPI | display | IMPLEMENTED |
| A0693 | Waveshare 4.2" | SPI | display | IMPLEMENTED |
| A0694 | Waveshare 7.5" | SPI | display | IMPLEMENTED |
| A0695 | GD2301 | SPI | display | IMPLEMENTED |
| A0696 | RA8875 TFT | SPI | display | IMPLEMENTED |

*... and 350 more DISPLAY modules*

## DISPLAY_ADVANCED

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A17591 | TFT Display 1 | SPI | px | IMPLEMENTED |
| A17592 | E-Paper 2 | SPI | px | IMPLEMENTED |
| A17593 | OLED Advanced 3 | I2C | px | IMPLEMENTED |
| A17594 | LED Matrix 4 | SPI | px | IMPLEMENTED |
| A17595 | TFT Display 5 | SPI | px | IMPLEMENTED |
| A17596 | E-Paper 6 | SPI | px | IMPLEMENTED |
| A17597 | OLED Advanced 7 | I2C | px | IMPLEMENTED |
| A17598 | LED Matrix 8 | SPI | px | IMPLEMENTED |
| A17599 | TFT Display 9 | SPI | px | IMPLEMENTED |
| A17600 | E-Paper 10 | SPI | px | IMPLEMENTED |
| A17601 | OLED Advanced 11 | I2C | px | IMPLEMENTED |
| A17602 | LED Matrix 12 | SPI | px | IMPLEMENTED |
| A17603 | TFT Display 13 | SPI | px | IMPLEMENTED |
| A17604 | E-Paper 14 | SPI | px | IMPLEMENTED |
| A17605 | OLED Advanced 15 | I2C | px | IMPLEMENTED |
| A17606 | LED Matrix 16 | SPI | px | IMPLEMENTED |
| A17607 | TFT Display 17 | SPI | px | IMPLEMENTED |
| A17608 | E-Paper 18 | SPI | px | IMPLEMENTED |
| A17609 | OLED Advanced 19 | I2C | px | IMPLEMENTED |
| A17610 | LED Matrix 20 | SPI | px | IMPLEMENTED |
| A17611 | TFT Display 21 | SPI | px | IMPLEMENTED |
| A17612 | E-Paper 22 | SPI | px | IMPLEMENTED |
| A17613 | OLED Advanced 23 | I2C | px | IMPLEMENTED |
| A17614 | LED Matrix 24 | SPI | px | IMPLEMENTED |
| A17615 | TFT Display 25 | SPI | px | IMPLEMENTED |
| A17616 | E-Paper 26 | SPI | px | IMPLEMENTED |
| A17617 | OLED Advanced 27 | I2C | px | IMPLEMENTED |
| A17618 | LED Matrix 28 | SPI | px | IMPLEMENTED |
| A17619 | TFT Display 29 | SPI | px | IMPLEMENTED |
| A17620 | E-Paper 30 | SPI | px | IMPLEMENTED |
| A17621 | OLED Advanced 31 | I2C | px | IMPLEMENTED |
| A17622 | LED Matrix 32 | SPI | px | IMPLEMENTED |
| A17623 | TFT Display 33 | SPI | px | IMPLEMENTED |
| A17624 | E-Paper 34 | SPI | px | IMPLEMENTED |
| A17625 | OLED Advanced 35 | I2C | px | IMPLEMENTED |
| A17626 | LED Matrix 36 | SPI | px | IMPLEMENTED |
| A17627 | TFT Display 37 | SPI | px | IMPLEMENTED |
| A17628 | E-Paper 38 | SPI | px | IMPLEMENTED |
| A17629 | OLED Advanced 39 | I2C | px | IMPLEMENTED |
| A17630 | LED Matrix 40 | SPI | px | IMPLEMENTED |
| A17631 | TFT Display 41 | SPI | px | IMPLEMENTED |
| A17632 | E-Paper 42 | SPI | px | IMPLEMENTED |
| A17633 | OLED Advanced 43 | I2C | px | IMPLEMENTED |
| A17634 | LED Matrix 44 | SPI | px | IMPLEMENTED |
| A17635 | TFT Display 45 | SPI | px | IMPLEMENTED |
| A17636 | E-Paper 46 | SPI | px | IMPLEMENTED |
| A17637 | OLED Advanced 47 | I2C | px | IMPLEMENTED |
| A17638 | LED Matrix 48 | SPI | px | IMPLEMENTED |
| A17639 | TFT Display 49 | SPI | px | IMPLEMENTED |
| A17640 | E-Paper 50 | SPI | px | IMPLEMENTED |

*... and 250 more DISPLAY_ADVANCED modules*

## ENERGY

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A16491 | Solar Panel 1 | ANALOG | V | IMPLEMENTED |
| A16492 | Wind Turbine 2 | ANALOG | V | IMPLEMENTED |
| A16493 | Battery Bank 3 | I2C | V | IMPLEMENTED |
| A16494 | Power Grid 4 | I2C | W | IMPLEMENTED |
| A16495 | Energy Meter 5 | I2C | kWh | IMPLEMENTED |
| A16496 | Solar Panel 6 | ANALOG | V | IMPLEMENTED |
| A16497 | Wind Turbine 7 | ANALOG | V | IMPLEMENTED |
| A16498 | Battery Bank 8 | I2C | V | IMPLEMENTED |
| A16499 | Power Grid 9 | I2C | W | IMPLEMENTED |
| A16500 | Energy Meter 10 | I2C | kWh | IMPLEMENTED |
| A16501 | Solar Panel 11 | ANALOG | V | IMPLEMENTED |
| A16502 | Wind Turbine 12 | ANALOG | V | IMPLEMENTED |
| A16503 | Battery Bank 13 | I2C | V | IMPLEMENTED |
| A16504 | Power Grid 14 | I2C | W | IMPLEMENTED |
| A16505 | Energy Meter 15 | I2C | kWh | IMPLEMENTED |
| A16506 | Solar Panel 16 | ANALOG | V | IMPLEMENTED |
| A16507 | Wind Turbine 17 | ANALOG | V | IMPLEMENTED |
| A16508 | Battery Bank 18 | I2C | V | IMPLEMENTED |
| A16509 | Power Grid 19 | I2C | W | IMPLEMENTED |
| A16510 | Energy Meter 20 | I2C | kWh | IMPLEMENTED |
| A16511 | Solar Panel 21 | ANALOG | V | IMPLEMENTED |
| A16512 | Wind Turbine 22 | ANALOG | V | IMPLEMENTED |
| A16513 | Battery Bank 23 | I2C | V | IMPLEMENTED |
| A16514 | Power Grid 24 | I2C | W | IMPLEMENTED |
| A16515 | Energy Meter 25 | I2C | kWh | IMPLEMENTED |
| A16516 | Solar Panel 26 | ANALOG | V | IMPLEMENTED |
| A16517 | Wind Turbine 27 | ANALOG | V | IMPLEMENTED |
| A16518 | Battery Bank 28 | I2C | V | IMPLEMENTED |
| A16519 | Power Grid 29 | I2C | W | IMPLEMENTED |
| A16520 | Energy Meter 30 | I2C | kWh | IMPLEMENTED |
| A16521 | Solar Panel 31 | ANALOG | V | IMPLEMENTED |
| A16522 | Wind Turbine 32 | ANALOG | V | IMPLEMENTED |
| A16523 | Battery Bank 33 | I2C | V | IMPLEMENTED |
| A16524 | Power Grid 34 | I2C | W | IMPLEMENTED |
| A16525 | Energy Meter 35 | I2C | kWh | IMPLEMENTED |
| A16526 | Solar Panel 36 | ANALOG | V | IMPLEMENTED |
| A16527 | Wind Turbine 37 | ANALOG | V | IMPLEMENTED |
| A16528 | Battery Bank 38 | I2C | V | IMPLEMENTED |
| A16529 | Power Grid 39 | I2C | W | IMPLEMENTED |
| A16530 | Energy Meter 40 | I2C | kWh | IMPLEMENTED |
| A16531 | Solar Panel 41 | ANALOG | V | IMPLEMENTED |
| A16532 | Wind Turbine 42 | ANALOG | V | IMPLEMENTED |
| A16533 | Battery Bank 43 | I2C | V | IMPLEMENTED |
| A16534 | Power Grid 44 | I2C | W | IMPLEMENTED |
| A16535 | Energy Meter 45 | I2C | kWh | IMPLEMENTED |
| A16536 | Solar Panel 46 | ANALOG | V | IMPLEMENTED |
| A16537 | Wind Turbine 47 | ANALOG | V | IMPLEMENTED |
| A16538 | Battery Bank 48 | I2C | V | IMPLEMENTED |
| A16539 | Power Grid 49 | I2C | W | IMPLEMENTED |
| A16540 | Energy Meter 50 | I2C | kWh | IMPLEMENTED |

*... and 450 more ENERGY modules*

## ENVIRONMENT

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A11191 | Weather Station 1 | I2C | raw | IMPLEMENTED |
| A11192 | Air Quality 2 | I2C | aqi | IMPLEMENTED |
| A11193 | CO2 Sensor 3 | I2C | ppm | IMPLEMENTED |
| A11194 | VOC Sensor 4 | I2C | ppb | IMPLEMENTED |
| A11195 | Particulate 5 | UART | ug/m3 | IMPLEMENTED |
| A11196 | Ozone Sensor 6 | ANALOG | ppb | IMPLEMENTED |
| A11197 | NO2 Sensor 7 | ANALOG | ppb | IMPLEMENTED |
| A11198 | SO2 Sensor 8 | ANALOG | ppb | IMPLEMENTED |
| A11199 | Weather Station 9 | I2C | raw | IMPLEMENTED |
| A11200 | Air Quality 10 | I2C | aqi | IMPLEMENTED |
| A11201 | CO2 Sensor 11 | I2C | ppm | IMPLEMENTED |
| A11202 | VOC Sensor 12 | I2C | ppb | IMPLEMENTED |
| A11203 | Particulate 13 | UART | ug/m3 | IMPLEMENTED |
| A11204 | Ozone Sensor 14 | ANALOG | ppb | IMPLEMENTED |
| A11205 | NO2 Sensor 15 | ANALOG | ppb | IMPLEMENTED |
| A11206 | SO2 Sensor 16 | ANALOG | ppb | IMPLEMENTED |
| A11207 | Weather Station 17 | I2C | raw | IMPLEMENTED |
| A11208 | Air Quality 18 | I2C | aqi | IMPLEMENTED |
| A11209 | CO2 Sensor 19 | I2C | ppm | IMPLEMENTED |
| A11210 | VOC Sensor 20 | I2C | ppb | IMPLEMENTED |
| A11211 | Particulate 21 | UART | ug/m3 | IMPLEMENTED |
| A11212 | Ozone Sensor 22 | ANALOG | ppb | IMPLEMENTED |
| A11213 | NO2 Sensor 23 | ANALOG | ppb | IMPLEMENTED |
| A11214 | SO2 Sensor 24 | ANALOG | ppb | IMPLEMENTED |
| A11215 | Weather Station 25 | I2C | raw | IMPLEMENTED |
| A11216 | Air Quality 26 | I2C | aqi | IMPLEMENTED |
| A11217 | CO2 Sensor 27 | I2C | ppm | IMPLEMENTED |
| A11218 | VOC Sensor 28 | I2C | ppb | IMPLEMENTED |
| A11219 | Particulate 29 | UART | ug/m3 | IMPLEMENTED |
| A11220 | Ozone Sensor 30 | ANALOG | ppb | IMPLEMENTED |
| A11221 | NO2 Sensor 31 | ANALOG | ppb | IMPLEMENTED |
| A11222 | SO2 Sensor 32 | ANALOG | ppb | IMPLEMENTED |
| A11223 | Weather Station 33 | I2C | raw | IMPLEMENTED |
| A11224 | Air Quality 34 | I2C | aqi | IMPLEMENTED |
| A11225 | CO2 Sensor 35 | I2C | ppm | IMPLEMENTED |
| A11226 | VOC Sensor 36 | I2C | ppb | IMPLEMENTED |
| A11227 | Particulate 37 | UART | ug/m3 | IMPLEMENTED |
| A11228 | Ozone Sensor 38 | ANALOG | ppb | IMPLEMENTED |
| A11229 | NO2 Sensor 39 | ANALOG | ppb | IMPLEMENTED |
| A11230 | SO2 Sensor 40 | ANALOG | ppb | IMPLEMENTED |
| A11231 | Weather Station 41 | I2C | raw | IMPLEMENTED |
| A11232 | Air Quality 42 | I2C | aqi | IMPLEMENTED |
| A11233 | CO2 Sensor 43 | I2C | ppm | IMPLEMENTED |
| A11234 | VOC Sensor 44 | I2C | ppb | IMPLEMENTED |
| A11235 | Particulate 45 | UART | ug/m3 | IMPLEMENTED |
| A11236 | Ozone Sensor 46 | ANALOG | ppb | IMPLEMENTED |
| A11237 | NO2 Sensor 47 | ANALOG | ppb | IMPLEMENTED |
| A11238 | SO2 Sensor 48 | ANALOG | ppb | IMPLEMENTED |
| A11239 | Weather Station 49 | I2C | raw | IMPLEMENTED |
| A11240 | Air Quality 50 | I2C | aqi | IMPLEMENTED |

*... and 1150 more ENVIRONMENT modules*

## HOME_AUTOMATION

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A14691 | Smart Switch 1 | DIGITAL | bool | IMPLEMENTED |
| A14692 | Smart Dimmer 2 | PWM | duty | IMPLEMENTED |
| A14693 | Thermostat 3 | I2C | C | IMPLEMENTED |
| A14694 | Smart Lock 4 | DIGITAL | bool | IMPLEMENTED |
| A14695 | Motion Detector 5 | DIGITAL | bool | IMPLEMENTED |
| A14696 | Doorbell 6 | DIGITAL | bool | IMPLEMENTED |
| A14697 | Garage Door 7 | DIGITAL | bool | IMPLEMENTED |
| A14698 | Blind Controller 8 | PWM | pos | IMPLEMENTED |
| A14699 | Smart Switch 9 | DIGITAL | bool | IMPLEMENTED |
| A14700 | Smart Dimmer 10 | PWM | duty | IMPLEMENTED |
| A14701 | Thermostat 11 | I2C | C | IMPLEMENTED |
| A14702 | Smart Lock 12 | DIGITAL | bool | IMPLEMENTED |
| A14703 | Motion Detector 13 | DIGITAL | bool | IMPLEMENTED |
| A14704 | Doorbell 14 | DIGITAL | bool | IMPLEMENTED |
| A14705 | Garage Door 15 | DIGITAL | bool | IMPLEMENTED |
| A14706 | Blind Controller 16 | PWM | pos | IMPLEMENTED |
| A14707 | Smart Switch 17 | DIGITAL | bool | IMPLEMENTED |
| A14708 | Smart Dimmer 18 | PWM | duty | IMPLEMENTED |
| A14709 | Thermostat 19 | I2C | C | IMPLEMENTED |
| A14710 | Smart Lock 20 | DIGITAL | bool | IMPLEMENTED |
| A14711 | Motion Detector 21 | DIGITAL | bool | IMPLEMENTED |
| A14712 | Doorbell 22 | DIGITAL | bool | IMPLEMENTED |
| A14713 | Garage Door 23 | DIGITAL | bool | IMPLEMENTED |
| A14714 | Blind Controller 24 | PWM | pos | IMPLEMENTED |
| A14715 | Smart Switch 25 | DIGITAL | bool | IMPLEMENTED |
| A14716 | Smart Dimmer 26 | PWM | duty | IMPLEMENTED |
| A14717 | Thermostat 27 | I2C | C | IMPLEMENTED |
| A14718 | Smart Lock 28 | DIGITAL | bool | IMPLEMENTED |
| A14719 | Motion Detector 29 | DIGITAL | bool | IMPLEMENTED |
| A14720 | Doorbell 30 | DIGITAL | bool | IMPLEMENTED |
| A14721 | Garage Door 31 | DIGITAL | bool | IMPLEMENTED |
| A14722 | Blind Controller 32 | PWM | pos | IMPLEMENTED |
| A14723 | Smart Switch 33 | DIGITAL | bool | IMPLEMENTED |
| A14724 | Smart Dimmer 34 | PWM | duty | IMPLEMENTED |
| A14725 | Thermostat 35 | I2C | C | IMPLEMENTED |
| A14726 | Smart Lock 36 | DIGITAL | bool | IMPLEMENTED |
| A14727 | Motion Detector 37 | DIGITAL | bool | IMPLEMENTED |
| A14728 | Doorbell 38 | DIGITAL | bool | IMPLEMENTED |
| A14729 | Garage Door 39 | DIGITAL | bool | IMPLEMENTED |
| A14730 | Blind Controller 40 | PWM | pos | IMPLEMENTED |
| A14731 | Smart Switch 41 | DIGITAL | bool | IMPLEMENTED |
| A14732 | Smart Dimmer 42 | PWM | duty | IMPLEMENTED |
| A14733 | Thermostat 43 | I2C | C | IMPLEMENTED |
| A14734 | Smart Lock 44 | DIGITAL | bool | IMPLEMENTED |
| A14735 | Motion Detector 45 | DIGITAL | bool | IMPLEMENTED |
| A14736 | Doorbell 46 | DIGITAL | bool | IMPLEMENTED |
| A14737 | Garage Door 47 | DIGITAL | bool | IMPLEMENTED |
| A14738 | Blind Controller 48 | PWM | pos | IMPLEMENTED |
| A14739 | Smart Switch 49 | DIGITAL | bool | IMPLEMENTED |
| A14740 | Smart Dimmer 50 | PWM | duty | IMPLEMENTED |

*... and 650 more HOME_AUTOMATION modules*

## I2C

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0370 | MPU6050 | I2C | g/deg/s | IMPLEMENTED |
| A0371 | MPU6050 6-axis | I2C | g/deg/s | IMPLEMENTED |
| A0372 | MPU9250 | I2C | 9-DOF | IMPLEMENTED |
| A0373 | MPU9255 | I2C | 9-DOF | IMPLEMENTED |
| A0374 | MPU9250 9-axis | I2C | 9-DOF | IMPLEMENTED |
| A0375 | ICM20948 | I2C | 9-DOF | IMPLEMENTED |
| A0376 | ICM20608 | I2C | 6-DOF | IMPLEMENTED |
| A0377 | ICM20602 | I2C | 6-DOF | IMPLEMENTED |
| A0378 | ICM20649 | I2C | 6-DOF | IMPLEMENTED |
| A0379 | ICM20689 | I2C | 6-DOF | IMPLEMENTED |
| A0380 | ICM42688 | I2C | 6-DOF | IMPLEMENTED |
| A0381 | BNO055 | I2C | 9-DOF | IMPLEMENTED |
| A0382 | BNO080 | I2C | 9-DOF | IMPLEMENTED |
| A0383 | BNO085 | I2C | 9-DOF | IMPLEMENTED |
| A0384 | LSM6DS3 | I2C | 6-DOF | IMPLEMENTED |
| A0385 | LSM6DSL | I2C | 6-DOF | IMPLEMENTED |
| A0386 | LSM6DSO | I2C | 6-DOF | IMPLEMENTED |
| A0387 | LSM6DSRX | I2C | 6-DOF | IMPLEMENTED |
| A0388 | LSM6DSM | I2C | 6-DOF | IMPLEMENTED |
| A0389 | LSM6DS3H | I2C | 6-DOF | IMPLEMENTED |
| A0390 | BMI160 | I2C | 6-DOF | IMPLEMENTED |
| A0391 | BMI160 6-axis | I2C | 6-DOF | IMPLEMENTED |
| A0392 | BMI270 | I2C | 6-DOF | IMPLEMENTED |
| A0393 | BMI088 | I2C | 6-DOF | IMPLEMENTED |
| A0394 | ADXL345 | I2C | g | IMPLEMENTED |
| A0395 | ADXL335 | I2C | g | IMPLEMENTED |
| A0396 | ADXL377 | I2C | g | IMPLEMENTED |
| A0397 | ADXL362 | I2C | g | IMPLEMENTED |
| A0398 | L3G4200D | I2C | deg/s | IMPLEMENTED |
| A0399 | L3GD20 | I2C | deg/s | IMPLEMENTED |
| A0400 | L3GD20H | I2C | deg/s | IMPLEMENTED |
| A0401 | HMC5883L | I2C | µT | IMPLEMENTED |
| A0402 | HMC5983 | I2C | µT | IMPLEMENTED |
| A0403 | QMC5883L | I2C | µT | IMPLEMENTED |
| A0404 | QMC6300 | I2C | µT | IMPLEMENTED |
| A0405 | MMC5883MA | I2C | µT | IMPLEMENTED |
| A0406 | MMC5983MA | I2C | µT | IMPLEMENTED |
| A0407 | SHT31 | I2C | °C/%RH | IMPLEMENTED |
| A0408 | SHT35 | I2C | °C/%RH | IMPLEMENTED |
| A0409 | SHT40 | I2C | °C/%RH | IMPLEMENTED |
| A0410 | SHT41 | I2C | °C/%RH | IMPLEMENTED |
| A0411 | SHT45 | I2C | °C/%RH | IMPLEMENTED |
| A0412 | AHT10 | I2C | °C/%RH | IMPLEMENTED |
| A0413 | AHT20 | I2C | °C/%RH | IMPLEMENTED |
| A0414 | AHT21 | I2C | °C/%RH | IMPLEMENTED |
| A0415 | AHT25 | I2C | °C/%RH | IMPLEMENTED |
| A0416 | MCP9808 | I2C | °C | IMPLEMENTED |
| A0417 | MCP9804 | I2C | °C | IMPLEMENTED |
| A0418 | TMP117 | I2C | °C | IMPLEMENTED |
| A0419 | TMP116 | I2C | °C | IMPLEMENTED |

*... and 1150 more I2C modules*

## INDUSTRIAL

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A12391 | Modbus RTU 1 | UART | raw | IMPLEMENTED |
| A12392 | CAN Bus 2 | SPI | raw | IMPLEMENTED |
| A12393 | 4-20mA 3 | ANALOG | mA | IMPLEMENTED |
| A12394 | RS485 4 | UART | raw | IMPLEMENTED |
| A12395 | Industrial Sensor 5 | I2C | raw | IMPLEMENTED |
| A12396 | PLC Interface 6 | SPI | raw | IMPLEMENTED |
| A12397 | Modbus RTU 7 | UART | raw | IMPLEMENTED |
| A12398 | CAN Bus 8 | SPI | raw | IMPLEMENTED |
| A12399 | 4-20mA 9 | ANALOG | mA | IMPLEMENTED |
| A12400 | RS485 10 | UART | raw | IMPLEMENTED |
| A12401 | Industrial Sensor 11 | I2C | raw | IMPLEMENTED |
| A12402 | PLC Interface 12 | SPI | raw | IMPLEMENTED |
| A12403 | Modbus RTU 13 | UART | raw | IMPLEMENTED |
| A12404 | CAN Bus 14 | SPI | raw | IMPLEMENTED |
| A12405 | 4-20mA 15 | ANALOG | mA | IMPLEMENTED |
| A12406 | RS485 16 | UART | raw | IMPLEMENTED |
| A12407 | Industrial Sensor 17 | I2C | raw | IMPLEMENTED |
| A12408 | PLC Interface 18 | SPI | raw | IMPLEMENTED |
| A12409 | Modbus RTU 19 | UART | raw | IMPLEMENTED |
| A12410 | CAN Bus 20 | SPI | raw | IMPLEMENTED |
| A12411 | 4-20mA 21 | ANALOG | mA | IMPLEMENTED |
| A12412 | RS485 22 | UART | raw | IMPLEMENTED |
| A12413 | Industrial Sensor 23 | I2C | raw | IMPLEMENTED |
| A12414 | PLC Interface 24 | SPI | raw | IMPLEMENTED |
| A12415 | Modbus RTU 25 | UART | raw | IMPLEMENTED |
| A12416 | CAN Bus 26 | SPI | raw | IMPLEMENTED |
| A12417 | 4-20mA 27 | ANALOG | mA | IMPLEMENTED |
| A12418 | RS485 28 | UART | raw | IMPLEMENTED |
| A12419 | Industrial Sensor 29 | I2C | raw | IMPLEMENTED |
| A12420 | PLC Interface 30 | SPI | raw | IMPLEMENTED |
| A12421 | Modbus RTU 31 | UART | raw | IMPLEMENTED |
| A12422 | CAN Bus 32 | SPI | raw | IMPLEMENTED |
| A12423 | 4-20mA 33 | ANALOG | mA | IMPLEMENTED |
| A12424 | RS485 34 | UART | raw | IMPLEMENTED |
| A12425 | Industrial Sensor 35 | I2C | raw | IMPLEMENTED |
| A12426 | PLC Interface 36 | SPI | raw | IMPLEMENTED |
| A12427 | Modbus RTU 37 | UART | raw | IMPLEMENTED |
| A12428 | CAN Bus 38 | SPI | raw | IMPLEMENTED |
| A12429 | 4-20mA 39 | ANALOG | mA | IMPLEMENTED |
| A12430 | RS485 40 | UART | raw | IMPLEMENTED |
| A12431 | Industrial Sensor 41 | I2C | raw | IMPLEMENTED |
| A12432 | PLC Interface 42 | SPI | raw | IMPLEMENTED |
| A12433 | Modbus RTU 43 | UART | raw | IMPLEMENTED |
| A12434 | CAN Bus 44 | SPI | raw | IMPLEMENTED |
| A12435 | 4-20mA 45 | ANALOG | mA | IMPLEMENTED |
| A12436 | RS485 46 | UART | raw | IMPLEMENTED |
| A12437 | Industrial Sensor 47 | I2C | raw | IMPLEMENTED |
| A12438 | PLC Interface 48 | SPI | raw | IMPLEMENTED |
| A12439 | Modbus RTU 49 | UART | raw | IMPLEMENTED |
| A12440 | CAN Bus 50 | SPI | raw | IMPLEMENTED |

*... and 750 more INDUSTRIAL modules*

## MEDICAL

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A13191 | Heart Rate 1 | I2C | bpm | IMPLEMENTED |
| A13192 | SpO2 2 | I2C | % | IMPLEMENTED |
| A13193 | ECG 3 | ANALOG | mV | IMPLEMENTED |
| A13194 | Blood Pressure 4 | I2C | mmHg | IMPLEMENTED |
| A13195 | Body Temp 5 | I2C | C | IMPLEMENTED |
| A13196 | Glucose 6 | I2C | mg/dL | IMPLEMENTED |
| A13197 | Heart Rate 7 | I2C | bpm | IMPLEMENTED |
| A13198 | SpO2 8 | I2C | % | IMPLEMENTED |
| A13199 | ECG 9 | ANALOG | mV | IMPLEMENTED |
| A13200 | Blood Pressure 10 | I2C | mmHg | IMPLEMENTED |
| A13201 | Body Temp 11 | I2C | C | IMPLEMENTED |
| A13202 | Glucose 12 | I2C | mg/dL | IMPLEMENTED |
| A13203 | Heart Rate 13 | I2C | bpm | IMPLEMENTED |
| A13204 | SpO2 14 | I2C | % | IMPLEMENTED |
| A13205 | ECG 15 | ANALOG | mV | IMPLEMENTED |
| A13206 | Blood Pressure 16 | I2C | mmHg | IMPLEMENTED |
| A13207 | Body Temp 17 | I2C | C | IMPLEMENTED |
| A13208 | Glucose 18 | I2C | mg/dL | IMPLEMENTED |
| A13209 | Heart Rate 19 | I2C | bpm | IMPLEMENTED |
| A13210 | SpO2 20 | I2C | % | IMPLEMENTED |
| A13211 | ECG 21 | ANALOG | mV | IMPLEMENTED |
| A13212 | Blood Pressure 22 | I2C | mmHg | IMPLEMENTED |
| A13213 | Body Temp 23 | I2C | C | IMPLEMENTED |
| A13214 | Glucose 24 | I2C | mg/dL | IMPLEMENTED |
| A13215 | Heart Rate 25 | I2C | bpm | IMPLEMENTED |
| A13216 | SpO2 26 | I2C | % | IMPLEMENTED |
| A13217 | ECG 27 | ANALOG | mV | IMPLEMENTED |
| A13218 | Blood Pressure 28 | I2C | mmHg | IMPLEMENTED |
| A13219 | Body Temp 29 | I2C | C | IMPLEMENTED |
| A13220 | Glucose 30 | I2C | mg/dL | IMPLEMENTED |
| A13221 | Heart Rate 31 | I2C | bpm | IMPLEMENTED |
| A13222 | SpO2 32 | I2C | % | IMPLEMENTED |
| A13223 | ECG 33 | ANALOG | mV | IMPLEMENTED |
| A13224 | Blood Pressure 34 | I2C | mmHg | IMPLEMENTED |
| A13225 | Body Temp 35 | I2C | C | IMPLEMENTED |
| A13226 | Glucose 36 | I2C | mg/dL | IMPLEMENTED |
| A13227 | Heart Rate 37 | I2C | bpm | IMPLEMENTED |
| A13228 | SpO2 38 | I2C | % | IMPLEMENTED |
| A13229 | ECG 39 | ANALOG | mV | IMPLEMENTED |
| A13230 | Blood Pressure 40 | I2C | mmHg | IMPLEMENTED |
| A13231 | Body Temp 41 | I2C | C | IMPLEMENTED |
| A13232 | Glucose 42 | I2C | mg/dL | IMPLEMENTED |
| A13233 | Heart Rate 43 | I2C | bpm | IMPLEMENTED |
| A13234 | SpO2 44 | I2C | % | IMPLEMENTED |
| A13235 | ECG 45 | ANALOG | mV | IMPLEMENTED |
| A13236 | Blood Pressure 46 | I2C | mmHg | IMPLEMENTED |
| A13237 | Body Temp 47 | I2C | C | IMPLEMENTED |
| A13238 | Glucose 48 | I2C | mg/dL | IMPLEMENTED |
| A13239 | Heart Rate 49 | I2C | bpm | IMPLEMENTED |
| A13240 | SpO2 50 | I2C | % | IMPLEMENTED |

*... and 350 more MEDICAL modules*

## MOTOR

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A9391 | DC Motor 1 | PWM | rpm | IMPLEMENTED |
| A9392 | Stepper Motor 2 | PWM | steps | IMPLEMENTED |
| A9393 | Servo Motor 3 | PWM | deg | IMPLEMENTED |
| A9394 | BLDC Motor 4 | PWM | rpm | IMPLEMENTED |
| A9395 | Linear Actuator 5 | PWM | mm | IMPLEMENTED |
| A9396 | ESC 6 | PWM | duty | IMPLEMENTED |
| A9397 | DC Motor 7 | PWM | rpm | IMPLEMENTED |
| A9398 | Stepper Motor 8 | PWM | steps | IMPLEMENTED |
| A9399 | Servo Motor 9 | PWM | deg | IMPLEMENTED |
| A9400 | BLDC Motor 10 | PWM | rpm | IMPLEMENTED |
| A9401 | Linear Actuator 11 | PWM | mm | IMPLEMENTED |
| A9402 | ESC 12 | PWM | duty | IMPLEMENTED |
| A9403 | DC Motor 13 | PWM | rpm | IMPLEMENTED |
| A9404 | Stepper Motor 14 | PWM | steps | IMPLEMENTED |
| A9405 | Servo Motor 15 | PWM | deg | IMPLEMENTED |
| A9406 | BLDC Motor 16 | PWM | rpm | IMPLEMENTED |
| A9407 | Linear Actuator 17 | PWM | mm | IMPLEMENTED |
| A9408 | ESC 18 | PWM | duty | IMPLEMENTED |
| A9409 | DC Motor 19 | PWM | rpm | IMPLEMENTED |
| A9410 | Stepper Motor 20 | PWM | steps | IMPLEMENTED |
| A9411 | Servo Motor 21 | PWM | deg | IMPLEMENTED |
| A9412 | BLDC Motor 22 | PWM | rpm | IMPLEMENTED |
| A9413 | Linear Actuator 23 | PWM | mm | IMPLEMENTED |
| A9414 | ESC 24 | PWM | duty | IMPLEMENTED |
| A9415 | DC Motor 25 | PWM | rpm | IMPLEMENTED |
| A9416 | Stepper Motor 26 | PWM | steps | IMPLEMENTED |
| A9417 | Servo Motor 27 | PWM | deg | IMPLEMENTED |
| A9418 | BLDC Motor 28 | PWM | rpm | IMPLEMENTED |
| A9419 | Linear Actuator 29 | PWM | mm | IMPLEMENTED |
| A9420 | ESC 30 | PWM | duty | IMPLEMENTED |
| A9421 | DC Motor 31 | PWM | rpm | IMPLEMENTED |
| A9422 | Stepper Motor 32 | PWM | steps | IMPLEMENTED |
| A9423 | Servo Motor 33 | PWM | deg | IMPLEMENTED |
| A9424 | BLDC Motor 34 | PWM | rpm | IMPLEMENTED |
| A9425 | Linear Actuator 35 | PWM | mm | IMPLEMENTED |
| A9426 | ESC 36 | PWM | duty | IMPLEMENTED |
| A9427 | DC Motor 37 | PWM | rpm | IMPLEMENTED |
| A9428 | Stepper Motor 38 | PWM | steps | IMPLEMENTED |
| A9429 | Servo Motor 39 | PWM | deg | IMPLEMENTED |
| A9430 | BLDC Motor 40 | PWM | rpm | IMPLEMENTED |
| A9431 | Linear Actuator 41 | PWM | mm | IMPLEMENTED |
| A9432 | ESC 42 | PWM | duty | IMPLEMENTED |
| A9433 | DC Motor 43 | PWM | rpm | IMPLEMENTED |
| A9434 | Stepper Motor 44 | PWM | steps | IMPLEMENTED |
| A9435 | Servo Motor 45 | PWM | deg | IMPLEMENTED |
| A9436 | BLDC Motor 46 | PWM | rpm | IMPLEMENTED |
| A9437 | Linear Actuator 47 | PWM | mm | IMPLEMENTED |
| A9438 | ESC 48 | PWM | duty | IMPLEMENTED |
| A9439 | DC Motor 49 | PWM | rpm | IMPLEMENTED |
| A9440 | Stepper Motor 50 | PWM | steps | IMPLEMENTED |

*... and 750 more MOTOR modules*

## ONEWIRE

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0866 | DS18B20 | 1-WIRE | °C | IMPLEMENTED |
| A0867 | DS18S20 | 1-WIRE | °C | IMPLEMENTED |
| A0868 | DS1822 | 1-WIRE | °C | IMPLEMENTED |
| A0869 | DS1825 | 1-WIRE | °C | IMPLEMENTED |
| A0870 | DS2438 | 1-WIRE | V/A/°C | IMPLEMENTED |
| A0871 | DS2413 | 1-WIRE | 2 GPIO | IMPLEMENTED |
| A0872 | DS2406 | 1-WIRE | 2 GPIO | IMPLEMENTED |
| A0873 | DS2408 | 1-WIRE | 8 GPIO | IMPLEMENTED |
| A0874 | DS2450 | 1-WIRE | 4-ch ADC | IMPLEMENTED |
| A0875 | DS2417 | 1-WIRE | time | IMPLEMENTED |
| A0876 | DS2423 | 1-WIRE | counter | IMPLEMENTED |
| A0877 | iButton DS1990A | 1-WIRE | UID | IMPLEMENTED |
| A0878 | iButton DS1921 | 1-WIRE | temp log | IMPLEMENTED |
| A0879 | iButton DS1922 | 1-WIRE | temp log | IMPLEMENTED |
| A0880 | iButton DS1963 | 1-WIRE | SHA | IMPLEMENTED |
| A1987 | 1-Wire Sensor 1 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1988 | 1-Wire Device 2 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1989 | 1-Wire Sensor 3 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1990 | 1-Wire Device 4 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1991 | 1-Wire Sensor 5 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1992 | 1-Wire Device 6 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1993 | 1-Wire Sensor 7 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1994 | 1-Wire Device 8 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1995 | 1-Wire Sensor 9 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A1996 | 1-Wire Device 10 | ONEWIRE | ESP32+ESP8266 | IMPLEMENTED |
| A3102 | 1-Wire Sensor 1 | ONEWIRE | raw | IMPLEMENTED |
| A3103 | 1-Wire Device 2 | ONEWIRE | raw | IMPLEMENTED |
| A3104 | 1-Wire Temp 3 | ONEWIRE | C | IMPLEMENTED |
| A3105 | 1-Wire Sensor 4 | ONEWIRE | raw | IMPLEMENTED |
| A3106 | 1-Wire Device 5 | ONEWIRE | raw | IMPLEMENTED |
| A3107 | 1-Wire Temp 6 | ONEWIRE | C | IMPLEMENTED |
| A3108 | 1-Wire Sensor 7 | ONEWIRE | raw | IMPLEMENTED |
| A3109 | 1-Wire Device 8 | ONEWIRE | raw | IMPLEMENTED |
| A3110 | 1-Wire Temp 9 | ONEWIRE | C | IMPLEMENTED |
| A3111 | 1-Wire Sensor 10 | ONEWIRE | raw | IMPLEMENTED |
| A3112 | 1-Wire Device 11 | ONEWIRE | raw | IMPLEMENTED |
| A3113 | 1-Wire Temp 12 | ONEWIRE | C | IMPLEMENTED |
| A3114 | 1-Wire Sensor 13 | ONEWIRE | raw | IMPLEMENTED |
| A3115 | 1-Wire Device 14 | ONEWIRE | raw | IMPLEMENTED |
| A3116 | 1-Wire Temp 15 | ONEWIRE | C | IMPLEMENTED |
| A6831 | 1-Wire Sensor 1 | ONEWIRE | raw | IMPLEMENTED |
| A6832 | 1-Wire Device 2 | ONEWIRE | raw | IMPLEMENTED |
| A6833 | 1-Wire Temp 3 | ONEWIRE | C | IMPLEMENTED |
| A6834 | 1-Wire EEPROM 4 | ONEWIRE | bytes | IMPLEMENTED |
| A6835 | 1-Wire Sensor 5 | ONEWIRE | raw | IMPLEMENTED |
| A6836 | 1-Wire Device 6 | ONEWIRE | raw | IMPLEMENTED |
| A6837 | 1-Wire Temp 7 | ONEWIRE | C | IMPLEMENTED |
| A6838 | 1-Wire EEPROM 8 | ONEWIRE | bytes | IMPLEMENTED |
| A6839 | 1-Wire Sensor 9 | ONEWIRE | raw | IMPLEMENTED |
| A6840 | 1-Wire Device 10 | ONEWIRE | raw | IMPLEMENTED |

*... and 50 more ONEWIRE modules*

## POWER

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A8391 | Battery Monitor 1 | I2C | V | IMPLEMENTED |
| A8392 | Solar Charger 2 | ANALOG | V | IMPLEMENTED |
| A8393 | Voltage Regulator 3 | ANALOG | V | IMPLEMENTED |
| A8394 | Current Monitor 4 | I2C | mA | IMPLEMENTED |
| A8395 | Power Meter 5 | I2C | W | IMPLEMENTED |
| A8396 | Energy Monitor 6 | I2C | kWh | IMPLEMENTED |
| A8397 | PMIC 7 | I2C | V | IMPLEMENTED |
| A8398 | Fuel Gauge 8 | I2C | % | IMPLEMENTED |
| A8399 | Battery Monitor 9 | I2C | V | IMPLEMENTED |
| A8400 | Solar Charger 10 | ANALOG | V | IMPLEMENTED |
| A8401 | Voltage Regulator 11 | ANALOG | V | IMPLEMENTED |
| A8402 | Current Monitor 12 | I2C | mA | IMPLEMENTED |
| A8403 | Power Meter 13 | I2C | W | IMPLEMENTED |
| A8404 | Energy Monitor 14 | I2C | kWh | IMPLEMENTED |
| A8405 | PMIC 15 | I2C | V | IMPLEMENTED |
| A8406 | Fuel Gauge 16 | I2C | % | IMPLEMENTED |
| A8407 | Battery Monitor 17 | I2C | V | IMPLEMENTED |
| A8408 | Solar Charger 18 | ANALOG | V | IMPLEMENTED |
| A8409 | Voltage Regulator 19 | ANALOG | V | IMPLEMENTED |
| A8410 | Current Monitor 20 | I2C | mA | IMPLEMENTED |
| A8411 | Power Meter 21 | I2C | W | IMPLEMENTED |
| A8412 | Energy Monitor 22 | I2C | kWh | IMPLEMENTED |
| A8413 | PMIC 23 | I2C | V | IMPLEMENTED |
| A8414 | Fuel Gauge 24 | I2C | % | IMPLEMENTED |
| A8415 | Battery Monitor 25 | I2C | V | IMPLEMENTED |
| A8416 | Solar Charger 26 | ANALOG | V | IMPLEMENTED |
| A8417 | Voltage Regulator 27 | ANALOG | V | IMPLEMENTED |
| A8418 | Current Monitor 28 | I2C | mA | IMPLEMENTED |
| A8419 | Power Meter 29 | I2C | W | IMPLEMENTED |
| A8420 | Energy Monitor 30 | I2C | kWh | IMPLEMENTED |
| A8421 | PMIC 31 | I2C | V | IMPLEMENTED |
| A8422 | Fuel Gauge 32 | I2C | % | IMPLEMENTED |
| A8423 | Battery Monitor 33 | I2C | V | IMPLEMENTED |
| A8424 | Solar Charger 34 | ANALOG | V | IMPLEMENTED |
| A8425 | Voltage Regulator 35 | ANALOG | V | IMPLEMENTED |
| A8426 | Current Monitor 36 | I2C | mA | IMPLEMENTED |
| A8427 | Power Meter 37 | I2C | W | IMPLEMENTED |
| A8428 | Energy Monitor 38 | I2C | kWh | IMPLEMENTED |
| A8429 | PMIC 39 | I2C | V | IMPLEMENTED |
| A8430 | Fuel Gauge 40 | I2C | % | IMPLEMENTED |
| A8431 | Battery Monitor 41 | I2C | V | IMPLEMENTED |
| A8432 | Solar Charger 42 | ANALOG | V | IMPLEMENTED |
| A8433 | Voltage Regulator 43 | ANALOG | V | IMPLEMENTED |
| A8434 | Current Monitor 44 | I2C | mA | IMPLEMENTED |
| A8435 | Power Meter 45 | I2C | W | IMPLEMENTED |
| A8436 | Energy Monitor 46 | I2C | kWh | IMPLEMENTED |
| A8437 | PMIC 47 | I2C | V | IMPLEMENTED |
| A8438 | Fuel Gauge 48 | I2C | % | IMPLEMENTED |
| A8439 | Battery Monitor 49 | I2C | V | IMPLEMENTED |
| A8440 | Solar Charger 50 | ANALOG | V | IMPLEMENTED |

*... and 950 more POWER modules*

## RADIO

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0659 | MAX98357 I2S Amp | I2S | audio | IMPLEMENTED |
| A0660 | MAX98357A | I2S | audio | IMPLEMENTED |
| A0661 | TPA2012 | I2S | audio | IMPLEMENTED |
| A0662 | TPA2016 | I2S | audio | IMPLEMENTED |
| A0663 | PCA9635 Audio | I2S | audio | IMPLEMENTED |
| A0664 | WM8731 | I2S | audio | IMPLEMENTED |
| A0665 | WM8960 | I2S | audio | IMPLEMENTED |
| A0666 | PCM1808 | I2S | audio | IMPLEMENTED |
| A0667 | PCM5102 | I2S | audio | IMPLEMENTED |
| A0668 | PCM5122 | I2S | audio | IMPLEMENTED |
| A0749 | MFRC522 RFID | SPI | UID | IMPLEMENTED |
| A0750 | MFRC522 NFC | SPI | UID | IMPLEMENTED |
| A0751 | PN532 SPI | SPI | UID | IMPLEMENTED |
| A0752 | PN532 NFC SPI | SPI | UID | IMPLEMENTED |
| A0753 | RC522 RFID | SPI | UID | IMPLEMENTED |
| A0754 | ISO14443A NFC | SPI | UID | IMPLEMENTED |
| A0755 | MIFARE Classic 1K | SPI | UID | IMPLEMENTED |
| A0756 | MIFARE Classic 4K | SPI | UID | IMPLEMENTED |
| A0757 | NTAG213 | SPI | UID | IMPLEMENTED |
| A0758 | NTAG215 | SPI | UID | IMPLEMENTED |
| A0759 | NTAG216 | SPI | UID | IMPLEMENTED |
| A0760 | EM4100 RFID | SPI | UID | IMPLEMENTED |
| A0846 | DFPlayer Mini | UART | track | IMPLEMENTED |
| A0847 | DFPlayer DFRobot | UART | track | IMPLEMENTED |
| A0848 | YX5200 | UART | track | IMPLEMENTED |
| A0849 | JQ6500 | UART | track | IMPLEMENTED |
| A0850 | JQ6500-16P | UART | track | IMPLEMENTED |
| A0851 | WT588D | UART | track | IMPLEMENTED |
| A0852 | WT588D-U | UART | track | IMPLEMENTED |
| A0853 | WT2003H | UART | track | IMPLEMENTED |
| A0854 | WT2003S | UART | track | IMPLEMENTED |
| A0855 | ISD1820 | UART | record | IMPLEMENTED |
| A0856 | ISD1820P | UART | record | IMPLEMENTED |
| A0857 | APR33A3 | UART | record | IMPLEMENTED |
| A0858 | APR33A3-TC | UART | record | IMPLEMENTED |
| A0859 | Voice Recorder | UART | record | IMPLEMENTED |
| A0860 | PN532 UART | UART | UID | IMPLEMENTED |
| A0861 | PN532 NFC UART | UART | UID | IMPLEMENTED |
| A0862 | RDM6300 RFID | UART | UID | IMPLEMENTED |
| A0863 | RDM6300 125kHz | UART | UID | IMPLEMENTED |
| A0864 | EM4100 UART | UART | UID | IMPLEMENTED |
| A0865 | GY-RDM6300 | UART | UID | IMPLEMENTED |
| A0987 | IR Remote NEC | GPIO | code | IMPLEMENTED |
| A0988 | IR Remote Sony | GPIO | code | IMPLEMENTED |
| A0989 | IR Remote RC5 | GPIO | code | IMPLEMENTED |
| A0990 | IR Remote RC6 | GPIO | code | IMPLEMENTED |
| A0991 | IR Transmitter | GPIO | code | IMPLEMENTED |
| A0992 | IR Blaster | GPIO | code | IMPLEMENTED |
| A0993 | IR Receiver Module | GPIO | code | IMPLEMENTED |
| A0994 | IR LED | GPIO | code | IMPLEMENTED |

*... and 450 more RADIO modules*

## ROBOTICS

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A14091 | IMU 1 | I2C | raw | IMPLEMENTED |
| A14092 | Encoder 2 | DIGITAL | ticks | IMPLEMENTED |
| A14093 | Lidar 3 | UART | mm | IMPLEMENTED |
| A14094 | Ultrasonic Array 4 | DIGITAL | cm | IMPLEMENTED |
| A14095 | Force Sensor 5 | ANALOG | N | IMPLEMENTED |
| A14096 | Gyroscope 6 | I2C | deg/s | IMPLEMENTED |
| A14097 | Accelerometer 7 | I2C | g | IMPLEMENTED |
| A14098 | IMU 8 | I2C | raw | IMPLEMENTED |
| A14099 | Encoder 9 | DIGITAL | ticks | IMPLEMENTED |
| A14100 | Lidar 10 | UART | mm | IMPLEMENTED |
| A14101 | Ultrasonic Array 11 | DIGITAL | cm | IMPLEMENTED |
| A14102 | Force Sensor 12 | ANALOG | N | IMPLEMENTED |
| A14103 | Gyroscope 13 | I2C | deg/s | IMPLEMENTED |
| A14104 | Accelerometer 14 | I2C | g | IMPLEMENTED |
| A14105 | IMU 15 | I2C | raw | IMPLEMENTED |
| A14106 | Encoder 16 | DIGITAL | ticks | IMPLEMENTED |
| A14107 | Lidar 17 | UART | mm | IMPLEMENTED |
| A14108 | Ultrasonic Array 18 | DIGITAL | cm | IMPLEMENTED |
| A14109 | Force Sensor 19 | ANALOG | N | IMPLEMENTED |
| A14110 | Gyroscope 20 | I2C | deg/s | IMPLEMENTED |
| A14111 | Accelerometer 21 | I2C | g | IMPLEMENTED |
| A14112 | IMU 22 | I2C | raw | IMPLEMENTED |
| A14113 | Encoder 23 | DIGITAL | ticks | IMPLEMENTED |
| A14114 | Lidar 24 | UART | mm | IMPLEMENTED |
| A14115 | Ultrasonic Array 25 | DIGITAL | cm | IMPLEMENTED |
| A14116 | Force Sensor 26 | ANALOG | N | IMPLEMENTED |
| A14117 | Gyroscope 27 | I2C | deg/s | IMPLEMENTED |
| A14118 | Accelerometer 28 | I2C | g | IMPLEMENTED |
| A14119 | IMU 29 | I2C | raw | IMPLEMENTED |
| A14120 | Encoder 30 | DIGITAL | ticks | IMPLEMENTED |
| A14121 | Lidar 31 | UART | mm | IMPLEMENTED |
| A14122 | Ultrasonic Array 32 | DIGITAL | cm | IMPLEMENTED |
| A14123 | Force Sensor 33 | ANALOG | N | IMPLEMENTED |
| A14124 | Gyroscope 34 | I2C | deg/s | IMPLEMENTED |
| A14125 | Accelerometer 35 | I2C | g | IMPLEMENTED |
| A14126 | IMU 36 | I2C | raw | IMPLEMENTED |
| A14127 | Encoder 37 | DIGITAL | ticks | IMPLEMENTED |
| A14128 | Lidar 38 | UART | mm | IMPLEMENTED |
| A14129 | Ultrasonic Array 39 | DIGITAL | cm | IMPLEMENTED |
| A14130 | Force Sensor 40 | ANALOG | N | IMPLEMENTED |
| A14131 | Gyroscope 41 | I2C | deg/s | IMPLEMENTED |
| A14132 | Accelerometer 42 | I2C | g | IMPLEMENTED |
| A14133 | IMU 43 | I2C | raw | IMPLEMENTED |
| A14134 | Encoder 44 | DIGITAL | ticks | IMPLEMENTED |
| A14135 | Lidar 45 | UART | mm | IMPLEMENTED |
| A14136 | Ultrasonic Array 46 | DIGITAL | cm | IMPLEMENTED |
| A14137 | Force Sensor 47 | ANALOG | N | IMPLEMENTED |
| A14138 | Gyroscope 48 | I2C | deg/s | IMPLEMENTED |
| A14139 | Accelerometer 49 | I2C | g | IMPLEMENTED |
| A14140 | IMU 50 | I2C | raw | IMPLEMENTED |

*... and 550 more ROBOTICS modules*

## SECURITY

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A16091 | Fingerprint 1 | UART | id | IMPLEMENTED |
| A16092 | Face Recognition 2 | SPI | id | IMPLEMENTED |
| A16093 | RFID Reader 3 | SPI | uid | IMPLEMENTED |
| A16094 | Alarm 4 | DIGITAL | bool | IMPLEMENTED |
| A16095 | Camera Security 5 | SPI | px | IMPLEMENTED |
| A16096 | Door Sensor 6 | DIGITAL | bool | IMPLEMENTED |
| A16097 | Fingerprint 7 | UART | id | IMPLEMENTED |
| A16098 | Face Recognition 8 | SPI | id | IMPLEMENTED |
| A16099 | RFID Reader 9 | SPI | uid | IMPLEMENTED |
| A16100 | Alarm 10 | DIGITAL | bool | IMPLEMENTED |
| A16101 | Camera Security 11 | SPI | px | IMPLEMENTED |
| A16102 | Door Sensor 12 | DIGITAL | bool | IMPLEMENTED |
| A16103 | Fingerprint 13 | UART | id | IMPLEMENTED |
| A16104 | Face Recognition 14 | SPI | id | IMPLEMENTED |
| A16105 | RFID Reader 15 | SPI | uid | IMPLEMENTED |
| A16106 | Alarm 16 | DIGITAL | bool | IMPLEMENTED |
| A16107 | Camera Security 17 | SPI | px | IMPLEMENTED |
| A16108 | Door Sensor 18 | DIGITAL | bool | IMPLEMENTED |
| A16109 | Fingerprint 19 | UART | id | IMPLEMENTED |
| A16110 | Face Recognition 20 | SPI | id | IMPLEMENTED |
| A16111 | RFID Reader 21 | SPI | uid | IMPLEMENTED |
| A16112 | Alarm 22 | DIGITAL | bool | IMPLEMENTED |
| A16113 | Camera Security 23 | SPI | px | IMPLEMENTED |
| A16114 | Door Sensor 24 | DIGITAL | bool | IMPLEMENTED |
| A16115 | Fingerprint 25 | UART | id | IMPLEMENTED |
| A16116 | Face Recognition 26 | SPI | id | IMPLEMENTED |
| A16117 | RFID Reader 27 | SPI | uid | IMPLEMENTED |
| A16118 | Alarm 28 | DIGITAL | bool | IMPLEMENTED |
| A16119 | Camera Security 29 | SPI | px | IMPLEMENTED |
| A16120 | Door Sensor 30 | DIGITAL | bool | IMPLEMENTED |
| A16121 | Fingerprint 31 | UART | id | IMPLEMENTED |
| A16122 | Face Recognition 32 | SPI | id | IMPLEMENTED |
| A16123 | RFID Reader 33 | SPI | uid | IMPLEMENTED |
| A16124 | Alarm 34 | DIGITAL | bool | IMPLEMENTED |
| A16125 | Camera Security 35 | SPI | px | IMPLEMENTED |
| A16126 | Door Sensor 36 | DIGITAL | bool | IMPLEMENTED |
| A16127 | Fingerprint 37 | UART | id | IMPLEMENTED |
| A16128 | Face Recognition 38 | SPI | id | IMPLEMENTED |
| A16129 | RFID Reader 39 | SPI | uid | IMPLEMENTED |
| A16130 | Alarm 40 | DIGITAL | bool | IMPLEMENTED |
| A16131 | Camera Security 41 | SPI | px | IMPLEMENTED |
| A16132 | Door Sensor 42 | DIGITAL | bool | IMPLEMENTED |
| A16133 | Fingerprint 43 | UART | id | IMPLEMENTED |
| A16134 | Face Recognition 44 | SPI | id | IMPLEMENTED |
| A16135 | RFID Reader 45 | SPI | uid | IMPLEMENTED |
| A16136 | Alarm 46 | DIGITAL | bool | IMPLEMENTED |
| A16137 | Camera Security 47 | SPI | px | IMPLEMENTED |
| A16138 | Door Sensor 48 | DIGITAL | bool | IMPLEMENTED |
| A16139 | Fingerprint 49 | UART | id | IMPLEMENTED |
| A16140 | Face Recognition 50 | SPI | id | IMPLEMENTED |

*... and 350 more SECURITY modules*

## SPECIAL

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0591 | INA219 | I2C | A/V/W | IMPLEMENTED |
| A0592 | INA220 | I2C | A/V/W | IMPLEMENTED |
| A0593 | INA226 | I2C | A/V/W | IMPLEMENTED |
| A0594 | INA230 | I2C | A/V/W | IMPLEMENTED |
| A0595 | INA231 | I2C | A/V/W | IMPLEMENTED |
| A0596 | INA233 | I2C | A/V/W | IMPLEMENTED |
| A0597 | INA260 | I2C | A/V/W | IMPLEMENTED |
| A0598 | INA3221 | I2C | 3-ch A/V/W | IMPLEMENTED |
| A0599 | INA3221 3-channel | I2C | A/V/W | IMPLEMENTED |
| A0600 | LTC2944 | I2C | A/V/W | IMPLEMENTED |
| A0601 | LTC2945 | I2C | A/V/W | IMPLEMENTED |
| A0602 | LTC2946 | I2C | A/V/W | IMPLEMENTED |
| A0603 | LTC4151 | I2C | A/V/W | IMPLEMENTED |
| A0604 | ZXCT1081 | I2C | A | IMPLEMENTED |
| A0605 | ZXCT1082 | I2C | A | IMPLEMENTED |
| A0606 | PZEM-004T (I2C) | I2C | W/V/A/Wh | IMPLEMENTED |
| A0607 | PZEM-017 (I2C) | I2C | W/V/A/Wh | IMPLEMENTED |
| A0630 | PMS5003T | UART | µg/m³ | IMPLEMENTED |
| A0631 | PMS7003T | UART | µg/m³ | IMPLEMENTED |
| A0632 | PMSA003I | UART | µg/m³ | IMPLEMENTED |
| A0633 | SPS30 | UART | µg/m³ | IMPLEMENTED |
| A0634 | SPS30 PM | UART | µg/m³ | IMPLEMENTED |
| A0635 | Plantower PMS5003 | UART | µg/m³ | IMPLEMENTED |
| A0636 | Plantower PMS7003 | UART | µg/m³ | IMPLEMENTED |
| A0775 | ATM90E32 | SPI | Wh | IMPLEMENTED |
| A0776 | ATM90E32A | SPI | Wh | IMPLEMENTED |
| A0777 | ADE7753 | SPI | Wh | IMPLEMENTED |
| A0778 | ADE7758 | SPI | Wh | IMPLEMENTED |
| A0779 | ADE7763 | SPI | Wh | IMPLEMENTED |
| A0780 | ADE7858 | SPI | Wh | IMPLEMENTED |
| A0781 | ADE7878 | SPI | Wh | IMPLEMENTED |
| A0782 | CS5463 | SPI | Wh | IMPLEMENTED |
| A0783 | CS5464 | SPI | Wh | IMPLEMENTED |
| A0784 | CS5467 | SPI | Wh | IMPLEMENTED |
| A0785 | CS5480 | SPI | Wh | IMPLEMENTED |
| A0786 | CS5484 | SPI | Wh | IMPLEMENTED |
| A0813 | PMS5003 PM | UART | µg/m³ | IMPLEMENTED |
| A0814 | PMS7003 PM | UART | µg/m³ | IMPLEMENTED |
| A0815 | PMS1003 PM | UART | µg/m³ | IMPLEMENTED |
| A0816 | PMSA003 PM | UART | µg/m³ | IMPLEMENTED |
| A0817 | SDS011 PM | UART | µg/m³ | IMPLEMENTED |
| A0818 | HPMA115S0 PM | UART | µg/m³ | IMPLEMENTED |
| A0819 | SPS30 PM | UART | µg/m³ | IMPLEMENTED |
| A0820 | SPS30 PM2.5 | UART | µg/m³ | IMPLEMENTED |
| A0839 | PZEM-004T V3 | UART | W/V/A/Wh | IMPLEMENTED |
| A0840 | PZEM-004T V4 | UART | W/V/A/Wh | IMPLEMENTED |
| A0841 | PZEM-017 | UART | W/V/A/Wh | IMPLEMENTED |
| A0842 | PZEM-016 | UART | W/V/A/Wh | IMPLEMENTED |
| A0843 | PZEM-003 | UART | W/V/A/Wh | IMPLEMENTED |
| A0844 | PZEM-004T DC | UART | W/V/A/Wh | IMPLEMENTED |

*... and 750 more SPECIAL modules*

## SPI

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0573 | MCP3008 ADC | SPI | 0-1023 | IMPLEMENTED |
| A0574 | MCP3208 ADC | SPI | 0-4095 | IMPLEMENTED |
| A0579 | MCP4725 | SPI | 0-4095 | IMPLEMENTED |
| A0580 | MCP4725A0 | SPI | 0-4095 | IMPLEMENTED |
| A0581 | MCP4725A1 | SPI | 0-4095 | IMPLEMENTED |
| A0582 | MCP4725A2 | SPI | 0-4095 | IMPLEMENTED |
| A0583 | MCP4822 | SPI | 0-4095 | IMPLEMENTED |
| A0584 | MCP4821 | SPI | 0-4095 | IMPLEMENTED |
| A0585 | MCP4921 | SPI | 0-4095 | IMPLEMENTED |
| A0586 | MCP4922 | SPI | 0-4095 | IMPLEMENTED |
| A0589 | ADS7828 | SPI | 0-4095 | IMPLEMENTED |
| A0590 | ADS7829 | SPI | 0-4095 | IMPLEMENTED |
| A0729 | MCP3008 SPI | SPI | 0-1023 | IMPLEMENTED |
| A0730 | MCP3208 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0731 | MCP3002 SPI | SPI | 0-1023 | IMPLEMENTED |
| A0732 | MCP3004 SPI | SPI | 0-1023 | IMPLEMENTED |
| A0733 | MCP3202 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0734 | MCP3204 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0735 | MCP3301 | SPI | 0-65535 | IMPLEMENTED |
| A0736 | MCP3302 | SPI | 0-65535 | IMPLEMENTED |
| A0737 | MCP3304 | SPI | 0-65535 | IMPLEMENTED |
| A0738 | MCP4822 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0739 | MCP4821 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0740 | MCP4921 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0741 | MCP4922 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0742 | LTC1257 | SPI | 0-4095 | IMPLEMENTED |
| A0743 | LTC1258 | SPI | 0-4095 | IMPLEMENTED |
| A0744 | ADS7828 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0745 | ADS7829 SPI | SPI | 0-4095 | IMPLEMENTED |
| A0746 | MAX1161 | SPI | 0-1023 | IMPLEMENTED |
| A0747 | MAX1162 | SPI | 0-1023 | IMPLEMENTED |
| A0748 | MAX1164 | SPI | 0-1023 | IMPLEMENTED |
| A1937 | SPI ADC 1 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1938 | SPI DAC 2 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1939 | SPI Flash 3 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1940 | SPI Display 4 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1941 | SPI ADC 5 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1942 | SPI DAC 6 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1943 | SPI Flash 7 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1944 | SPI Display 8 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1945 | SPI ADC 9 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1946 | SPI DAC 10 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1947 | SPI Flash 11 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1948 | SPI Display 12 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1949 | SPI ADC 13 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1950 | SPI DAC 14 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1951 | SPI Flash 15 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1952 | SPI Display 16 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1953 | SPI ADC 17 | SPI | ESP32+ESP8266 | IMPLEMENTED |
| A1954 | SPI DAC 18 | SPI | ESP32+ESP8266 | IMPLEMENTED |

*... and 250 more SPI modules*

## STORAGE

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0514 | EEPROM 24LC256 | I2C | bytes | IMPLEMENTED |
| A0515 | EEPROM 24LC512 | I2C | bytes | IMPLEMENTED |
| A0516 | EEPROM 24LC1024 | I2C | bytes | IMPLEMENTED |
| A0517 | EEPROM 24LC32 | I2C | bytes | IMPLEMENTED |
| A0518 | EEPROM 24LC64 | I2C | bytes | IMPLEMENTED |
| A0519 | EEPROM 24LC128 | I2C | bytes | IMPLEMENTED |
| A0520 | EEPROM AT24C256 | I2C | bytes | IMPLEMENTED |
| A0521 | EEPROM AT24C512 | I2C | bytes | IMPLEMENTED |
| A0522 | EEPROM AT24C1024 | I2C | bytes | IMPLEMENTED |
| A0523 | FRAM MB85RC256V | I2C | bytes | IMPLEMENTED |
| A0524 | FRAM MB85RC16 | I2C | bytes | IMPLEMENTED |
| A0525 | FRAM MB85RC64 | I2C | bytes | IMPLEMENTED |
| A0526 | FRAM MB85RC128 | I2C | bytes | IMPLEMENTED |
| A0527 | FRAM FM24V10 | I2C | bytes | IMPLEMENTED |
| A0528 | FRAM FM24V01 | I2C | bytes | IMPLEMENTED |
| A0529 | FRAM FM24V02 | I2C | bytes | IMPLEMENTED |
| A0530 | FRAM FM24V05 | I2C | bytes | IMPLEMENTED |
| A0531 | EEPROM 93C46 | I2C | bytes | IMPLEMENTED |
| A0532 | EEPROM 93C56 | I2C | bytes | IMPLEMENTED |
| A0533 | EEPROM 93C66 | I2C | bytes | IMPLEMENTED |
| A0534 | EEPROM 93C86 | I2C | bytes | IMPLEMENTED |
| A0535 | PCF8574 | I2C | 8 GPIO | IMPLEMENTED |
| A0536 | PCF8574A | I2C | 8 GPIO | IMPLEMENTED |
| A0537 | PCF8575 | I2C | 16 GPIO | IMPLEMENTED |
| A0538 | PCF8575A | I2C | 16 GPIO | IMPLEMENTED |
| A0539 | MCP23008 | I2C | 8 GPIO | IMPLEMENTED |
| A0540 | MCP23017 | I2C | 16 GPIO | IMPLEMENTED |
| A0541 | MCP23018 | I2C | 16 GPIO | IMPLEMENTED |
| A0542 | MCP23S17 | I2C | 16 GPIO | IMPLEMENTED |
| A0543 | TCA9548A | I2C | 8 ch I2C Mux | IMPLEMENTED |
| A0544 | TCA9548 | I2C | 8 ch I2C Mux | IMPLEMENTED |
| A0545 | PCA9548A | I2C | 8 ch I2C Mux | IMPLEMENTED |
| A0546 | PCA9547 | I2C | 2 ch I2C Mux | IMPLEMENTED |
| A0547 | PCA9546A | I2C | 4 ch I2C Mux | IMPLEMENTED |
| A0548 | PCA9545A | I2C | 4 ch I2C Mux | IMPLEMENTED |
| A0549 | PCA9685 | I2C | 16 PWM | IMPLEMENTED |
| A0550 | PCA9685 Servo | I2C | 16 servo | IMPLEMENTED |
| A0551 | PCA9635 | I2C | 16 LED | IMPLEMENTED |
| A0552 | PCA9555 | I2C | 16 GPIO | IMPLEMENTED |
| A0553 | PCA9554 | I2C | 8 GPIO | IMPLEMENTED |
| A0554 | PCA9536 | I2C | 8 GPIO | IMPLEMENTED |
| A0555 | PCA9538 | I2C | 8 GPIO | IMPLEMENTED |
| A0556 | PCA9539 | I2C | 16 GPIO | IMPLEMENTED |
| A0557 | MAX7300 | I2C | 10 GPIO | IMPLEMENTED |
| A0558 | MAX7310 | I2C | 18 GPIO | IMPLEMENTED |
| A0698 | SD Card SPI | SPI | bytes | IMPLEMENTED |
| A0699 | MicroSD SPI | SPI | bytes | IMPLEMENTED |
| A0700 | SD Card SDIO | SDIO | bytes | IMPLEMENTED |
| A0701 | W25Q128 | SPI | bytes | IMPLEMENTED |
| A0702 | W25Q64 | SPI | bytes | IMPLEMENTED |

*... and 650 more STORAGE modules*

## STORAGE_ADVANCED

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A17891 | Flash Storage 1 | SPI | bytes | IMPLEMENTED |
| A17892 | SD Card 2 | SPI | bytes | IMPLEMENTED |
| A17893 | NVS Storage 3 | SPI | bytes | IMPLEMENTED |
| A17894 | LittleFS 4 | SPI | bytes | IMPLEMENTED |
| A17895 | Flash Storage 5 | SPI | bytes | IMPLEMENTED |
| A17896 | SD Card 6 | SPI | bytes | IMPLEMENTED |
| A17897 | NVS Storage 7 | SPI | bytes | IMPLEMENTED |
| A17898 | LittleFS 8 | SPI | bytes | IMPLEMENTED |
| A17899 | Flash Storage 9 | SPI | bytes | IMPLEMENTED |
| A17900 | SD Card 10 | SPI | bytes | IMPLEMENTED |
| A17901 | NVS Storage 11 | SPI | bytes | IMPLEMENTED |
| A17902 | LittleFS 12 | SPI | bytes | IMPLEMENTED |
| A17903 | Flash Storage 13 | SPI | bytes | IMPLEMENTED |
| A17904 | SD Card 14 | SPI | bytes | IMPLEMENTED |
| A17905 | NVS Storage 15 | SPI | bytes | IMPLEMENTED |
| A17906 | LittleFS 16 | SPI | bytes | IMPLEMENTED |
| A17907 | Flash Storage 17 | SPI | bytes | IMPLEMENTED |
| A17908 | SD Card 18 | SPI | bytes | IMPLEMENTED |
| A17909 | NVS Storage 19 | SPI | bytes | IMPLEMENTED |
| A17910 | LittleFS 20 | SPI | bytes | IMPLEMENTED |
| A17911 | Flash Storage 21 | SPI | bytes | IMPLEMENTED |
| A17912 | SD Card 22 | SPI | bytes | IMPLEMENTED |
| A17913 | NVS Storage 23 | SPI | bytes | IMPLEMENTED |
| A17914 | LittleFS 24 | SPI | bytes | IMPLEMENTED |
| A17915 | Flash Storage 25 | SPI | bytes | IMPLEMENTED |
| A17916 | SD Card 26 | SPI | bytes | IMPLEMENTED |
| A17917 | NVS Storage 27 | SPI | bytes | IMPLEMENTED |
| A17918 | LittleFS 28 | SPI | bytes | IMPLEMENTED |
| A17919 | Flash Storage 29 | SPI | bytes | IMPLEMENTED |
| A17920 | SD Card 30 | SPI | bytes | IMPLEMENTED |
| A17921 | NVS Storage 31 | SPI | bytes | IMPLEMENTED |
| A17922 | LittleFS 32 | SPI | bytes | IMPLEMENTED |
| A17923 | Flash Storage 33 | SPI | bytes | IMPLEMENTED |
| A17924 | SD Card 34 | SPI | bytes | IMPLEMENTED |
| A17925 | NVS Storage 35 | SPI | bytes | IMPLEMENTED |
| A17926 | LittleFS 36 | SPI | bytes | IMPLEMENTED |
| A17927 | Flash Storage 37 | SPI | bytes | IMPLEMENTED |
| A17928 | SD Card 38 | SPI | bytes | IMPLEMENTED |
| A17929 | NVS Storage 39 | SPI | bytes | IMPLEMENTED |
| A17930 | LittleFS 40 | SPI | bytes | IMPLEMENTED |
| A17931 | Flash Storage 41 | SPI | bytes | IMPLEMENTED |
| A17932 | SD Card 42 | SPI | bytes | IMPLEMENTED |
| A17933 | NVS Storage 43 | SPI | bytes | IMPLEMENTED |
| A17934 | LittleFS 44 | SPI | bytes | IMPLEMENTED |
| A17935 | Flash Storage 45 | SPI | bytes | IMPLEMENTED |
| A17936 | SD Card 46 | SPI | bytes | IMPLEMENTED |
| A17937 | NVS Storage 47 | SPI | bytes | IMPLEMENTED |
| A17938 | LittleFS 48 | SPI | bytes | IMPLEMENTED |
| A17939 | Flash Storage 49 | SPI | bytes | IMPLEMENTED |
| A17940 | SD Card 50 | SPI | bytes | IMPLEMENTED |

*... and 150 more STORAGE_ADVANCED modules*

## UART

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A0787 | GPS NEO-6M | UART | lat/lon | IMPLEMENTED |
| A0788 | GPS NEO-7M | UART | lat/lon | IMPLEMENTED |
| A0789 | GPS NEO-8M | UART | lat/lon | IMPLEMENTED |
| A0790 | GPS NEO-M8N | UART | lat/lon | IMPLEMENTED |
| A0791 | GPS NEO-M9N | UART | lat/lon | IMPLEMENTED |
| A0792 | GPS ATGM336H | UART | lat/lon | IMPLEMENTED |
| A0793 | GPS L76K | UART | lat/lon | IMPLEMENTED |
| A0794 | GPS L76B | UART | lat/lon | IMPLEMENTED |
| A0795 | GPS PA6H | UART | lat/lon | IMPLEMENTED |
| A0796 | GPS PA6C | UART | lat/lon | IMPLEMENTED |
| A0797 | GPS GT-U7 | UART | lat/lon | IMPLEMENTED |
| A0798 | GPS GY-NEO6MV2 | UART | lat/lon | IMPLEMENTED |
| A0799 | GPS GY-GPS6MV2 | UART | lat/lon | IMPLEMENTED |
| A0800 | GPS Quectel L80 | UART | lat/lon | IMPLEMENTED |
| A0801 | GPS Quectel L86 | UART | lat/lon | IMPLEMENTED |
| A0802 | GPS Ublox C099 | UART | lat/lon | IMPLEMENTED |
| A0803 | GPS Ublox ZED-F9P | UART | lat/lon | IMPLEMENTED |
| A0804 | GNSS RTK | UART | lat/lon | IMPLEMENTED |
| A1967 | UART Sensor 1 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1968 | UART Module 2 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1969 | UART Sensor 3 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1970 | UART Module 4 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1971 | UART Sensor 5 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1972 | UART Module 6 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1973 | UART Sensor 7 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1974 | UART Module 8 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1975 | UART Sensor 9 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1976 | UART Module 10 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1977 | UART Sensor 11 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1978 | UART Module 12 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1979 | UART Sensor 13 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1980 | UART Module 14 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1981 | UART Sensor 15 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1982 | UART Module 16 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1983 | UART Sensor 17 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1984 | UART Module 18 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1985 | UART Sensor 19 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A1986 | UART Module 20 | UART | ESP32+ESP8266 | IMPLEMENTED |
| A3077 | UART Sensor 1 | UART | raw | IMPLEMENTED |
| A3078 | UART Module 2 | UART | raw | IMPLEMENTED |
| A3079 | UART Device 3 | UART | raw | IMPLEMENTED |
| A3080 | UART Sensor 4 | UART | raw | IMPLEMENTED |
| A3081 | UART Module 5 | UART | raw | IMPLEMENTED |
| A3082 | UART Device 6 | UART | raw | IMPLEMENTED |
| A3083 | UART Sensor 7 | UART | raw | IMPLEMENTED |
| A3084 | UART Module 8 | UART | raw | IMPLEMENTED |
| A3085 | UART Device 9 | UART | raw | IMPLEMENTED |
| A3086 | UART Sensor 10 | UART | raw | IMPLEMENTED |
| A3087 | UART Module 11 | UART | raw | IMPLEMENTED |
| A3088 | UART Device 12 | UART | raw | IMPLEMENTED |

*... and 150 more UART modules*

## WEARABLE

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A15791 | Accelerometer 1 | I2C | g | IMPLEMENTED |
| A15792 | Gyroscope 2 | I2C | deg/s | IMPLEMENTED |
| A15793 | Heart Rate 3 | I2C | bpm | IMPLEMENTED |
| A15794 | Step Counter 4 | I2C | steps | IMPLEMENTED |
| A15795 | SpO2 5 | I2C | % | IMPLEMENTED |
| A15796 | Accelerometer 6 | I2C | g | IMPLEMENTED |
| A15797 | Gyroscope 7 | I2C | deg/s | IMPLEMENTED |
| A15798 | Heart Rate 8 | I2C | bpm | IMPLEMENTED |
| A15799 | Step Counter 9 | I2C | steps | IMPLEMENTED |
| A15800 | SpO2 10 | I2C | % | IMPLEMENTED |
| A15801 | Accelerometer 11 | I2C | g | IMPLEMENTED |
| A15802 | Gyroscope 12 | I2C | deg/s | IMPLEMENTED |
| A15803 | Heart Rate 13 | I2C | bpm | IMPLEMENTED |
| A15804 | Step Counter 14 | I2C | steps | IMPLEMENTED |
| A15805 | SpO2 15 | I2C | % | IMPLEMENTED |
| A15806 | Accelerometer 16 | I2C | g | IMPLEMENTED |
| A15807 | Gyroscope 17 | I2C | deg/s | IMPLEMENTED |
| A15808 | Heart Rate 18 | I2C | bpm | IMPLEMENTED |
| A15809 | Step Counter 19 | I2C | steps | IMPLEMENTED |
| A15810 | SpO2 20 | I2C | % | IMPLEMENTED |
| A15811 | Accelerometer 21 | I2C | g | IMPLEMENTED |
| A15812 | Gyroscope 22 | I2C | deg/s | IMPLEMENTED |
| A15813 | Heart Rate 23 | I2C | bpm | IMPLEMENTED |
| A15814 | Step Counter 24 | I2C | steps | IMPLEMENTED |
| A15815 | SpO2 25 | I2C | % | IMPLEMENTED |
| A15816 | Accelerometer 26 | I2C | g | IMPLEMENTED |
| A15817 | Gyroscope 27 | I2C | deg/s | IMPLEMENTED |
| A15818 | Heart Rate 28 | I2C | bpm | IMPLEMENTED |
| A15819 | Step Counter 29 | I2C | steps | IMPLEMENTED |
| A15820 | SpO2 30 | I2C | % | IMPLEMENTED |
| A15821 | Accelerometer 31 | I2C | g | IMPLEMENTED |
| A15822 | Gyroscope 32 | I2C | deg/s | IMPLEMENTED |
| A15823 | Heart Rate 33 | I2C | bpm | IMPLEMENTED |
| A15824 | Step Counter 34 | I2C | steps | IMPLEMENTED |
| A15825 | SpO2 35 | I2C | % | IMPLEMENTED |
| A15826 | Accelerometer 36 | I2C | g | IMPLEMENTED |
| A15827 | Gyroscope 37 | I2C | deg/s | IMPLEMENTED |
| A15828 | Heart Rate 38 | I2C | bpm | IMPLEMENTED |
| A15829 | Step Counter 39 | I2C | steps | IMPLEMENTED |
| A15830 | SpO2 40 | I2C | % | IMPLEMENTED |
| A15831 | Accelerometer 41 | I2C | g | IMPLEMENTED |
| A15832 | Gyroscope 42 | I2C | deg/s | IMPLEMENTED |
| A15833 | Heart Rate 43 | I2C | bpm | IMPLEMENTED |
| A15834 | Step Counter 44 | I2C | steps | IMPLEMENTED |
| A15835 | SpO2 45 | I2C | % | IMPLEMENTED |
| A15836 | Accelerometer 46 | I2C | g | IMPLEMENTED |
| A15837 | Gyroscope 47 | I2C | deg/s | IMPLEMENTED |
| A15838 | Heart Rate 48 | I2C | bpm | IMPLEMENTED |
| A15839 | Step Counter 49 | I2C | steps | IMPLEMENTED |
| A15840 | SpO2 50 | I2C | % | IMPLEMENTED |

*... and 250 more WEARABLE modules*

## WIRELESS

| ID | Name | Bus | Unit | Status |
|----|------|-----|------|--------|
| A6891 | WiFi Module 1 | WIFI | bytes | IMPLEMENTED |
| A6892 | BLE Module 2 | BLE | bytes | IMPLEMENTED |
| A6893 | LoRa Module 3 | SPI | bytes | IMPLEMENTED |
| A6894 | Zigbee Module 4 | SPI | bytes | IMPLEMENTED |
| A6895 | Thread Module 5 | SPI | bytes | IMPLEMENTED |
| A6896 | NFC Module 6 | I2C | bytes | IMPLEMENTED |
| A6897 | RFID Module 7 | SPI | bytes | IMPLEMENTED |
| A6898 | Sub-GHz 8 | SPI | bytes | IMPLEMENTED |
| A6899 | ESP-NOW 9 | WIFI | bytes | IMPLEMENTED |
| A6900 | Matter 10 | WIFI | bytes | IMPLEMENTED |
| A6901 | WiFi Module 11 | WIFI | bytes | IMPLEMENTED |
| A6902 | BLE Module 12 | BLE | bytes | IMPLEMENTED |
| A6903 | LoRa Module 13 | SPI | bytes | IMPLEMENTED |
| A6904 | Zigbee Module 14 | SPI | bytes | IMPLEMENTED |
| A6905 | Thread Module 15 | SPI | bytes | IMPLEMENTED |
| A6906 | NFC Module 16 | I2C | bytes | IMPLEMENTED |
| A6907 | RFID Module 17 | SPI | bytes | IMPLEMENTED |
| A6908 | Sub-GHz 18 | SPI | bytes | IMPLEMENTED |
| A6909 | ESP-NOW 19 | WIFI | bytes | IMPLEMENTED |
| A6910 | Matter 20 | WIFI | bytes | IMPLEMENTED |
| A6911 | WiFi Module 21 | WIFI | bytes | IMPLEMENTED |
| A6912 | BLE Module 22 | BLE | bytes | IMPLEMENTED |
| A6913 | LoRa Module 23 | SPI | bytes | IMPLEMENTED |
| A6914 | Zigbee Module 24 | SPI | bytes | IMPLEMENTED |
| A6915 | Thread Module 25 | SPI | bytes | IMPLEMENTED |
| A6916 | NFC Module 26 | I2C | bytes | IMPLEMENTED |
| A6917 | RFID Module 27 | SPI | bytes | IMPLEMENTED |
| A6918 | Sub-GHz 28 | SPI | bytes | IMPLEMENTED |
| A6919 | ESP-NOW 29 | WIFI | bytes | IMPLEMENTED |
| A6920 | Matter 30 | WIFI | bytes | IMPLEMENTED |
| A6921 | WiFi Module 31 | WIFI | bytes | IMPLEMENTED |
| A6922 | BLE Module 32 | BLE | bytes | IMPLEMENTED |
| A6923 | LoRa Module 33 | SPI | bytes | IMPLEMENTED |
| A6924 | Zigbee Module 34 | SPI | bytes | IMPLEMENTED |
| A6925 | Thread Module 35 | SPI | bytes | IMPLEMENTED |
| A6926 | NFC Module 36 | I2C | bytes | IMPLEMENTED |
| A6927 | RFID Module 37 | SPI | bytes | IMPLEMENTED |
| A6928 | Sub-GHz 38 | SPI | bytes | IMPLEMENTED |
| A6929 | ESP-NOW 39 | WIFI | bytes | IMPLEMENTED |
| A6930 | Matter 40 | WIFI | bytes | IMPLEMENTED |
| A6931 | WiFi Module 41 | WIFI | bytes | IMPLEMENTED |
| A6932 | BLE Module 42 | BLE | bytes | IMPLEMENTED |
| A6933 | LoRa Module 43 | SPI | bytes | IMPLEMENTED |
| A6934 | Zigbee Module 44 | SPI | bytes | IMPLEMENTED |
| A6935 | Thread Module 45 | SPI | bytes | IMPLEMENTED |
| A6936 | NFC Module 46 | I2C | bytes | IMPLEMENTED |
| A6937 | RFID Module 47 | SPI | bytes | IMPLEMENTED |
| A6938 | Sub-GHz 48 | SPI | bytes | IMPLEMENTED |
| A6939 | ESP-NOW 49 | WIFI | bytes | IMPLEMENTED |
| A6940 | Matter 50 | WIFI | bytes | IMPLEMENTED |

*... and 1450 more WIRELESS modules*

