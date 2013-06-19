#include <syslinux/config.h>
#include <com32.h>
#include <fs.h>

extern far_ptr_t OrigESDI;
extern uint64_t Hidden;
extern uint16_t BIOSType;
extern uint16_t bios_cdrom;
extern uint8_t DriveNumber;
extern uint8_t spec_packet;

__export void get_derivative_info(union syslinux_derivative_info *di)
{
	di->iso.filesystem = SYSLINUX_FS_ISOLINUX;
	di->iso.sector_shift = SectorShift;
	di->iso.drive_number = DriveNumber;
	di->iso.cd_mode = (BIOSType - bios_cdrom >> 2);

	di->iso.spec_packet = spec_packet;
	di->iso.esdi_ptr = GET_PTR(OrigESDI);
	di->iso.partoffset = Hidden;
}