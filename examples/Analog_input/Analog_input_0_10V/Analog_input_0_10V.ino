/*
 * IMPORTANT NOTE:
 *
 * This example is associated with the deprecated Arduino_MachineControl library.
 * We have introduced a new and improved library called Arduino_PortentaMachineControl, which offers enhanced features
 * and ongoing support. 
 * We encourage you to update your projects to use the new library.
 * 
 * The functions and syntax in this example are not compatible with Arduino_PortentaMachineControl.
 * Please refer to the migration guide for necessary adjustments.
 */

/*
  Machine Control - Analog in 0 - 10 V Example

  This example provides the voltage value acquired by the
  Machine Control. For each channel of the ANALOG IN connector,
  there is a resistor divider made by a 100k and 39k,
  the input voltage is divided by a ratio of 0.28.
  Maximum input voltage is 10V.
  To use the 0V-10V functionality, a 24V supply on
  the PWR SUPPLY connector is necessary.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/
#include <Arduino_MachineControl.h>

using namespace machinecontrol;

float res_divider = 0.28057;
float reference = 3.0;

void setup() {
  analogReadResolution(16);

  Serial.begin(9600);
  analog_in.set0_10V();
}

void loop() {
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535 / res_divider;
  Serial.print("Voltage CH0: ");
  Serial.print(voltage_ch0, 3);
  Serial.println("V");

  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535 / res_divider;
  Serial.print("Voltage CH1: ");
  Serial.print(voltage_ch1, 3);
  Serial.println("V");

  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535 / res_divider;
  Serial.print("Voltage CH2: ");
  Serial.print(voltage_ch2, 3);
  Serial.println("V");
  Serial.println();
  delay(250);
}
