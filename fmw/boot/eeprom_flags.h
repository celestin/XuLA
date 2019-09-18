
#ifndef EEPROM_FLAGS_H
#define EEPROM_FLAGS_H

/**
   Definitions of flags stored in EEPROM of the uC.
 */

#define JTAG_DISABLE_FLAG_ADDR 0xFD
#define DISABLE_JTAG 0x69

#define FLASH_ENABLE_FLAG_ADDR 0xFE
#define ENABLE_FLASH 0xAC

#define BOOT_SELECT_FLAG_ADDR 0xFF
#define BOOT_INTO_USER_MODE 0xC5
#define BOOT_INTO_REFLASH_MODE 0x3A

#endif
