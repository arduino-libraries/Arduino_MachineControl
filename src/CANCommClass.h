/**
 * @file CANCommClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the CANCommClass used to initialize and interact with the CAN Bus communication protocol on the Portenta Machine Control board.
 *
 * This library provides a class to manage the CAN Bus communication protocol of the Portenta Machine Control board.
 * It allows initializing and interacting with the CAN Bus protocol. The library also initializes the corresponding LED for CAN.
 */ 

#ifndef __CAN_COMM_CLASS_H
#define __CAN_COMM_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <pinDefinitions.h>
#include <mbed.h>

/* Class ----------------------------------------------------------------------*/

/**
 * @class CANCommClass
 * @brief Class for managing the CAN Bus communication protocol of the Portenta Machine Control.
 *
 * The `CANCommClass` is a subclass of `mbed::CAN` and provides methods to work with the CAN Bus communication protocol on the Portenta Machine Control board.
 * It includes initialization of the corresponding LED for CAN.
 */
class CANCommClass: public mbed::CAN { //TODO: Check ARDUINO API VERSION to use Arduino_CAN
    public:
        /**
         * @brief Construct a CANCommClass object.
         *
         * This constructor initializes a CANCommClass object with the specified CAN_TX and CAN_RX pins.
         *
         * @param can_tx_pin The pin for transmitting data on the CAN Bus.
         * @param can_rx_pin The pin for receiving data on the CAN Bus.
         */
        CANCommClass(PinName can_tx_pin = PB_8, PinName can_rx_pin = PH_13);

        /**
         * @brief Destruct the CANCommClass object.
         *
         * This destructor releases any resources used by the CANCommClass object.
         */
        ~CANCommClass();

        /**
         * @brief Begin the CAN communication protocol.
         *
         * This method initializes the CAN communication protocol, including the corresponding LED for CAN.
         *
         * @param can_bitrate The desired bitrate for the CAN communication protocol.
         * @return true If the initialization is successful, false otherwise.
         */
        bool begin(int can_bitrate);

        /**
         * @brief Close the CAN communication protocol.
         *
         * This method de-initializes the CAN communication protocol, stopping communication on the CAN Bus.
         */
        void end();

    private:
        /**
         * @brief Set the CAN transceiver in Normal mode.
         *
         * In this mode, the CAN transceiver can transmit and receive data via the bus lines CANH and CANL.
         */
        void _enable();

        /**
         * @brief Set the CAN transceiver in Standby (low power) mode.
         *
         * In this mode, the CAN transceiver will not be able to transmit or correctly receive data via the bus lines.
         * The wake-up filter on the output of the low-power receiver does not latch bus dominant states,
         * but ensures that only bus dominant and bus recessive states that persist longer than tfltr(wake)
         * bus are reflected on pin RXD.
         */
        void _disable();
};

extern CANCommClass MachineControl_CANComm;

#endif /* __CAN_COMM_CLASS_H */