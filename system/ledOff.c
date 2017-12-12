#include<xinu.h>

void ledOff() {
//	ledWrite(TRUE,pin);
//	control(led,1,TRUE,pin);
	putc(led,'F');
//	ledputc(TRUE,pin,26);
}
