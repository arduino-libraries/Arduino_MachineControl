/**
 * @file EncoderClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the EncoderClass of the Portenta Machine Control.
 */

/* Includes -----------------------------------------------------------------*/
#include "EncoderClass.h"

/* Functions -----------------------------------------------------------------*/
EncoderClass::EncoderClass(PinName enc0_A_pin, PinName enc0_B_pin, PinName enc0_I_pin,
                           PinName enc1_A_pin, PinName enc1_B_pin, PinName enc1_I_pin)
    : _enc0(enc0_A_pin, enc0_B_pin, enc0_I_pin, 0),
      _enc1(enc1_A_pin, enc1_B_pin, enc1_I_pin, 0) 
{ }

EncoderClass::~EncoderClass()
{ }

QEI& EncoderClass::operator[](int index) {
    switch (index) {
        case 0:
            return _enc0;
        case 1:
            return _enc1;
        default:
            // Return encoder 0 by default if an invalid index is provided
            return _enc0;
    }
}

EncoderClass MachineControl_Encoders;
/**** END OF FILE ****/