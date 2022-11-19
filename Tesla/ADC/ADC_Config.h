/*
 * ADC_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#ifndef ADC_ADC_CONFIG_H_
#define ADC_ADC_CONFIG_H_

/*	ADC Multiplexer Selection Register – ADMUX – Reference Selection Bits
 *	VREF_AREF 	->	AREF, Internal Vref turned off
 * 	VREF_AVCC	->	AVCC with external capacitor at AREF pin
 * 	VREF_IREF	->	Internal 2.56V Voltage Reference with external capacitor at AREF pin	*/
#define 	ADC_RSB		VREF_AREF

/*	ADC Multiplexer Selection Register – ADMUX – ADC Left Adjust Result
 * 	ADLAR_RIGHT	-> (ADCH 2 - ADCL 8)
 * 	ADLAR_LEFT	-> (ADCH 8 - ADCL 2) */
#define 	ADC_LAR		ADLAR_RIGHT

/*	ADC Control and Status Register A – ADCSRA - ADC Enable
 * 	ADC_ENABLE
 * 	ADC_DISABLE	*/
#define 	ADEN		ADC_ENABLE

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Enable
 * 	ADC_AUTO_TRIG_ENABLE
 * 	ADC_AUTO_TRIG_DISABLE	*/
#define 	ADATE		ADC_AUTO_TRIG_ENABLE

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Source
 * 	ADC_AUTO_TRIG_FREE_RUNNING_MODE
 * 	ADC_AUTO_TRIG_ANALOG_COMPARATOR
 * 	ADC_AUTO_TRIG_EXTERNAL_INTERRUPT_REQUEST
 * 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER0_COMPARE_MATCH
 * 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER0_OVERFLOW
 * 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_COMPARE_MATCH_B
 * 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_OVERFLOW
 * 	ADC_AUTO_TRIG_FREE_TIMER_COUNTER1_COMPARE_EVENT		*/
#define 	ADTS		ADC_AUTO_TRIG_FREE_RUNNING_MODE

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Source - ADC Interrupt Enable
 *	ADC_INTERRUPT_ENABLE
 *	ADC_INTERRUPT_DISABLE	*/
#define		ADIE		ADC_INTERRUPT_ENABLE

/*	ADC Control and Status Register A – ADCSRA - ADC Auto Trigger Source - ADC Interrupt Enable
 *	ADC_PRES0	->	2
 *	ADC_PRES2	->	2
 *	ADC_PRES4	->	4
 *	ADC_PRES8	->	8
 *	ADC_PRES16	->	16
 *	ADC_PRES32	->	32
 *	ADC_PRES64	->	64
 *	ADC_PRES128	->	128		*/
#define 	ADPS		ADC_PRES128

#endif /* ADC_ADC_CONFIG_H_ */
