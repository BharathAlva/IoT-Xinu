/* ttyinit.c - ttyinit */

#include <xinu.h>

struct	ledcblk	ledtab[Nled];

/*------------------------------------------------------------------------
 *  ttyinit  -  Initialize buffers and modes for a tty line
 *------------------------------------------------------------------------
 */
devcall	ledinit(
	  struct dentry	*devptr		/* Entry in device switch table	*/
	)
{
	struct	ledcblk	*ledptr;		/* Pointer to ttytab entry	*/

	ledptr = &ledtab[devptr->dvminor];

	/* Initialize values in the LED control block */
	ledptr->toggle = FALSE;
	
	return OK;
}

