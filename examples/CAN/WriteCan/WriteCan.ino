/*
 * Portenta Machine Control - CAN Write Example
 *
 * This sketch shows the usage of the CAN transceiver on the Machine Control
 * and demonstrates how to transmit data from the TX CAN channel.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

static uint32_t const CAN_ID = 13ul;
static uint32_t msg_cnt = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  if (!MachineControl_CANComm.begin(CanBitRate::BR_500k)) {
    Serial.println("CAN init failed.");
    while(1) ;
  }
}

void loop() {
  /* Assemble the CAN message */
  uint8_t const msg_data[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
  CanMsg msg(CAN_ID, sizeof(msg_data), msg_data);

  /* Transmit the CAN message */
  int const rc = MachineControl_CANComm.write(msg);
  if (rc <= 0) {
    Serial.print("CAN write failed with error code: ");
    Serial.println(rc);
    while(1) ;
  }

  Serial.println("CAN write message!");

  /* Increase the message counter */
  msg_cnt++;

  /* Only send one message per second */
  delay(1000);
}