/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Timer_Interface.h
 *  Module:  MCAL/Timer
 *  Description:  Timer Driver Interface File
*******************************************************************/
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "GPIO_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"
#include "Macros.h"
/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
* Syntax          : WDT_VidStart(void)
* Description     : Starts the Watchdog Timer with the predefined number 
*                   of cycles. Once started, the system will be reset if 
*                   the Watchdog Timer overflows without being cleared.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : None
* Parameters (out): None
* Return value    : Void
********************************************************************/
void WDT_VidStart(void);
/********************************************************************
* Syntax          : WDT_VidStop(void)
* Description     : Stops the Watchdog Timer. Disables the WDT to prevent 
*                   system reset from a Watchdog Timer overflow.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : None
* Parameters (out): None
* Return value    : Void
********************************************************************/
void WDT_VidStop(void);

/****************************************************************************************
* Syntax          : Timer_0_VidInitialization(u8 Copy_u8Mode, u8 Copy_u8OCR_Value, 
*                                             u8 Copy_u8Compare_Match_Interrupt, 
*                                             u8 Copy_u8Over_Flow_Interrupt, 
*                                             u8 Copy_u8Timer_Pre_Scalar)
* Description     : This function initializes Timer 0 of the MCU based on the desired mode,
*                   compare match value, overflow setting, and prescaler setting.
*                   The function provides the ability to select between different 
*                   timer modes like Normal, CTC, PWM, etc. It also allows enabling/disabling 
*                   the compare match and overflow interrupts and selecting the timer's prescaler.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u8Mode - Timer 0 mode selection.
*                   Copy_u8OCR_Value - Output Compare register value for Timer 0.
*                   Copy_u8Compare_Match_Interrupt - Enables/Disables compare match interrupt.
*                   Copy_u8Over_Flow_Interrupt - Enables/Disables overflow interrupt.
*                   Copy_u8Timer_Pre_Scalar - Timer 0 prescaler selection.
* Parameters (out): None
* Return value    : Void
* Note            : Assumes certain configurations and settings are available. 
*                   Some defined constants, like PWM_Mode, are checked and utilized 
*                   within the function. The function sets and clears various bits 
*                   in Timer 0 registers based on the passed parameters to achieve 
*                   the desired configuration.
***************************************************************************************/
void Timer_0_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Timer_Pre_Scalar);

/***********************************************************************
* Syntax          : Timer_0_VidBusy_Wait_ms(u32 Copy_u32Delay)
* Description     : Uses Timer 0 to introduce a busy-wait delay. The delay is 
*                   achieved using the configured pre-scaler value and by counting 
*                   the timer overflows or using CTC (Clear Timer on Compare) mode.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u32Delay - The desired delay in milliseconds.
* Parameters (out): None
* Return value    : Void
* Note            : The function depends on some global definitions like CPU_Freq 
*                   and several internal and external function/variable dependencies.
*                   It assumes a certain pre-scaler value for the timer and may not 
*                   work correctly if other parts of the code change these configurations.
************************************************************************/
void Timer_0_VidBusy_Wait_ms(u32 Copy_u32Delay);

/***********************************************************************
* Syntax          : Timer_0_VidDelay_ms(u32 Copy_u32Delay, void (*Copy_VidDelay_Func)(void))
* Description     : Configures Timer 0 to introduce a delay. During this delay, 
*                   a specified function (passed as a callback) will be executed
*                   either upon a Compare Match interrupt or an Overflow interrupt 
*                   depending on the desired delay duration and timer configurations.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u32Delay - The desired delay in milliseconds.
*                   Copy_VidDelay_Func - A callback function to be executed during the delay.
* Parameters (out): None
* Return value    : Void
* Note            : The function relies on some global definitions like CPU_Freq 
*                   and has several internal and external function/variable dependencies.
*                   It assumes a certain pre-scaler value for the timer and may not 
*                   work correctly if other parts of the code change these configurations.
************************************************************************/
void Timer_0_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));

