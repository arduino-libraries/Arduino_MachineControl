#include <Arduino.h>
#include <mbed.h>

/**
 * The DigitalOutputClass is used to interface with the IO Expander and
 * set the digital outputs.
 */
class DigitalOutputsClass {
public:

	/**
	 * Set all digital outputs at the same time. 
	 * @param val 8 bit integer to set all 8 channels. e.g:
	 * Set all to HIGH -> val = 255 (0b11111111)
	 * Set all to LOW  -> val = 0   (0b00000000)
	 */
	void setAll(uint8_t val);

	 /**
	 * Set a particular digital output
	 * @param index digital output to be set
	 * @param val set value (HIGH/LOW)
	 */
	void set(int index, bool val);

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

	mbed::DigitalOut& operator[](int index);

private:
	mbed::DigitalOut dig_out_latch_retry = mbed::DigitalOut(PB_2);
	mbed::DigitalOut out[8] = {
		mbed::DigitalOut(PI_6), mbed::DigitalOut(PH_9), mbed::DigitalOut(PJ_9), mbed::DigitalOut(PE_2),
		mbed::DigitalOut(PI_3), mbed::DigitalOut(PI_2), mbed::DigitalOut(PD_3), mbed::DigitalOut(PA_14)
	};
};

extern DigitalOutputsClass digital_outputs;