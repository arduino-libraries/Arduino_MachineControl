/**
 * @file COMMClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the COMMClass used to initialize and interact with communication protocols (CAN Bus, RS485, and RS232) on the Portenta Machine Control board.
 *
 */

/* Includes -----------------------------------------------------------------*/
#include "COMMClass.h"

/* Functions -----------------------------------------------------------------*/
COMMClass::COMMClass() {
	pinMode(PinNameToIndex(PA_13), OUTPUT); //Disable CAN pin
	pinMode(PinNameToIndex(PB_8), OUTPUT);
	pinMode(PinNameToIndex(PH_13), OUTPUT);

	pinMode(PinNameToIndex(PA_0), OUTPUT);
	pinMode(PinNameToIndex(PI_9), OUTPUT);

	pinMode(PinNameToIndex(PG_9), OUTPUT);
	pinMode(PinNameToIndex(PA_10), OUTPUT);
	pinMode(PinNameToIndex(PI_15), OUTPUT);
	pinMode(PinNameToIndex(PI_14), OUTPUT);
	pinMode(PinNameToIndex(PG_14), OUTPUT);
	pinMode(PinNameToIndex(PA_9), OUTPUT);
}

COMMClass::~COMMClass() 
{ }

bool COMMClass::begin() {
	/* Turn-off LEDs CAN */
	digitalWrite(PinNameToIndex(PB_8), HIGH);
	digitalWrite(PinNameToIndex(PH_13), HIGH);

	/* Turn-off LEDs RS485 */
	digitalWrite(PinNameToIndex(PA_0), LOW);
	digitalWrite(PinNameToIndex(PI_9), LOW);

	/* Set defaults for RS485 */
	RS485Disable();
	RS485SetModeRS232(false);
	RS485SetFullDuplex(false);
	RS485SetYZTerm(false);
	RS485SetABTerm(false);
	RS485SetSlew(false);

	return true;
}

void COMMClass::CANEnable() {
	digitalWrite(PinNameToIndex(PA_13), LOW);
}

void COMMClass::CANDisable() {
	digitalWrite(PinNameToIndex(PA_13), HIGH);
}

void COMMClass::RS485Enable() { 
	digitalWrite(PinNameToIndex(PG_9), HIGH);
}

void COMMClass::RS485Disable() { 
	digitalWrite(PinNameToIndex(PG_9), LOW);
}

void COMMClass::RS485SetModeRS232(bool enable) 	{ 
	digitalWrite(PinNameToIndex(PA_10), enable ? LOW : HIGH);
}

void COMMClass::RS485SetYZTerm(bool enable) { 
	digitalWrite(PinNameToIndex(PI_15), enable ? HIGH : LOW);
}

void COMMClass::RS485SetABTerm(bool enable) { 
	digitalWrite(PinNameToIndex(PI_14), enable ? HIGH : LOW);
}

void COMMClass::RS485SetSlew(bool enable) {
	digitalWrite(PinNameToIndex(PG_14), enable ? LOW : HIGH);
}

void COMMClass::RS485SetFullDuplex(bool enable) 	{
	digitalWrite(PinNameToIndex(PA_9), enable ? LOW : HIGH);
	if (enable) {
		// RS485 Full Duplex require YZ and AB 120 Ohm termination enabled
		RS485SetYZTerm(true);
		RS485SetABTerm(true);
	}
}

COMMClass MachineControl_CommProtocols;
/**** END OF FILE ****/