/*
 * Portenta Machine Control - Fast Analog In 0-10 V 
 *
 * This example provides the voltage value acquired by the Machine Control using the Arduino_AdvancedAnalog library,
 * which is designed to offer enhanced performance in terms of acquisition speed compared to the MachineControl_AnalogIn feature.
 * For each channel of the ANALOG IN connector, there is a resistor divider made by a 100k and 39k; the input voltage is divided by a ratio of 0.28.
 * The maximum input voltage is 10V.
 * To use the 0V-10V functionality, a 24V supply on the PWR SUPPLY connector is necessary.
 *
 * The circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Leonardo Cavagnis @leonardocavagnis
 */

#include <Arduino_MachineControl.h>
#include <Arduino_AdvancedAnalog.h>

const float RES_DIVIDER = 0.28057;
const float REFERENCE   = 3.0;

//A3 is connected to PMC-AI0, A2 is connected to PMC-AI1
AdvancedADC MachineControl_FastAnalogIn01(A3, A2); //A3 & A2 share the same ADC instance (ADC3)
//A1 is connected to PMC-AI2
AdvancedADC MachineControl_FastAnalogIn2(A1); 

uint16_t adc_get_buf(AdvancedADC &adc);
void adc_get_buf(AdvancedADC &adc, uint16_t * sample_buf, uint8_t sample_buf_size);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  // Configure the sensor type 0-10V
  MachineControl_AnalogIn.begin(SensorType::V_0_10);

  // Initialize the Advanced Analog feature on PMC AI pins
  if (!MachineControl_FastAnalogIn01.begin(AN_RESOLUTION_16, 8000, 32, 3)) {
      Serial.println("AI0, AI1: Failed to start analog acquisition!");
      while (1);
  }

  if (!MachineControl_FastAnalogIn2.begin(AN_RESOLUTION_16, 8000, 32, 3)) {
      Serial.println("AI2: Failed to start analog acquisition!");
      while (1);
  }
}

void loop() {
  uint16_t raw_voltage_ch01[2]  = {0, 0};
  uint16_t raw_voltage_ch2      = 0;

  adc_get_buf(MachineControl_FastAnalogIn01, raw_voltage_ch01, 2);
  float voltage_ch0 = ((float)raw_voltage_ch01[0] * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH0: ");
  Serial.print(voltage_ch0, 3);
  Serial.println("V");

  float voltage_ch1 = ((float)raw_voltage_ch01[1] * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH1: ");
  Serial.print(voltage_ch1, 3);
  Serial.println("V");

  raw_voltage_ch2 = adc_get_buf(MachineControl_FastAnalogIn2);
  float voltage_ch2 = ((float)raw_voltage_ch2 * REFERENCE) / 65535 / RES_DIVIDER;
  Serial.print("Voltage CH2: ");
  Serial.print(voltage_ch2, 3);
  Serial.println("V");
  
  Serial.println();
  delay(250);
}

uint16_t adc_get_buf(AdvancedADC &adc) {
  uint16_t sample = 0;

  if (adc.available()) {
      SampleBuffer buf = adc.read();

      // Print first sample.
      sample = buf[0];
      Serial.println(sample);

      // Release the buffer to return it to the pool.
      buf.release();
  }

  return sample;
}

void adc_get_buf(AdvancedADC &adc, uint16_t * sample_buf, uint8_t sample_buf_size) {
  if (adc.available()) {
      SampleBuffer buf = adc.read();

      for (uint8_t pos = 0; pos < sample_buf_size; pos++) {
        sample_buf[pos] = buf[pos];
        Serial.println(sample_buf[pos]);
      }

      // Release the buffer to return it to the pool.
      buf.release();
  }

  return;
}