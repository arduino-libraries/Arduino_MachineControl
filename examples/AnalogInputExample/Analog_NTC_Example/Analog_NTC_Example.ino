/*
  Automation Carrirer - Analog in NTC Example

  This example provides the resistor value acquired by the
  Automation Carrier. A 3V voltage reference is connected
  to each channel of the ANALOG_IN connector. The reference
  has a 100k resistor in series, so it can provide only a low
  current.
  The voltage sampled by the ADC on Portenta is the reference
  voltage divided by the voltage divider composed by the
  input resistor and the 100k in series to the voltage reference.
  The resistor value is calculated by inverting the formula of the
  voltage divider.
  To use the NTC functionality, the 24V supply on
  PWR SUPPLY connector is necessary.

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
  analog_in.setNTC();
}

void loop() {
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float resistance_ch0;
  if (voltage_ch0 < 3) {
    resistance_ch0 = ((-100000) * voltage_ch0) / (voltage_ch0 - 3);
  } else {
    resistance_ch0 = -1;
  }
  Serial.print("Resistor ch0: ");
  Serial.print(resistance_ch0);
  Serial.println("ohm");

  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float resistance_ch1;
  if (voltage_ch1 < 3) {
    resistance_ch1 = ((-100000) * voltage_ch1) / (voltage_ch1 - 3);
  } else {
    resistance_ch1 = -1;
  }
  Serial.print("Resistor ch1: ");
  Serial.print(resistance_ch1);
  Serial.println("ohm");

  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float resistance_ch2;
  if (voltage_ch2 < 3) {
    resistance_ch2 = ((-100000) * voltage_ch2) / (voltage_ch2 - 3);
  } else {
    resistance_ch2 = -1;
  }
  Serial.print("Scaled ch2: ");
  Serial.print(resistance_ch2);
  Serial.println("ohm");
  Serial.println();
  delay(250);
}
