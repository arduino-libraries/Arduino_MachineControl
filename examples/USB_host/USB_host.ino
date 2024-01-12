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

#include <Arduino_MachineControl.h>
#include <USBHost.h>

#include "TUSB_helpers.h"

using namespace machinecontrol;

// Redirect log output from MbedOS and low-level libraries to Serial
REDIRECT_STDOUT_TO(Serial);

USBHost usb;

void setup()
{
  Serial1.begin(115200);
  usb_controller.powerEnable();
  usb.Init(USB_CORE_ID_FS, class_table);
  
}

void loop() {
  usb.Task();
}


