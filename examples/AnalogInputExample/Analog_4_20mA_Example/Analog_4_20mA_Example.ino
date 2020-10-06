/*
  Automation Carrier - Analog in 4 - 20 mA Example

  This example provides the current value acquired by the
  Automation Carrier. For each channel of the ANALOG IN
   connector, there is a 120 ohm resistor to GND. The current
  of the 4-20mA sensor flows through it, generating a voltage
  which is sampled by the Portenta's ADC.
  To use the 4-20mA functionality, a 24V supply on
  the PWR SUPPLY connector is necessary.

  The circuit:
   - Portenta H7
   - Automation Carrier

  created 18 September 2020
  by Silvio Navaretti
  modified 30 September 2020
  by  Riccardo Rizzo
  This example code is in the public domain.
*/
#include <AutomationCarrier.h>

using namespace automation;

float reference = 3.3;

void setup() {
  analogReadResolution(16);

  Serial.begin(9600);
  analog_in.set4_20mA();
}

void loop() {
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float current_ch0 = voltage_ch0 / 120 * 1000;
  Serial.print("Measured Current ch0: ");
  Serial.print(current_ch0);
  Serial.println("mA");

  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float current_ch1 = voltage_ch1 / 120 * 1000;
  Serial.print("Measured Current  ch1: ");
  Serial.print(current_ch1);
  Serial.println("mA");
  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float current_ch2 = voltage_ch2 / 120 * 1000;
  Serial.print("Measured Current  ch2: ");
  Serial.print(current_ch2);
  Serial.println("mA");

  Serial.println();
  delay(250);
}
