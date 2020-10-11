// esb_test_io.ino
// Simply test to check button, pots and rotary encoder
// and OLED display

#define ES_HAVE_OLED
#include "es_buddy.h"

ESBuddyOLED esb;

void setup() {
  Serial.begin(115200);
  AudioMemory(30);
  esb.init();
}

void loop() {
  static int count = 0;

  esb.dumpState(Serial);

  esb.displayClear();
  esb.dumpState(esb);
  esb.displayUpdate();

  esb.ledBarWrite(count++);

  delay(500);
}