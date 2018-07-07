/*
 * LED.c
 *
 * Created: 7/8/2018 1:45:49 AM
 *  Author: Alaa Salman
 */ 
#include "LED.h"
#include "LED_CFG.h"
#include "GPIO.h"
#include "GPIO_CFG.h"
extern const LED_ConfigType LED_Config[LEDS_NUMBER];

unsigned char data;
void LED_TurnOn(unsigned char LedId){

	data =  LED_Config[LedId].Connection;
	GPIO_Write(data,LED_Config[LedId].LedGroupId);
}

void LED_TurnOff(unsigned char LedId){
	data = ~(LED_Config[LedId].Connection);
	GPIO_Write(data,LED_Config[LedId].LedGroupId);
}

void LED_Toggle(unsigned char LedId){
	unsigned char previous_data = GPIO_Read(LedId);
	if(previous_data==0)
	LED_TurnOn(LedId);
	else
	LED_TurnOff(LedId);
}