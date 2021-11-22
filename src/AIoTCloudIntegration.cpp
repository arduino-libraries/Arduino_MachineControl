#if defined __has_include
#  if __has_include (<ArduinoIoTCloud.h>)
#    include <ArduinoIoTCloud.h>

#include "Arduino_MachineControl.h"

static int analog_inputs[3];
static int analog_outputs[4];

static void read_inputs() {
	while (1) {
		analog_inputs[0] = machinecontrol::analog_in[0].read_u16();
		analog_inputs[1] = machinecontrol::analog_in[1].read_u16();
		analog_inputs[2] = machinecontrol::analog_in[2].read_u16();
		delay(1000);
	}
}

static void onAnalogOutChange() {

	// Frequency must be set by the user; this only configures the duty cycle
	machinecontrol::analog_out.write(0, analog_outputs[0]);
	machinecontrol::analog_out.write(1, analog_outputs[1]);
	machinecontrol::analog_out.write(2, analog_outputs[2]);
	machinecontrol::analog_out.write(3, analog_outputs[3]);
}

static void aiot_integration() {
	ArduinoCloud.addProperty(analog_inputs[0], Permission::Read).publishOnChange(1);
	ArduinoCloud.addProperty(analog_inputs[1], Permission::Read).publishOnChange(1);
	ArduinoCloud.addProperty(analog_inputs[2], Permission::Read).publishOnChange(1);
	ArduinoCloud.addProperty(analog_outputs[0], Permission::Write).onUpdate(onAnalogOutChange);
	ArduinoCloud.addProperty(analog_outputs[1], Permission::Write).onUpdate(onAnalogOutChange);
	ArduinoCloud.addProperty(analog_outputs[2], Permission::Write).onUpdate(onAnalogOutChange);
	ArduinoCloud.addProperty(analog_outputs[3], Permission::Write).onUpdate(onAnalogOutChange);
}

class AIoTIntegration {
public:
	AIoTIntegration() {
		ArduinoCloud.initializeBoardSpecificProperties(aiot_integration);
		th.start(read_inputs);
	}

private:
	rtos::Thread th;
};

AIoTIntegration pmc_integration;

#  endif
#endif