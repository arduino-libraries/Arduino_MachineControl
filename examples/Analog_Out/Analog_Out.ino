/*
  Machine Control - Analog out Example

  This example shows how to use the Analog out channels on
  the Machine Control.
  The example sets the channels PWM period in the setup,
  then loops the channels voltage output value from 0V to 10.4V.

  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/

#include <Arduino_MachineControl.h>

float voltage = 0;

void setup() {
  MachineControl_AnalogOut.begin();

  MachineControl_AnalogOut.setPeriod(0, 4); //4ms - 250Hz
  MachineControl_AnalogOut.setPeriod(1, 4);
  MachineControl_AnalogOut.setPeriod(2, 4);
  MachineControl_AnalogOut.setPeriod(3, 4);
  
  Serial.begin(9600);
  Serial.println("Analog out test");
}

void loop() {
  MachineControl_AnalogOut.write(0, voltage);
  MachineControl_AnalogOut.write(1, voltage);
  MachineControl_AnalogOut.write(2, voltage);
  MachineControl_AnalogOut.write(3, voltage);

  Serial.println("All channels set at " + String(voltage) + "V");
  
  voltage = voltage + 0.1;
  //Maximum output value is 10.5V
  if (voltage >= 10.5) {
    voltage = 0;
    delay(100); //Additional 100 ms delay introduced to manage 10.5V -> 0V fall time of 150 ms
  }
  delay(100);
}
