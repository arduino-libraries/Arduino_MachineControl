/**
 * @file RtcControllerClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the RtcControllerClass, a wrapper for the PCF8563T RTC of the Portenta Machine Control.
 *
 * This header file defines the RtcControllerClass, which serves as a wrapper for the PCF8563TClass.
 * The class allows setting and getting the time to/from the PCF8563T RTC (Real-Time Clock).
 */

#ifndef __RTC_CONTROLLER_CLASS_H
#define __RTC_CONTROLLER_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/RTC/PCF8563T.h"
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class RtcControllerClass
 * @brief Class for controlling the PCF8563T RTC.
 *
 * This class serves as a wrapper for the PCF8563TClass and provides additional functionalities
 * for controlling the Real-Time Clock on the target platform.
 */
class RtcControllerClass : public PCF8563TClass {
	public:
		/**
		 * @brief Construct a RtcControllerClass object with an interrupt pin.
		 *
		 * This constructor initializes a RtcControllerClass object.
		 * 
		 * @param int_pin The pin number for the interrupt pin (default is PB_9).
		 */
		RtcControllerClass(PinName int_pin = MC_RTC_INT_PIN);

		/**
		 * @brief Destructor for the RtcControllerClass.
		 *
		 * This destructor is responsible for cleaning up any resources associated with the RtcControllerClass.
		 */
		~RtcControllerClass();

	private:
		PinName _int; // Pin for the interrupt
};

extern RtcControllerClass MachineControl_RTCController;

#endif /*  __RTC_CONTROLLER_CLASS_H */
