#include "midian.h"

// Note/Key Pin Aliases
const uint8_t p0 = 2;
const uint8_t pins[NUM_KEYS] = {p0};
uint8_t notes[NUM_KEYS];

// uint16_t keysOn = 0x0000;
// uint16_t keysOff = 0x0000;

void noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.write(channel);
  Serial.write(note);
  Serial.write(velocity);
}

void readKeys() {
  const uint8_t velocity = 0x45; // for now, const vel.

  for (int i = 0; i < NUM_KEYS; i++) {
    // maybe try this for speed: https://forum.arduino.cc/t/digitalwritefast-digitalreadfast-pinmodefast-etc/47037/2
    if (digitalRead(pins[i]) == LOW) {
      noteOn(0x90, notes[i], velocity);
      // delay(1); // debounce?
      //some flush cmd?
    } else {
      // maybe 0x90 still? but 0x80 for note off usually...
      noteOn(0x80, notes[i], 0);
      // dleay and flush?
    }
  }
}