/* 
  using gpio expander class https://www.i2cdevlib.com/devices/tca6424a#source
  Ask Giampaolo for proper porting
  Expander interrupt is PI_5
  prog_latch_retry (AKA TERM ? ) is PH_14

  TODO: check if Wire and address are correct
*/

#include "utility/ioexpander/ArduinoIOExpander.h"
#include <Arduino.h>
#include <mbed.h>

/**
 * The ProgrammableDIOClass is used to initialize the IOExpanders and configure the 
 * thermal shutdown mode of the high side switches.
 */
class ProgrammableDIOClass : public ArduinoIOExpanderClass {
public:

	/**
	 * Test connection with the IOExpander and set all the pins to the default mode. 
	 * @return true if OK, false if fault
	 */
	bool init();

	/**
	 * Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in latch mode. 
	 * The output latches off when thermal shutdown occurs. 
	 */
	void setLatch();

	 /**
	 * Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in auto-retry mode. 
	 * The output automatically recovers when TJ < T(SD) – T(hys), but the current is limited to ICL(TSD) 
	 * to avoid repetitive thermal shutdown. 
	 */
	void setRetry();
private:
	mbed::DigitalOut prog_latch_retry = mbed::DigitalOut(PH_14);
};

extern ProgrammableDIOClass digital_programmables;