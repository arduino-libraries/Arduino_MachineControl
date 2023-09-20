/*
 * Portenta Machine Control - Temperature Probes RTD Example
 *
 * This example provides a method to test the 3-wire RTDs
 * on the Machine Control Carrier. It is also possible to
 * acquire 2-wire RTDs by shorting the RTDx pin to the TPx pin.
 * The Machine Control Carrier features a precise 400 ohm 0.1% reference resistor,
 * which serves as a reference for the MAX31865.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *  - 3-wire RTD or 2-wire RTD
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

// The value of the Rref resistor. Use 430.0 for PT100
#define RREF      400.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  MachineControl_RTDTempProbe.begin(THREE_WIRE);
}

void loop() {
  MachineControl_RTDTempProbe.selectChannel(0);
  Serial.println("CHANNEL 0 SELECTED");
  uint16_t rtd = MachineControl_RTDTempProbe.readRTD();
  float ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  uint8_t fault = MachineControl_RTDTempProbe.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_RTDTempProbe.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_RTDTempProbe.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_RTDTempProbe.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_RTDTempProbe.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  MachineControl_RTDTempProbe.selectChannel(1);
  Serial.println("CHANNEL 1 SELECTED");
  rtd = MachineControl_RTDTempProbe.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = MachineControl_RTDTempProbe.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_RTDTempProbe.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_RTDTempProbe.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_RTDTempProbe.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_RTDTempProbe.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(100);

  MachineControl_RTDTempProbe.selectChannel(2);
  Serial.println("CHANNEL 2 SELECTED");
  rtd = MachineControl_RTDTempProbe.readRTD();
  ratio = rtd;
  ratio /= 32768;

  // Check and print any faults
  fault = MachineControl_RTDTempProbe.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (MachineControl_RTDTempProbe.getHighThresholdFault(fault)) {
      Serial.println("RTD High Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowThresholdFault(fault)) {
      Serial.println("RTD Low Threshold");
    }
    if (MachineControl_RTDTempProbe.getLowREFINFault(fault)) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (MachineControl_RTDTempProbe.getHighREFINFault(fault)) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getLowRTDINFault(fault)) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (MachineControl_RTDTempProbe.getVoltageFault(fault)) {
      Serial.println("Under/Over voltage");
    }
    MachineControl_RTDTempProbe.clearFault();
  } else {
    Serial.print("RTD value: "); Serial.println(rtd);
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(MachineControl_RTDTempProbe.readTemperature(RNOMINAL, RREF));
  }
  Serial.println();
  delay(1000);
}
