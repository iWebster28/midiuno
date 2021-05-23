#include "midian.h"

void noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.write(channel);
  Serial.write(note);
  Serial.write(velocity);
}
