/*
 * IMPORTANT NOTE:
 *
 * This example is associated with the deprecated Arduino_MachineControl library.
 * We have introduced a new and improved library called Arduino_PortentaMachineControl, which offers enhanced features
 * and ongoing support. 
 * We encourage you to update your projects to use the new library.
 * 
 * The functions and syntax in this example are not compatible with Arduino_PortentaMachineControl.
 * Please refer to the migration guide for necessary adjustments.
 */

/*
  Machine Control - Digital Input Example

  This sketch shows how to periodically read from all the DIGITAL
  INPUTS channels on the Machine Control.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/
#include <Arduino_MachineControl.h>
#include "Wire.h"

using namespace machinecontrol;
  uint16_t readings = 0;

void setup() {
  Serial.begin(9600);
  //The loop starts only when the Serial Monitor is opened.
  while(!Serial);
  Wire.begin();

  if (!digital_inputs.init()) {
    Serial.println("Digital input GPIO expander initialization fail!!");
 }
}

void loop() {
  //Reads and Prints all channels (in a single operation)
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
  uint32_t inputs = digital_inputs.readAll();
  Serial.println("CH00: " + String((inputs & (1 << DIN_READ_CH_PIN_00)) >> DIN_READ_CH_PIN_00));
  Serial.println("CH01: " + String((inputs & (1 << DIN_READ_CH_PIN_01)) >> DIN_READ_CH_PIN_01));
  Serial.println("CH02: " + String((inputs & (1 << DIN_READ_CH_PIN_02)) >> DIN_READ_CH_PIN_02));
  Serial.println("CH03: " + String((inputs & (1 << DIN_READ_CH_PIN_03)) >> DIN_READ_CH_PIN_03));
  Serial.println("CH04: " + String((inputs & (1 << DIN_READ_CH_PIN_04)) >> DIN_READ_CH_PIN_04));
  Serial.println("CH05: " + String((inputs & (1 << DIN_READ_CH_PIN_05)) >> DIN_READ_CH_PIN_05));
  Serial.println("CH06: " + String((inputs & (1 << DIN_READ_CH_PIN_06)) >> DIN_READ_CH_PIN_06));
  Serial.println("CH07: " + String((inputs & (1 << DIN_READ_CH_PIN_07)) >> DIN_READ_CH_PIN_07));
  Serial.println();
}
