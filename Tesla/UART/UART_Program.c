/*
 * UART_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#include "../00-Lib/STD_TYPES.h"
#include "../00-Lib/BIT_MATH.h"

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"

static void (*UART_RX_COMPLETE_CallBack)(u8)={NULL};
//static void (*UART_TX_COMPLETE_CallBack)(void);

void UART_voidInit(void)
{

#if 	RXCIE == RXCI_DS
	CLR_BIT(UCSRB , UCSRB_RXCIE);
#elif 	RXCIE == RXCI_EN
	SET_BIT(UCSRB , UCSRB_RXCIE);
#endif

#if 	TXCIE == TXCI_DS
	CLR_BIT(UCSRB , UCSRB_TXCIE);
#elif 	TXCIE == TXCI_EN
	SET_BIT(UCSRB , UCSRB_TXCIE);
#endif

#if 	UDRIE == UDRI_DS
	CLR_BIT(UCSRB , UCSRB_UDRIE);
#elif 	UDRIE == UDRI_EN
	SET_BIT(UCSRB , UCSRB_UDRIE);
#endif

#if 	RXEN == RX_DS
	CLR_BIT(UCSRB , UCSRB_RXEN);
#elif 	RXEN == RX_EN
	SET_BIT(UCSRB , UCSRB_RXEN);
#endif

#if 	TXEN == TX_DS
	CLR_BIT(UCSRB , UCSRB_TXEN);
#elif 	TXEN == TX_EN
	SET_BIT(UCSRB , UCSRB_TXEN);
#endif

	u8 UCSRC_setting=0  ;

	SET_BIT(UCSRC_setting , UCSRC_URSEL );

#if 	UMSEL == USART_Asynch
	CLR_BIT(UCSRC_setting , UCSRC_UMSEL);
#elif 	UMSEL == USART_Synch
	SET_BIT(UCSRC_setting , UCSRC_UMSEL);
#endif

	UCSRC_setting &= ~(0b11<<4);
	UCSRC_setting |= (UPM << 4);

#if 	USBS == SB_1BIT
	CLR_BIT(UCSRC_setting , UCSRC_USBS);
#elif 	USBS == SB_2BIT
	SET_BIT(UCSRC_setting , UCSRC_USBS);
#endif

#if 	UCSZ == UCSZ_9BIT
	SET_BIT(UCSRB , UCSRB_UCSZ2);
	SET_BIT(UCSRC_setting , UCSRC_UCSZ1);
	SET_BIT(UCSRC_setting , UCSRC_UCSZ0);
#else
	UCSRC_setting &= ~(0b11<< 1);
	UCSRC_setting |= (UCSZ << 1);
#endif

	UCSRC=UCSRC_setting;

	/* Set buad rate to 9600 */
}

void UART_voidTransmitByte_synch(u8 Copy_data)
{
	while (GET_BIT(UCSRA , UCSRA_UDRE) == 0);
	UDR = Copy_data ;
}

u8 UART_voidRecieverByte_synch(void)
{
	while (GET_BIT(UCSRA , UCSRA_RXC) == 0);
	return UDR ;
}

u8 UART_u8GetUDRValue(void)
{
	return UDR ;
}

void UART_voidSetBaudRate(u32 Copy_u32BoudRate)
{
	u32 BR = 8000000/Copy_u32BoudRate ;
	BR /=16 ;
	BR -= 1 ;
	if(BR < 255)
	{
		UBRRL = (u8)(BR) ;

	}
	else
	{
		UBRRL = (u8)BR ;
		UBRRH = 0b00001111 & (BR >> 8) ;
	}
}

void UART_voidSendString (const u8 *Copy_StrPtr)
{
	while (*Copy_StrPtr != NULL)
	{
		UART_voidTransmitByte_synch(*Copy_StrPtr);
		Copy_StrPtr++;
	}
}

void UART_voidRecString (u8 *Copy_StrPtr)
{
	do
	{
		*Copy_StrPtr = UART_voidRecieverByte_synch();
		Copy_StrPtr++;
	}while ((*(Copy_StrPtr-1) != '\r') && (*(Copy_StrPtr-1) != '\n') );
	*(Copy_StrPtr-1) = NULL;
}

void UART_voidRegisterCallback(u8 Copy_UART_Interrupt ,void (*fptr)(u8))
{
	switch(Copy_UART_Interrupt)
	{
	case 0 :
		UART_RX_COMPLETE_CallBack = fptr;
		break;
//	case 1 :
//		UART_TX_COMPLETE_CallBack = fptr ;
//		break;
	}
}

void __vector_13(void) __attribute((signal));
void __vector_13(void)
{
	if (UART_RX_COMPLETE_CallBack != NULL) {
		UART_RX_COMPLETE_CallBack(UDR);
	}
}

//void __vector_14(void) __attribute((signal));
//void __vector_14(void)
//{
//	if(UART_TX_COMPLETE_CallBack != NULL)
//	{
//		UART_TX_COMPLETE_CallBack() ;
//	}
//}
