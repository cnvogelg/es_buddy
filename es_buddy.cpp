#include "es_buddy.h"

const int myInput = AUDIO_INPUT_LINEIN;

ESBuddy::ESBuddy()
    : _encoder(ES_ROTARY_ENCA_PIN, ES_ROTARY_ENCB_PIN)
{}

void ESBuddy::init(float volume)
{
    pinMode(ES_BUTTON_PIN, INPUT);
    // setup LEDs
    pinMode(ES_LED1_PIN, OUTPUT);
    pinMode(ES_LED2_PIN, OUTPUT);
    pinMode(ES_LED3_PIN, OUTPUT);
    pinMode(ES_LED4_PIN, OUTPUT);

    // setup shield mixer
    _audioShield.enable();
    _audioShield.inputSelect(myInput);
    _audioShield.volume(volume);
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
    printer.println("ESBuddy:");

    printer.print("  button=");
    printer.println(this->buttonRead() ? "DOWN" : "up");

    printer.print("  potLo=");
    printer.print(this->potLoRead());
    printer.print("/");
    printer.println(this->potLoReadRaw());

    printer.print("  potUp=");
    printer.print(this->potUpRead());
    printer.print("/");
    printer.println(this->potUpReadRaw());

    printer.print("  encoder=");
    printer.println(this->encoderRead());
}
