#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Encoder 0 State: ");
  Serial.println(MachineControl_Encoders[0].getCurrentState(),BIN);
  Serial.print("Encoder 0 Pulses: ");
  Serial.println(MachineControl_Encoders[0].getPulses());
  Serial.print("Encoder 0 Revolutions: ");
  Serial.println(MachineControl_Encoders[0].getRevolutions());
  Serial.println();
 
  Serial.print("Encoder 1 State: ");
  Serial.println(MachineControl_Encoders[1].getCurrentState(),BIN);
  Serial.print("Encoder 1 Pulses: ");
  Serial.println(MachineControl_Encoders[1].getPulses());
  Serial.print("Encoder 1 Revolutions: ");
  Serial.println(MachineControl_Encoders[1].getRevolutions());
  Serial.println();
  delay(25);
}
