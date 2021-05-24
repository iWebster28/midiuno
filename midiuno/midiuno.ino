/*
  midiuno
  Ian Webster 
  May 2021
  
  This software is adapted from the following reference: 
  http://www.arduino.cc/en/Tutorial/Midi
 */

#include "midian.h"

void setup() {
  Serial.begin(31250); // MIDI Baud Rate
  // Setup pins
  for (uint8_t i = 0 ; i < NUM_KEYS; i++) {
    pinMode(pins[i], INPUT_PULLUP);
    notes[i] = 0x30 + i; // A0 + i
  }

}

void loop() {

  // Next step: read from pins
  // using bitmap? OR all the notes? store 4 bytes (in 2 separate ints?) for 32 notes total?
  // use bitRead and bitWrite?
  // avoid O(n) somehow?

  readKeys();


  

  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
  // for (int note = 0x1E; note < 0x5A; note ++) {
  //   //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
  //   noteOn(0x90, note, 0x45);
  //   delay(100);
  //   //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
  //   noteOn(0x90, note, 0x00);  
  //   delay(100);
  // }
}
