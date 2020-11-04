/*
  CAN Write Example

  This sketch shows how to use the CAN transceiver on the Machine
  Control and how to transmit data from the TX CAN channel.

  Circuit:
   - Portenta H7
   - Automation Carrier


  created 25 August 2020
  by Silvio Navaretti
  modified 4 November 2020
  by Riccardo Rizzo
*/
#include <AutomationCarrier.h>
#include <CAN.h>
using namespace automation;

#define DATARATE_2MB     260000
#define DATARATE_1_5MB   206000
#define DATARATE_1MB     125000
#define DATARATE_800KB   100000


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Serial.println("Start CAN initialization");
  comm_protocols.enableCAN();
  comm_protocols.can.frequency(DATARATE_800KB);
  Serial.println("Initialization done");
}

int counter = 0;
unsigned char payload = 0x49;
int payload_size = 1;

void loop() {

  mbed::CANMessage msg = mbed::CANMessage(13ul, &payload, payload_size);
  if (comm_protocols.can.write(msg)) {
    Serial.println("Message sent");
  }

  delay(100);
}
