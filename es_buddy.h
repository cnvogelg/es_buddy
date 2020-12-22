#ifndef ES_BUDDY_H
#define ES_BUDDY_H

#include <Arduino.h>
#include <Audio.h>
#include <Encoder.h>
#include <Bounce.h>

#include "drawable.h"
#include "event.h"

// TFT Support
#ifdef ES_HAVE_TFT
#include <ST7735_t3.h>
#endif
// OLED Support
#ifdef ES_HAVE_OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef ES_OLED_WIDTH
#define ES_OLED_WIDTH 128
#endif
#ifndef ES_OLED_HEIGHT
#define ES_OLED_HEIGHT 64
#endif

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
#define ES_ROTARY_ENCA_PIN      16
#define ES_ROTARY_ENCB_PIN      17

#define ES_BUTTON_PIN           2
#define ES_LED1_PIN             3
#define ES_LED2_PIN             4
#define ES_LED3_PIN             5
#define ES_LED4_PIN             6

#define ES_MIDI_IN_PIN          0
#define ES_MIDI_OUT_PIN         1


enum class ButtonState { RISE, FALL, NONE };

class ESBuddy : public Print, public EventSource
{
public:
    ESBuddy();

    void init(float volume=0.5f);

    AudioStream &audioInput() { return _audioInput; }
    AudioStream &audioOutput() { return _audioOutput; }

    int encoderRead();
    ButtonState buttonRead();
    bool isButtonDown() { buttonRead(); return _buttonDown; }

    int potLoReadRaw() { return analogRead(ES_POT_LO_PIN); }
    int potUpReadRaw() { return analogRead(ES_POT_UP_PIN); }

    float potLoRead() { return analogRead(ES_POT_LO_PIN) / 1024.f; }
    float potUpRead() { return analogRead(ES_POT_UP_PIN) / 1024.f; }

    void ledWrite(int num, bool on) { digitalWrite(led_pins[num], on ? HIGH : LOW); }
    void ledBarWrite(int val);

    void dumpState(Print &printer);
    void dumpAudioState(Print &printer);

    // Print support
    virtual size_t write(uint8_t c)  { return Serial.write(c); }
    virtual size_t write(const uint8_t *buffer, size_t size) {
        return Serial.write(buffer, size);
    }

    virtual bool pollEvent(Event &e);

private:
    AudioInputI2S          _audioInput;  
    AudioOutputI2S         _audioOutput;  
    AudioControlSGTL5000   _audioShield;

    Encoder                _encoder;
    int                    _encVal;
    Bounce                 _button;
    bool                   _buttonDown;  
    unsigned long          _pressStart;
    bool                   _buttonLong;
    bool                   _buttonExtraLong;

    const int led_pins[4] = {
        ES_LED1_PIN, ES_LED2_PIN, ES_LED3_PIN, ES_LED4_PIN
    };
};

#ifdef ES_HAVE_TFT

class ESBuddyTFT : public ESBuddy, public Display
{
public:
    static const int DISPLAY_WIDTH = 160;
    static const int DISPLAY_HEIGHT = 128;

    static const int FONT_WIDTH = 6;
    static const int FONT_HEIGHT = 8;

    ESBuddyTFT() : 
        ESBuddy(),
        _tftDisplay(
            ES_DISPLAY_CS_PIN,
            ES_DISPLAY_DC_PIN, 
            ES_DISPLAY_MOSI_PIN,
            ES_DISPLAY_SCK_PIN, 
            ES_DISPLAY_RST_PIN
        )
    {}

    void init(float volume=0.5f)
    {
        ESBuddy::init(volume);

        _tftDisplay.initR(INITR_BLACKTAB);
        _tftDisplay.setRotation(3);
        _tftDisplay.fillScreen(ST7735_BLACK);

        _penColor = ST7735_WHITE;
    }

    ST7735_t3 &display() { return _tftDisplay; }

    virtual void displayClear() { 
        _tftDisplay.useFrameBuffer(true);
        _tftDisplay.fillScreen(ST7735_BLACK);
        homeCursor();
    }
    virtual void displayUpdate() { _tftDisplay.updateScreen(); }

    virtual int getDisplayWidth() { return DISPLAY_WIDTH; }
    virtual int getDisplayHeight() { return DISPLAY_HEIGHT; }

