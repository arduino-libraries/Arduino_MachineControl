/*
  Automation Carrier - Thermocouples Read Sensors

  This example reads the temperatures measured by the thermocouples
  connected to the Automation Carrier's temp probe inputs and prints
  them to the Serial Monitor once a second.

  The circuit:
   - Portenta H7
   - Automation Carrier
   - Two K Type thermocouple temperature sensors connected to the
      TEMP PROBES's TP0s and TP1s inputs of Automation Carrier
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
  Serial.println("Thermocouples");
  temp_probes.resetTH();
  temp_probes.tc.begin();
}

void loop() {
  // Enables Thermocouples chip select
  // and runs Channels readings
  temp_probes.enableTC();

  temp_probes.selectChannel(0);
  Serial.print("Reference temperature ch0: ");
  Serial.print(temp_probes.tc.readReferenceTemperature());
  Serial.println(" °C");
  Serial.print("Temperature ch0: ");
  Serial.print(temp_probes.tc.readTemperature());
  Serial.println(" °C");
  
  temp_probes.selectChannel(1);
  Serial.print("Reference temperature ch1: ");
  Serial.print(temp_probes.tc.readReferenceTemperature());
  Serial.println(" °C");

  Serial.print("Temperature ch1: ");
  Serial.print(temp_probes.tc.readTemperature(PROBE_J));
  Serial.println(" °C");

  temp_probes.selectChannel(2);
  Serial.print("Reference temperature ch2: ");
  Serial.print(temp_probes.tc.readReferenceTemperature());
  Serial.println(" °C");

  Serial.print("Temperature ch2: ");
  Serial.print(temp_probes.tc.readTemperature());
  Serial.println(" °C");

  Serial.println();
  delay(1000);
}
