/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: AFIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef AFIO_INT_H
#define AFIO_INT_H

/**********************************************************************************************************
 * Description : Interface Function to select the needed pin for a line (EXTI)
 * Outputs     : void
 * Inputs      : Needed line, needed pin
 ***********************************************************************************************************/
void AFIO_vSetEXTICfg(u8 A_u8Line, u8 A_u8PinId);

#endif /* AFIO_INT_H */