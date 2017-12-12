/* tty.h */

#define GPIO1 0x4804C000
#define GPIO0 0x44E07000


struct	ledcblk	{			/* led control block	*/
	bool8 toggle;
};
extern struct ledcblk ledtab[];


