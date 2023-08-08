/*
 * Portenta Machine Control - Digital Output Example
 *
 * This sketch shows how to send values on the DIGITAL OUT channels on the Machine Control.
 * The DIGITAL OUT channels are high-side switches capable of handling up to 0.5A.
 * There is an overcurrent protection that opens the channel when the current exceeds 0.7A with a +-20% tolerance.
 * The overcurrent protection can be set to operate in two different modes for all channels:
 *   1) Latch mode: When overcurrent is detected, the channel remains open until toggled via software.
 *   2) Auto retry: When overcurrent is detected, the channel opens, but after several tens of milliseconds,
 *      it attempts to close itself automatically. If overcurrent persists, the channel will continuously toggle.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 * 
 * NOTE: connect pin "24V IN" of the DIGITAL_OUTPUTS connector to 24V
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  //Set over current behavior of all channels to latch mode (true)
  MachineControl_DigitalOutputs.begin(true);
  
  //At startup set all channels to OPEN
  MachineControl_DigitalOutputs.writeAll(0);
}

void loop() {
  Serial.println("DIGITAL OUT:");
  
  // Set all channels to CLOSED
  MachineControl_DigitalOutputs.writeAll(255);
  Serial.print("All channels are CLOSED for 1 s...");
  delay(1000);
  
  // Set all channels to OPEN
  MachineControl_DigitalOutputs.writeAll(0);
  Serial.println("now they are OPEN.");
  delay(1000);

  // Toggle each channel for 1 s, one by one
  
  MachineControl_DigitalOutputs.write(0, HIGH);
  Serial.print("CH0 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(0, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(1, HIGH);
  Serial.print("CH1 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(1, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(2, HIGH);
  Serial.print("CH2 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(2, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(3, HIGH);
  Serial.print("CH3 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(3, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(4, HIGH);
  Serial.print("CH4 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(4, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(5, HIGH);
  Serial.print("CH5 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(5, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(6, HIGH);
  Serial.print("CH6 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(6, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(7, HIGH);
  Serial.print("CH7 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(7, LOW);
  Serial.println("now is OPEN.");

  Serial.println();
  delay(1000);
}