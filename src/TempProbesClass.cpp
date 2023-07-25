/**
 * @file TempProbesClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Temperature Probes connector of the Portenta Machine Control. 
 */

/* Includes -----------------------------------------------------------------*/
#include "TempProbesClass.h"

#if __has_include("portenta_info.h")
#include "portenta_info.h"
#define TRY_REV2_RECOGNITION
uint8_t* boardInfo();
#define PMC_R2_SKU  (24 << 8 | 3)
#endif

/* Functions -----------------------------------------------------------------*/
TempProbesClass::TempProbesClass(PinName ch_sel0_pin, 
                                 PinName ch_sel1_pin,
                                 PinName ch_sel2_pin,
                                 PinName rtd_th_pin)
: _ch_sel0{ch_sel0_pin}, _ch_sel1{ch_sel0_pin}, _ch_sel2{ch_sel2_pin}, _rtd_th{rtd_th_pin}                     
{ }

TempProbesClass::~TempProbesClass() 
{ }

bool TempProbesClass::begin(uint8_t tempprobe_type, uint8_t io_address) {
    bool status = true; 

    switch(tempprobe_type) {
        case TEMPPROBE_RTD:
            TempProbesClass::RTD.begin(io_address);
            _enableRTD();
            break;
        case TEMPPROBE_TC:
            TempProbesClass::TC.begin();
            _enableTC();
            break;
        default:
            status = false;
            break;
    }

    pinMode(_ch_sel0, OUTPUT);
    pinMode(_ch_sel1, OUTPUT);
    pinMode(_ch_sel2, OUTPUT);
    pinMode(_rtd_th, OUTPUT);

    pinMode(PI_0, OUTPUT);
    pinMode(PA_6, OUTPUT);

    return status;
}

void TempProbesClass::selectChannel(int channel) {

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

void TempProbesClass::end() {
    _disableCS();
}

void TempProbesClass::_enableTC() {
    digitalWrite(_rtd_th, LOW);

    digitalWrite(PI_0, LOW);
    digitalWrite(PA_6, HIGH);
}

void TempProbesClass::_enableRTD() {
    digitalWrite(_rtd_th, HIGH);

    digitalWrite(PI_0, HIGH);
    digitalWrite(PA_6, LOW);
}

void TempProbesClass::_disableCS() {
    digitalWrite(PI_0, HIGH);
    digitalWrite(PA_6, HIGH);
}

TempProbesClass MachineControl_TempProbes;
/**** END OF FILE ****/