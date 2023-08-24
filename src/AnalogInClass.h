/**
 * @file AnalogInClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Analog IN connector of the Portenta Machine Control library.
 *
 * This library allows to set the resistor configuration for the type of connected analog sensor (0-10V, 4-20mA or NTC)
 * and to capture the analog values acquired by the ANALOG IN channels.
 */

#ifndef __ANALOGIN_CLASS_H
#define __ANALOGIN_CLASS_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Exported defines ----------------------------------------------------------*/

/**
 * @brief Enum class that represents different sensor types.
 */
enum class SensorType {
    NTC = 1,
    V_0_10 = 2,
    MA_4_20 = 3
};
 
/* Class ----------------------------------------------------------------------*/

/**
 * @class AnalogInClass
 * @brief Class for the Analog IN connector of the Portenta Machine Control.
 */
class AnalogInClass {
    public:
        /**
         * @brief Construct an Analog Input reader for the Portenta Machine Control.
         *
         * @param ai0_pin The analog pin number of the channel 0
         * @param ai1_pin The analog pin number of the channel 1
         * @param ai2_pin The analog pin number of the channel 2
         */
        AnalogInClass(PinName ai0_pin = MC_AI_AI0_PIN, PinName ai1_pin = MC_AI_AI1_PIN, PinName ai2_pin = MC_AI_AI2_PIN);
        
        /**
         * @brief Destruct the AnalogInClass object.
         *
         * This destructor releases any resources used by the AnalogInClass object.
         */
        ~AnalogInClass();

        /**
         * @brief Initialize the analog reader, configure the sensor type and read resolution.
         *
         * @param sensor_type The sensor type (NTC, V_0_10 or MA_4_20)
         * @param res_bits Resolution in bits of the read analog value
         * @return true If the analog reader is successfully initialized, false otherwise
         */
        bool begin(SensorType sensor_type, int res_bits = 16);

        /**
         * @brief Read the sampled voltage from the selected channel.
         * 
         * @param channel The analog input channel number
         * @return uint16_t The analog value between 0.0 and 1.0 normalized to a 16-bit value
         */
        uint16_t read(int channel);

    private:
        PinName _ai0;   // Analog input pin for channel 0
        PinName _ai1;   // Analog input pin for channel 1
        PinName _ai2;   // Analog input pin for channel 2
};

extern AnalogInClass MachineControl_AnalogIn;

#endif /* __ANALOGIN_CLASS_H */