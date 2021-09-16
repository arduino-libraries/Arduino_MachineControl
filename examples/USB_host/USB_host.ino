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


