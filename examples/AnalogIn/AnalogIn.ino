#include <MachineControl.h>

void setup() {
  MachineControl.begin(); //put it in a fail safe status
}

void loop() {
  MachineControl.analogMode(0_10V);

  for (int i = 0; i < 3; i++) {
    Serial.print("CH0: ");
    Serial.print(MachineControl.analogRead(i));
    Serial.println("V");
  }

  MachineControl.analogMode(4_20mA);

  for (int i = 0; i < 3; i++) {
    Serial.print("CH0: ");
    Serial.print(MachineControl.analogRead(i));
    Serial.println("A");
  }

  MachineControl.analogMode(NTC);

  for (int i = 0; i < 3; i++) {
    Serial.print("CH0: ");
    Serial.print(MachineControl.analogRead(i));
    Serial.println("Ohms");
  }
}
