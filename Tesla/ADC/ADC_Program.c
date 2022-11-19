/*
 * ADC_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#include "../00-Lib/STD_TYPES.h"
#include "../00-Lib/BIT_MATH.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

static void (*G_ADC_Callback)(void);

// void (*callback[4])(void) = NULL array to pointer to function

/*void (*callback[0])(void)
 * {
 *
 * }*/

void ADC_voidInit(void)
{
	/*	1- Select Reference Selection Bits	*/
	ADMUX &= ~(0b11<<6);
	ADMUX |= (ADC_RSB << 6);

	/*2- Select ADC Left Adjust Result*/
#if 	ADC_LAR == ADLAR_RIGHT
	CLR_BIT(ADMUX , 5);
#elif 	ADC_LAR == ADLAR_LEFT
	SET_BIT(ADMUX , 5);
#endif

	/*3- ADC enable*/
#if 	ADEN == ADC_ENABLE
	SET_BIT(ADCSRA , 7);
#elif 	ADEN == ADC_DISABLE
	CLR_BIT(ADCSRA , 7);
#endif

	/*4- Auto trigger enable*/
#if 	ADATE == ADC_AUTO_TRIG_ENABLE
	SET_BIT(ADCSRA , 5);
	/*4.a- select auto trigger mode*/
	SFIOR &= ~(0b111<<5);
	SFIOR |= (ADTS << 5);
#elif 	ADATE == ADC_AUTO_TRIG_DISABLE
	CLR_BIT(ADCSRA , 5);
#endif

	/*5- interrupt enable/disable*/
#if 	ADIE == ADC_INTERRUPT_ENABLE
	SET_BIT(ADCSRA , 3);
#elif 	ADIE == ADC_INTERRUPT_DISABLE
	CLR_BIT(ADCSRA , 3);
#endif

	/*6- Convention clock prescaller */
	ADCSRA &= ~(0b111);
	ADCSRA |= (ADPS);
}
u16 ADC_u16ReadDigitalValue_synch(u8 Copy_u8IDChannel){
	/* 	ADC Multiplexer Selection Register – ADMUX – Analog Channel and Gain Selection Bits
	 *	ADC0	ADC1	ADC2	ADC3	ADC4	ADC5	ADC6	ADC7
	 *	ADC0_ADC0_10X 	ADC1_ADC0_10X 	ADC0_ADC0_200X	ADC1_ADC0_200X
	 *	ADC2_ADC2_10X 	ADC3_ADC2_10X 	ADC2_ADC2_200X	ADC3_ADC2_200X
	 *	ADC0_ADC1     	ADC1_ADC1     	ADC2_ADC1     	ADC3_ADC1
	 *	ADC4_ADC1     	ADC5_ADC1     	ADC6_ADC1     	ADC7_ADC1
	 *	ADC0_ADC2     	ADC1_ADC2     	ADC2_ADC2     	ADC3_ADC2
	 *	ADC4_ADC2     	ADC5_ADC2     										*/
	ADMUX &= ~(0b11111);
	ADMUX |= (Copy_u8IDChannel & 0x07);

	/*	ADC Control and Status Register A – ADCSRA - ADC Start Conversion	*/
	SET_BIT(ADCSRA , 6);

	/*WAIT for convertio complete*/
	while(GET_BIT(ADCSRA , ADIF) == 0){}
	/*CLEAR ADC Interrupt Flag*/
	SET_BIT(ADCSRA , ADIF);
	/*RETURN ADC VALUE*/
	return ADC_data ;
}

u16 ADC_u16GETADC_DATA(void)
{
	return ADC_data;

}

void ADC_StartConversion(u8 cpy_Channelnum)
{
	//1-select channel
	if (cpy_Channelnum <8)
	{
		ADMUX= (ADMUX & 0xE0)| cpy_Channelnum;
		//2-start conversion
		SET_BIT(ADCSRA,6);
	}
}

void ADC_voidSetCallback(void(*fptr)(void))
{
	G_ADC_Callback = fptr ;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(G_ADC_Callback != NULL)
	{
		G_ADC_Callback();
	}
}
