/*
 * Portenta Machine Control - Analog in 4-20 mA
 *
 * This example provides the current value acquired by the Machine Control.
 * For each channel of the ANALOG IN connector, a 120 ohm resistor to GND is present.
 * The current from the 4-20mA sensor passes through it, generating a voltage
 * that is sampled by the Portenta's ADC.
 * To use the 4-20mA functionality, a 24V supply on the PWR SUPPLY connector is required.
 *
 * The circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

#define SENSE_RES 120

const float REFERENCE = 3.0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  MachineControl_AnalogIn.begin(SensorType::MA_4_20);
}

void loop() {
  float raw_voltage_ch0 = MachineControl_AnalogIn.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * REFERENCE) / 65535;
  float current_ch0 = (voltage_ch0 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH0: ");
  Serial.print(current_ch0);
  Serial.println("mA");

  float raw_voltage_ch1 = MachineControl_AnalogIn.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * REFERENCE) / 65535;
  float current_ch1 = (voltage_ch1 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH1: ");
  Serial.print(current_ch1);
  Serial.println("mA");

  float raw_voltage_ch2 = MachineControl_AnalogIn.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * REFERENCE) / 65535;
  float current_ch2 = (voltage_ch2 / SENSE_RES) * 1000;
  Serial.print("Measured Current CH2: ");
  Serial.print(current_ch2);
  Serial.println("mA");

  Serial.println();
  delay(250);
}
