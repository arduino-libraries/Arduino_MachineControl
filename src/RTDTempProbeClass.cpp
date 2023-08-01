/**
 * @file RTDTempProbeClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Resistance Temperature Detector (RTD) temperature sensor connector of the Portenta Machine Control.
 */

/* Includes -----------------------------------------------------------------*/
#include "RTDTempProbeClass.h"

#if __has_include("portenta_info.h")
#include "portenta_info.h"
#define TRY_REV2_RECOGNITION
uint8_t* boardInfo();
#define PMC_R2_SKU  (24 << 8 | 3)
#endif

/* Functions -----------------------------------------------------------------*/
RTDTempProbeClass::RTDTempProbeClass(PinName rtd_cs_pin,
                                     PinName ch_sel0_pin, 
                                     PinName ch_sel1_pin,
                                     PinName ch_sel2_pin,
                                     PinName rtd_th_pin)
: MAX31865Class(rtd_cs_pin), _rtd_cs{rtd_cs_pin}, _ch_sel0{ch_sel0_pin}, _ch_sel1{ch_sel0_pin}, _ch_sel2{ch_sel2_pin}, _rtd_th{rtd_th_pin}                     
{ }

RTDTempProbeClass::~RTDTempProbeClass() 
{ }

bool RTDTempProbeClass::begin(uint8_t io_address) {
    MAX31865Class::begin(io_address);

    pinMode(_ch_sel0, OUTPUT);
    pinMode(_ch_sel1, OUTPUT);
    pinMode(_ch_sel2, OUTPUT);
    pinMode(_rtd_th, OUTPUT);

    pinMode(_rtd_cs, OUTPUT);

    _enable();

    return true;
}

void RTDTempProbeClass::selectChannel(int channel) {

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

void RTDTempProbeClass::end() {
    MAX31865Class::end();
    
    _disable();
}

void RTDTempProbeClass::_enable() {
    digitalWrite(_rtd_th, HIGH);

    digitalWrite(_rtd_cs, LOW);
}

void RTDTempProbeClass::_disable() {
    digitalWrite(_rtd_cs, HIGH);
}

RTDTempProbeClass MachineControl_RTDTempProbe;
/**** END OF FILE ****/