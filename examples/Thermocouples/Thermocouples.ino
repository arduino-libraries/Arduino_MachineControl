/*TEST DIGITAL PROGRAMMABLE AUTOMATION
  2020_09_17 
*/
#include <AutomationCarrier.h>

using namespace automation;
  uint16_t letture = 0;
  
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Digital programmable test:");
  programmable_digital_io.prog_latch_retry=0;
  digital_programmable.setAll(255);
}

void loop() {

}
