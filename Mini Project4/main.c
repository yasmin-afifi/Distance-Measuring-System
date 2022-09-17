 /******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Source file for Main
 *
 * Author: Yasmin Khaled
 *
 *******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */

extern uint8 g_edgeCount;

int main(void)
{
	uint16 distance = 0;

	/* Initialize both the LCD and Ultrasonic driver */
	LCD_init();
	Ultrasonic_init();

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	while(1)
	{
		if(g_edgeCount == 2)
		{
			Icu_DeInit(); /* Disable ICU Driver */
			g_edgeCount = 0;
			LCD_displayString("Distance= ");
			/* get the calculated distance */
			distance = Ultrasonic_readDistance();

			/* display the distance on LCD screen */
			LCD_intgerToString(distance);
			LCD_displayString("cm");
		}
	}

}
