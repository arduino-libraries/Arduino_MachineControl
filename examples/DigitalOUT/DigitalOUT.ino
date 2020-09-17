/*TEST DIGITAL OUT AUTOMATION
  2020_09_17 
*/
#include <AutomationCarrier.h>

using namespace automation;
  uint16_t letture = 0;
  
void setup() {
  digital_outputs.setAll(0);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Digital out test:");
  programmable_digital_io.prog_latch_retry=0;
  digital_outputs.setAll(255);
}


void loop() {

}
