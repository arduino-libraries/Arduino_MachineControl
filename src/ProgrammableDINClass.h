/**
 * @file ProgrammableDINClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Programmable Digital Input connector of the Portenta Machine Control library.
 *
 * This library allows interfacing with the IO Expander and configuring the digital inputs.
 */

#ifndef __PROGRAMMABLE_DIN_CLASS_H
#define __PROGRAMMABLE_DIN_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/ioexpander/ArduinoIOExpander.h"
#include <Arduino.h>
#include <mbed.h>

/* Class ----------------------------------------------------------------------*/

/**
 * @class ProgrammableDINClass
 * @brief Class for the Programmable Digital Input connector of the Portenta Machine Control.
 *
 * This class extends the ArduinoIOExpanderClass to interface with the IO Expander and provides methods to configure digital inputs.
 */
class ProgrammableDINClass : public ArduinoIOExpanderClass {
    public:
        /**
         * @brief Construct a ProgrammableDINClass object.
         *
         * This constructor initializes a ProgrammableDINClass object.
         */
        ProgrammableDINClass();

        /**
         * @brief Destruct the ProgrammableDINClass object.
         *
         * This destructor releases any resources used by the ProgrammableDINClass object.
         */
	    ~ProgrammableDINClass();

        /**
         * @brief Initialize the ProgrammableDIN module.
         *
         * Test connection with the IOExpander and set all the pins to the default mode.
         *
         * @return true If the ProgrammableDIN module is successfully initialized, false otherwise.
         */
        bool begin();
};

extern ProgrammableDINClass MachineControl_DigitalInputs;

#endif /* __PROGRAMMABLE_DIN_CLASS_H */