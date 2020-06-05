#include <util/delay.h>

#include <LUFA/Drivers/Peripheral/Serial.h>
#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/USB/Core/Device.h>

#include "communication.h"
#include "watchdog.h"



int main() {
    setupCommunication();
    disableWatchdog();
    USB_Init(USB_DEVICE_OPT_FULLSPEED);

    fprintf(&gl_USARTStream, "System started.");
    

    while (true) {
        HID_Task();
        USB_USBTask();
    }    

    return 1;
}

void HID_Task() {
    if (USB_DeviceState != DEVICE_STATE_Configured) {
        return;
    }

    Endpoint_SelectEndpoint(ENDPOINT_DIR_OUT | 1);

}