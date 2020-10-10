#ifndef ES_BUDDY_H
#define ES_BUDDY_H

#include "Arduino.h"
#include "Audio.h"
#include "Encoder.h"

#ifdef ES_HAVE_TFT
#include "ST7735_t3.h"
#endif
#ifdef ES_HAVE_OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#endif

// ----- EuroShield Pin Defitions

// Teensy 4.0
#if defined(__IMXRT1062__)

#define ES_DISPLAY_MISO_PIN     12
#define ES_DISPLAY_MOSI_PIN     11
#define ES_DISPLAY_SCK_PIN      13
#define ES_DISPLAY_DC_PIN       22
#define ES_DISPLAY_CS_PIN       10
#define ES_DISPLAY_RST_PIN      9

#define ES_POT_LO_PIN           15
#define ES_POT_UP_PIN           14

// Teensy 3.2
#elif defined(__MK20DX256__)

#define ES_DISPLAY_MISO_PIN     12
#define ES_DISPLAY_MOSI_PIN     7
#define ES_DISPLAY_SCK_PIN      14
#define ES_DISPLAY_DC_PIN       15
#define ES_DISPLAY_CS_PIN       10
#define ES_DISPLAY_RST_PIN      8

#define ES_POT_LO_PIN           21
#define ES_POT_UP_PIN           20

// Unsupported Teensy
#else
#error Unknown Teensy
#endif

// common defs
#define ES_ROTARY_ENCA_PIN      17
#define ES_ROTARY_ENCB_PIN      16

#define ES_BUTTON_PIN           2
#define ES_LED1_PIN             3
#define ES_LED2_PIN             4
#define ES_LED3_PIN             5
#define ES_LED4_PIN             6

#define ES_MIDI_IN_PIN          0
#define ES_MIDI_OUT_PIN         1


class ESBuddy : public Print
{
public:
    ESBuddy();

    void init(float volume=0.5f);

    AudioStream &audioInput() { return _audioInput; }
    AudioStream &audioOutput() { return _audioOutput; }

    int encoderRead() { return _encoder.read(); }
    int encoderReadAndReset() { return _encoder.readAndReset(); }

    int potLoReadRaw() { return analogRead(ES_POT_LO_PIN); }
    int potUpReadRaw() { return analogRead(ES_POT_UP_PIN); }

    float potLoRead() { return analogRead(ES_POT_LO_PIN) / 1024.f; }
    float potUpRead() { return analogRead(ES_POT_UP_PIN) / 1024.f; }

    void ledWrite(int num, bool on) { digitalWrite(led_pins[num], on ? HIGH : LOW); }
    void ledBarWrite(int val);
    bool buttonRead() { return digitalRead(ES_BUTTON_PIN) == HIGH; }

#ifdef ES_HAVE_TFT
    ST7735_t3 &display() { return _tftDisplay; }
    void displayClear() { _tftDisplay.fillScreen(ST7735_BLACK); this->home(); }
    void displayUpdate() { _tftDisplay.updateScreen(); }

    void home() { _tftDisplay.setCursor(0,0); }
    void setCursor(int x, int y) {
        _tftDisplay.setCursor(
            x * _tftDisplay.getTextSizeX(),
            y * _tftDisplay.getTextSizeY() );
    }

    // Print support
    virtual size_t write(uint8_t c)  { return _tftDisplay.write(c); }
    virtual size_t write(const uint8_t *buffer, size_t size) {
        return _tftDisplay.write(buffer, size);
    }
#else
#ifdef ES_HAVE_OLED
    Adafruit_SSD1306 &display() { return _oledDisplay; }
    void displayClear() { _oledDisplay.clearDisplay(); }
    void displayUpdate() { _oledDisplay.display(); }

    void home() { _oledDisplay.setCursor(0,0); }
    void setCursor(int x, int y) { _oledDisplay.setCursor(x,y); }

    // Print support
    virtual size_t write(uint8_t c)  { return _oledDisplay.write(c); }
    virtual size_t write(const uint8_t *buffer, size_t size) {
        return _oledDisplay.write(buffer, size);
    }
#endif
#endif

    void dumpState(Print &printer);

private:
    AudioInputI2S          _audioInput;  
    AudioOutputI2S         _audioOutput;  
    AudioControlSGTL5000   _audioShield;

    Encoder                _encoder;

#ifdef ES_HAVE_TFT
    ST7735_t3              _tftDisplay;
#endif
#ifdef ES_HAVE_OLED
    Adafruit_SSD1306       _oledDisplay;
#endif

    const int led_pins[4] = {
        ES_LED1_PIN, ES_LED2_PIN, ES_LED3_PIN, ES_LED4_PIN
    };
};

#endif // ES_BUDDY_H
