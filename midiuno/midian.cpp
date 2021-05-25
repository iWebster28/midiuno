#include "midian.h"

// Note/Key Pin Aliases
const uint8_t p0 = 2;
const uint8_t p1 = 3;
const uint8_t p2 = 4;
const uint8_t p3 = 5;
const uint8_t p4 = 6;
const uint8_t p5 = 7;
const uint8_t pins[NUM_KEYS] = {p0/*, p1, p2, p3, p4, p5*/};
uint8_t notes[NUM_KEYS];
// Previous VALUE (on/off)
uint8_t prev_bitmap = 0xFF; //0xFF because active low. Initially all keys OFF, i.e. High.

void noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.write(channel);
  Serial.write(note);
  Serial.write(velocity);
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

    //(PIND & (0x01 << (i + PIN_START))) // isolates the binary digit. 
    // then ```>> (i + PIN_START)``` acts as a "reduction AND"
    uint8_t pin = (PIND & (0x01 << (i + PIN_START))) >> (i + PIN_START);
//    uint8_t pin = digitalRead(pins[i] == LOW);
//    Serial.println(pin);

    // Just to track if STATE changed from last loop of fastReadKeys polling.
    if (pin ^ (prev_bitmap & (0x01 << i))) { // ! b/c active low
//      Serial.println(PIND, HEX);
//      Serial.println(pin, HEX);
//      Serial.println(prev_bitmap, HEX);
//      Serial.println(prev_bitmap, HEX);

      // Based on curr value.
      if (!pin) { // i.e. note is ON (active low)
        noteOn(0x90, notes[i], velocity); // NOTE ON
        bitWrite(prev_bitmap, i, 0); // write a 0 to signify that the note is ON now.
      } else {
        noteOn(0x80, notes[i], 0); // NOTE OFF
        bitWrite(prev_bitmap, i, 1);
      }
    }
  }
}
