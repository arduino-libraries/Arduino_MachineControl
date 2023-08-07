/**
 * @file DigitalOutputsClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Digital Output connector of the Portenta Machine Control library.
 *
 * This library allows to interface with the IO Expander and set the digital outputs.
 */

#ifndef __DIGITALOUTPUTS_CLASS_H
#define __DIGITALOUTPUTS_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class DigitalOutputsClass
 * @brief Class for the Digital Output connector of the Portenta Machine Control.
 */
class DigitalOutputsClass {
    public:
        /**
         * @brief Construct a DigitalOutputsClass object.
         *
         * This constructor initializes a DigitalOutputsClass object with the specified pin assignments for digital outputs.
         *
         * @param do0_pin The pin number for the digital output channel 0.
         * @param do1_pin The pin number for the digital output channel 1.
         * @param do2_pin The pin number for the digital output channel 2.
         * @param do3_pin The pin number for the digital output channel 3.
         * @param do4_pin The pin number for the digital output channel 4.
         * @param do5_pin The pin number for the digital output channel 5.
         * @param do6_pin The pin number for the digital output channel 6.
         * @param do7_pin The pin number for the digital output channel 7.
         * @param latch_pin The pin number for the latch mode control.
         */
        DigitalOutputsClass(PinName do0_pin = MC_DO_DO0_PIN, 
                            PinName do1_pin = MC_DO_DO1_PIN, 
                            PinName do2_pin = MC_DO_DO2_PIN, 
                            PinName do3_pin = MC_DO_DO3_PIN,
                            PinName do4_pin = MC_DO_DO4_PIN,
                            PinName do5_pin = MC_DO_DO5_PIN,
                            PinName do6_pin = MC_DO_DO6_PIN,
                            PinName do7_pin = MC_DO_DO7_PIN,
                            PinName latch_pin = MC_DO_LATCH_PIN);

        /**
         * @brief Destruct the DigitalOutputsClass object.
         *
         * This destructor releases any resources used by the DigitalOutputsClass object.
         */               
        ~DigitalOutputsClass();

        /**
         * @brief Initialize the DigitalOutputs module with the specified latch mode.
         * 
         * @param latch_mode The latch mode for thermal shutdown. If true, thermal shutdown operates in the latch mode. Otherwise, it operates in the auto-retry mode.
         * @return true If the DigitalOutputs module is successfully initialized, false Otherwise
         */
        bool begin(bool latch_mode = true);

        /**
         * @brief Write the output value for the given channel.
         *
         * @param channel The channel number to write to.
         * @param val The value to write. It can be either PinStatus::HIGH or PinStatus::LOW.
         */
        void write(uint8_t channel, PinStatus val);
        
        /**
         * @brief Set the state of all digital outputs simultaneously.
         *
         * @param val_mask An 8-bit integer representing the state of all 8 channels. Each bit corresponds to a channel, where 1 represents HIGH and 0 represents LOW.
         * For example:
         * - To set all channels to HIGH: val_mask = 255 (0b11111111)
         * - To set all channels to LOW: val_mask = 0 (0b00000000)
         */
        void writeAll(uint8_t val_mask);
        
    private:
        PinName _do0;      // Digital output pin for DO (Digital Out) channel 0
        PinName _do1;      // Digital output pin for DO (Digital Out) channel 1
        PinName _do2;      // Digital output pin for DO (Digital Out) channel 2
        PinName _do3;      // Digital output pin for DO (Digital Out) channel 3
        PinName _do4;      // Digital output pin for DO (Digital Out) channel 4
        PinName _do5;      // Digital output pin for DO (Digital Out) channel 5
        PinName _do6;      // Digital output pin for DO (Digital Out) channel 6
        PinName _do7;      // Digital output pin for DO (Digital Out) channel 7
        PinName _latch;    // Latch control pin

        /**
         * @brief Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in latch mode. 
         * The output latches off when thermal shutdown occurs. 
         */
        void _setLatchMode();

        /**
         * @brief Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in auto-retry mode. 
         * The output automatically recovers when TJ < T(SD) – T(hys), but the current is limited to ICL(TSD) 
         * to avoid repetitive thermal shutdown. 
         */
        void _setAutoRetryMode();
};

extern DigitalOutputsClass MachineControl_DigitalOutputs;

#endif /* __DIGITALOUTPUTS_CLASS_H */