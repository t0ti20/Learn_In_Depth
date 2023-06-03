#define RCC_BASE 			0x40021000
#define PORTA_BASE 			0x40010800
#define GPIOA_ODR			(PORTA_BASE+0x0C)
#define RCC_APB2ENR			*((vuint32_t *)(RCC_BASE+0x18))
#define GPIOA_CRH			*((vuint32_t *)(PORTA_BASE+0x04))
typedef volatile unsigned int vuint32_t;
volatile unsigned char arr[]="123";
volatile unsigned char arr2[4];
typedef union 
{
	vuint32_t Regester;
	struct
	{
		vuint32_t 				:13;
		vuint32_t Pin_13		:1;	
		vuint32_t 				:18;		
	}Bits;
}GPIOX_ODR;
#define Port_A 		(*((GPIOX_ODR *)(GPIOA_ODR)))
int Intery_Function (void)
{
	int i=0;
	RCC_APB2ENR|=1<<2;
	GPIOA_CRH&=0xff0fffff;
	GPIOA_CRH|=0x00200000;
	while(1)
	{
		Port_A.Bits.Pin_13=1;
		for(i=0;i<1000;i++);
		Port_A.Bits.Pin_13=0;
		for(i=0;i<1000;i++);
	}
}
extern void NMI_Handler(void)
{
	
}
