/*
 * ADC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

/*	ADC Register	*/
#define 	ADMUX 		*((volatile u8  *)(0x27))
#define 	ADCSRA 		*((volatile u8  *)(0x26))
#define 	ADCL 		*((volatile u8  *)(0x24))
#define 	ADCH 		*((volatile u8  *)(0x25))
#define 	SFIOR 		*((volatile u8  *)(0x50))

#define		ADC_data	*((volatile u16 *)(0x24))

/*	ADC Multiplexer Selection Register – ADMUX – Reference Selection Bits	*/
#define 	VREF_AREF	0b00
#define 	VREF_AVCC	0b01
#define 	VREF_IREF	0b11

/*	ADC Multiplexer Selection Register – ADMUX – ADC Left Adjust Result		*/
#define 	ADLAR_RIGHT	0
#define 	ADLAR_LEFT	1

/*	ADC Control and Status Register A – ADCSRA - ADC Enable					*/
#define 	ADC_DISABLE		0
#define 	ADC_ENABLE		1

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Enable	*/
#define 	ADC_AUTO_TRIG_DISABLE	0
#define 	ADC_AUTO_TRIG_ENABLE	1

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Source	*/
#define 	ADC_AUTO_TRIG_FREE_RUNNING_MODE						0
#define 	ADC_AUTO_TRIG_ANALOG_COMPARATOR						1
#define 	ADC_AUTO_TRIG_EXTERNAL_INTERRUPT_REQUEST			2
#define 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER0_COMPARE_MATCH		3
#define 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER0_OVERFLOW			4
#define 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_COMPARE_MATCH_B	5
#define 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_OVERFLOW			6
#define 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_COMPARE_EVENT		7

/*	ADC Control and Status Register A – ADCSRA - ADC Interrupt Flag			*/
#define 	ADIF		4

/*	ADC Control and Status Register A – ADCSRA - ADC Interrupt Enable		*/
#define		ADC_INTERRUPT_DISABLE	0
#define		ADC_INTERRUPT_ENABLE	1

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Source - ADC Interrupt Enable	*/
#define 	ADC_PRES0		0b000
#define 	ADC_PRES2		0b001
#define 	ADC_PRES4		0b010
#define 	ADC_PRES8		0b011
#define 	ADC_PRES16		0b100
#define 	ADC_PRES32		0b101
#define 	ADC_PRES64		0b110
#define 	ADC_PRES128		0b111

#endif /* ADC_ADC_PRIVATE_H_ */
