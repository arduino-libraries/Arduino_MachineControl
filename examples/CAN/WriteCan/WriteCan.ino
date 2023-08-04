/*
  CAN Write Example

  This sketch shows how to use the CAN transceiver on the Machine
  Control and how to transmit data from the TX CAN channel.

  Circuit:
   - Portenta H7
   - Machine Control

*/
#include <Arduino_MachineControl.h>

static uint32_t const CAN_ID = 13ul;

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

static uint32_t msg_cnt = 0;

void loop()
{
  /* Assemble a CAN message */
  uint8_t const msg_data[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
  memcpy((void *)(msg_data + 8), &msg_cnt, sizeof(msg_cnt));
  CanMsg msg(CAN_ID, sizeof(msg_data), msg_data);

  /* Transmit the CAN message, capture and display an
   * error core in case of failure.
   */
  if (int const rc = MachineControl_CANComm.write(msg); rc <= 0)
  {
    Serial.print  ("CAN write failed with error code ");
    Serial.println(rc);
    for (;;) { }
  }

  Serial.println("CAN write message!");

  /* Increase the message counter. */
  msg_cnt++;

  /* Only send one message per second. */
  delay(1000);
}