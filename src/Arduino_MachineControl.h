#ifndef __MACHINE_CONTROL_H__
#define __MACHINE_CONTROL_H__

#include "utility/MAX31865/MAX31865.h"
#include "utility/THERMOCOUPLE/MAX31855.h"
#include <ArduinoRS485.h>
#include "utility/QEI/QEI.h"
#include "utility/ioexpander/ArduinoIOExpander.h"
#include "utility/RTC/PCF8563T.h"
#include "utility/RTC/PCF8563T.h"

#include <Arduino.h>
#include <pinDefinitions.h>
#include <mbed.h>

#include "AnalogInClass.h"
#include "AnalogOutClass.h"
#include "DigitalOutputsClass.h"
#include "ProgrammableDIOClass.h"
#include "ProgrammableDINClass.h"
#include "RTDClass.h"

namespace machinecontrol {

/**
 * The COMMClass is used to initialize the CAN and RS485 LEDs and 
 * establish the power mode of the CAN bus. 
 */
class COMMClass {
public:
	// to be tested: check if can be made a big pin initialization

	 /**
	 * Shutdown RS485 and CAN LEDs
	 */
	void init() {
		//SHUTDOWN OF RS485 LEDS
		digitalWrite(PinNameToIndex(PA_0), LOW);
		digitalWrite(PinNameToIndex(PI_9), LOW);
		//SHUTDOWN OF CAN LEDS
		digitalWrite(PinNameToIndex(PB_8), HIGH);
		digitalWrite(PinNameToIndex(PH_13), HIGH);

		// SET DEFAULTS for RS485
		rs485Enable(false);
		rs485ModeRS232(false);
		rs485FullDuplex(false);
		rs485YZTerm(false);
		rs485ABTerm(false);
		rs485Slew(false);
	}

	 /**
	 * Set the CAN transceiver in Normal mode. In this mode, the transceiver 
	 * can transmit and receive data via the bus lines CANH and CANL.
	 */
	void enableCAN() {
		can_disable = 0;
	}

	 /**
	 * Set the CAN transceiver in standby (low power) mode. In this mode the
	 * transceiver will not be able to transmit or correctly receive data via the bus lines.
	 * The wake-up filter on the output of the low-power receiver does not latch bus dominant states,
	 * but ensures that only bus dominant and bus recessive states that persist longer than tfltr(wake)
	 * bus are reflected on pin RXD.
	 */
	void disableCAN() {
		can_disable = 1;
	}

	arduino::UART _UART4_ {PA_0, PI_9, NC, NC};
	mbed::CAN can {PB_8, PH_13};

	RS485Class rs485 {_UART4_, PinNameToIndex(PA_0), PinNameToIndex(PI_13), PinNameToIndex(PI_10)};

	void rs485Enable(bool enable) 		{ digitalWrite(PinNameToIndex(PG_9),  enable ? 	HIGH : LOW); }
	void rs485ModeRS232(bool enable) 	{ digitalWrite(PinNameToIndex(PA_10), enable ? 	LOW : HIGH); }
	void rs485YZTerm(bool enable) 		{ digitalWrite(PinNameToIndex(PI_15), enable ? 	HIGH : LOW); }
	void rs485ABTerm(bool enable) 		{ digitalWrite(PinNameToIndex(PI_14), enable ? 	HIGH : LOW); }
    void rs485Slew(bool enable)  		{ digitalWrite(PinNameToIndex(PG_14), enable ? 	LOW : HIGH); }
	void rs485FullDuplex(bool enable) 	{
		digitalWrite(PinNameToIndex(PA_9), enable ? LOW : HIGH);
		if (enable) {
			// RS485 Full Duplex require YZ and AB 120 Ohm termination enabled
			rs485YZTerm(true);
			rs485ABTerm(true);
		}
	}

private:
	mbed::DigitalOut can_disable = mbed::DigitalOut(PA_13, 0);
};

extern COMMClass comm_protocols;

/* 
  TODO: writeme 
  Use QEI library for mbed since it implements index pin
*/
 /**
 * The EncoderClass is a wrapper for manipulating Quadrature Encoder Interface devices.
 */
class EncoderClass {
public:
  /**
	 * returns the encoder variable depending on the index
	 * @param  index integer for selecting the encoder (0 or 1)
	 * @return enc_0 for index = 0, enc_1 for index = 1
	 */
	EncoderClass()
		: enc_0{PJ_8, PH_12, PH_11, 0}
		, enc_1{PC_13, PI_7, PJ_10, 0} {};


	QEI& operator[](int index) {
		switch (index) {
			case 0:
				return enc_0;
			case 1:
				return enc_1;
		}
	}
private:
	QEI enc_0;
	QEI enc_1;
};

extern EncoderClass encoders;

/**
 * The RtcControllerClass is a wrapper for the PCF8563TClass() that is used to 
 * set and get the time to/from the PCF8563T RTC.
 *  
 */
class RtcControllerClass : public PCF8563TClass {
public:
	mbed::DigitalIn int_pin = mbed::DigitalIn(PB_9,PullUp);
private:

};

extern RtcControllerClass rtc_controller;


/**
 * The USB Class is used to enable/disable the power of the USBA (Host) and configure
 * the callbacks for the different host types (i.e. Keyboard, mouse, storage device etc). 
 */
class USBClass {
public:
	USBClass()
		: _power{PB_14, 0}
		, _usbflag{PB_15}
		{};
		
	/**
	 * Enable power to USBA VBUS. 
	 */
	void powerEnable() {
		_power = 0;
	}

	/**
	 * Disable power to USBA VBUS.  
	 */
	void powerDisable() {
		_power = 1;
	}

	/**
	 * Flag to indicate overcurrent, overtemperature, or reverse−voltage conditions on the USBA VBUS. 	 
	 * Active−low open−drain output.
	 * @return true if OK, false if fault
	 */
	bool vflagRead() {
		return _usbflag;
	}

private:
	mbed::DigitalOut _power;
	mbed::DigitalIn _usbflag;
};


extern USBClass usb_controller;


}
#endif
