/*
 * IMPORTANT NOTE:
 *
 * This example is associated with the deprecated Arduino_MachineControl library.
 * We have introduced a new and improved library called Arduino_PortentaMachineControl, which offers enhanced features
 * and ongoing support. 
 * We encourage you to update your projects to use the new library.
 * 
 * The functions and syntax in this example are not compatible with Arduino_PortentaMachineControl.
 * Please refer to the migration guide for necessary adjustments.
 */

/*
  Machine Control - RTC Example

  This sketch shows how to use the RTC PCF8563T on the Machine
  Control Carrier and how to configure the PCF8563T's
  time registers.

  Circuit:
   - Portenta H7
   - Machine Control

*/
#include <Arduino_MachineControl.h>

using namespace machinecontrol;

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
  // The RTC time can be set as epoch, using one of the following two options:
  // - Calendar time: rtc_controller.setEpoch(years,  months,  days, hours, minutes, seconds);
  // - UTC time: rtc_controller.setEpoch(date_in_seconds);
  rtc_controller.setYears(years);
  rtc_controller.setMonths(months);
  rtc_controller.setDays(days);
  rtc_controller.setHours(hours);
  rtc_controller.setMinutes(minutes);
  rtc_controller.setSeconds(seconds);
  rtc_controller.setEpoch();
}

void loop() {
  // APIs to get date's fields.
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
  time_t utc_time = time(NULL);
  Serial.print("Date as UTC time: ");
  Serial.println(utc_time);
  Serial.println();
  delay(1000);
}
