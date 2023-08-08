/*
 * Portenta Machine Control - Analog out
 *
 * This example demonstrates the utilization of the Analog out channels on the Machine Control.
 * The example configures the channels' PWM period in the setup and then iterates through voltage
 * output values from 0V to 10.5V in a loop.
 *
 * The circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

#define PERIOD_MS 4 /* 4ms - 250Hz */

float voltage = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  MachineControl_AnalogOut.begin();

  MachineControl_AnalogOut.setPeriod(0, PERIOD_MS); 
  MachineControl_AnalogOut.setPeriod(1, PERIOD_MS);
  MachineControl_AnalogOut.setPeriod(2, PERIOD_MS);
  MachineControl_AnalogOut.setPeriod(3, PERIOD_MS);
}

void loop() {
  MachineControl_AnalogOut.write(0, voltage);
  MachineControl_AnalogOut.write(1, voltage);
  MachineControl_AnalogOut.write(2, voltage);
  MachineControl_AnalogOut.write(3, voltage);

  Serial.println("All channels set at " + String(voltage) + "V");
  
  voltage = voltage + 0.1;
  /* Maximum output value is 10.5V */
  if (voltage >= 10.5) {
    voltage = 0;
    delay(100); /* Additional 100 ms delay introduced to manage 10.5V -> 0V fall time of 150 ms */
  }

  delay(100);
}
