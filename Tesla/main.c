/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#include "00-LIB/STD_TYPES.h"

#include <util/delay.h>

#include "01-DIO/DIO_Interface.h"
#include "GIE/GIE_Interface.h"
#include "UART/UART_Interface.h"
#include "LCD/LCD_interface.h"
#include "ADC/ADC_Interface.h"

volatile char buffer[10];
volatile u8 uart_flag = 0;
u16 heat_value = 0 ;

void uart_cbk(u8 data)
{
	static u32 buffer_idx = 0;
	buffer[buffer_idx] = data;
	if (buffer_idx == (sizeof(buffer) / sizeof(buffer[0])-1) || buffer[buffer_idx] == '\n' || buffer[buffer_idx] == '\r')
	{
		buffer[buffer_idx] = '\0';
		buffer_idx = 0 ;
		uart_flag = 1;
	}
	else
	{
		buffer_idx++;
	}
}

volatile u16 adc_data=0;
volatile u8 ADC_flag=0;

void ADC_INTERUPTHANDLEER(void)
{
	adc_data =ADC_u16GETADC_DATA();
	ADC_flag=1;
	ADC_StartConversion(ADC7);
}

void stop_void(void)
{
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 , DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN2 , DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN3 , DIO_LOW);
}

int main()
{
	LCD_vidinit();

	UART_voidInit();
	UART_voidSetBaudRate(9600);
	UART_voidRegisterCallback(0,uart_cbk);

	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN2 , DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN3 , DIO_OUTPUT);

	ADC_voidSetCallback(ADC_INTERUPTHANDLEER);
	ADC_voidInit();
	ADC_StartConversion(ADC7);

	GIE_voidEnable();
	UART_voidSendString("Hello My Friend \r\n");
	LCD_vidsetcursorposition(1,0);
	LCD_printstring("Temp: ");

	u16 TEmperature=0;

	while(1)
	{
		if (ADC_flag==1)
		{
			ADC_flag=0;
			ADC_StartConversion(7);
			TEmperature=(adc_data*(u16)500)/1024;
			LCD_vidsetcursorposition(1,7);
			LCD_printstring("         ");
			if(TEmperature < 40)
			{
				LCD_vidsetcursorposition(1,7);
				LCD_vidprintNumber(TEmperature);
			}
			else
			{
				LCD_vidsetcursorposition(1,7);
				LCD_printstring("Warning");
				stop_void();
			}

			_delay_ms(100);
		}

		if (uart_flag == 1) {
			stop_void();
			LCD_vidsetcursorposition(0,0);
			LCD_printstring("        ");
			LCD_vidsetcursorposition(0,0);
			switch(buffer[0])
			{
			case 'f':
				DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
				LCD_printstring("Forward");
				break;
			case 'b':
				DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 , DIO_HIGH);
				LCD_printstring("Backword");
				break;
			case 'r':
				DIO_voidSetPinValue(DIO_PORTA , DIO_PIN2 , DIO_HIGH);
				LCD_printstring("Right");
				break;
			case 'l':
				DIO_voidSetPinValue(DIO_PORTA , DIO_PIN3 , DIO_HIGH);
				LCD_printstring("Left");
				break;
			case 's':
				stop_void();
				LCD_printstring("Stop");
				break;
			default:
				UART_voidSendString("Wrong answer\r\n") ;
				LCD_printstring("Wrong answer");
				break;
			}
			UART_voidSendString(buffer) ;
			UART_voidTransmitByte_synch('\r');
			uart_flag = 0;
		}
	}
}
