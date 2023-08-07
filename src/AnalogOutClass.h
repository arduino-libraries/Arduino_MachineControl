/**
 * @file AnalogOutClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Analog OUT connector of the Portenta Machine Control library.
 *
 * This library allows to configure the analog channels as PWM, to set frequency and value.
 */

#ifndef __ANALOGOUT_CLASS_H
#define __ANALOGOUT_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class AnalogOutClass
 * @brief Class for the Analog OUT connector of the Portenta Machine Control.
 */
class AnalogOutClass {
    public:
        /**
         * @brief Construct an Analog Output writer for the Portenta Machine Control.
         *
         * @param ao0_pin The analog pin number of the channel 0
         * @param ao1_pin The analog pin number of the channel 1
         * @param ao2_pin The analog pin number of the channel 2
         * @param ao3_pin The analog pin number of the channel 2
         */
        AnalogOutClass(PinName ao0_pin = MC_AO_AO0_PIN, PinName ao1_pin = MC_AO_AO1_PIN, PinName ao2_pin = MC_AO_AO2_PIN, PinName ao3_pin = MC_AO_AO3_PIN);
        
        /**
         * @brief Destruct the AnalogOutClass object.
         *
         * This destructor releases any resources used by the AnalogOutClass object.
         */
        ~AnalogOutClass();

        /**
         * @brief Initialize the PWM, configure the default frequency for all channels (500Hz)
         *  
         * @return true If the PWM is successfully initialized, false Otherwise
         */
        bool begin();

        /**
         * @brief Set the PWM period (frequency) on the selected channel
         * 
         * @param channel selected channel
         * @param period_ms PWM period in ms
         */
        void setPeriod(int channel, uint8_t period_ms);

        /**
         * @brief Set output voltage value on the selected channel
         * 
         * @param channel selected channel
         * @param voltage desired output voltage (max 10.5V)
         */
        void write(int channel, float voltage);

    private:
        mbed::PwmOut _ao0;   // PWM output for Analog Out channel 0
        mbed::PwmOut _ao1;   // PWM output for Analog Out channel 1
        mbed::PwmOut _ao2;   // PWM output for Analog Out channel 2
        mbed::PwmOut _ao3;   // PWM output for Analog Out channel 3
};

extern AnalogOutClass MachineControl_AnalogOut;

#endif /* __ANALOGOUT_CLASS_H */