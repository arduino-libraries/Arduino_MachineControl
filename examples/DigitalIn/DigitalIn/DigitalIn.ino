/*TEST RTD AUTOMATION
  2020_08_25 SILVIO NAVARETTI
*/
#include <AutomationCarrier.h>

using namespace automation;
  uint16_t letture = 0;
  
void setup() {
  Serial.begin(9600);
  while(!Serial);
}


void loop() {
  letture = digital_inputs.readAll();
  Serial.println(letture, BIN);
  delay(100);
}
