#include <MachineControl.h>

void setup() {
  MachineControl.begin() //put it in a fail safe status
}

void loop() {
  for (int i = 0; i <; i++) {
    MachineControl.digitalWrite(i, HIGH);
    delay(1000);
    MachineControl.digitalWrite(i, LOW);
    delay(1000);
  }
}
