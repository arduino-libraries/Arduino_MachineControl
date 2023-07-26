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
  if(!MachineControl_RTCController.begin()) {
    Serial.println("Initialization fail!");
  }
  Serial.println("Initialization Done!");

  // APIs to set date's fields: years, months, days, hours, minutes and seconds
  // The RTC time can be set as epoch, using one of the following two options:
  // - Calendar time: MachineControl_RTCController.setEpoch(years,  months,  days, hours, minutes, seconds);
  // - UTC time: MachineControl_RTCController.setEpoch(date_in_seconds);
  MachineControl_RTCController.setYears(years);
  MachineControl_RTCController.setMonths(months);
  MachineControl_RTCController.setDays(days);
  MachineControl_RTCController.setHours(hours);
  MachineControl_RTCController.setMinutes(minutes);
  MachineControl_RTCController.setSeconds(seconds);
  MachineControl_RTCController.setEpoch();
}

void loop() {
  // APIs to get date's fields.
  Serial.print("Date: ");
  Serial.print(MachineControl_RTCController.getYears());
  Serial.print("/");
  Serial.print(MachineControl_RTCController.getMonths());
  Serial.print("/");
  Serial.print(MachineControl_RTCController.getDays());
  Serial.print(" - ");
  Serial.print(MachineControl_RTCController.getHours());
  Serial.print(":");
  Serial.print(MachineControl_RTCController.getMinutes());
  Serial.print(":");
  Serial.println(MachineControl_RTCController.getSeconds());
  time_t utc_time = time(NULL);
  Serial.print("Date as UTC time: ");
  Serial.println(utc_time);
  Serial.println();
  delay(1000);
}
