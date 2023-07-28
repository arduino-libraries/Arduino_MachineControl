/**
 * @file AnalogOutClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Analog OUT connector of the Portenta Machine Control library. 
 */

/* Includes -----------------------------------------------------------------*/
#include "AnalogOutClass.h"

/* Private defines -----------------------------------------------------------*/
#define MCAO_MAX_VOLTAGE    10.5

/* Functions -----------------------------------------------------------------*/
AnalogOutClass::AnalogOutClass(PinName ao0_pin, PinName ao1_pin, PinName ao2_pin, PinName ao3_pin)
                : _ao0{mbed::PwmOut(ao0_pin)}, _ao1{mbed::PwmOut(ao1_pin)}, _ao2{mbed::PwmOut(ao2_pin)}, _ao3{mbed::PwmOut(ao3_pin)}
{ }

AnalogOutClass::~AnalogOutClass() 
{ }

bool AnalogOutClass::begin() {
  setPeriod(0, 2); //2ms - 500Hz
  setPeriod(1, 2);
  setPeriod(2, 2);
  setPeriod(3, 2);

  return true;
}

void AnalogOutClass::setPeriod(int channel, uint8_t period_ms) {
    switch (channel) {
        case 0:
            _ao0.period_ms(period_ms);
            break;
        case 1:
            _ao1.period_ms(period_ms);
            break;
        case 2:
            _ao2.period_ms(period_ms);
            break;
        case 3:
            _ao3.period_ms(period_ms);
            break;
    }
}

void AnalogOutClass::write(int channel, float voltage) {
    if (voltage < 0) {
        voltage = 0;
    }

    if (voltage > MCAO_MAX_VOLTAGE) {
        voltage = MCAO_MAX_VOLTAGE;
    }

    switch (channel) {
        case 0:
            _ao0.write(voltage / MCAO_MAX_VOLTAGE);
            break;
        case 1:
            _ao1.write(voltage / MCAO_MAX_VOLTAGE);
            break;
        case 2:
            _ao2.write(voltage / MCAO_MAX_VOLTAGE);
            break;
        case 3:
            _ao3.write(voltage / MCAO_MAX_VOLTAGE);
            break;
    }
}

AnalogOutClass MachineControl_AnalogOut;
/**** END OF FILE ****/