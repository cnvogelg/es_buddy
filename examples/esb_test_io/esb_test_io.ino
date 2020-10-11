// esb_test_io.ino
// Simply test to check button, pots and rotary encoder

#include "es_buddy.h"

ESBuddy esb;

void setup() {
  Serial.begin(115200);
  AudioMemory(30);
  esb.init();
}

void loop() {
  static int count = 0;

  esb.dumpState(Serial);
  esb.ledBarWrite(count++);

  delay(500);
}
