#include <xinu.h>


devcall gpio_write(bool8 toggle, int16 pin ) {
//	int offset;
	unsigned int oeaddr_offset;
	unsigned int dataOut_offset;
	unsigned int baseAddress;
	switch(pin) {
		case 12: 
			 
				 baseAddress = GPIO1;
				 oeaddr_offset = 0xEFFFFFFF;
				 dataOut_offset = 0x10000000;			 
			 
			 
			 
			 break;
		
		case 13: baseAddress = GPIO0;
			 oeaddr_offset = 0x7FFFFFFF;
			 dataOut_offset = 0x80000000;
			 break;
				 
		case 14:  baseAddress = GPIO1;
			  oeaddr_offset = 0xFFFDFFF;
			  dataOut_offset = 0x0002000;
			  break;
				  
		case 15: baseAddress = GPIO1;
			 oeaddr_offset = 0xFFFF7FF;
			 dataOut_offset = 0x0000800;
			 break;
				 
		case 16: baseAddress = GPIO1;
			 oeaddr_offset = 0xFFF7FFFF;
			 dataOut_offset = 0x00080000;
			 break;
			 
		case 17: baseAddress = GPIO0;
			 oeaddr_offset = 0xFFFFFFDF;
			 dataOut_offset = 0x00000020;
			 break;
			 
		case 18: baseAddress = GPIO0;
			 oeaddr_offset = 0xFFFFFFEF;
			 dataOut_offset = 0x00000010;
			 break;
				 

	}
	
	//int offset = 28;
	

	unsigned int *oeAddr = baseAddress + 0x134;
//	unsigned int *oeAddr_GPIO1 = GPIO1 + 0x134;
	unsigned int *dataOutAddr = baseAddress + 0x13C;
//	unsigned int *dataOut_GPIO1 = GPIO1 + 0x13C;
	unsigned int newOEAddrVal = *oeAddr & oeaddr_offset;
	*oeAddr = newOEAddrVal;
	unsigned int newdataoutval = *dataOutAddr ^ dataOut_offset;
	if(toggle == FALSE) {
			newdataoutval = 0x00000000;
	}
	*dataOutAddr = newdataoutval;
	
//	kprintf("led On!!");
	return OK;


	
}
