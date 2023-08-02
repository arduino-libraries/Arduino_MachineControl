#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Encoder 0 State: ");
  Serial.println(MachineControl_Encoders.getCurrentState(0),BIN);
  Serial.print("Encoder 0 Pulses: ");
  Serial.println(MachineControl_Encoders.getPulses(0));
  Serial.print("Encoder 0 Revolutions: ");
  Serial.println(MachineControl_Encoders.getRevolutions(0));
  Serial.println();
 
  Serial.print("Encoder 1 State: ");
  Serial.println(MachineControl_Encoders.getCurrentState(1),BIN);
  Serial.print("Encoder 1 Pulses: ");
  Serial.println(MachineControl_Encoders.getPulses(1));
  Serial.print("Encoder 1 Revolutions: ");
  Serial.println(MachineControl_Encoders.getRevolutions(1));
  Serial.println();
  delay(25);
}
