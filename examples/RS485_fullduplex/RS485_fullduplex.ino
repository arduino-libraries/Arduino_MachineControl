/*
  RS485 Full duplex communication

  This sketch shows how to use the SP335ECR1 on the Automation
  Carrier as a full duplex RS485 interface, how to periodically
  send a string on the RS485 TX channel and how to receive data
  from the interface RX channel.

  Circuit:
   - Portenta H7
   - Automation Carrier
   - A Slave device with RS485 inteface


  created 25 August 2020
  by Silvio Navaretti
  modified 24 September 2020
  by Martino Facchin, Riccardo Rizzo
*/

#include "AutomationCarrier.h"

using namespace automation;

unsigned long counter = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  Serial.println("Start RS485 initialization");

  // Initialize the serial interface, enable the 
  // RS485 on SP335ECR1 and set as full duplex 
  comm_protocols.rs485.begin(9600);
  comm_protocols.rs485.enable = 1;
  comm_protocols.rs485.sel_485 = 1;
  comm_protocols.rs485.half_duplex = 0;

  Serial.println("Initialization done!");
}


void loop() {
  // Call receive(); sets properly the flux controll pins
  // and allow to receive data if available
  comm_protocols.rs485.receive();
  if (comm_protocols.rs485.available()) {
    Serial.print("read byte: ");
    Serial.write(comm_protocols.rs485.read());
    Serial.println();
  }
  // Call beginTransmission(); sets properly the flux controll pins
  // and allow to start a trasnsmissio, if instead of a string wants
  // to send byte use the API write();
  comm_protocols.rs485.beginTransmission();
  comm_protocols.rs485.print("hello ");
  comm_protocols.rs485.println(counter);
  comm_protocols.rs485.endTransmission();
  counter++;

  delay(1000);
}
