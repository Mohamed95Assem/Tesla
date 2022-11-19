/*
 * GIE_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: moham
 */

#include "../00-Lib/STD_TYPES.h"
#include "../00-Lib/BIT_MATH.h"

#include "../01-DIO/DIO_Interface.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , I_BIT);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG , I_BIT);
}
