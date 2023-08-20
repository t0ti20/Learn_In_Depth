/******************************************************************/
/******************************************************************/
typedef volatile unsigned int vuint32_t;
#define RCC_BASE 			(0x400FE000)
#define GPIO_BASE 			(0x40025000)
#define GPIOF_DATA			(*((vuint32_t *)(GPIO_BASE+0x3FC)))
#define GPIOF_DIRECTION		(*((vuint32_t *)(GPIO_BASE+0x400)))
#define GPIOF_ENABLE		(*((vuint32_t *)(GPIO_BASE+0x51C)))
#define SYSCTL_RCGC2		(*((vuint32_t *)(RCC_BASE +0x108)))
/******************************************************************/
/******************************************************************/

/******************************************************************/
/******************************************************************/
int Intery_Function (void)
{
	SYSCTL_RCGC2=0X20;
	for(volatile int x =200;x;x--);
	GPIOF_DIRECTION|=1<<3;
	GPIOF_ENABLE|=1<<3;
	while(1)
	{
		GPIOF_DATA|=(1<<3);
		for(volatile unsigned int x =200000;x;x--);
		GPIOF_DATA&=~(1<<3);
		for(volatile unsigned int x =200000;x;x--);
	}
}