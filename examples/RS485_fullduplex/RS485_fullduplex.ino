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
  RS485 Full duplex communication

  This sketch shows how to use the SP335ECR1 on the Machine
  Control as a full duplex (AB and YZ) RS485 interface, how to periodically
  send a string on the RS485 TX channel and how to receive data
  from the interface RX channel.

  Circuit:
   - Portenta H7
   - Machine Control
   - A Slave device with RS485 interface
   - Connect TXP to A(+) and TXN to B(-)
   - Connect RXP to Y(+) and RXN to Z(-)

*/

#include "Arduino_MachineControl.h"

using namespace machinecontrol;

constexpr unsigned long sendInterval { 1000 };
unsigned long sendNow { 0 };
unsigned long counter = 0;

void setup()
{

    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect.
    }
    delay(1000);
    Serial.println("Start RS485 initialization");

    // Set the PMC Communication Protocols to default config
    comm_protocols.init();
    // RS485/RS232 default config is:
    // - RS485 mode
    // - Half Duplex
    // - No A/B and Y/Z 120 Ohm termination enabled

    // Enable the RS485/RS232 system
    comm_protocols.rs485Enable(true);

    // Enable Full Duplex mode
    // This will also enable A/B and Y/Z 120 Ohm termination resistors
    comm_protocols.rs485FullDuplex(true);
    
    // Specify baudrate, and preamble and postamble times for RS485 communication
    comm_protocols.rs485.begin(115200, 0, 500);
    
    // Start in receive mode
    comm_protocols.rs485.receive();
    

    Serial.println("Initialization done!");
}

void loop()
{
    if (comm_protocols.rs485.available())
        Serial.write(comm_protocols.rs485.read());

    if (millis() > sendNow) {
        // Disable receive mode before transmission
        comm_protocols.rs485.noReceive();

        comm_protocols.rs485.beginTransmission();

        comm_protocols.rs485.print("hello ");
        comm_protocols.rs485.println(counter++);

        comm_protocols.rs485.endTransmission();
        
        // Re-enable receive mode after transmission
        comm_protocols.rs485.receive();

        sendNow = millis() + sendInterval;
    }
}
