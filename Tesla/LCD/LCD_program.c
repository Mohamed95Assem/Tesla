/*
 * LCD_program.c
 *
 *  Created on: Apr 12, 2022
 *      Author: elgendy
 */
#include <util/delay.h>

#include "../00-LIB/STD_TYPES.h"

#include "../01-DIO/DIO_Interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_vidinit(void)
{
	//RS
	DIO_voidSetPinDirection(LCD_CTRL_port,LCD_RS_PIN ,DIO_OUTPUT);
	//RW
	DIO_voidSetPinDirection(LCD_CTRL_port,DIO_PIN1,DIO_OUTPUT);
	//E
	DIO_voidSetPinDirection(LCD_CTRL_port,DIO_PIN2,DIO_OUTPUT);
	//DATA pins
	DIO_voidSetPortDirection(LCD_DATA_port,0xff);

	_delay_ms(50);
	LCD_vidsendcommend(0b00111000);
	_delay_ms(1);
	LCD_vidsendcommend(0b00001100);
	_delay_ms(1);
	LCD_vidsendcommend(0b00000001);
	_delay_ms(3);
	LCD_vidsendcommend(0b00000110);
	_delay_ms(5);
}

void LCD_vidsendcommend(u8 cpy_u8command)
{
	//RS ->low
	DIO_voidSetPinValue(DIO_PORTB,LCD_RS_PIN ,DIO_LOW);
	//RW -> low
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
	//DB pins -> command
	DIO_voidSetPortValue(LCD_DATA_port,cpy_u8command);
	//pulse Enable
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	_delay_ms(1);

}
void LCD_vidsendchar(u8 cpy_u8charachter)
{

	//RS -> high
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	//RW -> low
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
	//DB pins -> command
	DIO_voidSetPortValue(LCD_DATA_port,cpy_u8charachter);
	//pulse Enable
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	_delay_ms(1);




}
void LCD_printstring(char cpy_u8str[])

{

	for (u8 i=0;cpy_u8str[i]!='\0';i++)
	{

		LCD_vidsendchar(cpy_u8str[i]);

	}
}

void LCD_vidclearLCD(void)
{
	LCD_vidsendcommend(0b00000001);

}

void LCD_vidprintNumber(u32 num)
{

	u8 digit_counter=0;
	u8 zero_flag=0;

	s32 rev=0;
	while(num>0)
	{
		rev=(rev*10)+(num%10);
		if (num%10 == 0 && zero_flag==0)
		{
			digit_counter++;
		}
		else
		{
			zero_flag=1;
		}
		num/=10;

	}
	while(rev>0)
	{

		LCD_vidsendchar((rev%10)+'0');
		rev/=10;
	}

	/*while(digit_counter>0)
	{
	LCD_vidsendchar('0');
	digit_counter--;


	}*/
	for(u8 i=0;i<digit_counter;i++)
	{

		LCD_vidsendchar('0');
	}

}






void LCD_vidsavecustomchar(u8 u8_arr[],u8 cpy_u8CGRAM_addr)
{
	if (cpy_u8CGRAM_addr<8)
	{
		LCD_vidsendcommend(0x40 + ( 8 * (cpy_u8CGRAM_addr)));

		for(u8 i=0; i<8;i++)
		{
			LCD_vidsendchar(u8_arr[i]);

		}
		LCD_vidsendcommend(0x80);
	}
}



void LCD_vidsetcursorposition(u8 cpy_u8linenum , u8 cpy_u8charpos)
{
	switch(cpy_u8linenum)
	{

	case 0:
		LCD_vidsendcommend(0x80 + cpy_u8charpos +0);
		break;
	case 1:
		LCD_vidsendcommend(0x80 + cpy_u8charpos +64);
		break;
	}
}
