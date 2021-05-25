## Midiuno
A MIDI Footswitch Project for musicians.

### HW
* Arduino Uno R3.  

### SW
* mocoLUFA MIDI Firmware  
* Reference code from http://www.arduino.cc/en/Tutorial/Midi

### Roadmap
* Consider low latency
* FIFO or Ring Buffer for notes?
* Switch debouncing? Resistor/cap
  * Consider max key repetition

* Arduino can do "protothreading" - send multiple notes @ same time?
* 

### Resources
[mocoLUFA MIDI Firmware](https://github.com/kuwatay/mocolufa)  
[mocoLUFA Online Tool](https://moco-lufa-web-client.herokuapp.com/#/)  
[FLIP Firmware Flash SW for ATmega16u2](https://www.microchip.com/Developmenttools/ProductDetails/FLIP)  
[Flip Tutorial](https://www.youtube.com/watch?v=fSXZMVdO5Sg)  

#### Etc
[Arduino Port Manipulation by Byte](https://www.arduino.cc/en/Reference/PortManipulation)  
[ATmega328p Mapping](https://www.arduino.cc/en/Hacking/PinMapping168)
