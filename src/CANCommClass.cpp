/**
 * @file CANCommClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the CANCommClass used to initialize and interact with the CAN Bus communication protocol on the Portenta Machine Control board.
 */ 

/* Includes -----------------------------------------------------------------*/
#include "CANCommClass.h"
#include <pinDefinitions.h>

/* Functions -----------------------------------------------------------------*/
CANCommClass::CANCommClass(PinName can_tx_pin, PinName can_rx_pin, PinName can_stb_pin) :
			_can(can_rx_pin, can_tx_pin), _tx{can_tx_pin}, _rx{can_rx_pin}, _stb{can_stb_pin}
{ }

CANCommClass::~CANCommClass() 
{ }

bool CANCommClass::begin(CanBitRate can_bitrate) {
	pinMode(PinNameToIndex(_stb), OUTPUT);

	_enable();

	return _can.begin(can_bitrate);
}

int CANCommClass::write(CanMsg const & msg) {
	return _can.write(msg);
}

size_t CANCommClass::available() {
	return _can.available();
}

CanMsg CANCommClass::read() {
	return _can.read();
}

void CANCommClass::end() {
	_disable();

	_can.end();
}

void CANCommClass::_enable() {
	digitalWrite(PinNameToIndex(_stb), LOW);
}

void CANCommClass::_disable() {
	digitalWrite(PinNameToIndex(_stb), HIGH);
}

CANCommClass MachineControl_CANComm;
/**** END OF FILE ****/