/*********************************************************************************************
* Syntax          : void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void))
* Description     : This function registers a callback function that will be executed 
*                   when Timer 0 matches the configured compare value.
*                   It is essential to configure the timer in CTC mode or similar modes that 
*                   utilize the compare match feature, and set the desired compare value.
*                   The callback function should be concise and effective, as it disrupts 
*                   the main program flow.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_VidInturrept - A pointer to the callback function that will be 
*                   executed when Timer 0 has a compare match.
* Parameters (out): None
* Return value    : Void
* Note            : The compare match interrupt should be enabled for this function to work. 
*                   Moreover, global interrupts must be enabled for the ISR to be triggered.
*********************************************************************************************/
void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));

/********************************************************************************************
* Syntax          : void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void))
* Description     : This function registers a callback function that will be executed 
*                   when Timer 0 overflows.
*                   It is essential to configure and start the timer with the appropriate 
*                   mode and prescaler to ensure the overflow occurs at the desired rate.
*                   The callback function should be short and efficient, as it disrupts 
*                   the main program flow.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_VidInturrept - A pointer to the callback function that will be 
*                   executed when Timer 0 overflows.
* Parameters (out): None
* Return value    : Void
* Note            : The ISR should be enabled for this function to work. 
*                   Moreover, global interrupts must be enabled for the ISR to be triggered.
********************************************************************************************/
void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));

/***************************************************************************************
* Syntax          : Timer_2_VidInitialization(u8 Copy_u8Mode, u8 Copy_u8OCR_Value, u8 Copy_u8Compare_Match_Interrupt, u8 Copy_u8Over_Flow_Interrupt, u8 Copy_u8Timer_Pre_Scalar)
* Description     : This function configures and initializes Timer 2 of the MCU. It allows 
*                   the user to set the timer mode (Normal, CTC, PWM, etc.), configure the 
*                   output compare register (OCR), enable or disable interrupts, and set the 
*                   timer's prescalar value for adjusting its ticking rate.
*                   The function employs multiple switches to configure the various parameters 
*                   based on the input values. It also uses macro definitions for specific 
*                   settings to ensure proper configuration.
*                   The function is particularly useful for setting up Timer 2 for various 
*                   timing or PWM tasks in embedded applications.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u8Mode - Specifies the timer mode (e.g., Normal, CTC, PWM).
*                   Copy_u8OCR_Value - The value to be set in the Output Compare Register (OCR).
*                   Copy_u8Compare_Match_Interrupt - Controls the Compare Match interrupt (enable/disable).
*                   Copy_u8Over_Flow_Interrupt - Controls the Timer Overflow interrupt (enable/disable).
*                   Copy_u8Timer_Pre_Scalar - Specifies the timer prescalar value.
* Parameters (out): None
* Return value    : Void
* Note            : The function assumes certain macro definitions and configurations are 
*                   available in the program. For proper operation, the relevant header files 
*                   and configurations should be included.
***************************************************************************************/
void Timer_2_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Timer_Pre_Scalar);

/***************************************************************************************
* Syntax          : Timer_2_VidBusy_Wait_ms(u32 Copy_u32Delay)
* Description     : This function introduces a delay using Timer 2 of the MCU via busy-waiting. 
*                   Rather than using interrupts, this function repeatedly checks the status 
*                   registers to determine if the desired delay period has elapsed. This form 
*                   of delay can be used in contexts where interrupts might not be preferable.
*                   For delay intervals that can be covered in a single overflow/compare 
*                   match of the timer, the function configures Timer 2 in the appropriate 
*                   mode (CTC/Normal) and waits for the OCF2 (Output Compare Flag) to be set. 
*                   If the required delay exceeds the max value of Timer 2 (255 ticks), the 
*                   function divides the delay into intervals that are manageable by the timer 
*                   and waits for the TOV2 (Timer Overflow Flag) to be set multiple times.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u32Delay - Required delay in milliseconds.
* Parameters (out): None
* Return value    : Void
* Note            : The function assumes certain configurations and settings are available. 
*                   It works in tandem with other functions like Timer_2_VidInitialization 
*                   to achieve the desired delay functionality. Busy-waiting consumes CPU 
*                   cycles, so use with care in time-critical applications.
***************************************************************************************/
void Timer_2_VidBusy_Wait_ms(u32 Copy_u32Delay);

