/*
  Automation Carrier - Thermocouples Read Sensors

  This example reads the temperatures measured by the thermocouples
  connected to the Automation Carrier's temp probe inputs and prints
  them to the Serial Monitor once a second.

  The circuit:
   - Portenta H7
   - Automation Carrier
   - Two K Type thermocouple temperature sensors connected to
      TEMP PROBES CH0 and CH1 on the Automation Carrier
   - A J Type thermocouple temperature sensor connected to
     TEMP PROBES CH3 on the Automation Carrier


  created 25 August 2020
  by Silvio Navaretti
  modified 28 September 2020
  by  Riccardo Rizzo
  This example code is in the public domain.
*/

#include <AutomationCarrier.h>

using namespace automation;

void setup() {
  Serial.begin(9600);
  temp_probes.resetTH();
  temp_probes.tc.begin();
  // Enables Thermocouples chip select
  temp_probes.enableTC();
}

void loop() {
  temp_probes.selectChannel(0);
  float temp_ch0 = temp_probes.tc.readTemperature();
  Serial.print("Temperature CH0 [°C]: ");
  Serial.print(temp_ch0);
  Serial.print(" ");

  temp_probes.selectChannel(1);
  float temp_ch1 = temp_probes.tc.readTemperature();
  Serial.print(", CH1 [°C]: ");
  Serial.print(temp_ch1);
  Serial.print(" ");
 
  temp_probes.selectChannel(2);
  float temp_ch2 = temp_probes.tc.readTemperature();
  Serial.print(", CH2 [°C]: ");
  Serial.print(temp_ch2);
  Serial.println();
}
