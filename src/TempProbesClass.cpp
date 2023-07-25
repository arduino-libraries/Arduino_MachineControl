#include "TempProbesClass.h"

#if __has_include("portenta_info.h")
#include "portenta_info.h"
#define TRY_REV2_RECOGNITION
uint8_t* boardInfo();
#define PMC_R2_SKU  (24 << 8 | 3)
#endif

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

    for (int i=0; i<3; i++) {
        ch_sel[i] = (i == channel ? 1 : 0);
    }
    delay(150);
}

void TempProbesClass::enableTC() {
    rtd_th = 0;
    digitalWrite(PI_0, LOW);
    digitalWrite(PA_6, HIGH);
}

void TempProbesClass::enableRTD() {
    rtd_th = 1;
    digitalWrite(PI_0, HIGH);
    digitalWrite(PA_6, LOW);
}

void TempProbesClass::disableCS() {
    digitalWrite(PI_0, HIGH);
    digitalWrite(PA_6, HIGH);
}

TempProbesClass temp_probes;