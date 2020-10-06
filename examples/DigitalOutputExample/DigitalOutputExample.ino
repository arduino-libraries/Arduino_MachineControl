/*
  Automation Carrier - Digital Output Example

  This sketch shows how to send a value on the DIGITAL
  OUTPUTS channels on the Automation Carrier.

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
  uint16_t letture = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Digital out test");
  digital_outputs.setAll(0);
  programmable_digital_io.setLatch();
  // To write on a single channel use the API set(int channel_index, bool val)
  digital_outputs.setAll(255);
}


void loop() {

}
