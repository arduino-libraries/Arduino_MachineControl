/*
  Machine Control - Analog out Example

  This example shows how to use the Analog out channels on
  Machine Control.

  The circuit:
   - Portenta H7
   - Machine Control

  created 17 November 2020
  by  Riccardo Rizzo
  This example code is in the public domain.
*/
#include <AutomationCarrier.h>

using namespace automation;

void setup() {
  Serial.begin(9600);
  Serial.println("Analogout test");

}

float counter = 0;

void loop() {

  analog_out.period_ms(0, 4);
  analog_out.write(0, counter);
  analog_out.period_ms(1, 4);
  analog_out.write(1, counter);
  analog_out.period_ms(2, 4);
  analog_out.write(2, counter);
  analog_out.period_ms(3, 4);
  analog_out.write(3, counter);
  delay(10);
  counter = counter + 0.1;
  if ( counter >= 10.5 )
  {
    counter = 0;
  }
}
