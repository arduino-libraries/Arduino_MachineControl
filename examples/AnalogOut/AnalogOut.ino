#include <MachineControl.h>

void setup() {
  MachineControl.begin() //put it in a fail safe status
}

void loop() {
  MachineControl.analogWrite(0, 3.3); //generate 3.3V on A0
  MachineControl.analogWrite(0, 4.1); //generate 4.1V on A0
  MachineControl.analogWrite(0, 5.0); //generate 5.0V on A0
  MachineControl.analogWrite(0, 10.4); //generate 10.4V on A0
  delay(100);
}
