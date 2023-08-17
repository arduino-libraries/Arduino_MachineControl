# Portenta Machine Control Library

[![Check Arduino status](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/check-arduino.yml)
[![Compile Examples status](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/compile-examples.yml)
[![Spell Check status](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MachineControl/actions/workflows/spell-check.yml)

[![License](https://img.shields.io/badge/License-LGPLv2.1-blue.svg)](https://github.com/arduino-libraries/Arduino_MachineControl/blob/master/LICENSE.txt)

The Portenta Machine Control Library is a C++ library designed to efficiently manage the functionalities of the Portenta Machine Control board. It provides extensive support for inputs such as digital, analog, and encoder signals, while offering outputs including digital and analog signals. This library also menages communication through protocols like CAN-BUS and serial ports, and allows connectivity via Ethernet, USB, Wi-Fi, and Bluetooth Low Energy.

The library empowers users to easily initialize, control, and access the diverse functionalities of the Portenta Machine Control, enhancing its capability and adaptability for industrial applications.

📚 For more information about this library please visit us at:
https://www.arduino.cc/reference/en/libraries/arduino_machinecontrol

## Features

- Manages input signals, including:
    - 8 digital inputs at 24Vdc
    - 2 channels for encoder readings
    - 3 analog inputs for PT100/J/K temperature probes
    - 3 analog inputs for 4-20mA/0-10V/NTC signals

- Manages output signals, including:
    - 8 digital outputs at 24Vdc
    - 4 analog outputs at 0-10V

- Provides control for other I/O:
    - 12 programmable digital I/O at 24V

- Supports various communication protocols:
    - CAN-BUS
    - Serial protocols (RS232/RS422/RS485)
    - USB

- Handles RTC (Real-Time Clock) functionality

## Usage

To use this library, you must have a properly powered Portenta Machine Control board running at 24V. Once you have ensured the correct power supply and established the connection, you can include the machine control library in your Arduino sketch and use its functions to manage the board features.

Here is a minimal example to control a digital output:

```cpp
// Include the Arduino MachineControl library
#include <Arduino_MachineControl.h>

void setup() {
    // Initialize the digital outputs module of the MachineControl library
    MachineControl_DigitalOutputs.begin();
}

void loop() {
    // Turn on the digital output at channel 0
    MachineControl_DigitalOutputs.write(0, HIGH);
    delay(1000);
    // Turn off the digital output at channel 0
    MachineControl_DigitalOutputs.write(0, LOW);
    delay(1000);
}
```

## Examples

- **[Analog_input_0_10V](../examples/Analog_input/Analog_input_0_10V):** This example demonstrates how to read analog input signals in the 0-10V range.
- **[Analog_input_4_20mA](../examples/Analog_input/Analog_input_4_20mA):** This example demonstrates how to read analog input signals in the 4-20mA range.
- **[Analog_input_NTC](../examples/Analog_input/Analog_input_NTC):** This example shows reading analog input signals from NTC temperature probes.
- **[Analog_Out](../examples/Analog_Out):** This example shows how to control analog output signals.
- **[ReadCan](../examples/CAN/ReadCan):** This example demonstrates how to read data using the CAN-BUS communication protocol.
- **[WriteCan](../examples/CAN/WriteCan):** This example demonstrates how to send data using the CAN-BUS communication protocol.
- **[Digital_output](../examples/Digital_output):** This example shows how to control digital output signals.
- **[Digital_input](../examples/Digital_programmable/Digital_input):** This example shows how to read digital input signals.
- **[GPIO_programmable](../examples/Digital_programmable/GPIO_programmable):** This example demonstrates the usage of programmable digital I/O pins.
- **[Encoders](../examples/Encoders):** This example shows how to work with encoder readings.
- **[Ethernet](../examples/Ethernet):** This example shows how to establish Ethernet communication and connects to a website.
- **[RS232](../examples/RS232):** This example demonstrates serial communication using the RS232 protocol.
- **[RS485_fullduplex](../examples/RS485_fullduplex):** This example demonstrates full-duplex serial communication using the RS485 protocol.
- **[RS485_halfduplex](../examples/RS485_halfduplex):** This example demonstrates half-duplex serial communication using the RS485 protocol.
- **[RTC](../examples/RTC):** This example shows how to interact with the Real-Time Clock functionality.
- **[RTC_Alarm](../examples/RTC_Alarm):** This example demonstrates how to set up and utilize RTC alarms.
- **[Temp_probes_RTD](../examples/Temp_probes_RTD):** This example demonstrates the temperature probe readings using RTD sensors.
- **[Temp_probes_Thermocouples](../examples/Temp_probes_Thermocouples):** This example demonstrates the temperature probe readings using thermocouple sensors.
- **[USB_host](../examples/USB_host):** This example shows the USB host functionality.

## API

The API documentation can be found [here](./api.md).

## License

This library is released under the [LGPLv2.1 license](https://github.com/arduino-libraries/Arduino_MachineControl/blob/master/LICENSE.txt).
