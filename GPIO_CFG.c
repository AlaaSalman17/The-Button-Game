/*
 * GPIO_CFG.c
 *
 * Created: 7/8/2018 1:44:13 AM
 *  Author: Alaa Salman
 */ 

#include "GPIO.H"
#include "GPIO_CFG.H"
GPIO_ConfigType GPIO_Param[GROUPS_NUM] =
{
	{
		0,0x01 ,0xff,0x00
	},
	{
		0,0x02 ,0xff,0x00
	},
	{
		0,0x04 ,0xff,0x00
	},
	{
		0,0x08 ,0xff,0x00
	},
	{
		0,0x10 ,0xff,0x00
	},
	{
		0,0x20 ,0xff,0x00
	},
	{
		0,0x40 ,0xff,0x00
	},
	{
		2,0x01 ,0xff,0x00
	},
	{
		2,0x02 ,0xff,0x00
	},
	{
		2,0x04 ,0xff,0x00
	},
	{
		2,0x08 ,0xff,0x00
	},
	{
		2,0x10 ,0xff,0x00
	},
	{
		2,0x20 ,0xff,0x00
	},
	{
		2,0x40 ,0xff,0x00
	},
	{
		0,0x80,0x00,0x00
	},
	{
		2,0x80,0x00,0x00
	}
};