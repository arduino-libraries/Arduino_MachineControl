/**
 * @file CANCommClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the CANCommClass used to initialize and interact with the CAN Bus communication protocol on the Portenta Machine Control board.
 *
 * This library provides a class to manage the CAN Bus communication protocol of the Portenta Machine Control board.
 * It allows initializing and interacting with the CAN Bus protocol.
 */ 

#ifndef __CAN_COMM_CLASS_H
#define __CAN_COMM_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>
#include <Arduino_CAN.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class CANCommClass
 * @brief Class for managing the CAN Bus communication protocol of the Portenta Machine Control.
 *
 * The `CANCommClass` provides methods to work with the CAN Bus communication protocol on the Portenta Machine Control board.
 */
class CANCommClass {
    public:
        /**
         * @brief Construct a CANCommClass object.
         *
         * This constructor initializes a CANCommClass object with the specified CAN_TX and CAN_RX pins.
         *
         * @param can_tx_pin The pin for transmitting data on the CAN Bus.
         * @param can_rx_pin The pin for receiving data on the CAN Bus.
         * @param can_stb_pin The pin to control the standby (low-power) mode of the CAN transceiver.
         */
        CANCommClass(PinName can_tx_pin = MC_CAN_TX_PIN, PinName can_rx_pin = MC_CAN_RX_PIN, PinName can_stb_pin = MC_CAN_STB_PIN);

        /**
         * @brief Destruct the CANCommClass object.
         *
         * This destructor releases any resources used by the CANCommClass object.
         */
        ~CANCommClass();

        /**
         * @brief Begin the CAN communication protocol.
         *
         * This method initializes the CAN communication protocol.
         *
         * @param can_bitrate The desired bitrate for the CAN communication protocol.
         * @return true If the initialization is successful, false otherwise.
         */
        bool begin(CanBitRate can_bitrate);

        /**
         * @brief Write a CAN message to the bus.
         *
         * This method sends a CAN message over the bus.
         *
         * @param msg The CAN message to be sent, represented by a `CanMsg` object.
         * @return The number of bytes sent or <=0 in case of an error.
         */
        int write(CanMsg const & msg);
        
        /**
         * @brief Check the number of available CAN messages in the receive buffer.
         *
         * This method checks the number of CAN messages available to read from the bus.
         *
         * @return The number of available CAN messages.
         */
        size_t available();
        
        /**
         * @brief Read a CAN message from the bus.
         *
         * This method reads a CAN message from the receive buffer.
         *
         * @return The received CAN message as a `CanMsg` object.
         */
        CanMsg read();

        /**
         * @brief Close the CAN communication protocol.
         *
         * This method de-initializes the CAN communication protocol, stopping communication on the CAN Bus.
         */
        void end();

    private:
        Arduino_CAN _can;
        PinName _tx;
        PinName _rx;
        PinName _stb;

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
