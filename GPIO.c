/*
 * GPIO.c
 *
 * Created: 7/8/2018 1:43:31 AM
 *  Author: Alaa Salman
 */ 

#include "GPIO.h"
#include "GPIO_CFG.h"
#define PORT(CH_ID) *((volatile unsigned char*)(0x3b - (3*CH_ID) - 0x00))
#define DDR(CH_ID) *((volatile unsigned char*)(0x3b - (3*CH_ID) - 0x01))
#define PIN(CH_ID) *((volatile unsigned char*)(0x3b - (3*CH_ID) - 0x02))
extern GPIO_ConfigType GPIO_Param[GROUPS_NUM];
void GPIO_Init(void)
{
	int i;
	for(i = 0; i < GROUPS_NUM; i++)
	{
		DDR(GPIO_Param[i].PortId) |= (GPIO_Param[i].GroupMask & GPIO_Param[i].GroupDir);
		PORT(GPIO_Param[i].PortId) |= (GPIO_Param[i].GroupMask & GPIO_Param[i].UsePullUp) & (~GPIO_Param[i].GroupDir) ;
	}
	
}
void GPIO_Write(unsigned char Data, unsigned char GroupId)
{
	PORT(GPIO_Param[GroupId].PortId) &=~(GPIO_Param[GroupId].GroupMask);
	PORT(GPIO_Param[GroupId].PortId) |= (Data & GPIO_Param[GroupId].GroupMask);
}

unsigned char GPIO_Read(unsigned char GroupId)
{
	return 	PIN(GPIO_Param[GroupId].PortId) & GPIO_Param[GroupId].GroupMask;
}