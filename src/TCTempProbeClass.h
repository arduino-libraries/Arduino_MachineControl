/**
 * @file TCTempProbeClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Thermocouple (TC) temperature sensor connector of the Portenta Machine Control.
 *
 * This library allows interfacing with TC temperature sensors using the MAX31855 digital converter. 
 * It provides methods to select input channel, enabling and disabling the sensor, and reading temperature values.
 */

#ifndef __TC_TEMPPROBE_CLASS_H
#define __TC_TEMPPROBE_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/MAX31865/MAX31865.h"
#include "utility/THERMOCOUPLE/MAX31855.h"
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class TCTempProbeClass
 * @brief Class for managing thermocouples temperature sensor of the Portenta Machine Control.
 *
 * This class allows interfacing with thermocouple temperature sensors through the use of the MAX31855 digital converter.
 * It provides methods to configure and read temperature values from the selected input channel.
 */
class TCTempProbeClass: public MAX31855Class {
public:
    /**
     * @brief Construct a TCTempProbeClass object.
     *
     * This constructor initializes a TCTempProbeClass object with the specified pin assignments for channel selection and TC connection.
     *
     * @param tc_cs_pin The pin number for the chip select (CS) pin of the Thermocouple temperature sensor.
     * @param ch_sel0_pin The pin number for the first channel selection bit.
     * @param ch_sel1_pin The pin number for the second channel selection bit.
     * @param ch_sel2_pin The pin number for the third channel selection bit.
     */
    TCTempProbeClass(PinName tc_cs_pin = MC_TC_CS_PIN, 
                     PinName ch_sel0_pin = MC_TC_SEL0_PIN, 
                     PinName ch_sel1_pin = MC_TC_SEL1_PIN, 
                     PinName ch_sel2_pin = MC_TC_SEL2_PIN);
   
    /**
     * @brief Destruct the TCTempProbeClass object.
     *
     * This destructor releases any resources used by the TCTempProbeClass object.
     */
    ~TCTempProbeClass();

    /**
     * @brief Initialize the TCTempProbeClass.
     *
     * @return true If initialization is successful, false otherwise.
     */
    bool begin();

    /**
     * @brief Disable the temperature sensors and release any resources.
     */
    void end();

    /**
     * @brief Select the input channel to be read (3 channels available).
     *
     * @param channel The channel number (0-2) to be selected for temperature reading.
     */
    void selectChannel(int channel);

private:
    PinName _tc_cs;     // Pin for the CS of Thermocouple
    PinName _ch_sel0;   // Pin for the first channel selection bit
    PinName _ch_sel1;   // Pin for the second channel selection bit
    PinName _ch_sel2;   // Pin for the third channel selection bit

    /**
     * @brief Enable the chip select (CS) of the MAX31855 digital converter.
     */
    void _enable();

    /**
     * @brief Disable the chip select (CS) of the MAX31855 digital converter.
     */
    void _disable();
};

extern TCTempProbeClass MachineControl_TCTempProbe;

#endif /* __TC_TEMPPROBE_CLASS_H */
