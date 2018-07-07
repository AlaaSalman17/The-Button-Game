/*
 * LED.h
 *
 * Created: 7/8/2018 1:45:59 AM
 *  Author: Alaa Salman
 */ 


#ifndef LED_H_
#define LED_H_


typedef enum {ACTIVE_LOW = 0, ACTIVE_HIGH = 0xff} LedType;
typedef struct
{
	unsigned char LedGroupId;
	LedType Connection;
}LED_ConfigType;
void LED_TurnOn(unsigned char LedId);
void LED_TurnOff(unsigned char LedId);
void LED_Toggle(unsigned char LedId);


#endif /* LED_H_ */