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

using namespace machinecontrol;

void setup() {
  //analog_out.period_ms(CHANNEL, PERIOD_MILLISECONDS);
  analog_out.period_ms(0, 4);
  analog_out.period_ms(1, 4);
  analog_out.period_ms(2, 4);
  analog_out.period_ms(3, 4);
  
  Serial.begin(9600);
  Serial.println("Analog out test");

}

//Output values which will be changed with this variable
float counter = 1;

void loop() {
  //analog_out.write(CHANNEL, OUTPUT_VOLTAGE_VALUE);
  analog_out.write(0, counter);
  analog_out.write(1, counter);
  analog_out.write(2, counter);
  analog_out.write(3, counter);
  Serial.println("All channels set at "+String(counter)+"V");
  
  counter = counter + 0.1;
  //Maximum output value is 10.4V
  if (counter >= 10.5)
  {
    counter = 0;
    //Additional 100 ms delay introduced to manage 10.5V -> 0V fall time of 150 ms
    delay(100);
  }
  delay(100);
}
