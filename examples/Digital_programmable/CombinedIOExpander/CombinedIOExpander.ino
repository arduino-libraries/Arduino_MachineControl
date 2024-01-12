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
  Machine Control - IOExpander Read And Write Example

  This sketch shows how to use the GPIO Expanders on the Machine Control,
  how to periodically send a value on the PROGRAMMABLE DIGITAL I/O
  output channels and how to periodically read from the PROGRAMMABLE
  DIGITAL I/O input channels and DIGITAL INPUT channels.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/

#include <Arduino_MachineControl.h>
#include "Wire.h"
using namespace machinecontrol;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Wire.begin();
  if (!digital_inputs.init()){
    Serial.println("GPIO expander initialization fail!!");
 }
 if (!digital_programmables.init()){
    Serial.println("GPIO expander initialization fail!!");
 }

  Serial.println("GPIO expander initialization done");
  digital_programmables.setLatch();
  Serial.println("GPIO expander initialization done");
//  digital_inputs.setLatch();
}

void loop() {
  // Write the status value to On to Pin 3
  digital_programmables.set(IO_WRITE_CH_PIN_03, SWITCH_ON);
  delay(1000);

  // Read from PROGRAMMABLE DIGITAL I/O Pin 3
  Serial.println("Read IO Pin 03: " + String(digital_programmables.read(IO_READ_CH_PIN_03)));
  delay(1000);

  // Read from DIGITAL INPUT Expander Pin 3 
  Serial.println("Read DIN Pin 03: " + String(digital_inputs.read(DIN_READ_CH_PIN_03)));
  delay(1000);

  // Write the status value to Off to Pin 3
  digital_programmables.set(IO_WRITE_CH_PIN_03, SWITCH_OFF);
  delay(1000);

  Serial.println();
  // Write the status value to On to all the Output Pins
  digital_programmables.writeAll(SWITCH_ON_ALL);

  // Reads from all Input Pins
  readAll();
  delay(1000);

  // Write the status value to Off all to all the Output Pins
  digital_programmables.writeAll(SWITCH_OFF_ALL);

  // Reads from all Input Pins
  readAll();
  Serial.println();
  delay(1000);

}


void readAll() {
  uint32_t inputs = digital_programmables.readAll();
  Serial.println("CH00: " + String((inputs & (1 << IO_READ_CH_PIN_00)) >> IO_READ_CH_PIN_00));
  Serial.println("CH01: " + String((inputs & (1 << IO_READ_CH_PIN_01)) >> IO_READ_CH_PIN_01));
  Serial.println("CH02: " + String((inputs & (1 << IO_READ_CH_PIN_02)) >> IO_READ_CH_PIN_02));
  Serial.println("CH03: " + String((inputs & (1 << IO_READ_CH_PIN_03)) >> IO_READ_CH_PIN_03));
  Serial.println("CH04: " + String((inputs & (1 << IO_READ_CH_PIN_04)) >> IO_READ_CH_PIN_04));
  Serial.println("CH05: " + String((inputs & (1 << IO_READ_CH_PIN_05)) >> IO_READ_CH_PIN_05));
  Serial.println("CH06: " + String((inputs & (1 << IO_READ_CH_PIN_06)) >> IO_READ_CH_PIN_06));
  Serial.println("CH07: " + String((inputs & (1 << IO_READ_CH_PIN_07)) >> IO_READ_CH_PIN_07));
  Serial.println("CH08: " + String((inputs & (1 << IO_READ_CH_PIN_08)) >> IO_READ_CH_PIN_08));
  Serial.println("CH09: " + String((inputs & (1 << IO_READ_CH_PIN_09)) >> IO_READ_CH_PIN_09));
  Serial.println("CH10: " + String((inputs & (1 << IO_READ_CH_PIN_10)) >> IO_READ_CH_PIN_10));
  Serial.println("CH11: " + String((inputs & (1 << IO_READ_CH_PIN_11)) >> IO_READ_CH_PIN_11));
  Serial.println();
  inputs = digital_inputs.readAll();
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
