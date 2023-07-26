#include <ArduinoRS485.h>
#include <Arduino.h>
#include <pinDefinitions.h>
#include <mbed.h>

/**
 * The COMMClass is used to initialize the CAN and RS485 LEDs and 
 * establish the power mode of the CAN bus. 
 */
class COMMClass {
public:
	// to be tested: check if can be made a big pin initialization

	 /**
	 * Shutdown RS485 and CAN LEDs
	 */
	void init();

	 /**
	 * Set the CAN transceiver in Normal mode. In this mode, the transceiver 
	 * can transmit and receive data via the bus lines CANH and CANL.
	 */
	void enableCAN();

	 /**
	 * Set the CAN transceiver in standby (low power) mode. In this mode the
	 * transceiver will not be able to transmit or correctly receive data via the bus lines.
	 * The wake-up filter on the output of the low-power receiver does not latch bus dominant states,
	 * but ensures that only bus dominant and bus recessive states that persist longer than tfltr(wake)
	 * bus are reflected on pin RXD.
	 */
	void disableCAN();

	void rs485Enable(bool enable);
	void rs485ModeRS232(bool enable);
	void rs485YZTerm(bool enable);
	void rs485ABTerm(bool enable);
    void rs485Slew(bool enable);
	void rs485FullDuplex(bool enable);

    arduino::UART _UART4_ {PA_0, PI_9, NC, NC};
    mbed::CAN can {PB_8, PH_13};
    RS485Class rs485 {_UART4_, PinNameToIndex(PA_0), PinNameToIndex(PI_13), PinNameToIndex(PI_10)};

private:
	mbed::DigitalOut can_disable = mbed::DigitalOut(PA_13, 0);
};

extern COMMClass comm_protocols;