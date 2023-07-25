/**
 * @file ProgrammableDINClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Programmable Digital Input connector of the Portenta Machine Control library.
 */

/* Includes -----------------------------------------------------------------*/
#include "ProgrammableDINClass.h"

/* Functions -----------------------------------------------------------------*/
ProgrammableDINClass::ProgrammableDINClass()
{ }

ProgrammableDINClass::~ProgrammableDINClass()
{ }

bool ProgrammableDINClass::begin() {
    ArduinoIOExpanderClass::begin(DIN_ADD);

    return true;
}

ProgrammableDINClass MachineControl_DigitalInputs;
/**** END OF FILE ****/
