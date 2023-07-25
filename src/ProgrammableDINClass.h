#include "utility/ioexpander/ArduinoIOExpander.h"
#include <Arduino.h>
#include <mbed.h>

class ProgrammableDINClass : public ArduinoIOExpanderClass {
public:
	/**
	 * Test connection with the IOExpander and set all the pins to the default mode. 
	 * @return true if OK, false if fault
	 */
	bool init();
};

extern ProgrammableDINClass digital_inputs;