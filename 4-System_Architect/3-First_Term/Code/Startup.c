#include <stdint.h>
extern int main(void);
void Reset();
extern uint32_t _stack_top;
extern uint32_t _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void Reset_Handled(){
	Reset();
}

void NMI(void)__attribute__((weak,alias("Reset_Handled")));;
void HardFault(void)__attribute__((weak,alias("Reset_Handled")));;
void MemManage(void)__attribute__((weak,alias("Reset_Handled")));;
void BusFualt(void)__attribute__((weak,alias("Reset_Handled")));;
void UsageFualt(void)__attribute__((weak,alias("Reset_Handled")));;
void Reserved(void)__attribute__((weak,alias("Reset_Handled")));;
void SVCall(void)__attribute__((weak,alias("Reset_Handled")));;
void DebugMonitor(void)__attribute__((weak,alias("Reset_Handled")));;
void Reserved1(void)__attribute__((weak,alias("Reset_Handled")));;
void PendSV(void)__attribute__((weak,alias("Reset_Handled")));;
void SysTick(void)__attribute__((weak,alias("Reset_Handled")));;
void WWDG(void)__attribute__((weak,alias("Reset_Handled")));;
void PVD(void)__attribute__((weak,alias("Reset_Handled")));;
void TAMPER(void)__attribute__((weak,alias("Reset_Handled")));;
void RTC(void)__attribute__((weak,alias("Reset_Handled")));;
void FLASH(void)__attribute__((weak,alias("Reset_Handled")));;
void RCC(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI0(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI1(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI2(void)__attribute__((weak,alias("Reset_Handled")));;

uint32_t vectors[]__attribute__((section(".vectors")))={
	(uint32_t) &_stack_top,
	(uint32_t) &Reset,
	(uint32_t) &NMI,
	(uint32_t) &HardFault,
	(uint32_t) &MemManage,
	(uint32_t) &BusFualt,
	(uint32_t) &UsageFualt,
	(uint32_t) &Reserved,	
	(uint32_t) &SVCall,
	(uint32_t) &DebugMonitor,
	(uint32_t) &Reserved1,
	(uint32_t) &PendSV,
	(uint32_t) &SysTick,
	(uint32_t) &WWDG,
	(uint32_t) &PVD,
	(uint32_t) &TAMPER,	
	(uint32_t) &RTC,
	(uint32_t) &FLASH,
	(uint32_t) &RCC,
	(uint32_t) &EXTI0,
	(uint32_t) &EXTI1,
	(uint32_t) &EXTI2,

};

void Reset(){
	uint32_t DATA_SIZE= (volatile uint8_t*)&_E_DATA - (volatile uint8_t*)&_S_DATA;
	uint32_t BSS_SIZE= (volatile uint8_t*)&_E_BSS - (volatile uint8_t*)&_S_BSS;
	volatile uint8_t *P_SRC=(volatile uint8_t*)&_E_text;
	volatile uint8_t *P_DIS=(volatile uint8_t*)&_S_DATA;
	uint8_t i;
	for(i=0;i<DATA_SIZE;i++){
		*P_DIS=*P_SRC;
		(volatile uint8_t*)P_DIS++;
		(volatile uint8_t*)P_SRC++;
	}
	P_DIS=(volatile uint8_t*)&_S_BSS;
	for(i=0;i<BSS_SIZE;i++){
		*P_DIS=0;
		(volatile uint8_t*)P_DIS++;
	}
	
main();
	
}