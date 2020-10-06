/*
  Automation Carrier - IOExpander Read And Write Example

  This sketch shows how to use the GPIO Expander on the Automation
  Carrier, how to periodically send a value on the PROGRAMMABLE DIGITAL I/O
  output channels and how to periodically read from the PROGRAMMABLE
  DIGITAL I/O input channels.

  The circuit:
   - Portenta H7
   - Automation Carrier

  created 25 August 2020
  by Silvio Navaretti
  modified 29 September 2020
  by Riccardo Rizzo
  This example code is in the public domain.
*/

#include <AutomationCarrier.h>

using namespace automation;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!programmable_digital_io.begin()){
    Serial.println("GPIO expander initialization fail!!");
  }

  Serial.println("GPIO expander initialization done");
  //Initialize all pins to the default mode
  programmable_digital_io.initPins();
  programmable_digital_io.setLatch();
}

void loop() {
  writeAll(HIGH);
  readAll();
  delay(1000);
  writeAll(LOW);
  readAll();
  delay(1000);

}

void writeAll(PinStatus status) {
  // write the status value to each pin
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_00, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_01, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_02, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_03, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_04, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_05, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_06, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_07, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_08, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_09, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_10, status);
  programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_11, status);
}

void readAll() {
  // Reads from input pin. This API returns -1 if you try to read from a write channel.
  Serial.println("Pin 00: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_00)));
  Serial.println("Pin 01: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_01)));
  Serial.println("Pin 02: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_02)));
  Serial.println("Pin 03: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_03)));
  Serial.println("Pin 04: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_04)));
  Serial.println("Pin 05: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_05)));
  Serial.println("Pin 06: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_06)));
  Serial.println("Pin 07: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_07)));
  Serial.println("Pin 08: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_08)));
  Serial.println("Pin 09: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_09)));
  Serial.println("Pin 10: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_10)));
  Serial.println("Pin 11: " + String(programmable_digital_io.digitalRead(IO_READ_CH_PIN_11)));
}
