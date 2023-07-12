#include "Arduino_MachineControl.h"

namespace machinecontrol {
RTDClass temp_probes;
COMMClass comm_protocols;
EncoderClass encoders;
DigitalOutputsClass digital_outputs;
ProgrammableDINClass digital_inputs;
ProgrammableDIOClass digital_programmables;
RtcControllerClass rtc_controller;
USBClass usb_controller;
}
