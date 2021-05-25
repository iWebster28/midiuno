/*
Ian Webster
May 2021
MIDI Library Functions for midiuno
*/

#include "Arduino.h"

// Globals
// Note/Key Pin Aliases
#define NUM_KEYS 1
#define PIN_START 2
#define DEBUGRATE 38400
#define MIDIRATE 31250

// Note/Key Pin Aliases
extern const uint8_t p0;
extern const uint8_t p1;
extern const uint8_t p2;
extern const uint8_t p3;
extern const uint8_t p4;
extern const uint8_t p5;
extern const uint8_t p6;
extern const uint8_t pins[NUM_KEYS];
extern uint8_t notes[NUM_KEYS];
extern uint8_t prev_bitmap;

/**
 * Sends a note with given `pitch` and `velocity` on channel `cmd`. 
 * 
 * @param channel is the MIDI channel to transmit on
 * @param pitch is the note frequency
 * @param velocity is note velocity, or loudness
 * @result void
 */
void noteOn(uint8_t channel, uint8_t note, uint8_t velocity);

/**
 * Reads keys into internal memory. Used to check if a note changed state before sending another message. 
 * 
 */
void readKeys();
void fastReadKeys();
