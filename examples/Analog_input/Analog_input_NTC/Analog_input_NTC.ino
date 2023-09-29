/*
 * Portenta Machine Control - Analog in NTC
 *
 * This example provides the resistance value acquired by the Machine Control.
 * A 3V voltage REFERENCE is connected to each channel of the ANALOG IN connector.
 * The REFERENCE has a 100k resistor in series, allowing only a low current flow.
 * The voltage sampled by the Portenta's ADC is the REFERENCE voltage divided by the voltage divider
 * composed of the input resistor and the 100k resistor in series with the voltage REFERENCE.
 * The resistor value is calculated by inversely applying the voltage divider formula.
 * To use the NTC functionality, a 24V supply on the PWR SUPPLY connector is required.
 *
 * The circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

#define REFERENCE_RES 100000

const float REFERENCE = 3.0;
const float LOWEST_VOLTAGE = 2.7;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  MachineControl_AnalogIn.begin(SensorType::NTC);
}

void loop() {
  float raw_voltage_ch0 = MachineControl_AnalogIn.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * REFERENCE) / 65535;
  float resistance_ch0;
  Serial.print("Resistance CH0: ");
  if (voltage_ch0 < LOWEST_VOLTAGE) {
    resistance_ch0 = ((-REFERENCE_RES) * voltage_ch0) / (voltage_ch0 - REFERENCE);
    Serial.print(resistance_ch0);
    Serial.println(" ohm");
  } else {
    resistance_ch0 = -1;
    Serial.println("NaN");
  }

  float raw_voltage_ch1 = MachineControl_AnalogIn.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * REFERENCE) / 65535;
  float resistance_ch1;
  Serial.print("Resistance CH1: ");
  if (voltage_ch1 < LOWEST_VOLTAGE) {
    resistance_ch1 = ((-REFERENCE_RES) * voltage_ch1) / (voltage_ch1 - REFERENCE);
    Serial.print(resistance_ch1);
    Serial.println(" ohm");
  } else {
    resistance_ch1 = -1;
    Serial.println("NaN");
  }

  float raw_voltage_ch2 = MachineControl_AnalogIn.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * REFERENCE) / 65535;
  float resistance_ch2;
  Serial.print("Resistance CH2: ");
  if (voltage_ch2 < LOWEST_VOLTAGE) {
    resistance_ch2 = ((-REFERENCE_RES) * voltage_ch2) / (voltage_ch2 - REFERENCE);
    Serial.print(resistance_ch2);
    Serial.println(" ohm");
  } else {
    resistance_ch2 = -1;
    Serial.println("NaN");
  }

  Serial.println();
  delay(250);
}
