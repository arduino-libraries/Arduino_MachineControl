/**
 * @file TCTempProbeClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Thermocouple (TC) temperature sensor connector of the Portenta Machine Control.
 */

/* Includes -----------------------------------------------------------------*/
#include "TCTempProbeClass.h"

#if __has_include("portenta_info.h")
#include "portenta_info.h"
#define TRY_REV2_RECOGNITION
uint8_t* boardInfo();
#define PMC_R2_SKU  (24 << 8 | 3)
#endif

/* Functions -----------------------------------------------------------------*/
TCTempProbeClass::TCTempProbeClass(PinName tc_cs_pin,
                                     PinName ch_sel0_pin, 
                                     PinName ch_sel1_pin,
                                     PinName ch_sel2_pin)
: MAX31855Class(tc_cs_pin), _tc_cs{tc_cs_pin}, _ch_sel0{ch_sel0_pin}, _ch_sel1{ch_sel0_pin}, _ch_sel2{ch_sel2_pin}                  
{ }

TCTempProbeClass::~TCTempProbeClass() 
{ }

bool TCTempProbeClass::begin() {
    MAX31855Class::begin();

    pinMode(_ch_sel0, OUTPUT);
    pinMode(_ch_sel1, OUTPUT);
    pinMode(_ch_sel2, OUTPUT);

    pinMode(_tc_cs, OUTPUT);

    _enable();

    return true;
}

void TCTempProbeClass::selectChannel(int channel) {

#ifdef TRY_REV2_RECOGNITION
    // check if OTP data is present AND the board is mounted on a r2 carrier
    auto info = (PortentaBoardInfo*)boardInfo();
    if (info->magic == 0xB5 && info->carrier == PMC_R2_SKU) {
        // reverse channels 0 and 2
        switch (channel) {
            case 0:
                channel = 2;
                break;
            case 2:
                channel = 0;
                break;
            default:
                break;
        }
    }
#endif
#undef TRY_REV2_RECOGNITION
    switch(channel) {
        case 0:
            digitalWrite(_ch_sel0, HIGH);
            digitalWrite(_ch_sel1, LOW);
            digitalWrite(_ch_sel2, LOW);
            break;
        case 1:
            digitalWrite(_ch_sel0, LOW);
            digitalWrite(_ch_sel1, HIGH);
            digitalWrite(_ch_sel2, LOW);
            break;
        case 2:
            digitalWrite(_ch_sel0, LOW);
            digitalWrite(_ch_sel1, LOW);
            digitalWrite(_ch_sel2, HIGH);
            break;
        default:
            digitalWrite(_ch_sel0, LOW);
            digitalWrite(_ch_sel1, LOW);
            digitalWrite(_ch_sel2, LOW);
            break;
    }
    delay(150);
}

void TCTempProbeClass::end() {
    MAX31855Class::end();
    
    _disable();
}

void TCTempProbeClass::_enable() {
    digitalWrite(_tc_cs, LOW);
}

void TCTempProbeClass::_disable() {
    digitalWrite(_tc_cs, HIGH);
}

TCTempProbeClass MachineControl_TCTempProbe;
/**** END OF FILE ****/