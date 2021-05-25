#include "midian.h"

// Note/Key Pin Aliases
const uint8_t p0 = 2;
const uint8_t pins[NUM_KEYS] = {p0};
uint8_t notes[NUM_KEYS];
// Previous VALUE (on/off)
uint8_t prev_bitmap = 0xFF; //0xFF because active low. Initially all keys OFF, i.e. High.
// Just to track if STATE changed from last loop of fastReadKeys polling.
//uint8_t held_bitmap = 0x00;

// uint16_t keysOn = 0x0000;
// uint16_t keysOff = 0x0000;

void noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
//  Serial.write(channel);
//  Serial.write(note);
//  Serial.write(velocity);
//  Serial.println("CH: ");
//  Serial.println(channel);
//  Serial.println("Note: ");
//  Serial.println(note);
//  Serial.println("Vel: ");
//  Serial.println(velocity);
//  Serial.println("----end-------");
}

void fastReadKeys() {
  const uint8_t velocity = 0x45;
  // If new key state(s) detected: (manual bit read)
  for (uint8_t i = 0; i < NUM_KEYS; i++) {
    // Has this note's value changed since last poll?
    // Assumption that all keys are unpressed to begin (i.e. PIND reads 0xFF)
    uint8_t pin = PIND & (0x01 << (i + PIN_START));
//    Serial.println(pin);
    if (pin ^ (prev_bitmap & (0x01 << i))) { // ! b/c active low
      // What do we set the note to, based on it's previous value?
      Serial.println(PIND, HEX);
      Serial.println(pin, HEX);
      Serial.println(prev_bitmap, HEX);
      exit(0);
      // Based on curr value.
      if (!pin) { // i.e. note is ON (active low)
        noteOn(0x90, notes[i], velocity); // NOTE ON
        bitWrite(prev_bitmap, i, 0); // write a 0 to signify that the note is ON now.
      } else {
        noteOn(0x90, notes[i], 0); // NOTE OFF
        bitWrite(prev_bitmap, i, 1);
      }
    }
//    Serial.println("");
//    Serial.println(pin);
//    Serial.println(prev_bitmap, HEX);
  }
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
