/**
 * @file USBControllerClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the USB Controller of the Portenta Machine Control.
 *
 * This library provides a class to manage the USB functionality of the Portenta Machine Control.
 * It enables or disables the power of the USB Host (USBA) and provides methods to check the fault status.
 */

#ifndef __USB_CONTROLLER_CLASS_H
#define __USB_CONTROLLER_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class USBClass
 * @brief Class for managing the USB functionality of the Portenta Machine Control.
 *
 * This class allows enabling or disabling the power of the USB Host (USBA) and checking for any fault status.
 */
class USBClass {
public:
    /**
     * @brief Construct a USBClass object.
     *
     * This constructor initializes a USBClass object with the specified pin assignments for power control and fault status.
     *
     * @param power_pin The pin number for controlling the power to the USBA VBUS.
     * @param usbflag_pin The pin number for reading the fault status of the USBA VBUS.
     */
    USBClass(PinName power_pin = MC_USB_PWR_PIN, PinName usbflag_pin = MC_USB_FLAG_PIN);

    /**
     * @brief Destruct the USBClass object.
     *
     * This destructor releases any resources used by the USBClass object.
     */
    ~USBClass();

    /**
     * @brief Begin the USB functionality.
     *
     * This method initializes the USB functionality by enabling power to the USBA VBUS.
     *
     * @return true If the initialization is successful, false otherwise.
     */
    bool begin();

    /**
     * @brief End the USB functionality.
     *
     * This method disables power to the USBA VBUS and releases any resources used by the USBClass object.
     */
    void end();

    /**
     * @brief Get the fault status of the USBA VBUS.
     *
     * This method reads the fault status of the USBA VBUS to check for overcurrent, overtemperature,
     * or reverse-voltage conditions.
     *
     * @return true if there is a fault, false if everything is okay.
     */
    bool getFaultStatus();

private:
    PinName _power;     // Pin for controlling the power to the USBA VBUS
    PinName _usbflag;   // Pin for reading the fault status of the USBA VBUS

    /**
     * @brief Enable power to the USBA VBUS.
     *
     * This private method is used to enable power to the USBA VBUS.
     */
    void _enable();

    /**
     * @brief Disable power to the USBA VBUS.
     *
     * This private method is used to disable power to the USBA VBUS.
     */
    void _disable();
};

extern USBClass MachineControl_USBController;

#endif /* __USB_CONTROLLER_CLASS_H */