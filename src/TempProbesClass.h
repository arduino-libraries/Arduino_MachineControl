#include "utility/MAX31865/MAX31865.h"
#include "utility/THERMOCOUPLE/MAX31855.h"
#include <Arduino.h>
#include <mbed.h>

/**
 * The TempProbesClass allows enabling and selecting the different temperature sensor inputs
 * (RTD and thermocouples)
 */
class TempProbesClass {
public:

	/**
	*  Select the input channel to be read (3 channels available)
	*  
	*  @param channel (0-2)
	*/   
	void selectChannel(int channel);

	/**
	*  Enable the CS of the Thermocouple to digital converter
	*  Disable the CS for the RTD to digital converter
	*/   
	void enableTC();

	/**
	*  Enable the CS of the RDT to digital converter. 
	*  Disable the CS of the Thermocouple to digital converter
	*/   
	void enableRTD();

	/**
	*  Disable Chip select for both RTD and thermocouple digital converters. 
	*  
	*/   
	void disableCS();

	MAX31865Class rtd = MAX31865Class(PA_6);
	MAX31855Class tc = MAX31855Class(7);
private:
	mbed::DigitalOut ch_sel[3] = { mbed::DigitalOut(PD_6), mbed::DigitalOut(PI_4), mbed::DigitalOut(PG_10)};
	mbed::DigitalOut rtd_th = mbed::DigitalOut(PC_15);
};

extern TempProbesClass temp_probes;