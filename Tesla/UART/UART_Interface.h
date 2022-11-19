/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

void UART_voidInit();

void UART_voidTransmitByte_synch(u8 Copy_data);
u8 UART_voidRecieverByte_synch(void);

u8 UART_u8GetUDRValue(void);
void UART_voidSetBaudRate(u32 Copy_u32BoudRate);

void UART_voidSendString (const u8 *Copy_StrPtr);
void UART_voidRecString (u8 *Copy_StrPtr);

void UART_voidRegisterCallback(u8 Copy_UART_Interrupt ,void (*fptr)(u8));

#endif /* UART_UART_INTERFACE_H_ */
