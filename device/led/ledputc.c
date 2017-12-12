#include<xinu.h>

devcall ledputc (struct dentry *devptr,char ch) {
	struct	ledcblk	*ledptr;		/* Pointer to led control block	*/
	bool8 toggle;
	ledptr = &ledtab[devptr->dvminor];
	if(ch=='T') {
		toggle = TRUE;
	}
	else toggle = FALSE;
	
	ledptr -> toggle = toggle;
	int16 pin = 13;
	gpio_write(toggle,pin);
	return OK;
}
