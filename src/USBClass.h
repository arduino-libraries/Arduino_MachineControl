#include <Arduino.h>
#include <mbed.h>

/**
 * The USB Class is used to enable/disable the power of the USBA (Host) and configure
 * the callbacks for the different host types (i.e. Keyboard, mouse, storage device etc). 
 */
class USBClass {
public:
	USBClass();
		
	/**
	 * Enable power to USBA VBUS. 
	 */
	void powerEnable();

	/**
	 * Disable power to USBA VBUS.  
	 */
	void powerDisable();

	/**
	 * Flag to indicate overcurrent, overtemperature, or reverse−voltage conditions on the USBA VBUS. 	 
	 * Active−low open−drain output.
	 * @return true if OK, false if fault
	 */
	bool vflagRead();

private:
	mbed::DigitalOut _power;
	mbed::DigitalIn _usbflag;
};

extern USBClass usb_controller;