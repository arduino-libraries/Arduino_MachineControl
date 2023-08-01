/**
 * @file CANCommClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the CANCommClass used to initialize and interact with the CAN Bus communication protocol on the Portenta Machine Control board.
 */ 

/* Includes -----------------------------------------------------------------*/
#include "CANCommClass.h"

/* Functions -----------------------------------------------------------------*/
CANCommClass::CANCommClass(PinName can_tx_pin, PinName can_rx_pin) :
			mbed::CAN(can_tx_pin, can_rx_pin)
{ }

CANCommClass::~CANCommClass() 
{ }

bool CANCommClass::begin(int can_bitrate) {
	pinMode(PinNameToIndex(PA_13), OUTPUT); //Disable CAN pin
	pinMode(PinNameToIndex(PB_8), OUTPUT);
	pinMode(PinNameToIndex(PH_13), OUTPUT);

	_enable();

	return mbed::CAN::frequency(can_bitrate);
}

void CANCommClass::end() {
	_disable();
}

void CANCommClass::_enable() {
	digitalWrite(PinNameToIndex(PA_13), LOW);
}

void CANCommClass::_disable() {
	digitalWrite(PinNameToIndex(PA_13), HIGH);
}

CANCommClass MachineControl_CANComm;
/**** END OF FILE ****/