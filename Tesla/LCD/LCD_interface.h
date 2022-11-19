/*
 * LCD_interface.h
 *
 *  Created on: Apr 12, 2022
 *      Author: elgendy
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_
void LCD_vidinit(void);

void LCD_vidsendcommend(u8 cpy_u8command);

void LCD_vidsendchar(u8 cpy_u8charachter);

void LCD_printstring(char *cpy_u8str);
void LCD_vidclearLCD(void);

void LCD_vidprintNumber(u32 num);


void LCD_vidsetcursorposition(u8 cpy_u8linenum , u8 cpy_u8charpos);

void LCD_vidsavecustomchar(u8 u8_arr[],u8 cpy_u8CGRAM_addr);
#endif /* LCD_LCD_INTERFACE_H_ */
