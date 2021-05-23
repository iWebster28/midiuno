/*
Ian Webster
May 2021
MIDI Library Functions for midiuno
*/
#include <stdint.h>
#include "HardwareSerial.h"

/**
 * Sends a note with given `pitch` and `velocity` on channel `cmd`. 
 * 
 * @param channel is the MIDI channel to transmit on
 * @param pitch is the note frequency
 * @param velocity is note velocity, or loudness
 * @result void
 */
void noteOn(uint8_t channel, uint8_t note, uint8_t velocity);
