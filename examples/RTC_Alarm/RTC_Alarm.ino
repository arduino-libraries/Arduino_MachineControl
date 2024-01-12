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

  if (!rtc_controller.begin()) {
    Serial.println("Initialization fail!");
  }


  Serial.println("Initialization Done!");

  // APIs to set date's fields: hours, minutes and seconds
  rtc_controller.setHours(hours);
  rtc_controller.setMinutes(minutes);
  rtc_controller.setSeconds(seconds);
  // Enables Alarm on PCF8563T
  rtc_controller.enableAlarm();

  // set the minutes at which the alarm should rise
  rtc_controller.setMinuteAlarm(46);

  // Attach an interrupt to the RTC interrupt pin
  attachInterrupt(RTC_INT, callback_alarm, FALLING);

  Serial.println();
}
int counter = 1;
void loop() {
  if (alarm_flag) {
    Serial.println("Alarm!!");
    detachInterrupt(RTC_INT);
    rtc_controller.setSeconds(seconds);
    rtc_controller.setMinuteAlarm(minutes + counter);
    rtc_controller.clearAlarm();
    attachInterrupt(RTC_INT, callback_alarm, FALLING);
    alarm_flag = false;

    // To disable the alarm uncomment the following line:
    // rtc_controller.disableAlarm();
  }

  // APIs to get date's fields.
  //Serial.println(digitalRead(rtc_controller.int_pin));
  Serial.print(rtc_controller.getHours());
  Serial.print(":");
  Serial.print(rtc_controller.getMinutes());
  Serial.print(":");
  Serial.println(rtc_controller.getSeconds());
  delay(1000);
}

void callback_alarm () {
  alarm_flag = true;
}
