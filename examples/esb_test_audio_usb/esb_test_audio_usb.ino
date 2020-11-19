// esb_test_io.ino
// test audio i/o
//
// Note: make sure to set Teensy USB Type to 'Audio' !

// select your display here
#define ES_HAVE_TFT
//#define ES_HAVE_OLED

#include "es_buddy.h"

ESBuddyTFT esb;

// route audio to/from USB
AudioInputUSB            usb_in;
AudioOutputUSB           usb_out;
AudioConnection          patchCord1(usb_in, 0, esb.audioOutput(), 0);
AudioConnection          patchCord2(usb_in, 1, esb.audioOutput(), 1);
AudioConnection          patchCord3(esb.audioInput(), 0, usb_out, 0);
AudioConnection          patchCord4(esb.audioInput(), 1, usb_out, 1);

// peak USB
AudioAnalyzePeak         usb_peak_l;
AudioAnalyzePeak         usb_peak_r;
AudioConnection          patchCord5(usb_in, 0, usb_peak_l, 0);
AudioConnection          patchCord6(usb_in, 1, usb_peak_r, 0);

// peak ES
AudioAnalyzePeak         esb_peak_l;
AudioAnalyzePeak         esb_peak_r;
AudioConnection          patchCord7(esb.audioInput(), 0, esb_peak_l, 0);
AudioConnection          patchCord8(esb.audioInput(), 1, esb_peak_r, 0);


void setup() {
  Serial.begin(115200);
  AudioMemory(30);
  esb.init(0.5f);
}

void loop() {
  static int count = 0;

  esb.dumpAudioState(Serial);

  esb.displayClear();
  esb.dumpAudioState(esb);
  
  float usb_l = usb_peak_l.read();
  float usb_r = usb_peak_r.read();
  esb.print("USB L=");
  esb.println(usb_l);
  esb.print("USB R=");
  esb.println(usb_r);

  float esb_l = esb_peak_l.read();
  float esb_r = esb_peak_r.read();
  esb.print("ESB L=");
  esb.println(esb_l);
  esb.print("ESB R=");
  esb.println(esb_r);

  esb.displayUpdate();

  esb.ledBarWrite(count++);

  delay(500);
}
