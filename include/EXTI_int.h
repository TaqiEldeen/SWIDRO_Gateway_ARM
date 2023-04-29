/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/
#ifndef EXTI_INT_H
#define EXTI_INT_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_pri.h"
#include "EXTI_reg.h"
#include "EXTI_cfg.h"

/*
 EXTI line 16 is connected to the PVD output
 EXTI line 17 is connected to the RTC Alarm event
 EXTI line 18 is connected to the USB Wakeup event
 EXTI line 19 is connected to the Ethernet Wakeup event (available only in connectivity line devices)
*/

/* Use this as the line needed */
typedef enum
{
    EXTI_0,
    EXTI_1,
    EXTI_2,
    EXTI_3,
    EXTI_4,
    EXTI_5,
    EXTI_6,
    EXTI_7,
    EXTI_8,
    EXTI_9,
    EXTI_10,
    EXTI_11,
    EXTI_12,
    EXTI_13,
    EXTI_14,
    EXTI_15
}EXTI_Line_t;

/**********************************************************************************************************
 * Description : Interface Function to Intialize the EXTI
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void EXTI_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to Enable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vEnable(u8 A_u8Line);

/**********************************************************************************************************
 * Description : Interface Function to Disable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vDisable(u8 A_u8Line);

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Sense Control
 * Outputs     : void
 * Inputs      : line number, sense control
 ***********************************************************************************************************/
void EXTI_vSetSenseControl(u8 A_u8Line, u8 A_u8SenseControl);

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Callback
 * Outputs     : void
 * Inputs      : pointer to function, line number
 ***********************************************************************************************************/
void EXTI_vSetCallback(u8 A_u8Line, ptr_func_t);

#endif  /* EXTI_INT_H */