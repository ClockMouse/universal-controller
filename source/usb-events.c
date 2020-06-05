#include "usb-events.h"


/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
	Serial_SendString("Connect Event\r\n.");
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
	Serial_SendString("Disconnect Event\r\n.");
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
    Serial_SendString("ConfigurationChanged Event\r\n.");

	// bool ConfigSuccess = true;

	// ConfigSuccess &= HID_Device_ConfigureEndpoints(&Joystick_HID_Interface);

	// USB_Device_EnableSOFEvents();
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
    Serial_SendString("ControlRequest Event\r\n.");
    fprintf(&gl_USARTStream, "RequestType:  %x\r\n", USB_ControlRequest.bmRequestType);
    fprintf(&gl_USARTStream, "Request:      %x\r\n", USB_ControlRequest.bRequest);
    fprintf(&gl_USARTStream, "Index:       %x\r\n", USB_ControlRequest.wIndex);
    fprintf(&gl_USARTStream, "Length:      %x\r\n", USB_ControlRequest.wLength);
    fprintf(&gl_USARTStream, "Value:       %x\r\n", USB_ControlRequest.wValue);
    fprintf(&gl_USARTStream, "----------------\r\n");

	//HID_Device_ProcessControlRequest(&Joystick_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void EVENT_USB_Device_StartOfFrame(void)
{
    Serial_SendString("StartOfFrame Event\r\n.");

	//HID_Device_MillisecondElapsed(&Joystick_HID_Interface);
}

void EVENT_USB_Device_Reset(void) {}