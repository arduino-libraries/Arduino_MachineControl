/*
 * Portenta Machine Control - Digital Input Example
 *
 * This sketch shows how to periodically read from all the DIGITAL INPUTS channels on the Machine Control.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

uint16_t readings = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Wire.begin();

  if (!MachineControl_DigitalInputs.begin()) {
    Serial.println("Digital input GPIO expander initialization fail!!");
 }
}

void loop() {
  //Reads and Prints all channels (in a single operation)
  readAll();

  //Read one-by-one each channel and print them one-by-one
  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_00);
  Serial.println("CH00: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_01);
  Serial.println("CH01: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_02);
  Serial.println("CH02: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_03);
  Serial.println("CH03: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_04);
  Serial.println("CH04: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_05);
  Serial.println("CH05: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_06);
  Serial.println("CH06: "+String(readings));

  readings = MachineControl_DigitalInputs.read(DIN_READ_CH_PIN_07);
  Serial.println("CH07: "+String(readings));

  Serial.println();

  delay(250);
}

uint8_t readAll() {
  uint32_t inputs = MachineControl_DigitalInputs.readAll();
  Serial.println("CH00: " + String((inputs & (1 << DIN_READ_CH_PIN_00)) >> DIN_READ_CH_PIN_00));
  Serial.println("CH01: " + String((inputs & (1 << DIN_READ_CH_PIN_01)) >> DIN_READ_CH_PIN_01));
  Serial.println("CH02: " + String((inputs & (1 << DIN_READ_CH_PIN_02)) >> DIN_READ_CH_PIN_02));
  Serial.println("CH03: " + String((inputs & (1 << DIN_READ_CH_PIN_03)) >> DIN_READ_CH_PIN_03));
  Serial.println("CH04: " + String((inputs & (1 << DIN_READ_CH_PIN_04)) >> DIN_READ_CH_PIN_04));
  Serial.println("CH05: " + String((inputs & (1 << DIN_READ_CH_PIN_05)) >> DIN_READ_CH_PIN_05));
  Serial.println("CH06: " + String((inputs & (1 << DIN_READ_CH_PIN_06)) >> DIN_READ_CH_PIN_06));
  Serial.println("CH07: " + String((inputs & (1 << DIN_READ_CH_PIN_07)) >> DIN_READ_CH_PIN_07));
  Serial.println();
}
