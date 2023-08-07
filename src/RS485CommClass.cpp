/**
 * @file RS485CommClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the RS485CommClass used to initialize and interact with RS485 and RS232 communication protocols on the Portenta Machine Control board.
 */

/* Includes -----------------------------------------------------------------*/
#include "RS485CommClass.h"
#include <pinDefinitions.h>

/* Functions -----------------------------------------------------------------*/

RS485CommClass::RS485CommClass(arduino::UART& uart_itf, PinName rs_tx_pin, PinName rs_de_pin, PinName rs_re_pin)
                    : RS485Class(uart_itf, PinNameToIndex(rs_tx_pin), PinNameToIndex(rs_de_pin), PinNameToIndex(rs_re_pin)) 
{ }

RS485CommClass::~RS485CommClass() 
{ }

void RS485CommClass::begin(unsigned long baudrate, int predelay, int postdelay) {
    /* Pinout configuration */
    pinMode(PinNameToIndex(MC_RS485_TX_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_RX_PIN), OUTPUT);

    pinMode(PinNameToIndex(MC_RS485_EN_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_RS232_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_FDTERM_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_TERM_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_SLEW_PIN), OUTPUT);
    pinMode(PinNameToIndex(MC_RS485_HF_PIN), OUTPUT);

	/* Turn-off LEDs RS485 */
	digitalWrite(PinNameToIndex(MC_RS485_TX_PIN), LOW);
	digitalWrite(PinNameToIndex(MC_RS485_RX_PIN), LOW);

	/* Set defaults for RS485 */
	_disable();
	setModeRS232(false);
	setFullDuplex(false);
	setYZTerm(false);
	setABTerm(false);
	setSlew(false);

    /* Enable RS485 communication */
    _enable();

    /* Call begin() base class to initialize RS485 communication */
    RS485Class::begin(baudrate, predelay, postdelay);

	return;
}

void RS485CommClass::end() {
    _disable();

    /* Call end() base class to de-initialize RS485 communication */
    RS485Class::end();
}

void RS485CommClass::setModeRS232(bool enable) 	{ 
	digitalWrite(PinNameToIndex(MC_RS485_RS232_PIN), enable ? LOW : HIGH);
}

void RS485CommClass::setYZTerm(bool enable) { 
	digitalWrite(PinNameToIndex(MC_RS485_FDTERM_PIN), enable ? HIGH : LOW);
}

void RS485CommClass::setABTerm(bool enable) { 
	digitalWrite(PinNameToIndex(MC_RS485_TERM_PIN), enable ? HIGH : LOW);
}

void RS485CommClass::setSlew(bool enable) {
	digitalWrite(PinNameToIndex(MC_RS485_SLEW_PIN), enable ? LOW : HIGH);
}

void RS485CommClass::setFullDuplex(bool enable) 	{
	digitalWrite(PinNameToIndex(MC_RS485_HF_PIN), enable ? LOW : HIGH);
	if (enable) {
		// RS485 Full Duplex require YZ and AB 120 Ohm termination enabled
		setYZTerm(true);
		setABTerm(true);
	}
}

void RS485CommClass::_enable() { 
	digitalWrite(PinNameToIndex(MC_RS485_EN_PIN), HIGH);
}

void RS485CommClass::_disable() { 
	digitalWrite(PinNameToIndex(MC_RS485_EN_PIN), LOW);
}

arduino::UART 	_UART4_	{MC_RS485_TX_PIN, MC_RS485_RX_PIN, NC, NC};
RS485CommClass MachineControl_RS485Comm(_UART4_);
/**** END OF FILE ****/