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

/* Class ----------------------------------------------------------------------*/

/**
 * @class DigitalOutputsClass
 * @brief Class for the Digital Output connector of the Portenta Machine Control.
 */
class DigitalOutputsClass {
    public:
        /**
         * @brief Construct an 
         *
         * @param 
         */
        DigitalOutputsClass(PinName do0_pin = PI_6, 
                            PinName do1_pin = PH_9, 
                            PinName do2_pin = PJ_9, 
                            PinName do3_pin = PE_2,
                            PinName do4_pin = PI_3,
                            PinName do5_pin = PI_2,
                            PinName do6_pin = PD_3,
                            PinName do7_pin = PA_14,
                            PinName latch_pin = PB_2);
        ~DigitalOutputsClass();

        /**
         * @brief Initialize the
         *  
         * @return true If the X is successfully initialized, false Otherwise
         */
        bool begin();

        /**
         * @brief Set a particular digital output
         * 
         * @param index digital output to be set
         * @param val set value (HIGH/LOW)
         */
        void write(uint8_t channel, PinStatus val);
        
        /**
         * @brief Set all digital outputs at the same time.
         *  
         * @param val 8 bit integer to set all 8 channels. e.g:
         * Set all to HIGH -> val = 255 (0b11111111)
         * Set all to LOW  -> val = 0   (0b00000000)
         */
        void writeAll(uint8_t val);

        /**
         * @brief Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in latch mode. 
         * The output latches off when thermal shutdown occurs. 
         */
        void setLatch();

        /**
         * @brief Configures the thermal shutdown of the high-side switches (TPS4H160) to operate in auto-retry mode. 
         * The output automatically recovers when TJ < T(SD) – T(hys), but the current is limited to ICL(TSD) 
         * to avoid repetitive thermal shutdown. 
         */
        void setRetry();
private:
        PinName _do0;
        PinName _do1;
        PinName _do2;
        PinName _do3;
        PinName _do4;
        PinName _do5;
        PinName _do6;
        PinName _do7;
        PinName _latch;
};

extern DigitalOutputsClass MachineControl_DigitalOutputs;

#endif /* __DIGITALOUTPUTS_CLASS_H */