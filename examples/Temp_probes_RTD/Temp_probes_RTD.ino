/*TEST RTD AUTOMATION
  2020_08_25 SILVIO NAVARETTI
*/
#include <AutomationCarrier.h>

using namespace automation;

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      400.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");
  temp_probes.setTH();
  temp_probes.selectChannel(0);
  temp_probes.rtd.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  temp_probes.t.begin();
}


void loop() {
  uint16_t rtd = temp_probes.rtd.readRTD();
  
  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  Serial.print("Ratio = "); Serial.println(ratio, 8);
  Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
  Serial.print("Temperature = "); Serial.println(temp_probes.rtd.temperature(RNOMINAL, RREF));

  // Check and print any faults
  uint8_t fault = temp_probes.rtd.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold");
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold");
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage");
    }
    temp_probes.rtd.clearFault();
  }
  Serial.println();
  delay(1000);

  Serial.print("Reference temperature ");
  Serial.print(temp_probes.t.readReferenceTemperature());
  Serial.println(" °C");

  Serial.print("Temperature ");
  Serial.print(temp_probes.t.readTemperature());
  Serial.println(" °C");

  Serial.println();
}
