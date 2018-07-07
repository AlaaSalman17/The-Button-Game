/*
 * GPIO.h
 *
 * Created: 7/8/2018 1:43:46 AM
 *  Author: Alaa Salman
 */ 


#ifndef GPIO_H_
#define GPIO_H_

typedef struct
{
	unsigned char PortId;
	unsigned char GroupMask;
	unsigned char GroupDir;
	unsigned char UsePullUp;
}GPIO_ConfigType;

void GPIO_Init(void);
void GPIO_Write(unsigned char Data, unsigned char GroupId);
unsigned char GPIO_Read(unsigned char GroupId);




#endif /* GPIO_H_ */