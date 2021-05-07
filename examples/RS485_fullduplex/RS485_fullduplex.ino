/*
  RS485 Full duplex communication

  This sketch shows how to use the SP335ECR1 on the Machine
  Control as a full duplex RS485 interface, how to periodically
  send a string on the RS485 TX channel and how to receive data
  from the interface RX channel.

  Circuit:
   - Portenta H7
   - Machine Control
   - A Slave device with RS485 inteface

*/

#include "MachineControl.h"

using namespace machinecontrol;

unsigned long counter = 0;

void setup()
{

    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect.
    }
    delay(1000);
    Serial.println("Start RS485 initialization");

    comm_protocols.rs485.begin(115200);
    comm_protocols.rs485.enable = 1;        // SDHN_N
    comm_protocols.rs485.sel_485 = 1;       // RS485_RS232_N
    comm_protocols.rs485.half_duplex = 0;   // HALF_FULL_N
    comm_protocols.rs485.receive();         // RE_N
    comm_protocols.rs485.fd_tx_term = 1;    // FD_TX_TERM - 120 Ohm Y-Z termination enabled when both TERM and FD_TX_TERM are high
    comm_protocols.rs485.term = 1;          // TERM - 120 Ohm A-B termination enabled when high

    Serial.println("Initialization done!");
}

constexpr unsigned long sendInterval { 1000 };
unsigned long sendNow { 0 };

constexpr unsigned long halfFullInterval { 5000 };
unsigned long halfFull { 0 };
byte halfFullStatus { 0 };

void loop()
{
    while (comm_protocols.rs485.available())
        Serial.write(comm_protocols.rs485.read());

    if (millis() > sendNow) {
        comm_protocols.rs485.noReceive();
        comm_protocols.rs485.beginTransmission();

        comm_protocols.rs485.print("hello ");
        comm_protocols.rs485.println(counter++);

        comm_protocols.rs485.endTransmission();
        comm_protocols.rs485.receive();

        sendNow = millis() + sendInterval;
    }
}
