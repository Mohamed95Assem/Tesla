/*
 * UART_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

/*	ADC Register	*/
#define 	UDR	 		*((volatile u8  *)(0x2C))
#define 	UCSRA 		*((volatile u8  *)(0x2B))
#define 	UCSRB 		*((volatile u8  *)(0x2A))
#define 	UCSRC 		*((volatile u8  *)(0x40))
#define 	UBRRL 		*((volatile u8  *)(0x29))
#define 	UBRRH 		*((volatile u8  *)(0x40))

/*USART Control and Status Register B – UCSRB - RX Complete Interrupt Enable */
#define 	RXCI_DS		0
#define 	RXCI_EN		1

/*USART Control and Status Register B – UCSRB - TX Complete Interrupt Enable */
#define 	TXCI_DS		0
#define 	TXCI_EN		1

/*USART Control and Status Register B – UCSRB - USART Data Register Empty Interrupt Enable */
#define 	UDRI_DS		0
#define 	UDRI_EN		1

/*USART Control and Status Register B – UCSRB - Receiver Enable*/
#define 	RX_DS		0
#define 	RX_EN		1

/*USART Control and Status Register B – UCSRB - Transmitter Enable*/
#define 	TX_DS		0
#define 	TX_EN		1

/*USART Control and Status Register C – UCSRC - USART Mode Select*/
#define 	USART_Asynch	0
#define 	USART_Synch		1

/*USART Control and Status Register C – UCSRC - Parity Mode*/
#define 	PM_DS			0
#define 	PM_EVEN			2
#define 	PM_ODD			3

/*USART Control and Status Register C – UCSRC - Stop Bit Select*/
#define 	SB_1BIT			0
#define 	SB_2BIT			1

/*USART Control and Status Register B,C – UCSRB,UCSRC - Character Size*/
#define 	UCSZ_5BIT		0
#define		UCSZ_6BIT		1
#define 	UCSZ_7BIT		2
#define 	UCSZ_8BIT		3
#define 	UCSZ_9BIT		7


/* UCSRA bits */
#define   UCSRA_RXC     7
#define   UCSRA_TXC     6
#define   UCSRA_UDRE    5
#define   UCSRA_FE      4
#define   UCSRA_DOR     3
#define   UCSRA_PE      2
#define   UCSRA_U2X     1
#define   UCSRA_MPCM    0

/* UCSRB bits */
#define  UCSRB_RXCIE    7
#define  UCSRB_TXCIE    6
#define  UCSRB_UDRIE    5
#define  UCSRB_RXEN     4
#define  UCSRB_TXEN     3
#define  UCSRB_UCSZ2    2
#define  UCSRB_RXB8     1
#define  UCSRB_TXB8     0

/* UCSRC bits */
#define  UCSRC_URSEL    7
#define  UCSRC_UMSEL    6
#define  UCSRC_UPM1     5
#define  UCSRC_UPM0     4
#define  UCSRC_USBS     3
#define  UCSRC_UCSZ1    2
#define  UCSRC_UCSZ0    1
#define  UCSRC_UCPOL    0


#endif /* UART_UART_PRIVATE_H_ */
