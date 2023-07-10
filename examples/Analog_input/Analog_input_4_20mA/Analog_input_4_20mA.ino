/*
  Machine Control - Analog in 4 - 20 mA Example

  This example provides the current value acquired by the
  Machine Control. For each channel of the ANALOG IN
  connector, there is a 120 ohm resistor to GND. The current
  of the 4-20mA sensor flows through it, generating a voltage
  which is sampled by the Portenta's ADC.
  To use the 4-20mA functionality, a 24V supply on
  the PWR SUPPLY connector is necessary.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/
#include <Arduino_MachineControl.h>

#define SENSE_RES 120

float reference = 3.3;

void setup() {
  Serial.begin(9600);
  MachineControl_AnalogIn.begin(MCAI_SENSOR_4_20MA);
}

void loop() {
  float raw_voltage_ch0 = MachineControl_AnalogIn.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float current_ch0 = (voltage_ch0 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH0: ");
  Serial.print(current_ch0);
  Serial.println("mA");

  float raw_voltage_ch1 = MachineControl_AnalogIn.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float current_ch1 = (voltage_ch1 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH1: ");
  Serial.print(current_ch1);
  Serial.println("mA");
  float raw_voltage_ch2 = MachineControl_AnalogIn.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float current_ch2 = (voltage_ch2 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH2: ");
  Serial.print(current_ch2);
  Serial.println("mA");

  Serial.println();
  delay(250);
}
