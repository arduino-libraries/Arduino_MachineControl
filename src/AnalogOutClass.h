/**
 * @file AnalogInClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the 
 *
 * This library allows to 
 */
#ifndef __ANALOGOUT_CLASS_H
#define __ANALOGOUT_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>

/* Class ----------------------------------------------------------------------*/

/**
 * @class AnalogOutClass
 * @brief Class for the 
 */
class AnalogOutClass {
    public:
        /**
         * Set output voltage value (PWM)
         * @param  index select channel
         * @param  voltage desired output voltage (max 10.5V)
         */
        void write(int index, float voltage);

        /**
         * Set the PWM period (frequency)
         * @param  index select channel
         * @param  period integer for selecting the period in ms
         */
        void period_ms(int index, uint8_t period);

        mbed::PwmOut& operator[](int index);

    private:
        mbed::PwmOut out_0 = mbed::PwmOut(PJ_11);
        mbed::PwmOut out_1 = mbed::PwmOut(PK_1);
        mbed::PwmOut out_2 = mbed::PwmOut(PG_7);
        mbed::PwmOut out_3 = mbed::PwmOut(PC_7);
};

extern AnalogOutClass analog_out;

#endif /* __ANALOGOUT_CLASS_H */