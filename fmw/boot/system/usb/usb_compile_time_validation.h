/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        usb_compile_time_validation.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 2.30.01+
 * Company:         Microchip Technology, Inc.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rawin Rojvanit       7/10/04     Original.
 ********************************************************************/

#ifndef USB_COMPILE_TIME_VALIDATION_H
#define USB_COMPILE_TIME_VALIDATION_H

/** I N C L U D E S *************************************************/
#include "system\typedefs.h"
#include "system\usb\usb.h"

/** U S B  V A L I D A T I O N **************************************/

#if (EP0_BUFF_SIZE != 8) && (EP0_BUFF_SIZE != 16) && \\
    (EP0_BUFF_SIZE != 32) && (EP0_BUFF_SIZE != 64)
#error(Invalid buffer size for endpoint 0,check "autofiles\usbcfg.h")
#endif

#endif //USB_COMPILE_TIME_VALIDATION_H
