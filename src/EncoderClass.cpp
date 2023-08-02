/**
 * @file EncoderClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the encoder module of the Portenta Machine Control.
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

void EncoderClass::reset(int channel) {
    switch (channel) {
        case 0:
            _enc0.reset();
            break;
        case 1:
            _enc1.reset();
            break;
        default:
            return;
    }
}

int EncoderClass::getCurrentState(int channel) {
    switch (channel) {
        case 0:
            return _enc0.getCurrentState();
        case 1:
            return _enc1.getCurrentState();
        default:
            return -1;
    }
}

int EncoderClass::getPulses(int channel) {
    switch (channel) {
        case 0:
            return _enc0.getPulses();
        case 1:
            return _enc1.getPulses();
        default:
            return -1;
    }
}

int EncoderClass::getRevolutions(int channel) {
    switch (channel) {
        case 0:
            return _enc0.getRevolutions();
        case 1:
            return _enc1.getRevolutions();
        default:
            return -1;
    }
}

EncoderClass MachineControl_Encoders;
/**** END OF FILE ****/