// esb_test_midi.ino
// test midi i/o
//
// Note: make sure to select Teensy USB Type: "MIDI" !

#include <MIDI.h>

// select your display here
#define ES_HAVE_TFT
//#define ES_HAVE_OLED

#include "es_buddy.h"

ESBuddyTFT esb;
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void setup() {
  Serial.begin(115200);
  AudioMemory(30);
  esb.init();
  MIDI.begin();
}

void print_midi(Print &printer, const char *who, uint8_t type, uint8_t d1, uint8_t d2, uint8_t ch)
{
  printer.print(who);
  printer.print(":");
  printer.print(type);
  printer.print("=");
  printer.print(d1);
  printer.print(",");
  printer.print(d2);
  printer.print(" @");
  printer.println(ch);
}

void loop() {
  static int count = 0;
  bool update = false;

  //esb.displayClear();

  // read HW MIDI
  if(MIDI.read()) {
    uint8_t type = MIDI.getType();
    uint8_t d1 = MIDI.getData1();
    uint8_t d2 = MIDI.getData2();
    uint8_t ch = MIDI.getChannel();

    print_midi(Serial, "HW", type, d1, d2, ch);
    print_midi(esb, "HW", type, d1, d2, ch);
    update = true;
  
    // forward to USB
    usbMIDI.send(type, d1, d2, ch, 0);
  }

  // read USB MIDI
  if(usbMIDI.read()) {
    uint8_t type = usbMIDI.getType();
    uint8_t d1 = usbMIDI.getData1();
    uint8_t d2 = usbMIDI.getData2();
    uint8_t ch = usbMIDI.getChannel();

    print_midi(Serial, "USB", type, d1, d2, ch);
    print_midi(esb, "USB", type, d1, d2, ch);
    update = true;
  
    // forward to HW MIDI
    MIDI.send((midi::MidiType)type, d1, d2, ch);    
  }

  if(update) {
    esb.displayUpdate();
    esb.ledBarWrite(count++);
    if(count == 10) {
      esb.displayClear();
      count = 0;
    }
  }
}
