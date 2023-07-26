#include "COMMClass.h"

void COMMClass::init() {
	//SHUTDOWN OF RS485 LEDS
	digitalWrite(PinNameToIndex(PA_0), LOW);
	digitalWrite(PinNameToIndex(PI_9), LOW);
	//SHUTDOWN OF CAN LEDS
	digitalWrite(PinNameToIndex(PB_8), HIGH);
	digitalWrite(PinNameToIndex(PH_13), HIGH);

	// SET DEFAULTS for RS485
	rs485Enable(false);
	rs485ModeRS232(false);
	rs485FullDuplex(false);
	rs485YZTerm(false);
	rs485ABTerm(false);
	rs485Slew(false);
}

void COMMClass::enableCAN() {
	can_disable = 0;
}

void COMMClass::disableCAN() {
	can_disable = 1;
}

void COMMClass::rs485Enable(bool enable) 		{ digitalWrite(PinNameToIndex(PG_9),  enable ? 	HIGH : LOW); }

void COMMClass::rs485ModeRS232(bool enable) 	{ digitalWrite(PinNameToIndex(PA_10), enable ? 	LOW : HIGH); }

void COMMClass::rs485YZTerm(bool enable) 		{ digitalWrite(PinNameToIndex(PI_15), enable ? 	HIGH : LOW); }

void COMMClass::rs485ABTerm(bool enable) 		{ digitalWrite(PinNameToIndex(PI_14), enable ? 	HIGH : LOW); }

void COMMClass::rs485Slew(bool enable)  		{ digitalWrite(PinNameToIndex(PG_14), enable ? 	LOW : HIGH); }

void COMMClass::rs485FullDuplex(bool enable) 	{
	digitalWrite(PinNameToIndex(PA_9), enable ? LOW : HIGH);
	if (enable) {
		// RS485 Full Duplex require YZ and AB 120 Ohm termination enabled
		rs485YZTerm(true);
		rs485ABTerm(true);
	}
}

COMMClass comm_protocols;