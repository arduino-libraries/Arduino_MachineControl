/**
 * @file RS485CommClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the RS485CommClass used to initialize and interact with RS485 and RS232 communication protocols on the Portenta Machine Control board.
 *
 * This library provides a class to manage the RS485 and RS232 communication protocols of the Portenta Machine Control board.
 * It allows initializing and interacting with the serial protocols. The library also initializes the corresponding LEDs.
 */ 

#ifndef __RS485_COMM_CLASS_H
#define __RS485_COMM_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <ArduinoRS485.h> 
#include <Arduino.h>      
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class RS485CommClass
 * @brief Class for managing the RS485 and RS232 communication protocols of the Portenta Machine Control.
 *
 * The `RS485CommClass` is a subclass of `RS485Class` and provides methods to work with the RS485 and RS232 communication protocols on the Portenta Machine Control board.
 * It includes features to initialize, configure, and interact with the serial protocols. The library also initializes the corresponding LED for RS485.
 */
class RS485CommClass : public RS485Class {
    public:
        /**
         * @brief Construct a RS485CommClass object.
         *
         * This constructor initializes a RS485CommClass object with the specified UART interface and pins.
         *
         * @param uart_itf The UART interface to use for communication.
         * @param rs_tx_pin The pin for transmitting data on the RS485 Bus.
         * @param rs_de_pin The pin for enabling the RS485 driver.
         * @param rs_re_pin The pin for setting the RS485 driver in receive or transmit mode.
         */
        RS485CommClass(arduino::UART& uart_itf, PinName rs_tx_pin = MC_RS485_TX_PIN, PinName rs_de_pin = MC_RS485_DE_PIN, PinName rs_re_pin = MC_RS485_RE_PIN);


        /**
         * @brief Destruct the RS485CommClass object.
         *
         * This destructor releases any resources used by the RS485CommClass object.
         * It will automatically be called when the object goes out of scope.
         */
        ~RS485CommClass();

        /**
         * @brief Begin the RS485 communication protocol.
         *
         * This method initializes the RS485 communication protocol with the specified baud rate and pre/post delays.
         *
         * @param baudrate The desired baud rate for the RS485 communication.
         * @param predelay The delay before sending data in the RS485 communication (default: RS485_DEFAULT_PRE_DELAY).
         * @param postdelay The delay after sending data in the RS485 communication (default: RS485_DEFAULT_POST_DELAY).
         */
        void begin(unsigned long baudrate = 115200, int predelay = RS485_DEFAULT_PRE_DELAY, int postdelay = RS485_DEFAULT_POST_DELAY);

        /**
         * @brief Close the RS485 communication protocol.
         *
         * This method de-initializes the RS485 communication protocol, stopping communication on the RS485 Bus.
         */
        void end();

        /**
         * @brief Set RS485 mode to RS232.
         *
         * This method sets the RS485 mode to RS232 or RS485.
         *
         * @param enable If true, sets the RS485 mode to RS232, else sets to RS485 mode.
         */
        void setModeRS232(bool enable);

        /**
         * @brief Set YZ termination for RS485 communication.
         *
         * This method enables or disables YZ termination for RS485 communication.
         *
         * @param enable If true, enables YZ termination, else disables it.
         */
        void setYZTerm(bool enable);

        /**
         * @brief Set AB termination for RS485 communication.
         *
         * This method enables or disables AB termination for RS485 communication.
         *
         * @param enable If true, enables AB termination, else disables it.
         */
        void setABTerm(bool enable);

        /**
         * @brief Set the slew rate for RS485 communication.
         *
         * This method enables or disables the slew rate control for RS485 communication.
         *
         * @param enable If true, enables the slew rate control, else disables it.
         */
        void setSlew(bool enable);

        /**
         * @brief Set RS485 communication to Full Duplex mode.
         *
         * This method sets RS485 communication to Full Duplex or Half Duplex mode.
         *
         * @param enable If true, sets RS485 communication to Full Duplex mode, else to Half Duplex mode.
         */
        void setFullDuplex(bool enable);

    private:
        /**
         * @brief Enable RS485 communication.
         *
         * This method enables RS485 communication.
         */
        void _enable();

        /**
         * @brief Disable RS485 communication.
         *
         * This method disables RS485 communication.
         */
        void _disable();
};

extern RS485CommClass MachineControl_RS485Comm;

#endif /* __RS485_COMM_CLASS_H */
