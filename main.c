/*
 * main.c
 *
 *  Created on: May 31, 2023
 *      Author: A-plus store
 */


#include "BIT_Math.h"
#include "STD_TYPES.h"


#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"


void Delay(void);

int main (void)
{
	
	__asm volatile ("MSR MSP , R3");

	MRCC_voidInitSystemClk();
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERAL_EN_GPIOA);

	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN1, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputType(MGPIOA_PORT, MGPIO_PIN1, MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutputSpeed(MGPIOA_PORT, MGPIO_PIN1, MGPIO_OUTPUT_SPEED_HIGH);


	while(1)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_HIGH);
	}
	return 0;
}
void Delay(void)
{
	//Empty for loop
	for (u16 i=0 ; i < 2500000 ; i++ )
	{
		//inline assembly code
		//Assembly Instru With c Code
		//Compiler Directive  => asm "assembly inst"
		asm("NOP");
	}
}
