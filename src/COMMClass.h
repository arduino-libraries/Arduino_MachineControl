/**
 * @file COMMClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the COMMClass used to initialize and interact with communication protocols (CAN Bus, RS485, and RS232) on the Portenta Machine Control board.
 *
 * This library provides a class to manage the communication protocols of the Portenta Machine Control board.
 * It allows initializing and interacting with the CAN Bus, RS485, and RS232 protocols. The library also initializes the corresponding LEDs for CAN and RS485.
 */ 

#ifndef __COMM_CLASS_H
#define __COMM_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <ArduinoRS485.h>
#include <Arduino.h>
#include <pinDefinitions.h>
#include <mbed.h>

/* Class ----------------------------------------------------------------------*/

/**
 * @class COMMClass
 * @brief Class for managing the communication protocols of the Portenta Machine Control.
 */
class COMMClass {
public:
    /**
     * @brief Construct a COMMClass object.
     *
     * This constructor initializes a COMMClass object.
     */
    COMMClass();

    /**
     * @brief Destruct the COMMClass object.
     *
     * This destructor releases any resources used by the COMMClass object.
     */
    ~COMMClass();

    /**
     * @brief Begin the communication protocols.
     *
     * This method initializes the communication protocols, including the RS485 and CAN LEDs.
     *
     * @return true If the initialization is successful, false otherwise.
     */
    bool begin();

    /**
     * @brief Set the CAN transceiver in Normal mode.
     *
     * In this mode, the transceiver can transmit and receive data via the bus lines CANH and CANL.
     */
    void CANEnable();

    /**
     * @brief Set the CAN transceiver in Standby (low power) mode.
     *
     * In this mode, the transceiver will not be able to transmit or correctly receive data via the bus lines.
     * The wake-up filter on the output of the low-power receiver does not latch bus dominant states,
     * but ensures that only bus dominant and bus recessive states that persist longer than tfltr(wake)
     * bus are reflected on pin RXD.
     */
    void CANDisable();

    /**
     * @brief Enable RS485 communication.
     *
     * This method enables RS485 communication.
     */
    void RS485Enable();

    /**
     * @brief Disable RS485 communication.
     *
     * This method disables RS485 communication.
     */
    void RS485Disable();

    /**
     * @brief Set RS485 mode to RS232.
     *
     * @param enable If true, sets the RS485 mode to RS232, else sets to RS485 mode.
     */
    void RS485SetModeRS232(bool enable);

    /**
     * @brief Set YZ termination for RS485 communication.
     *
     * @param enable If true, enables YZ termination, else disables it.
     */
    void RS485SetYZTerm(bool enable);

    /**
     * @brief Set AB termination for RS485 communication.
     *
     * @param enable If true, enables AB termination, else disables it.
     */
    void RS485SetABTerm(bool enable);

    /**
     * @brief Set the slew rate for RS485 communication.
     *
     * @param enable If true, enables the slew rate control, else disables it.
     */
    void RS485SetSlew(bool enable);

    /**
     * @brief Set RS485 communication to Full Duplex mode.
     *
     * @param enable If true, sets RS485 communication to Full Duplex mode, else to Half Duplex mode.
     */
    void RS485SetFullDuplex(bool enable);

	arduino::UART 	_UART4_	{PA_0, PI_9, NC, NC};
	mbed::CAN 		CAN 	{PB_8, PH_13};
	RS485Class 		RS485 	{_UART4_, PinNameToIndex(PA_0), PinNameToIndex(PI_13), PinNameToIndex(PI_10)};
};

extern COMMClass MachineControl_CommProtocols;

#endif /* __COMM_CLASS_H */