#include "ry_wsy301.h"
#include "app.h"

u8 get_station[8] = {0x00,0x03,0x00,0x01,0x00,0x01,0xD4,0x1B};

void get_thermo_hygro_barograph()
{
	u8 command[8] = {0xFF,0x03,0x00,0x00,0x00,0x03,0x10,0x15};
	comSendBuf(COM3,command, 8);
	//OSTimeDlyHMSM(0,0,0,5);
}