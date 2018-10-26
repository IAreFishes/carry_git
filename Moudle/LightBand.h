#ifndef __LightBand_H_
#define	__LightBand_H_

#include "stm32f4xx.h"
#include "can.h"

struct	lightband
{
	uint8_t 	site;
	uint16_t 	distance;
	uint8_t 	direction;

};

extern struct lightband LB_rx;
extern CAN_TX LightBand_Tx;
extern CAN_RX LightBand_Rx;




#endif



