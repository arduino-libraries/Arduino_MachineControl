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
  Machine Control - Temperature probes RTD example

  This example provides a way to test the 3-wire RTDs
  on the Machine control Carrier. It is possible to
  acquire 2-wire RTD simply by shorting the RTDx pin
  to the TPx pin. The Machine control carrier has on
  board a precise 400 ohm 0.1% reference resistor which
  is used as a reference by the MAX31865.

  The circuit:
   - Portenta H7
   - Portenta Machine Control Carrier
   - 3-wire RTD or 2-wire RTD
*/

#include <Arduino_MachineControl.h>

using namespace machinecontrol;

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      400.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600);
  Serial.println("MAX31865 PT100 Sensor Test!");
  temp_probes.rtd.begin(THREE_WIRE);
  temp_probes.enableRTD();
}

void loop() {
  temp_probes.selectChannel(0);
  Serial.println("CHANNEL 0 SELECTED");
  uint16_t rtd = temp_probes.rtd.readRTD();
  float ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  uint8_t fault = temp_probes.rtd.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (temp_probes.rtd.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (temp_probes.rtd.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (temp_probes.rtd.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (temp_probes.rtd.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    temp_probes.rtd.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(temp_probes.rtd.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  temp_probes.selectChannel(1);
  Serial.println("CHANNEL 1 SELECTED");
  rtd = temp_probes.rtd.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = temp_probes.rtd.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (temp_probes.rtd.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (temp_probes.rtd.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (temp_probes.rtd.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (temp_probes.rtd.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    temp_probes.rtd.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(temp_probes.rtd.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  temp_probes.selectChannel(2);
  Serial.println("CHANNEL 2 SELECTED");
  rtd = temp_probes.rtd.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = temp_probes.rtd.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (temp_probes.rtd.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (temp_probes.rtd.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (temp_probes.rtd.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (temp_probes.rtd.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (temp_probes.rtd.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    temp_probes.rtd.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(temp_probes.rtd.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(1000);
}
