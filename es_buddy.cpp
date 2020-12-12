#include "es_buddy.h"

const int myInput = AUDIO_INPUT_LINEIN;

ESBuddy::ESBuddy()
    : _encoder(ES_ROTARY_ENCB_PIN, ES_ROTARY_ENCA_PIN),
      _encVal(0),
      _button(ES_BUTTON_PIN, 5)
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

int ESBuddy::encoderRead()
{
    int val = _encoder.read();
    if(val == _encVal) {
        return 0;
    } else {
        int steps = (val - _encVal) / 4;
        _encVal += steps * 4;
        return steps;
    }
}

ButtonState ESBuddy::buttonRead() 
{ 
    _button.update();
    if(_button.risingEdge()) {
        _buttonDown = true;
        return ButtonState::RISE;
    } else if(_button.fallingEdge()) {
        _buttonDown = false;
        return ButtonState::FALL;
    } else {
        return ButtonState::NONE;
    }
}

bool ESBuddy::pollEvent(Event &e)
{
    // check button
    ButtonState state = buttonRead();
    if(state == ButtonState::RISE) {
        e.type = EventType::BUTTON_DOWN;
        _pressStart = millis();
        return true;
    }
    else if(state == ButtonState::FALL) {
        e.type = EventType::BUTTON_UP;
        return true;
    }

    // check long press
    if(_buttonDown) {
        unsigned long delta = millis() - _pressStart;
        if(delta > 500) {
            e.type = EventType::BUTTON_LONG_PRESS;
            return true;
        }
    }

    // check encoder
    int delta = encoderRead();
    if(delta < 0) {
        e.type = EventType::DEC_VALUE;
        e.value = -delta;
        return true;
    }
    else if(delta > 0) {
        e.type = EventType::INC_VALUE;
        e.value = delta;
        return true;
    }

    return false;
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
    ButtonState state = buttonRead();
    switch(state) {
        case ButtonState::NONE:
            printer.println("NONE");
            break;
        case ButtonState::RISE:
            printer.println("RISE");
            break;
        case ButtonState::FALL:
            printer.println("FALL");
            break;
    }

    printer.print("  potLo=");
    printer.print(potLoRead());
    printer.print("/");
    printer.println(potLoReadRaw());

    printer.print("  potUp=");
    printer.print(potUpRead());
    printer.print("/");
    printer.println(potUpReadRaw());

    printer.print("  encoder=");
    printer.println(encoderRead());
}

void ESBuddy::dumpAudioState(Print &printer)
{
    printer.println("AudioState:");
    printer.print("  proc=");
    printer.println(AudioProcessorUsage());
    printer.print("  max=");
    printer.println(AudioProcessorUsageMax());
}
