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
  Machine Control - Analog in NTC Example

  This example provides the resistance value acquired by the
  Machine Control. A 3V voltage reference is connected
  to each channel of the ANALOG IN connector. The reference
  has a 100k resistor in series, so it can provide only a low
  current.
  The voltage sampled by the Portenta's ADC is the reference
  voltage divided by the voltage divider composed by the
  input resistor and the 100k in series to the voltage reference.
  The resistor value is calculated by inverting the formula of the
  voltage divider.
  To use the NTC functionality, the 24V supply on
  the PWR SUPPLY connector is necessary.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/
#include <Arduino_MachineControl.h>

using namespace machinecontrol;

#define REFERENCE_RES 100000

float reference = 3.0;
float lowest_voltage = 2.7;

void setup() {
  analogReadResolution(16);

  Serial.begin(9600);
  analog_in.setNTC();
}

void loop() {
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float resistance_ch0;
  Serial.print("Resistance CH0: ");
  if (voltage_ch0 < lowest_voltage) {
    resistance_ch0 = ((-REFERENCE_RES) * voltage_ch0) / (voltage_ch0 - reference);
    Serial.print(resistance_ch0);
    Serial.println(" ohm");
  } else {
    resistance_ch0 = -1;
    Serial.println("NaN");
  }

  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float resistance_ch1;
  Serial.print("Resistance CH1: ");
  if (voltage_ch1 < lowest_voltage) {
    resistance_ch1 = ((-REFERENCE_RES) * voltage_ch1) / (voltage_ch1 - reference);
    Serial.print(resistance_ch1);
    Serial.println(" ohm");
  } else {
    resistance_ch1 = -1;
    Serial.println("NaN");
  }

  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float resistance_ch2;
  Serial.print("Resistance CH2: ");
  if (voltage_ch2 < lowest_voltage) {
    resistance_ch2 = ((-REFERENCE_RES) * voltage_ch2) / (voltage_ch2 - reference);
    Serial.print(resistance_ch2);
    Serial.println(" ohm");
  } else {
    resistance_ch2 = -1;
    Serial.println("NaN");
  }

  Serial.println();
  delay(250);
}
