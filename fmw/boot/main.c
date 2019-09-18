//********************************************************************
//
// Module Description:
//  This module starts the USB-to-JTAG interface or else it controls
//  the programming of the flash with a new program.
//
//********************************************************************

/** I N C L U D E S **********************************************************/
#include <p18cxxx.h>
#include "system\typedefs.h"                        // Required
#include "system\usb\usb.h"                         // Required
#include "io_cfg.h"                                 // Required
#include "eeprom_flags.h"                           // Required

#include "system\usb\usb_compile_time_validation.h" // Optional

#pragma code _HIGH_INTERRUPT_VECTOR = 0x000008
void _high_ISR (void)
{
    _asm goto RM_HIGH_INTERRUPT_VECTOR _endasm
}

#pragma code _LOW_INTERRUPT_VECTOR = 0x000018
void _low_ISR (void)
{
    _asm goto RM_LOW_INTERRUPT_VECTOR _endasm
}

#pragma code

void main(void)
{
    // Initialize firmware update input pin so pullup has time to work.
    INIT_FMWB();

    TRISC = 0xFF & ~LED_MASK & ~PROGB_MASK; // Outputs: LED and FPGA PROG#.
    PROGB = 0; // Keep FPGA in reset state by holding PROG# low.

    // Check to see if the user-mode firmware is being updated.
    // During boot, the uC checks EEPROM location BOOT_SELECT_FLAG_ADDR.
    // If this location contains BOOT_INTO_USER_MODE, then the uC
    // jumps to the user program.  If this location contains
    // BOOT_INTO_REFLASH_MODE, then the uC initializes its USB interface
    // and waits for packets to reprogram the part of the flash that
    // contains the user program.  If the location contains neither code,
    // then the uC will jump to the user program if the FMWB pin is high.
    // Otherwise, it will jump to the code for reprogramming the flash.
    EECON1 = 0x00;
    EEADR  = BOOT_SELECT_FLAG_ADDR;
    EECON1_RD = 1;
    if( EEDATA==BOOT_INTO_USER_MODE || (EEDATA!=BOOT_INTO_REFLASH_MODE && FMWB==1) )
    { // Go into user mode.
        _asm goto RM_RESET_VECTOR _endasm
    }
    
    // Initiate mode to update firmware via USB.
    mInitializeUSBDriver();     // See usbdrv.h
    USBCheckBusStatus();        // Modified to always enable USB module
    while(1)
    {
        USBDriverService();     // See usbdrv.c
        BootService();          // See boot.c
    }
}

#pragma code user = RM_RESET_VECTOR
