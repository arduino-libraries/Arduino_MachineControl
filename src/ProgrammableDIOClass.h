/**
 * @file ProgrammableDIOClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the Programmable Digital IO connector of the Portenta Machine Control library.
 *
 * This library allows interfacing with the IO Expander and configuring the thermal shutdown mode of the high-side switches.
 */

#ifndef __PROGRAMMABLE_DIO_CLASS_H
#define __PROGRAMMABLE_DIO_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/ioexpander/ArduinoIOExpander.h"
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class ProgrammableDIOClass
 * @brief Class for the Programmable Digital IO connector of the Portenta Machine Control.
 *
 * This class extends the ArduinoIOExpanderClass to interface with the IO Expander and provides methods to configure thermal shutdown modes.
 */
class ProgrammableDIOClass : public ArduinoIOExpanderClass {
public:
    /**
     * @brief Construct a ProgrammableDIOClass object.
     *
     * This constructor initializes a ProgrammableDIOClass object with the specified pin assignment for the latch pin.
     *
     * @param latch_pin The pin number for the latch mode control.
     */
    ProgrammableDIOClass(PinName latch_pin = MC_PDIO_LATCH_PIN);

    /**
     * @brief Destruct the ProgrammableDIOClass object.
     *
     * This destructor releases any resources used by the ProgrammableDIOClass object.
     */
    ~ProgrammableDIOClass();

    /**
     * @brief Initialize the ProgrammableDIO module with the specified latch mode.
     *
     * @param latch_mode The latch mode for thermal shutdown. If true, thermal shutdown operates in the latch mode. Otherwise, it operates in the auto-retry mode.
     * @return true If the ProgrammableDIO module is successfully initialized, false otherwise.
     */
    bool begin(bool latch_mode = true);

private:
    PinName _latch; // Latch control pin

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

extern ProgrammableDIOClass MachineControl_DigitalProgrammables;

#endif /* __PROGRAMMABLE_DIO_CLASS_H */