/***************************************************************************************
* Syntax          : Timer_2_VidDelay_ms(u32 Copy_u32Delay, void (*Copy_VidDelay_Func)(void))
* Description     : This function provides a delay mechanism using Timer 2 of the MCU. 
*                   The delay function can also execute a user-defined function after the 
*                   delay interval. The delay calculation is based on the configured timer's 
*                   prescaler and the CPU frequency.
*                   For delay intervals that can be covered in a single overflow/compare 
*                   match of the timer, the function configures Timer 2 in the appropriate 
*                   mode (CTC/Normal) and sets the corresponding interrupts. If the required 
*                   delay exceeds the max value of Timer 2 (255 ticks), the function divides 
*                   the delay into intervals that are manageable by the timer and uses overflow 
*                   interrupts to count the number of required intervals.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u32Delay - Required delay in milliseconds.
*                   Copy_VidDelay_Func - Pointer to the user-defined function that is executed after the delay interval.
* Parameters (out): None
* Return value    : Void
* Note            : The function assumes certain configurations and settings are available. 
*                   It works in tandem with other functions like Timer_2_VidInitialization, 
*                   Timer_2_VidCompare_Match_Inturrept, and Timer_2_VidOverflow_Inturrept to 
*                   achieve the desired delay functionality.
***************************************************************************************/
void Timer_2_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));

/*********************************************************************************************
* Syntax          : void Timer_2_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void))
* Description     : This function registers a callback function that will be executed 
*                   when Timer 2 matches the configured compare value.
*                   It is essential to configure the timer in CTC mode or similar modes that 
*                   utilize the compare match feature, and set the desired compare value.
*                   The callback function should be concise and effective, as it disrupts 
*                   the main program flow.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_VidInturrept - A pointer to the callback function that will be 
*                   executed when Timer 2 has a compare match.
* Parameters (out): None
* Return value    : Void
* Note            : The compare match interrupt should be enabled for this function to work. 
*                   Moreover, global interrupts must be enabled for the ISR to be triggered.
*********************************************************************************************/
void Timer_2_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));

/********************************************************************************************
* Syntax          : void Timer_2_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void))
* Description     : This function registers a callback function that will be executed 
*                   when Timer 2 overflows.
*                   It is essential to configure and start the timer with the appropriate 
*                   mode and prescaler to ensure the overflow occurs at the desired rate.
*                   The callback function should be short and efficient, as it disrupts 
*                   the main program flow.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_VidInturrept - A pointer to the callback function that will be 
*                   executed when Timer 2 overflows.
* Parameters (out): None
* Return value    : Void
* Note            : The ISR should be enabled for this function to work. 
*                   Moreover, global interrupts must be enabled for the ISR to be triggered.
********************************************************************************************/
void Timer_2_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));

/***************************************************************************************
* Syntax          : void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer, u8 Copy_u8Duty_Cycle)
* Description     : This function sets the duty cycle for a specified PWM timer. 
*                   The function uses the provided duty cycle percentage value to 
*                   calculate the appropriate value to be placed in the timer's 
*                   Output Compare Register (OCR) for generating the desired PWM signal.
*                   The function supports multiple timers (Timer 0, Timer 1, and Timer 2) 
*                   and configures the corresponding OCR based on the input timer selection.
*                   It's especially useful in embedded systems for controlling the brightness 
*                   of LEDs, the speed of motors, and other PWM-driven devices.
* Sync-Async      : Synchronous
* Reentrancy      : Non-Reentrant
* Parameters (in) : Copy_u8Timer - Specifies the timer to be configured (e.g., Timer_0, Timer_1, Timer_2).
*                   Copy_u8Duty_Cycle - The desired PWM duty cycle percentage (0-100%).
* Parameters (out): None
* Return value    : Void
* Note            : The function assumes that the respective timers have been properly 
*                   initialized for PWM operation before calling this function.
***************************************************************************************/
void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer,u8 Copy_u8Duty_Cycle);

#endif
/********************************************************************
 *  END OF FILE:  Timer_Interface.h
********************************************************************/
