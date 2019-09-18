/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        usb.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 2.30.01+
 * Company:         Microchip Technology, Inc.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rawin Rojvanit       11/19/04    Original.
 ********************************************************************/
#ifndef USB_H
#define USB_H

/*
 * usb.h provides a centralize way to include all files
 * required by Microchip USB Firmware.
 *
 * The order of inclusion is important.
 * Dependency conflicts are resolved by the correct ordering.
 */

#include "autofiles\usbcfg.h"
#include "system\usb\usbdefs\usbdefs_std_dsc.h"
#include "autofiles\usbdsc.h"

#include "system\usb\class\boot\boot.h"

#include "system\usb\usbdefs\usbdefs_ep0_buff.h"
#include "system\usb\usbmmap.h"

#include "system\usb\usbdrv\usbdrv.h"
#include "system\usb\usbctrltrf\usbctrltrf.h"
#include "system\usb\usb9\usb9.h"

#endif //USB_H
