/*
  CAN Read Example

  This sketch shows how to use the CAN transceiver on the Machine
  Control and how to receive data from the RX CAN channel.

  Circuit:
   - Portenta H7
   - Machine Control

*/
#include <Arduino_MachineControl.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  if (!MachineControl_CANComm.begin(CanBitRate::BR_500k))
  {
    Serial.println("CAN init failed.");
    for (;;) {}
  }
}

void loop()
{
  if (MachineControl_CANComm.available())
  {
    CanMsg const msg = MachineControl_CANComm.read();
    Serial.println(msg);
  }
}
