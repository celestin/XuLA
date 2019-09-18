/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        usbdsc.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 2.30.01+
 * Company:         Microchip Technology, Inc.
 *
 ********************************************************************/

/*********************************************************************
 * Descriptor specific type definitions are defined in:
 * system\usb\usbdefs\usbdefs_std_dsc.h
 ********************************************************************/

#ifndef USBDSC_H
#define USBDSC_H

/** I N C L U D E S *************************************************/
#include "system\typedefs.h"
#include "autofiles\usbcfg.h"
#include "system\usb\usb.h"

/** D E F I N I T I O N S *******************************************/

#define CFG01 rom struct                            \
{   USB_CFG_DSC             cd01;                   \
    USB_INTF_DSC            i00a00;                 \
    USB_EP_DSC              ep01o_i00a00;           \
    USB_EP_DSC              ep01i_i00a00;           \
} cfg01

/** E X T E R N S ***************************************************/
extern rom USB_DEV_DSC device_dsc;
extern CFG01;
extern rom struct{byte bLength;byte bDscType;word string[1];}sd000;

#endif //USBDSC_H
