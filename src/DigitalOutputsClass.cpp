/**
 * @file DigitalOutputsClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Digital Output connector connector of the Portenta Machine Control library. 
 */

/* Includes -----------------------------------------------------------------*/
#include "DigitalOutputsClass.h"

/* Functions -----------------------------------------------------------------*/
DigitalOutputsClass::DigitalOutputsClass(PinName do0_pin, 
                                        PinName do1_pin, 
                                        PinName do2_pin, 
                                        PinName do3_pin,
                                        PinName do4_pin,
                                        PinName do5_pin,
                                        PinName do6_pin,
                                        PinName do7_pin,
                                        PinName latch_pin)
: _do0{do0_pin}, _do1{do1_pin}, _do2{do2_pin}, _do3{do3_pin}, _do4{do4_pin}, _do5{do5_pin}, _do6{do6_pin}, _do7{do7_pin}, _latch{latch_pin}                      
{ }

DigitalOutputsClass::~DigitalOutputsClass() 
{ }

bool DigitalOutputsClass::begin() {
    pinMode(_do0, OUTPUT);
    pinMode(_do1, OUTPUT);
    pinMode(_do2, OUTPUT);
    pinMode(_do3, OUTPUT);
    pinMode(_do4, OUTPUT);
    pinMode(_do5, OUTPUT);
    pinMode(_do6, OUTPUT);
    pinMode(_do7, OUTPUT);

    pinMode(_latch, OUTPUT);

    return true;
}

void DigitalOutputsClass::write(uint8_t channel, PinStatus val) {
    switch (channel) {
        case 0:
            digitalWrite(_do0, val);
            break;
        case 1:
            digitalWrite(_do1, val);
            break;
        case 2:
            digitalWrite(_do2, val);
            break;
        case 3:
            digitalWrite(_do3, val);
            break;
        case 4:
            digitalWrite(_do4, val);
            break;
        case 5:
            digitalWrite(_do5, val);
            break;
        case 6:
            digitalWrite(_do6, val);
            break;
        case 7:
            digitalWrite(_do7, val);
            break;
        default:
            break;
    }
}

void DigitalOutputsClass::writeAll(uint8_t val) {
    for (uint8_t ch = 0; ch < 8; ch++) {
        if (val && (1 << ch)) {
            write(ch, HIGH);
        } else {
            write(ch, LOW);
        }
    }
}

void DigitalOutputsClass::setLatch() {
    digitalWrite(_latch, LOW);
}

void DigitalOutputsClass::setRetry() {
    digitalWrite(_latch, HIGH);
}

DigitalOutputsClass MachineControl_DigitalOutputs;
/**** END OF FILE ****/