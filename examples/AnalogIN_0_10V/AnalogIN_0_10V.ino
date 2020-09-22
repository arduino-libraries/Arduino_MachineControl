/*TEST AUTOMATION
  2020_09_18 SILVIO NAVARETTI
*/
#include <AutomationCarrier.h>

using namespace automation;

float raw_voltage_ch0 = 0;
float voltage_ch0 = 0;

float raw_voltage_ch1 = 0;
float voltage_ch1 = 0;

float raw_voltage_ch2 = 0;
float voltage_ch2 = 0;

float res_divider = 0.28057;

void setup() {
  analogReadResolution(16);

  analog_in.ch0_in1 = 1;
  analog_in.ch0_in2 = 1;
  analog_in.ch0_in3 = 0;
  analog_in.ch0_in4 = 1;
  
  analog_in.ch1_in1 = 1;
  analog_in.ch1_in2 = 1;
  analog_in.ch1_in3 = 0;
  analog_in.ch1_in4 = 1;
  
  analog_in.ch2_in1 = 1;
  analog_in.ch2_in2 = 1;
  analog_in.ch2_in3 = 0;
  analog_in.ch2_in4 = 1;

  Serial.begin(9600);
}

void loop() {
  raw_voltage_ch0 = analog_in.read(0);
  voltage_ch0 = (raw_voltage_ch0*3)/65536/res_divider;
  Serial.println("Scaled ch0: "+String(voltage_ch0));

  raw_voltage_ch1 = analog_in.read(1);
  voltage_ch1 = (raw_voltage_ch1*3)/65536/res_divider;
  Serial.println("Scaled ch1: "+String(voltage_ch1));

  raw_voltage_ch2 = analog_in.read(2);
  voltage_ch2 = (raw_voltage_ch2*3)/65536/res_divider;
  Serial.println("Scaled ch2: "+String(voltage_ch2)+"\n");
  delay(100);
}
