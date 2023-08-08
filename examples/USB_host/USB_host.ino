/*
 * Portenta Machine Control - USB Port Usage Example
 *
 * This example shows how to utilize the USB port on the Portenta Machine Control.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *  - USB device (e.g., keyboard, mouse, etc.)
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <Arduino_MachineControl.h>

#include <USBHost.h>
#include "TUSB_helpers.h"

REDIRECT_STDOUT_TO(Serial);

USBHost usb;

void setup() {
  Serial1.begin(9600);
  MachineControl_USBController.begin();

  usb.Init(USB_CORE_ID_FS, class_table);
}

void loop() {
  usb.Task();
}