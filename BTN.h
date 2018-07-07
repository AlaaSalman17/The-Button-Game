/*
 * BTN.h
 *
 * Created: 7/8/2018 1:49:24 AM
 *  Author: Alaa Salman
 */ 


#ifndef BTN_H_
#define BTN_H_

#define ON 1
#define OFF 0
#define  confidenceLevel 200
typedef enum {BTN_ACTIVE = 0, BTN_INACTIVE=1} BTN_StatusType;
void BTN_Init(void);
BTN_StatusType BTN_GetStatus(unsigned char BtnId);
char ButtonPressed(unsigned char BtnId);


#endif /* BTN_H_ */