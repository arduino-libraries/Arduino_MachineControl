/**
 * @file RtcControllerClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the RtcControllerClass, a wrapper for the PCF8563T RTC of the Portenta Machine Control.
 */

/* Includes -----------------------------------------------------------------*/
#include "RtcControllerClass.h"

/* Functions -----------------------------------------------------------------*/
RtcControllerClass::RtcControllerClass(PinName int_pin)
                                        : _int{int_pin}                   
{
    pinMode(_int, INPUT_PULLUP);
}

RtcControllerClass::~RtcControllerClass() 
{ }

RtcControllerClass MachineControl_RTCController;
/**** END OF FILE ****/