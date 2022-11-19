/*
 * DIO_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"


void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinNo , u8 Copy_u8Direction)
{
	if(Copy_u8Direction == DIO_OUTPUT)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(DDRA , Copy_u8PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(DDRB , Copy_u8PinNo);
			break;
		case DIO_PORTC:
			SET_BIT(DDRC , Copy_u8PinNo);
			break;
		case DIO_PORTD:
			SET_BIT(DDRD , Copy_u8PinNo);
			break;
		}
	}
	else if (Copy_u8Direction == DIO_INPUT)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA , Copy_u8PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB , Copy_u8PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC , Copy_u8PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD , Copy_u8PinNo);
			break;
		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinNo , u8 Copy_u8Value)
{
	if(Copy_u8Value == DIO_HIGH)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(PORTA , Copy_u8PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(PORTB , Copy_u8PinNo);
			break;
		case DIO_PORTC:
			SET_BIT(PORTC , Copy_u8PinNo);
			break;
		case DIO_PORTD:
			SET_BIT(PORTD , Copy_u8PinNo);
			break;
		}
	}
	else if (Copy_u8Value == DIO_LOW)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA , Copy_u8PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB , Copy_u8PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC , Copy_u8PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD , Copy_u8PinNo);
			break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinNo)
{
	u8 L_u8inValue = 0;
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
		L_u8inValue = GET_BIT(PINA , Copy_u8PinNo);
		break;
	case DIO_PORTB:
		L_u8inValue = GET_BIT(PINB , Copy_u8PinNo);
		break;
	case DIO_PORTC:
		L_u8inValue = GET_BIT(PINC , Copy_u8PinNo);
		break;
	case DIO_PORTD:
		L_u8inValue = GET_BIT(PIND , Copy_u8PinNo);
		break;
	}
	return L_u8inValue ;
}

void DIO_voidTogglePin(u8 Copy_u8PortId , u8 Copy_u8PinNo)
{
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA , Copy_u8PinNo);
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB , Copy_u8PinNo);
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC , Copy_u8PinNo);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD , Copy_u8PinNo);
		break;
	}
}

void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction)
{
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
		DDRA = Copy_u8Direction ;
		break;
	case DIO_PORTB:
		DDRB = Copy_u8Direction ;
		break;
	case DIO_PORTC:
		DDRC = Copy_u8Direction ;
		break;
	case DIO_PORTD:
		DDRD = Copy_u8Direction ;
		break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value)
{
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
		PORTA = Copy_u8Value ;
		break;
	case DIO_PORTB:
		PORTB = Copy_u8Value ;
		break;
	case DIO_PORTC:
		PORTC = Copy_u8Value ;
		break;
	case DIO_PORTD:
		PORTD = Copy_u8Value ;
		break;
	}
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{
	u8 L_u8inValue = 0;
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
		L_u8inValue = PINA ;
		break;
	case DIO_PORTB:
		L_u8inValue = PINB ;
		break;
	case DIO_PORTC:
		L_u8inValue = PINC ;
		break;
	case DIO_PORTD:
		L_u8inValue = PIND ;
		break;
	}
	return L_u8inValue ;
}
