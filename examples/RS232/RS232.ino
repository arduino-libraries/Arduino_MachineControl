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
  RS232 communication

  This sketch shows how to use the SP335ECR1 on the Machine
  Control as a RS232 interface, how to periodically send
  a string on the RS232 TX channel and how to receive data
  from the interface RX channel.

  Circuit:
   - Arduino Portenta Machine Control (PMC)
   - Device with RS232 interface
   - Connect PMC TXN to RS232 Device RXD
   - Connect PMC RXP to RS232 Device TXD
   - Connect PMC GND to RS232 Device GND

*/

#include <Arduino_MachineControl.h>

using namespace machinecontrol;

constexpr unsigned long sendInterval { 1000 };
unsigned long sendNow { 0 };

unsigned long counter { 0 };

void setup()
{

    Serial.begin(115200);
    // Wait for Serial or start after 2.5s
    for (auto const timeout = millis() + 2500; !Serial && timeout < millis(); delay(500))
        ;

    delay(2500);
    Serial.println("Start RS232 initialization");

    // Set the PMC Communication Protocols to default config
    comm_protocols.init();

    // RS485/RS232 default config is:
    // - RS485/RS232 system disabled
    // - RS485 mode
    // - Half Duplex
    // - No A/B and Y/Z 120 Ohm termination enabled

    // Enable the RS485/RS232 system
    comm_protocols.rs485Enable(true);
    // Enable the RS232 mode
    comm_protocols.rs485ModeRS232(true);

    // Specify baudrate for RS232 communication
    comm_protocols.rs485.begin(115200);
    // Start in receive mode
    comm_protocols.rs485.receive();

    Serial.println("Initialization done!");
}

void loop()
{
    if (comm_protocols.rs485.available())
        Serial.write(comm_protocols.rs485.read());

    if (millis() > sendNow) {
        String log = "[";
        log += sendNow;
        log += "] ";

        String msg = "hello ";
        msg += counter++;

        log += msg;
        Serial.println(log);

        // Disable receive mode before transmission
        comm_protocols.rs485.noReceive();

        comm_protocols.rs485.beginTransmission();
        comm_protocols.rs485.println(msg);
        comm_protocols.rs485.endTransmission();

        // Re-enable receive mode after transmission
        comm_protocols.rs485.receive();

        sendNow = millis() + sendInterval;
    }
}
