/*
 * BTN.c
 *
 * Created: 7/8/2018 1:49:14 AM
 *  Author: Alaa Salman
 */ 

#include "BTN.h"
#include "GPIO.h"
#include "BTN_CFG.h"
extern const unsigned char BTN_Config[BTNS_NUMBER] ;
unsigned char state[BTNS_NUMBER];
void BTN_Init(void)
{
	int i=0;
	for (i=0;i<BTNS_NUMBER;i++)
	{
		state[i]=OFF;
	}
	
	
	
}
BTN_StatusType BTN_GetStatus(unsigned char BtnId)
{
	BTN_StatusType output=0;
	unsigned input = GPIO_Read(BTN_Config[BtnId]);
	switch (state[BtnId])
	{
		case OFF:
		if (input ==0)
		{
			output=BTN_INACTIVE;
		}
		else
		{
			output=BTN_ACTIVE;
			state[BtnId]=ON;
		}
		break;
		
		case ON :
		if ( input==1 )
		{
			output=BTN_INACTIVE;
		}
		else
		{
			output=BTN_INACTIVE;
			state[BtnId]=OFF;
		}
		break;
	}
	return output;
}




char Pressed[ BTNS_NUMBER];
int Pressed_Confidence_Level[ BTNS_NUMBER]; //Measure button press cofidence
int Released_Confidence_Level[ BTNS_NUMBER]; //Measure button release confidence

char ButtonPressed(unsigned char BtnId)
{
	if (GPIO_Read(BTN_Config[BtnId]))
	{
		Pressed_Confidence_Level[BtnId] ++; //Increase Pressed Conficence
		Released_Confidence_Level[BtnId] = 0; //Reset released button confidence since there is a button press
		if (Pressed_Confidence_Level[BtnId] > confidenceLevel) //Indicator of good button press
		{
			if (Pressed[BtnId] == 0)
			{
				Pressed[BtnId] = 1;
				return 1;
			}
			//Zero it so a new pressed condition can be evaluated
			Pressed_Confidence_Level[BtnId] = 0;
		}
	}
	else
	{
		Released_Confidence_Level[BtnId] ++; //This works just like the pressed
		Pressed_Confidence_Level[BtnId] = 0; //Reset pressed button confidence since the button is released
		if (Released_Confidence_Level[BtnId] > confidenceLevel)
		{
			Pressed[BtnId] = 0;
			Released_Confidence_Level[BtnId] = 0;
		}
	}
	return 0;
}
