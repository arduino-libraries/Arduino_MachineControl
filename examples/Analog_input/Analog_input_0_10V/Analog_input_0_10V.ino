/*
 * Portenta Machine Control - Analog in 0-10 V 
 *
 * This example provides the voltage value acquired by the Machine Control. 
 * For each channel of the ANALOG IN connector, there is a resistor divider made by a 100k and 39k, 
 * the input voltage is divided by a ratio of 0.28.
 * Maximum input voltage is 10V.
 * To use the 0V-10V functionality, a 24V supply on the PWR SUPPLY connector is necessary.
 *
 * The circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

const float RES_DIVIDER = 0.28057;
const float REFERENCE   = 3.0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  MachineControl_AnalogIn.begin(SensorType::V_0_10);
}

void loop() {
  float raw_voltage_ch0 = MachineControl_AnalogIn.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH0: ");
  Serial.print(voltage_ch0, 3);
  Serial.println("V");

  float raw_voltage_ch1 = MachineControl_AnalogIn.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH1: ");
  Serial.print(voltage_ch1, 3);
  Serial.println("V");

  float raw_voltage_ch2 = MachineControl_AnalogIn.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH2: ");
  Serial.print(voltage_ch2, 3);
  Serial.println("V");
  
  Serial.println();
  delay(250);
}
