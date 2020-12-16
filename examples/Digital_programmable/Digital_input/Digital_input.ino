/*
  Machine Control - Digital Input Example

  This sketch shows how to periodically read from all the DIGITAL
  INPUTS channels on the Machine Control.

  The circuit:
   - Portenta H7
   - Machine Control

  created 25 August 2020
  by Silvio Navaretti
  modified 29 September 2020
  by Riccardo Rizzo
  modified 6 October 2020
  by Silvio Navaretti
  This example code is in the public domain.
*/
#include <AutomationCarrier.h>
#include "Wire.h"

using namespace automation;
  uint16_t readings = 0;

void setup() {
  Serial.begin(9600);
  //The loop starts only when the serial monitor is opened.
  while(!Serial);
  Wire.begin();

  if (!digital_inputs.init()) {
    Serial.println("Digital input GPIO expander initialization fail!!");
 }
}

void loop() {
  //Reads and Prints all channels and 
  readAll();

  //Read one-by-one each channel and print them one-by-one
  readings = digital_inputs.read(DIN_READ_CH_PIN_00);
  Serial.println("CH00: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_01);
  Serial.println("CH01: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_02);
  Serial.println("CH02: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_03);
  Serial.println("CH03: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_04);
  Serial.println("CH04: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_05);
  Serial.println("CH05: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_06);
  Serial.println("CH06: "+String(readings));

  readings = digital_inputs.read(DIN_READ_CH_PIN_07);
  Serial.println("CH07: "+String(readings));

  Serial.println();

  delay(250);
}

uint8_t readAll() {
  Serial.println("CH00: " + String(digital_inputs.read(DIN_READ_CH_PIN_00)));
  Serial.println("CH01: " + String(digital_inputs.read(DIN_READ_CH_PIN_01)));
  Serial.println("CH02: " + String(digital_inputs.read(DIN_READ_CH_PIN_02)));
  Serial.println("CH03: " + String(digital_inputs.read(DIN_READ_CH_PIN_03)));
  Serial.println("CH04: " + String(digital_inputs.read(DIN_READ_CH_PIN_04)));
  Serial.println("CH05: " + String(digital_inputs.read(DIN_READ_CH_PIN_05)));
  Serial.println("CH06: " + String(digital_inputs.read(DIN_READ_CH_PIN_06)));
  Serial.println("CH07: " + String(digital_inputs.read(DIN_READ_CH_PIN_07)));
  Serial.println();
}
