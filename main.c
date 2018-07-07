/*
 * TheButtonGame.c
 *
 * Created: 7/8/2018 1:42:51 AM
 * Author : Alaa Salman
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "GPIO.h"
#include "BTN.h"
#include "LED.h"


int main(void)
{
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	GPIO_Init();
	BTN_Init();
	int i=0,j=7;
	int Pressed = 0;
	int Pressed_Confidence_Level = 0; //Measure button press cofidence
	int Released_Confidence_Level = 0; //Measure button release confidence
	while(1){
		if(ButtonPressed(0))
		{
			LED_TurnOn(i);
			i++;
		}
		if (ButtonPressed(1))
		{
			LED_TurnOn(j);
			j++;
		}
		if(i==7 || j==14)
		{
			if (i==7)
			{
				int j=0;
				while(j<50)
				for(i=0;i<7;i++)
				{
					LED_Toggle(i);
					_delay_ms(100);
				}
				j++;
				break;
			}
			if (j==14)
			{
				int j=0;
				while(j<50)
				for(i=7;i<14;i++)
				{
					LED_Toggle(i);
					_delay_ms(100);
				}
				j++;
				break;
			}
		}
		
	}

}
