/*
  Automation Carrirer - Digital Input Example

  This sketch shows how to periodically read from all the Digital
  Inputs channels on the Automation Carrier.

  The circuit:
   - Portenta H7
   - Automation Carrier

  created 25 August 2020
  by Silvio Navaretti
  modified 29 September 2020
  by Riccardo Rizzo
  This example code is in the public domain.
*/
#include <AutomationCarrier.h>

using namespace automation;
  uint16_t readings = 0;

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  // To read from a single channel use the API digital_inputs.read(1);
  readings = digital_inputs.readAll();
  Serial.println(readings, BIN);
  delay(100);
}
