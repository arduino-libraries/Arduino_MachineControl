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
  setAll(SWITCH_ON);

  // Reads from all Input Pins
  readAll();
  delay(1000);

  // Write the status value to Off all to all the Output Pins
  setAll(SWITCH_OFF);

  // Reads from all Input Pins
  readAll();
  Serial.println();
  delay(1000);

}

void setAll(PinStatus status) {
  // Write the status value to each Pin
  digital_programmables.set(IO_WRITE_CH_PIN_00, status);
  digital_programmables.set(IO_WRITE_CH_PIN_01, status);
  digital_programmables.set(IO_WRITE_CH_PIN_02, status);
  digital_programmables.set(IO_WRITE_CH_PIN_03, status);
  digital_programmables.set(IO_WRITE_CH_PIN_04, status);
  digital_programmables.set(IO_WRITE_CH_PIN_05, status);
  digital_programmables.set(IO_WRITE_CH_PIN_06, status);
  digital_programmables.set(IO_WRITE_CH_PIN_07, status);
  digital_programmables.set(IO_WRITE_CH_PIN_08, status);
  digital_programmables.set(IO_WRITE_CH_PIN_09, status);
  digital_programmables.set(IO_WRITE_CH_PIN_10, status);
  digital_programmables.set(IO_WRITE_CH_PIN_11, status);
}

void readAll() {
  // Reads from input pins. This API returns -1 if you try to read from a write channel.
  Serial.println("IO Pin 00: " + String(digital_programmables.read(IO_READ_CH_PIN_00)));
  Serial.println("IO Pin 01: " + String(digital_programmables.read(IO_READ_CH_PIN_01)));
  Serial.println("IO Pin 02: " + String(digital_programmables.read(IO_READ_CH_PIN_02)));
  Serial.println("IO Pin 03: " + String(digital_programmables.read(IO_READ_CH_PIN_03)));
  Serial.println("IO Pin 04: " + String(digital_programmables.read(IO_READ_CH_PIN_04)));
  Serial.println("IO Pin 05: " + String(digital_programmables.read(IO_READ_CH_PIN_05)));
  Serial.println("IO Pin 06: " + String(digital_programmables.read(IO_READ_CH_PIN_06)));
  Serial.println("IO Pin 07: " + String(digital_programmables.read(IO_READ_CH_PIN_07)));
  Serial.println("IO Pin 08: " + String(digital_programmables.read(IO_READ_CH_PIN_08)));
  Serial.println("IO Pin 09: " + String(digital_programmables.read(IO_READ_CH_PIN_09)));
  Serial.println("IO Pin 10: " + String(digital_programmables.read(IO_READ_CH_PIN_10)));
  Serial.println("IO Pin 11: " + String(digital_programmables.read(IO_READ_CH_PIN_11)));  
  Serial.println();
  Serial.println("DIN Pin 00: " + String(digital_inputs.read(DIN_READ_CH_PIN_00)));
  Serial.println("DIN Pin 01: " + String(digital_inputs.read(DIN_READ_CH_PIN_01)));
  Serial.println("DIN Pin 02: " + String(digital_inputs.read(DIN_READ_CH_PIN_02)));
  Serial.println("DIN Pin 03: " + String(digital_inputs.read(DIN_READ_CH_PIN_03)));
  Serial.println("DIN Pin 04: " + String(digital_inputs.read(DIN_READ_CH_PIN_04)));
  Serial.println("DIN Pin 05: " + String(digital_inputs.read(DIN_READ_CH_PIN_05)));
  Serial.println("DIN Pin 06: " + String(digital_inputs.read(DIN_READ_CH_PIN_06)));
  Serial.println("DIN Pin 07: " + String(digital_inputs.read(DIN_READ_CH_PIN_07)));
}
