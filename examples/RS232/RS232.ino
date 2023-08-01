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

    // Set the PMC Communication Protocols to default config and enable the RS485/RS232 system
    // RS485/RS232 default config is:
    // - RS485/RS232 system disabled
    // - RS485 mode
    // - Half Duplex
    // - No A/B and Y/Z 120 Ohm termination enabled
    // Specify baudrate for the communication
    MachineControl_RS485Comm.begin(115200);

    // Enable the RS232 mode
    MachineControl_RS485Comm.setModeRS232(true);

    // Start in receive mode
    MachineControl_RS485Comm.receive();

    Serial.println("Initialization done!");
}

void loop()
{
    if (MachineControl_RS485Comm.available())
        Serial.write(MachineControl_RS485Comm.read());

    if (millis() > sendNow) {
        String log = "[";
        log += sendNow;
        log += "] ";

        String msg = "hello ";
        msg += counter++;

        log += msg;
        Serial.println(log);

        // Disable receive mode before transmission
        MachineControl_RS485Comm.noReceive();

        MachineControl_RS485Comm.beginTransmission();
        MachineControl_RS485Comm.println(msg);
        MachineControl_RS485Comm.endTransmission();

        // Re-enable receive mode after transmission
        MachineControl_RS485Comm.receive();

        sendNow = millis() + sendInterval;
    }
}
