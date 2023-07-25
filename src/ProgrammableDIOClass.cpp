/**
 * @file ProgrammableDIOClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Programmable Digital IO connector of the Portenta Machine Control library.  
 */

/* Includes -----------------------------------------------------------------*/
#include "ProgrammableDIOClass.h"

/* Functions -----------------------------------------------------------------*/
ProgrammableDIOClass::ProgrammableDIOClass(PinName latch_pin)
: _latch{latch_pin}                      
{ }

ProgrammableDIOClass::~ProgrammableDIOClass() 
{ }

bool ProgrammableDIOClass::begin(bool latch_mode) {
    ArduinoIOExpanderClass::begin(IO_ADD);

    pinMode(_latch, OUTPUT);

    if(latch_mode) {
        _setLatchMode();
    } else {
        _setAutoRetryMode();
    }

    return true;
}

void ProgrammableDIOClass::_setLatchMode() {
    digitalWrite(_latch, HIGH);
}

void ProgrammableDIOClass::_setAutoRetryMode() {
    digitalWrite(_latch, LOW);
}

ProgrammableDIOClass MachineControl_DigitalProgrammables;
/**** END OF FILE ****/