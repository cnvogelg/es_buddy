#include "es_buddy.h"

const int myInput = AUDIO_INPUT_LINEIN;

ESBuddy::ESBuddy()
    : _encoder(ES_ROTARY_ENCA_PIN, ES_ROTARY_ENCB_PIN)
#ifdef ES_HAVE_TFT
    , _tftDisplay(
        ES_DISPLAY_CS, 
        ES_DISPLAY_DC, 
        ES_DISPLAY_MOSI,
        ES_DISPLAY_SCK, 
        ES_DISPLAY_RST
    )
#endif
#ifdef ES_HAVE_OLED
    , _oledDisplay(
        ES_DISPLAY_MOSI,
        ES_DISPLAY_CLK,
        ES_DISPLAY_DC,
        ES_DISPLAY_RST,
        ES_DISPLAY_CS  
    )
#endif
{
}

void ESBuddy::init(float volume)
{
    // setup LEDs
    pinMode(ES_LED1_PIN, OUTPUT);
    pinMode(ES_LED2_PIN, OUTPUT);
    pinMode(ES_LED3_PIN, OUTPUT);
    pinMode(ES_LED4_PIN, OUTPUT);

    // setup shield mixer
    _audioShield.enable();
    _audioShield.inputSelect(myInput);
    _audioShield.volume(volume);

#ifdef ES_HAVE_TFT
    _tftDisplay.initR(INITR_BLACKTAB);
    _tftDisplay.setRotation(3);
    _tftDisplay.fillScreen(ST7735_BLACK);
    _tftDisplay.useFrameBuffer(true);
#endif
#ifdef ES_HAVE_OLED
    _oledDisplay.begin();
#endif
}

void ESBuddy::ledBarWrite(int val)
{
    digitalWrite(ES_LED1_PIN, (val & 1)== 1 ? HIGH : LOW);
    digitalWrite(ES_LED2_PIN, (val & 2)== 2 ? HIGH : LOW);
    digitalWrite(ES_LED3_PIN, (val & 4)== 4 ? HIGH : LOW);
    digitalWrite(ES_LED4_PIN, (val & 8)== 8 ? HIGH : LOW);
}

void ESBuddy::dumpState(Print &printer)
{
    printer.print("ESBuddy: button=");

    printer.println(this->buttonRead() ? "pressed" : "released");

    printer.print("  potLo=");
    printer.print(this->potLoRead());
    printer.print("/");
    printer.print(this->potLoReadRaw());

    printer.print(", potUp=");
    printer.print(this->potUpRead());
    printer.print("/");
    printer.println(this->potUpReadRaw());

    printer.print("  encoder=");
    printer.println(this->encoderRead());
}
