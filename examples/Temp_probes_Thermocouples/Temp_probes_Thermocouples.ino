/*
 * Portenta Machine Control - Thermocouples Temperature Reading Example
 *
 * This example reads the temperatures measured by the thermocouples
 * connected to the temp probe inputs on the Portenta Machine Control Carrier.
 * It prints the temperature values to the Serial Monitor every second.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *  - Two K Type thermocouple temperature sensors connected to TEMP PROBES CH0 and CH1
 *  - A J Type thermocouple temperature sensor connected to TEMP PROBES CH3
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  // Initialize temperature probes
  MachineControl_TCTempProbe.begin();
  Serial.println("Temperature probes initialization done");
}

void loop() {
  //Set CH0, has internal 150 ms delay
  MachineControl_TCTempProbe.selectChannel(0);
  //Take CH0 measurement
  float temp_ch0 = MachineControl_TCTempProbe.readTemperature();
  Serial.print("Temperature CH0 [°C]: ");
  Serial.print(temp_ch0);
  Serial.println();

  //Set CH1, has internal 150 ms delay
  MachineControl_TCTempProbe.selectChannel(1);
  //Take CH1 measurement
  float temp_ch1 = MachineControl_TCTempProbe.readTemperature();
  Serial.print("Temperature CH1 [°C]: ");
  Serial.print(temp_ch1);
  Serial.println();
 
  //Set CH2, has internal 150 ms delay
  MachineControl_TCTempProbe.selectChannel(2);
  //Take CH2 measurement
  float temp_ch2 = MachineControl_TCTempProbe.readTemperature();
  Serial.print("Temperature CH2 [°C]: ");
  Serial.print(temp_ch2);
  Serial.println();

  Serial.println();
}