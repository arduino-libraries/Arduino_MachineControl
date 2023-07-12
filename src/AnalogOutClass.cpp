/**
 * @file AnalogOutClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the 
 */

/* Includes -----------------------------------------------------------------*/
#include "AnalogOutClass.h"

/* Functions -----------------------------------------------------------------*/
void AnalogOutClass::write(int index, float voltage) {
    if (voltage < 0) {
        voltage = 0;
    }

    switch (index) {
        case 0:
            out_0.write(voltage / 10.5);
            break;
        case 1:
            out_1.write(voltage / 10.5);
            break;
        case 2:
            out_2.write(voltage / 10.5);
            break;
        case 3:
            out_3.write(voltage / 10.5);
            break;
    }
}

void AnalogOutClass::period_ms(int index, uint8_t period) {
    switch (index) {
        case 0:
            out_0.period_ms(period);
            break;
        case 1:
            out_1.period_ms(period);
            break;
        case 2:
            out_2.period_ms(period);
            break;
        case 3:
            out_3.period_ms(period);
            break;
    }
}

mbed::PwmOut& AnalogOutClass::operator[](int index) {
    switch (index) {
        case 0:
            return out_0;
        case 1:
            return out_1;
        case 2:
            return out_2;
        case 3:
            return out_3;
    }
}

AnalogOutClass analog_out;

/**** END OF FILE ****/