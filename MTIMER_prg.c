/*
 * MTIMER_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: weza
 */
#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "MTIMER_register.h"
#include "MTIMER_private.h"
#include "MTIMER_int.h"
#include"MTIMER_conf.h"
void timer0_FPWMInit()
{
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// set on top compare on match
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	//set timer0 pres
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
} //CHECKED
u8 MTimerVoidSetOCR0(u8 A_u8OCR){
	OCR0=A_u8OCR;
	return OCR0;
}
U16 MTimer1ReadICR(void){
	return 	ICR1;
}
void MTimer1ICUInit(){
	    CLR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	//set rising edge
		SET_BIT(TCCR1B,ICES1);
	//enable icu interrupt
		SET_BIT(TIMSK,TICIE1);
}

void MTimer1voidSetEdgeTrigger(u8 A_u8Trigger){
	if(A_u8Trigger==1){
		SET_BIT(TCCR1B,ICES1);
}
	else if(A_u8Trigger==0){
		CLR_BIT(TCCR1B,ICES1);
	}}
void MTimer1voidENABLEICU(void){
SET_BIT(TIMSK,TICIE1);
}
void MTimer1voidDisableICU(void){
CLR_BIT(TIMSK,TICIE1);}
void MTIMER0_VInit(void){
	// SELECT NORMAL MODE
	TCCR0=((TCCR0)&waveform_generation_mode_mask)|waveform_generation_mode;
#if (waveform_generation_mode==normal_mode)
    SET_BIT(TIMSK,TOIE0); //enable OVERFLOW interrupt
    CLR_BIT(TIMSK,OCIE0);
#elif (waveform_generation_mode==CTC)
    SET_BIT(TIMSK,OCIE0); //enable OVERFLOW interrupt
    CLR_BIT(TIMSK,TOIE0);
    TCCR0=((TCCR0)&output_mode_change_mask )|output_mode;
#elif (waveform_generation_mode==fast_PWM)
    TCCR0=((TCCR0)&output_mode_change_mask )|output_mode;
    SET_BIT(TIMSK,OCIE0);
#elif (waveform_generation_mode==PWM_phasecorrect)
    TCCR0=((TCCR0)&output_mode_change_mask )|output_mode;
    SET_BIT(TIMSK,OCIE0);
#endif
    TCCR0=((TCCR0)&generation_prescallar_mode_mask)|prescallar;
}
void MTimer1voidFPWInit(void){
			SET_BIT(TCCR1A,COM1A1);
			CLR_BIT(TCCR1A,COM1A0); //CHOOSE CHANNEL A
    		CLR_BIT(TCCR1A,WGM10);  //WAVEFORM MODE FPWM
	     	SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			CLR_BIT(TCCR1B,CS10);    //CHOOSE PRESCALAR8
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
void MTimer1voidNORMALInit(void){
			SET_BIT(TCCR1A,COM1A1);
			CLR_BIT(TCCR1A,COM1A0); //CHOOSE CHANNEL A
    		CLR_BIT(TCCR1A,WGM10);  //WAVEFORM MODE NORMAL
	     	CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			CLR_BIT(TCCR1B,CS10);    //CHOOSE PRESCALAR8
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}

U16 MTimer1ReadTCNT1(void){
	return TCNT1;
}
void MTimer1PreloadTCNT1(U16 A_U16Preload){
	TCNT1=A_U16Preload;
}

//clr the input capture enable

void Timer1_voidsetOCR1A(U16 A_U16OCR1A){
#if (Timer1_Channel_Selection==ChannelA)
		OCR1A=A_U16OCR1A;
#elif (Timer1_Channel_Selection==ChannelB)
		OCR1BLH=A_U16OCR1A;
#endif
	}
	void MT(U16 A_U16ICR1A){
			ICR1=A_U16ICR1A;
		}
u8 MTimerVoidPreload(u8 A_u8Preload){
	TCNT0=A_u8Preload;
	return TCNT0;
}

 //1000= 10^-3/10^-6 is the tick time
//void MServoRotate(U16 A_U16Aangle){
//	MTimerVoidSetOCR((A_U16Aangle*2*1000)/180);}


void (*callback_fun_Timer0_CTC)(void)=(void*)0;
void (*callback_fun_Timer0_NORMAL)(void)=(void*)0;
void (*callback_fun_Timer1)(void)=(void*)0;
void GetApp_Timer0_CTC(void (*ARG)(void)){
				callback_fun_Timer0_CTC=ARG;
			}
void GetApp_Timer0_NORMAL(void (*ARG)(void)){
				callback_fun_Timer0_NORMAL=ARG;
						}
void GetApp_Timer1(void (*ARG)(void)){
				callback_fun_Timer1=ARG;
			}
    void __vector_9(void) __attribute__ ((signal));
		void __vector_9(void){
	callback_fun_Timer1();
		}

	void __vector_10(void) __attribute__ ((signal));
			void __vector_10(void){
			  callback_fun_Timer0_CTC();
						}
		     void __vector_11(void) __attribute__ ((signal));
					void __vector_11(void){
					callback_fun_Timer0_NORMAL();
											}
void (*callback_fun_ICU)(void)=(void*)0;
void GetApp_ICU(void (*ARG)(void)){
			callback_fun_ICU=ARG;
			}
void __vector_6(void) __attribute__ ((signal));
			void __vector_6(void){
				callback_fun_ICU();
				}
