/*
  Automation Carrier - Digital Input Example

  This sketch shows how to periodically read from all the DIGITAL
  INPUTS channels on the Automation Carrier.

  The circuit:
   - Portenta H7
   - Automation Carrier

  created 25 August 2020
  by Silvio Navaretti
  modified 29 September 2020
  by Riccardo Rizzo
  modified 6 October 2020
  by Silvio Navaretti
  This example code is in the public domain.
*/
#include <AutomationCarrier.h>

using namespace automation;
  uint16_t readings = 0;

void setup() {
  Serial.begin(9600);
  //The loop starts only when the serial monitor is opened.
  while(!Serial);
}

void loop() {
  //Read all channels
  readings = digital_inputs.readAll();
  //Print all channels as binary numb
  Serial.print("DIGITAL INPUT, all channels, binary: ");
  Serial.println(readings, BIN);

  //Read one-by-one each channel and print them one-by-one
  
  readings = digital_inputs.read(0);
  Serial.println("CH0: "+String(readings));
  
  readings = digital_inputs.read(1);
  Serial.println("CH1: "+String(readings));
  
  readings = digital_inputs.read(2);
  Serial.println("CH2: "+String(readings));
  
  readings = digital_inputs.read(3);
  Serial.println("CH3: "+String(readings));
  
  readings = digital_inputs.read(4);
  Serial.println("CH4: "+String(readings));
  
  readings = digital_inputs.read(5);
  Serial.println("CH5: "+String(readings));
  
  readings = digital_inputs.read(6);
  Serial.println("CH6: "+String(readings));
  
  readings = digital_inputs.read(7);
  Serial.println("CH7: "+String(readings));

  Serial.println();
  delay(250);
}