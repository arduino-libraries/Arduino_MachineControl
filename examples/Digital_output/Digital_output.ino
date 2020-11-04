/*
  Automation Carrier - Digital Output Example

  This sketch shows how to send values on the
  DIGITAL OUT channels on the Automation Carrier.
  Please remember that pin "24V IN" of the connector
  DIGITAL_OUTPUTS must be connected to 24V.
  The DIGITAL OUT channels are high side switches
  capable to handle up to 0.5A. There is an over current
  protection that open the channel when the current is
  above 0.7A with a +-20% tolerance.
  The over current protection can be set to have two
  different behaviors, and it is the same for all channels:
    1) Latch mode: when the over current is detected
       the channel is opened, and will remain opened until
       it will be toggle via software.
    2) Auto retry: when the over current is detected
       the channel is openend, but after some tents of
       milliseconds the channel will automatically try
       to close itself again. In case of a persistant
       overcurrent the channel will continuously toggle.
  
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

void setup() {
  Serial.begin(9600);
  //The loop starts only when the serial monitor is opened.
  while (!Serial);

  //Set over current behavior of all channels to latch mode:
  digital_programmables.setLatch();
  //Set over current behavior of all channels to auto retry mode:
  digital_programmables.setRetry();
  
  //At startup set all channels to OPEN
  digital_outputs.setAll(0);
}


void loop() {
  Serial.println("DIGITAL OUT:");
  
  //Set all channels to CLOSED
  digital_outputs.setAll(255);
  Serial.print("All channels are CLOSED for 1s...");
  delay(1000);
  
  //Set all channels to OPEN
  digital_outputs.setAll(0);
  Serial.println("now they are OPEN.");
  delay(1000);

  //Toggle each channel for 1s, one by one
  
  digital_outputs.set(0, HIGH);
  Serial.print("CH0 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(0, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(1, HIGH);
  Serial.print("CH1 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(1, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(2, HIGH);
  Serial.print("CH2 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(2, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(3, HIGH);
  Serial.print("CH3 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(3, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(4, HIGH);
  Serial.print("CH4 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(4, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(5, HIGH);
  Serial.print("CH5 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(5, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(6, HIGH);
  Serial.print("CH6 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(6, LOW);
  Serial.println("now is OPEN.");

  digital_outputs.set(7, HIGH);
  Serial.print("CH7 is CLOSED for 1s...");
  delay(1000);
  digital_outputs.set(7, LOW);
  Serial.println("now is OPEN.");

  Serial.println();
  delay(1000);
}