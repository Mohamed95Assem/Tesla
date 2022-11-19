/*
 * ADC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

void ADC_voidInit(void);
u16 ADC_u16ReadDigitalValue_synch(u8 Copy_u8IDChannel); //synchronous function

/* 	ADC Multiplexer Selection Register – ADMUX – Analog Channel and Gain Selection Bits	*/
#define   ADC0                0
#define   ADC1                1
#define   ADC2                2
#define   ADC3                3
#define   ADC4                4
#define   ADC5                5
#define   ADC6                6
#define   ADC7                7
#define   ADC0_ADC0_10X       8
#define   ADC1_ADC0_10X       9
#define   ADC0_ADC0_200X      10
#define   ADC1_ADC0_200X      11
#define   ADC2_ADC2_10X       12
#define   ADC3_ADC2_10X       13
#define   ADC2_ADC2_200X      14
#define   ADC3_ADC2_200X      15
#define   ADC0_ADC1           16
#define   ADC1_ADC1           17
#define   ADC2_ADC1           18
#define   ADC3_ADC1           19
#define   ADC4_ADC1           20
#define   ADC5_ADC1           21
#define   ADC6_ADC1           22
#define   ADC7_ADC1           23
#define   ADC0_ADC2           24
#define   ADC1_ADC2           25
#define   ADC2_ADC2           26
#define   ADC3_ADC2           27
#define   ADC4_ADC2           28
#define   ADC5_ADC2           29

void ADC_voidSetCallback(void(*fptr)(void));

u16 ADC_u16GETADC_DATA(void);
void ADC_StartConversion(u8 cpy_Channelnum);

#endif /* ADC_ADC_INTERFACE_H_ */
