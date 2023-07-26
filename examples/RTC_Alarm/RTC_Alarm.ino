/*
  Machine Control - RTC Alarm Example

  This sketch shows how to use the RTC PCF8563T on the Machine
  Control Carrier and how to configure and use the PCF8563T's
  alarm.

  Circuit:
   - Portenta H7
   - Machine Control

*/
#include <Arduino_MachineControl.h>

using namespace machinecontrol;

int hours = 12;
int minutes = 45;
int seconds = 57;

void callback_alarm();

bool alarm_flag = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  Serial.println("Initialization");

  if (!MachineControl_RTCController.begin()) {
    Serial.println("Initialization fail!");
  }


  Serial.println("Initialization Done!");

  // APIs to set date's fields: hours, minutes and seconds
  MachineControl_RTCController.setHours(hours);
  MachineControl_RTCController.setMinutes(minutes);
  MachineControl_RTCController.setSeconds(seconds);
  // Enables Alarm on PCF8563T
  MachineControl_RTCController.enableAlarm();

  // set the minutes at which the alarm should rise
  MachineControl_RTCController.setMinuteAlarm(46);

  // Attach an interrupt to the RTC interrupt pin
  attachInterrupt(RTC_INT, callback_alarm, FALLING);

  Serial.println();
}
int counter = 1;
void loop() {
  if (alarm_flag) {
    Serial.println("Alarm!!");
    detachInterrupt(RTC_INT);
    MachineControl_RTCController.setSeconds(seconds);
    MachineControl_RTCController.setMinuteAlarm(minutes + counter);
    MachineControl_RTCController.clearAlarm();
    attachInterrupt(RTC_INT, callback_alarm, FALLING);
    alarm_flag = false;

    // To disable the alarm uncomment the following line:
    // MachineControl_RTCController.disableAlarm();
  }

  // APIs to get date's fields.
  //Serial.println(digitalRead(MachineControl_RTCController.int_pin));
  Serial.print(MachineControl_RTCController.getHours());
  Serial.print(":");
  Serial.print(MachineControl_RTCController.getMinutes());
  Serial.print(":");
  Serial.println(MachineControl_RTCController.getSeconds());
  delay(1000);
}

void callback_alarm () {
  alarm_flag = true;
}
