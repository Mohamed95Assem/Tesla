/*
 *
 *     __  _  __    _ __  _ _____ ___ ___ ___ __   ______
 *    | _\| |/__\  | |  \| |_   _| __| _ \ __/  \ / _/ __|
 *    | v | | \/ | | | | ' | | | | _|| v / _| /\ | \_| _|
 *    |__/|_|\__/  |_|_|\__| |_| |___|_|_\_||_||_|\__/___|
 *
 *  Created on: 16/9/2022
 *      Author: mohamed Assem
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define		DIO_PORTA		0
#define		DIO_PORTB		1
#define		DIO_PORTC		2
#define		DIO_PORTD		3

#define		DIO_PIN0		0
#define		DIO_PIN1		1
#define		DIO_PIN2		2
#define		DIO_PIN3		3
#define		DIO_PIN4		4
#define		DIO_PIN5		5
#define		DIO_PIN6		6
#define		DIO_PIN7		7

#define		DIO_OUTPUT		1
#define		DIO_INPUT		0

#define		DIO_HIGH		1
#define		DIO_LOW			0

void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinNo , u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinNo , u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinNo);
void DIO_voidTogglePin(u8 Copy_u8PortId , u8 Copy_u8PinNo);

void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8PortId);

#endif /* _DIO_INTERFACE_H_ */
