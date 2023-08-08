/*
 * Portenta Machine Control - IOExpander Read and Write Example
 *
 * This sketch shows the utilization of the GPIO Expanders on the Machine Control.
 * It demonstrates the periodic transmission of values on the PROGRAMMABLE DIGITAL I/O output channels
 * and the periodic reading from the PROGRAMMABLE DIGITAL I/O input channels.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Wire.begin();

  if (!MachineControl_DigitalProgrammables.begin()) {
    Serial.println("GPIO expander initialization fail!!");
  }

  Serial.println("GPIO expander initialization done");
}

void loop() {
  // Write the status value to On to Pin 3
  MachineControl_DigitalProgrammables.set(IO_WRITE_CH_PIN_03, SWITCH_ON);
  delay(1000);

  // Read from Pin 3
  Serial.println("Read Pin 03: " + String(MachineControl_DigitalProgrammables.read(IO_READ_CH_PIN_03)));
  delay(1000);

  // Write the status value to Off to Pin 3
  MachineControl_DigitalProgrammables.set(IO_WRITE_CH_PIN_03, SWITCH_OFF);
  delay(1000);

  Serial.println();
  // Sets all the status Pins Values to On in one single operation
  uint32_t status = ON_VALUE_PIN_10 | ON_VALUE_PIN_08 | ON_VALUE_PIN_06 | ON_VALUE_PIN_04 | ON_VALUE_PIN_02 | ON_VALUE_PIN_00;
  MachineControl_DigitalProgrammables.writeAll(status);
  delay(1000);

  // Toggles the actual status values of all digital programmables Pins
  MachineControl_DigitalProgrammables.toggle();
  delay(1000);

  Serial.println();
  // Write the status value to On to all the Output Pins
  MachineControl_DigitalProgrammables.writeAll(SWITCH_ON_ALL);

  // Reads from all Input Pins
  readAll();
  delay(1000);

  // Write the status value to Off all to all the Output Pins
  MachineControl_DigitalProgrammables.writeAll(SWITCH_OFF_ALL);

  // Reads from all Input Pins
  readAll();
  Serial.println();
  delay(1000);
}

uint8_t readAll() {
  uint32_t inputs = MachineControl_DigitalProgrammables.readAll();
  Serial.println("CH00: " + String((inputs & (1 << IO_READ_CH_PIN_00)) >> IO_READ_CH_PIN_00));
  Serial.println("CH01: " + String((inputs & (1 << IO_READ_CH_PIN_01)) >> IO_READ_CH_PIN_01));
  Serial.println("CH02: " + String((inputs & (1 << IO_READ_CH_PIN_02)) >> IO_READ_CH_PIN_02));
  Serial.println("CH03: " + String((inputs & (1 << IO_READ_CH_PIN_03)) >> IO_READ_CH_PIN_03));
  Serial.println("CH04: " + String((inputs & (1 << IO_READ_CH_PIN_04)) >> IO_READ_CH_PIN_04));
  Serial.println("CH05: " + String((inputs & (1 << IO_READ_CH_PIN_05)) >> IO_READ_CH_PIN_05));
  Serial.println("CH06: " + String((inputs & (1 << IO_READ_CH_PIN_06)) >> IO_READ_CH_PIN_06));
  Serial.println("CH07: " + String((inputs & (1 << IO_READ_CH_PIN_07)) >> IO_READ_CH_PIN_07));
  Serial.println("CH08: " + String((inputs & (1 << IO_READ_CH_PIN_08)) >> IO_READ_CH_PIN_08));
  Serial.println("CH09: " + String((inputs & (1 << IO_READ_CH_PIN_09)) >> IO_READ_CH_PIN_09));
  Serial.println("CH10: " + String((inputs & (1 << IO_READ_CH_PIN_10)) >> IO_READ_CH_PIN_10));  
  Serial.println("CH11: " + String((inputs & (1 << IO_READ_CH_PIN_11)) >> IO_READ_CH_PIN_11)); 
  Serial.println();
}

