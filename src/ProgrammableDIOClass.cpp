#include "ProgrammableDIOClass.h"

bool ProgrammableDIOClass::init() {
    return begin(IO_ADD);
}

void ProgrammableDIOClass::setLatch() {
    prog_latch_retry = 0;
}

void ProgrammableDIOClass::setRetry() {
    prog_latch_retry = 1;
}

ProgrammableDIOClass digital_programmables;