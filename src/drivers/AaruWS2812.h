// ============================================================
//  AARUESP WS2812 (NeoPixel) Driver
//  MADE BY AARUTO
// ============================================================
#ifndef AARUESP_WS2812_H
#define AARUESP_WS2812_H

#include "AARUESPTypes.h"
#include "AARUESPBoard.h"

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <stdint.h>
#endif

struct AaruRGB {
    uint8_t r, g, b;
    AaruRGB(uint8_t r_=0, uint8_t g_=0, uint8_t b_=0) : r(r_), g(g_), b(b_) {}
};

class AaruWS2812 {
public:
    AaruWS2812() = default;

    AaruespError begin(uint8_t pin, uint16_t num_leds);
    AaruespError begin(uint8_t pin, uint16_t num_leds, uint8_t type);

    AaruespError setPixel(uint16_t index, uint8_t r, uint8_t g, uint8_t b);
    AaruespError setPixel(uint16_t index, struct AaruRGB color);
    AaruespError setPixelHSV(uint16_t index, uint16_t h, uint8_t s, uint8_t v);
    AaruespError fill(uint8_t r, uint8_t g, uint8_t b, uint16_t start, uint16_t len);
    AaruespError fill(struct AaruRGB color, uint16_t start, uint16_t len);
    AaruespError clear();
    AaruespError show();

    void setBrightness(uint8_t b);

    AaruespError rainbow(uint16_t first_hue, uint16_t hue_step);
    AaruespError theaterChase(uint8_t r, uint8_t g, uint8_t b, uint8_t wait_ms);
    AaruespError colorWipe(uint8_t r, uint8_t g, uint8_t b, uint8_t wait_ms);

    uint16_t numLeds() const;
    struct AaruRGB getPixel(uint16_t index) const;
    bool isConfigured() const;
    AaruespError lastError() const;
    const char* errorString() const;

private:
    bool _configured;
    uint8_t _pin;
    uint16_t _num_leds;
    uint8_t _type;
    uint8_t _brightness;
    struct AaruRGB* _pixels;
    AaruespError _err;

    void sendBytes(const uint8_t* data, uint32_t len);
    static uint32_t rgbToRaw(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness);
};

#endif // AARUESP_WS2812_H
