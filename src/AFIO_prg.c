/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: AFIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB Inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          Moudlue Inclusion           */
#include "AFIO_pri.h"
#include "AFIO_cfg.h"
#include "AFIO_int.h"
#include "AFIO_reg.h"

/**********************************************************************************************************
 * Description : Interface Function to select the needed pin for a line (EXTI)
 * Outputs     : void
 * Inputs      : Needed line, needed pin
 ***********************************************************************************************************/
void AFIO_vSetEXTICfg(u8 A_u8Line, u8 A_u8PinId){
    u8 L_u8Index = 0;

    if(A_u8Line < 4)        L_u8Index = 0;  /*  First four lines */
    else if(A_u8Line < 8)   L_u8Index = 1;
    else if(A_u8Line < 12)  L_u8Index = 2;
    else if(A_u8Line < 16)  L_u8Index = 3;
    else {}/* Shouldn't be here! */

    if(A_u8Line > 4) {

    }
    A_u8Line %= 4;  /* Map the line to be in correct position. EX: line 15 % 4 -> 3 -> 3*4 -> 12 which is the correct index */
    AFIO->EXTICR[L_u8Index] &= ~(0xF       << (A_u8Line * 4));   /* Clear the prev cfg */
    AFIO->EXTICR[L_u8Index] |=  (A_u8PinId << (A_u8Line * 4));   /* Set the new cfg */    
}
