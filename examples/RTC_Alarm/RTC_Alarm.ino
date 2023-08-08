/*
 * Portenta Machine Control - RTC Alarm Example
 *
 * This sketch shows the usage of the RTC PCF8563T on the Machine
 * Control Carrier and demonstrates how to configure and utilize the PCF8563T's alarm.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

int hours = 12;
int minutes = 45;
int seconds = 57;

bool alarm_flag = false;
int counter = 1;

void callback_alarm();

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  Serial.print("RTC Initialization");
  if(!MachineControl_RTCController.begin()) {
    Serial.println(" fail!");
  }
  Serial.println(" done!");

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
}

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

  // APIs to get date's fields
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