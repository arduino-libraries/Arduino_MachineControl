/*TEST THERMOCOUPLES AUTOMATION
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
  Serial.println("Thermocouples");
  temp_probes.resetTH();
  temp_probes.selectChannel(2);
  temp_probes.t.begin();
}


void loop() {
  digitalWrite(PI_0, LOW);
  digitalWrite(PA_6, HIGH);
  Serial.print("Reference temperature ");
  Serial.print(temp_probes.t.readReferenceTemperature());
  Serial.println(" °C");

  Serial.print("Temperature ");
  Serial.print(temp_probes.t.readTemperature());
  Serial.println(" °C");
  
  Serial.println();
  delay(250);
}
