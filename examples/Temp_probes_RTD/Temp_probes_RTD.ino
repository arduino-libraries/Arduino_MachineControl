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

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      400.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600);
  Serial.println("MAX31865 PT100 Sensor Test!");
  MachineControl_TempProbes.begin(TEMPPROBE_RTD, THREE_WIRE);
}

void loop() {
  MachineControl_TempProbes.selectChannel(0);
  Serial.println("CHANNEL 0 SELECTED");
  uint16_t rtd = MachineControl_TempProbes.RTD.readRTD();
  float ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  uint8_t fault = MachineControl_TempProbes.RTD.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_TempProbes.RTD.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_TempProbes.RTD.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_TempProbes.RTD.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_TempProbes.RTD.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  MachineControl_TempProbes.selectChannel(1);
  Serial.println("CHANNEL 1 SELECTED");
  rtd = MachineControl_TempProbes.RTD.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = MachineControl_TempProbes.RTD.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_TempProbes.RTD.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_TempProbes.RTD.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_TempProbes.RTD.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_TempProbes.RTD.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  MachineControl_TempProbes.selectChannel(2);
  Serial.println("CHANNEL 2 SELECTED");
  rtd = MachineControl_TempProbes.RTD.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = MachineControl_TempProbes.RTD.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_TempProbes.RTD.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_TempProbes.RTD.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_TempProbes.RTD.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_TempProbes.RTD.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_TempProbes.RTD.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_TempProbes.RTD.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(1000);
}
