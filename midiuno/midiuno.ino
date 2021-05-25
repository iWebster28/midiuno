/*
  midiuno
  Ian Webster 
  May 2021
  
  This software is adapted from the following reference: 
  http://www.arduino.cc/en/Tutorial/Midi
 */

#include "midian.h"

void setup() {
  Serial.begin(MIDIRATE); // MIDI Baud Rate
  // Setup pins
  for (uint8_t i = 0 ; i < NUM_KEYS; i++) {
    pinMode(pins[i], INPUT_PULLUP);
    notes[i] = 0x30 + i; // A0 + i
  }

}

void loop() {
  fastReadKeys();
}
