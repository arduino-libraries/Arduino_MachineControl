#include "DigitalOutputsClass.h"

void DigitalOutputsClass::setAll(uint8_t val) {
    for (int i = 0; i < 8; i++) {
        out[i] = val & 0x1;
        val = val >> 1;
    }
}

void DigitalOutputsClass::set(int index, bool val) {
    out[index] = val;
}

void DigitalOutputsClass::setLatch() {
    dig_out_latch_retry = 0;
}

void DigitalOutputsClass::setRetry() {
    dig_out_latch_retry = 1;
}

mbed::DigitalOut& DigitalOutputsClass::operator[](int index) {
    return out[index];
}

DigitalOutputsClass digital_outputs;