    virtual void homeCursor() { _tftDisplay.setCursor(0,0); }
    virtual void setCursor(int col, int row) {
        _tftDisplay.setCursor(
            col * FONT_WIDTH,
            row * FONT_HEIGHT);
    }
    virtual void setCursorXY(int x, int y) {
        _tftDisplay.setCursor(x, y);
    }
    virtual int getMaxCursorCol() { return (DISPLAY_WIDTH / FONT_WIDTH)-1; }
    virtual int getMaxCursorRow() { return (DISPLAY_HEIGHT / FONT_HEIGHT)-1; }
    virtual Print &getPrint() { return *this; }

    virtual void setTextColor(uint16_t fg, uint16_t bg) {
        _tftDisplay.setTextColor(fg, bg);
    }
    virtual void setTextColor(uint16_t fg) {
        _tftDisplay.setTextColor(fg);
    }
    virtual void setTextScale(uint8_t sx, uint8_t sy) {
        _tftDisplay.setTextSize(sx, sy);
    }
    virtual int getTextSizeX() { return _tftDisplay.getTextSizeX(); }
    virtual int getTextSizeY() { return _tftDisplay.getTextSizeY(); }

    virtual int getFontWidth() { return FONT_WIDTH; }
    virtual int getFontHeight() { return FONT_HEIGHT; }

    // Print support
    virtual size_t write(uint8_t c)  { return _tftDisplay.write(c); }
    virtual size_t write(const uint8_t *buffer, size_t size) {
        return _tftDisplay.write(buffer, size);
    }

    // Drawable
    virtual void setColor(uint16_t color) { _penColor = color; }
    virtual void vline(int x, int y, int h) {
        _tftDisplay.drawFastVLine(x, y, h, _penColor);
    }
    virtual void hline(int x, int y, int w) {
        _tftDisplay.drawFastHLine(x, y, w, _penColor);
    }
    virtual void line(int x1, int y1, int x2, int y2) {
        _tftDisplay.drawLine(x1, y1, x2, y2, _penColor);
    }
    virtual void pixel(int x, int y) {
        _tftDisplay.drawPixel(x, y, _penColor);
    }
    virtual void fillRect(int x, int y, int w, int h)
    {
        _tftDisplay.fillRect(x, y, w, h, _penColor);
    }

    virtual void drawRect(int x, int y, int w, int h)
    {
        _tftDisplay.drawRect(x, y, w, h, _penColor);
    }

private:
    ST7735_t3 _tftDisplay;
    uint16_t  _penColor;
};
#endif // ES_HAVE_TFT

#ifdef ES_HAVE_OLED
class ESBuddyOLED : public ESBuddy, public Drawable
{
public:
    ESBuddyOLED() :
        ESBuddy(),
        _oledDisplay(
            ES_OLED_WIDTH,
            ES_OLED_HEIGHT,
            ES_DISPLAY_MOSI_PIN,
            ES_DISPLAY_SCK_PIN,
            ES_DISPLAY_DC_PIN,
            ES_DISPLAY_RST_PIN,
            ES_DISPLAY_CS_PIN  
        )
    {}

    void init(float volume=0.5f)
    {
        ESBuddy::init(volume);

        _oledDisplay.begin();
        _oledDisplay.setTextSize(1);
        _oledDisplay.setTextColor(WHITE);
    }

    Adafruit_SSD1306 &display() { return _oledDisplay; }

    void displayClear() { _oledDisplay.clearDisplay(); home(); }
    void displayUpdate() { _oledDisplay.display(); }

    void home() { _oledDisplay.setCursor(0,0); }
    void setCursor(int x, int y) { _oledDisplay.setCursor(x,y); }

    // Print support
    virtual size_t write(uint8_t c)  { return _oledDisplay.write(c); }
    virtual size_t write(const uint8_t *buffer, size_t size) {
        return _oledDisplay.write(buffer, size);
    }

    // Drawable
    virtual void setColor(uint16_t color) {}
    virtual void vline(int x, int y, int h) {
        _oledDisplay.drawFastVLine(x, y, h);
    }
    virtual void hline(int x, int y, int w) {
        _oledDisplay.drawFastHLine(x, y, w);
    }
    virtual void line(int x1, int y1, int x2, int y2) {
        _oleDisplay.drawLine(x1, y1, x2, y2);
    }

private:
    Adafruit_SSD1306 _oledDisplay;
};
#endif // ES_HAVE_OLED

#endif // ES_BUDDY_H
