/**
 * @file USBClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the USB Controller of the Portenta Machine Control.
 */

/* Includes -----------------------------------------------------------------*/
#include "USBClass.h"

/* Functions -----------------------------------------------------------------*/
USBClass::USBClass(PinName power_pin, PinName usbflag_pin)
		: _power{power_pin}, _usbflag{usbflag_pin}
{ }

USBClass::~USBClass() 
{ }

bool USBClass::begin() {
    pinMode(_power, OUTPUT);
    pinMode(_usbflag, INPUT);

    _enable();

    return true;
}

void USBClass::end() {
    _disable();
}

bool USBClass::getFaultStatus() {
    bool res = false;

    if (digitalRead(_usbflag) == LOW) {
        /* Active−low, asserted during overcurrent, overtemperature, or reverse−voltage conditions. */
        res = true;
    } else {
        res = false;
    }

    return res;
}

void USBClass::_enable() {
    digitalWrite(_power, LOW);
}

void USBClass::_disable() {
    digitalWrite(_power, HIGH);
}

USBClass MachineControl_USBController;
/**** END OF FILE ****/