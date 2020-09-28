/*
  RTC Example

  This sketch shows how to use the RTC PCF8563T on the Automation
  Carrier and how to configure the PCF8563T's time registers.

  Circuit:
   - Portenta H7
   - Automation Carrier
   - A Slave device with RS485 inteface


  created 24 September 2020
  by Riccardo Rizzo
*/
#include <AutomationCarrier.h>

using namespace automation;

int years = 20;
int months = 9;
int days = 24;
int hours = 12;
int minutes = 43;
int seconds = 31;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Serial.println("Initialization");
  if(!rtc_controller.begin()) {
    Serial.println("Initialization fail!");
  }
  Serial.println("Initialization Done!");

  // APIs to set date's fields: years, months, days, hours, minutes and seconds
  rtc_controller.setYears(years);
  rtc_controller.setMonths(months);
  rtc_controller.setDays(days);
  rtc_controller.setHours(hours);
  rtc_controller.setMinutes(minutes);
  rtc_controller.setSeconds(seconds);
}

void loop() {
  // APIs to get date's fileds.
  Serial.print("Date: ");
  Serial.print(rtc_controller.getYears());
  Serial.print("/");
  Serial.print(rtc_controller.getMonths());
  Serial.print("/");
  Serial.print(rtc_controller.getDays());
  Serial.print(" - ");
  Serial.print(rtc_controller.getHours());
  Serial.print(":");
  Serial.print(rtc_controller.getMinutes());
  Serial.print(":");
  Serial.println(rtc_controller.getSeconds());
  delay(60000);
}
