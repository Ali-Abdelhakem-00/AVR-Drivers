/*
 * TIMER_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: alibo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum
{
	NORMAL_MODE_T0, PWM_PHASE_CORRECT_T0 , CTC_T0 , FAST_PWM_T0,  // TIMER0
}TIMER_MODE_T0_t;



typedef enum
{

	NORMAL_MODE_T1=0                   , PWM_PHASE_CORRECT_8BIT_T1 ,
	PWM_PHASE_CORRECT_9BIT_T1          , PWM_PHASE_CORRECT_10BIT_T1,
	CTC_T1_OCRA1_TOP                   , FAST_PWM_8BIT_T1          ,
	FAST_PWM_9BIT_T1                   , FAST_PWM_10BIT_T1 ,
	PWM_PHASEANDFREQ_CORRECT_ICR1_TOP  ,PWM_PHASEANDFREQ_CORRECT_OCR1A_TOP,
	PWM_PHASECORRECT_ICR1_TOP          , PWM_PHASECORRECT_OCR1A_TOP ,
	CTC_T1_ICR1_TOP                    , RESERVED_T1 ,
	FAST_PWM_T1_ICR1_TOP               ,  FAST_PWM_T1_OCR1A_TOP
}TIMER_MODE_T1_t;

typedef enum
{
	OC_DISCONNECTED_NONPWM      , TOGGLE_OC_NONPWM  , CLEAR_OC_NONPWM  , SET_OC_NONPWM  ,
	OC_DISCONNECTED_FASTPWM = 0 , RESERVED          , CLEAR_OC_FASTPWM , SET_OC_FASTPWM ,
	OC_DISCONNECTED_PCPWM   = 0 , RESERVED1         ,  CLEAR_OC_PCPWM  ,  SET_OC_PCPWM
}CONTROL_OC_T0_t;

typedef enum
{
	OC1A__OC1B_DISCONNECTED_NONPWM      , TOGGLE_OC1A_OC1B_NONPWM             , CLEAR_OC1A_OC1B_NONPWM    ,  SET_OC1A_OC1B_NONPWM ,
	OC1A__OC1B_DISCONNECTED_FASTPWM = 0 , TOGGLE_OC1A_DISCONNECT_OC1B_FASTPWM , CLEAR_OC1A_OC1B_AND_SET_ATB0TTOM_FASTPWM   , SET_OC1A_OC1B_AND_CLEAR_ATB0TTOM_FASTPWM  ,
	OC1A__OC1B_DISCONNECTED_PCPWM   = 0 , TOGGLE_OC1A_DISCONNECT_OC1B_PCPWM   , CLEAR_OC1A_OC1B_UP_AND_SET_DOWN_PSPWM      , SET_OC1A_OC1B_UP_AND_CLEAR_DOWN_PSPWM

}CONTROL_OC_T1_t;
typedef enum
{
	NO_CLOCK_SOURCE_T0 , FCPU_T0 , FCPU_DIVBY_8_T0 , FCPU_DIVBY_32_T0 , FCPU_DIVBY_64_T0 , FCPU_DIVBY_128_T0 , FCPU_DIVBY_256_T0, FCPU_DIVBY_1024_T0

}CLOCK_SOURCE_T0_t;
typedef enum
{
	NO_CLOCK_SOURCE_T1 , FCPU_T1 , FCPU_DIVBY_8_T1 , FCPU_DIVBY_64_T1 , FCPU_DIVBY_256_T1 , FCPU_DIVBY_1024_T1 , EXTERNAL_FALLING_T1 , EXTERNAL_RISING_T1

}CLOCK_SOURCE_T1_t;

typedef struct
{
	TIMER_MODE_T0_t         timer_mode_T0;
	CONTROL_OC_T0_t         control_oc_T0;
	CLOCK_SOURCE_T0_t       clock_source_T0;
	u8                      Preload_Value_T0;
	u8                      Compare_Value_T0;
}TIMER_CONFIG_T0;



typedef struct
{
	TIMER_MODE_T1_t         timer_mode_T1;
	CONTROL_OC_T1_t         control_oc_T1;
	CLOCK_SOURCE_T1_t       clock_source_T1; // DIV_8

}TIMER_CONFIG_T1;

typedef enum
{
	CS00_BIT, CS01_BIT , CS02_BIT , WGM01_BIT , COM00_BIT , COM01_BIT , WGMOO_BIT , FOC0_BIT
}TCCR0_REG_t;
void Timer_voidT0Init  ( TIMER_CONFIG_T0 *Ptr_To_TIMERCONFIG);
void Timer_voidT0Dinit (void);
void Timer_StartT0(TIMER_CONFIG_T0 *Ptr_To_TIMERCONFIG);
u8 Timer_u8ReturnedTimer0_Counter0ValueT0(void);
void Timer_voidCallBackFun(void(*Ptr_To_Fun)(void));



void Timer_voidT1Init( TIMER_CONFIG_T1 *Ptr_To_TIMERCONFIG);
void Timer_voidSetCompareMatchValueT1A (u16 Copy);
void Timer_voidSetICRValueT1 (u16 Copy);
u16 Timer_u16ReturnedTimer1_Counter1ValueT1 (void);

void T1_SetCallBack(void (*Ptr_To_Fun)(void));


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
