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

#include <Arduino_MachineControl.h>

using namespace machinecontrol;

void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Encoder 0 State: ");
  Serial.println(encoders[0].getCurrentState(),BIN);
  Serial.print("Encoder 0 Pulses: ");
  Serial.println(encoders[0].getPulses());
  Serial.print("Encoder 0 Revolutions: ");
  Serial.println(encoders[0].getRevolutions());
  Serial.println();
 
  Serial.print("Encoder 1 State: ");
  Serial.println(encoders[1].getCurrentState(),BIN);
  Serial.print("Encoder 1 Pulses: ");
  Serial.println(encoders[1].getPulses());
  Serial.print("Encoder 1 Revolutions: ");
  Serial.println(encoders[1].getRevolutions());
  Serial.println();
  delay(25);
}
