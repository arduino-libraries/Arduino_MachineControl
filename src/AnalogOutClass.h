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
        AnalogOutClass(PinName ao0_pin = PJ_11, PinName ao1_pin = PK_1, PinName ao2_pin = PG_7, PinName ao3_pin = PC_7);
        ~AnalogOutClass();

        /**
         * @brief Initialize the PWM, configure the default frequency for all channels (500Hz)
         *  
         * @return true If the PWM is successfully initialized, false Otherwise
         */
        bool begin();

        /**
         * Set the PWM period (frequency) on the selected channel
         * @param channel selected channel
         * @param period_ms PWM period in ms
         */
        void setPeriod(int channel, uint8_t period_ms);

        /**
         * Set output voltage value on the selected channel
         * @param channel selected channel
         * @param voltage desired output voltage (max 10.5V)
         */
        void write(int channel, float voltage);

    private:
        mbed::PwmOut _ao0;
        mbed::PwmOut _ao1;
        mbed::PwmOut _ao2;
        mbed::PwmOut _ao3;
};

extern AnalogOutClass MachineControl_AnalogOut;

#endif /* __ANALOGOUT_CLASS_H */