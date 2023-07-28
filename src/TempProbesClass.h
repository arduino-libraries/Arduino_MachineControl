/**
 * @file TempProbesClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Temperature Probes connector of the Portenta Machine Control.
 *
 * This library allows interfacing with RTD (Resistance Temperature Detector) and Thermocouple temperature sensors
 * using the MAX31865 and MAX31855 digital converters. It provides methods to select the sensor type and input channel,
 * enabling and disabling the temperature sensors, and reading temperature values.
 */

#ifndef __TEMPPROBES_CLASS_H
#define __TEMPPROBES_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/MAX31865/MAX31865.h"
#include "utility/THERMOCOUPLE/MAX31855.h"
#include <Arduino.h>
#include <mbed.h>

/* Constants ------------------------------------------------------------------*/
#define TEMPPROBE_RTD   1
#define TEMPPROBE_TC    2

/* Class ----------------------------------------------------------------------*/

/**
 * @class TempProbesClass
 * @brief Class for managing temperature sensor inputs (RTD and thermocouples) of the Portenta Machine Control.
 *
 * This class allows interfacing with RTD and thermocouple temperature sensors through the use of the MAX31865 and MAX31855 digital converters.
 * It provides methods to configure and read temperature values from the selected input channel.
 */
class TempProbesClass {
public:
    /**
     * @brief Construct a TempProbesClass object.
     *
     * This constructor initializes a TempProbesClass object with the specified pin assignments for channel selection and RTD connection.
     *
     * @param ch_sel0_pin The pin number for the first channel selection bit.
     * @param ch_sel1_pin The pin number for the second channel selection bit.
     * @param ch_sel2_pin The pin number for the third channel selection bit.
     * @param rtd_th_pin The pin number for the RTD connection.
     */
    TempProbesClass(PinName ch_sel0_pin = PD_6, PinName ch_sel1_pin = PI_4, PinName ch_sel2_pin = PG_10, PinName rtd_th_pin = PC_15);
   
    /**
     * @brief Destruct the TempProbesClass object.
     *
     * This destructor releases any resources used by the TempProbesClass object.
     */
    ~TempProbesClass();

    /**
     * @brief Initialize the TempProbesClass with the specified temperature probe type and I/O address.
     *
     * @param tempprobe_type The type of temperature probe (RTD or thermocouple).
     * @param io_address The I/O address for communication with the digital converters (default is THREE_WIRE).
     * @return true If initialization is successful, false otherwise.
     */
    bool begin(uint8_t tempprobe_type, uint8_t io_address = THREE_WIRE);

    /**
     * @brief Select the input channel to be read (3 channels available).
     *
     * @param channel The channel number (0-2) to be selected for temperature reading.
     */
    void selectChannel(int channel);

    /**
     * @brief Disable the temperature sensors and release any resources.
     */
    void end();

    // Instances of the MAX31865 and MAX31855 digital converter classes for RTD and thermocouple respectively
    MAX31865Class RTD = MAX31865Class(PA_6);
    MAX31855Class TC = MAX31855Class(7);

private:
    PinName _ch_sel0; // Pin for the first channel selection bit
    PinName _ch_sel1; // Pin for the second channel selection bit
    PinName _ch_sel2; // Pin for the third channel selection bit
    PinName _rtd_th;  // Pin for the RTD connection

    /**
     * @brief Enable the chip select (CS) of the Thermocouple to digital converter and disable the CS for the RTD to digital converter.
     */
    void _enableTC();

    /**
     * @brief Enable the chip select (CS) of the RTD to digital converter and disable the CS of the Thermocouple to digital converter.
     */
    void _enableRTD();

    /**
     * @brief Disable chip select (CS) for both RTD and thermocouple digital converters.
     */
    void _disableCS();
};

extern TempProbesClass MachineControl_TempProbes;

#endif /* __TEMPPROBES_CLASS_H */
