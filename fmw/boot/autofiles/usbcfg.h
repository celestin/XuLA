/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        usbcfg.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 2.30.01+
 * Company:         Microchip Technology, Inc.
 *
 ********************************************************************/

#ifndef USBCFG_H
#define USBCFG_H

/** D E F I N I T I O N S *******************************************/
#define EP0_BUFF_SIZE           8   // 8, 16, 32, or 64
#define MAX_NUM_INT             1   // For tracking Alternate Setting

/* Parameter definitions are defined in usbdrv.h */
#define MODE_PP                 _PPBM0
#define UCFG_VAL                _PUEN|_TRINT|_FS|MODE_PP

/*
 * Both I/O sense pins below are not used in this application.
 * This helps to decrease the size of the firmware code.
 */
//#define USE_SELF_POWER_SENSE_IO
//#define USE_USB_BUS_SENSE_IO

/** D E V I C E  C L A S S  U S A G E *******************************/

/*
 * MUID = Microchip USB Class ID
 * Used to identify which of the USB classes owns the current
 * session of control transfer over EP0
 */
#define MUID_NULL               0
#define MUID_USB9               1

/** E N D P O I N T S  A L L O C A T I O N **************************/
/*
 * See usbmmap.c for an explanation of how the endpoint allocation works
 */

/* Bootloader */
#define BOOT_INTF_ID            0x00
#define BOOT_UEP                UEP1
#define BOOT_BD_OUT             ep1Bo
#define BOOT_BD_IN              ep1Bi
#define BOOT_EP_SIZE            64

#define MAX_EP_NUMBER           1           // UEP1

#endif //USBCFG_H
