#include "USBClass.h"

USBClass::USBClass()
		: _power{PB_14, 0}, _usbflag{PB_15}
{ }

void USBClass::powerEnable() {
    _power = 0;
}

void USBClass::powerDisable() {
    _power = 1;
}

bool USBClass::vflagRead() {
    return _usbflag;
}

USBClass usb_controller;