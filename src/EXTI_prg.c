/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/

/*      LIB Inclusion       */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*      Module Inclusion      */
#include "EXTI_pri.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"


/**********************************************************************************************************
 * Description : Interface Function to Intialize the EXTI
 * Outputs     : void
 * Inputs      : void
 * NOTES       : To Enable the EXTI, you have to use the EXTI_vEnable function
 ***********************************************************************************************************/
void EXTI_vInit(void) {
    /* Disable all EXTI */
    EXTI->IMR = 0x00000000;
    /* Clear all EXTI */
    EXTI->PR = 0x00000000;
    /* Disable all EXTI SenseControl */
    EXTI->RTSR = 0x00000000;
    EXTI->FTSR = 0x00000000;

    /* Set EXTI Sense Control */
    EXTI_vSetSenseControl(EXTI_0,  EXTI_SENSE_CONTROL_LINE0);
    EXTI_vSetSenseControl(EXTI_1,  EXTI_SENSE_CONTROL_LINE1);
    EXTI_vSetSenseControl(EXTI_2,  EXTI_SENSE_CONTROL_LINE2);
    EXTI_vSetSenseControl(EXTI_3,  EXTI_SENSE_CONTROL_LINE3);
    EXTI_vSetSenseControl(EXTI_4,  EXTI_SENSE_CONTROL_LINE4);
    EXTI_vSetSenseControl(EXTI_5,  EXTI_SENSE_CONTROL_LINE5);
    EXTI_vSetSenseControl(EXTI_6,  EXTI_SENSE_CONTROL_LINE6);
    EXTI_vSetSenseControl(EXTI_7,  EXTI_SENSE_CONTROL_LINE7);
    EXTI_vSetSenseControl(EXTI_8,  EXTI_SENSE_CONTROL_LINE8);
    EXTI_vSetSenseControl(EXTI_9,  EXTI_SENSE_CONTROL_LINE9);
    EXTI_vSetSenseControl(EXTI_10, EXTI_SENSE_CONTROL_LINE10);
    EXTI_vSetSenseControl(EXTI_11, EXTI_SENSE_CONTROL_LINE11);
    EXTI_vSetSenseControl(EXTI_12, EXTI_SENSE_CONTROL_LINE12);
    EXTI_vSetSenseControl(EXTI_13, EXTI_SENSE_CONTROL_LINE13);
    EXTI_vSetSenseControl(EXTI_14, EXTI_SENSE_CONTROL_LINE14);
    EXTI_vSetSenseControl(EXTI_15, EXTI_SENSE_CONTROL_LINE15);
}

/**********************************************************************************************************
 * Description : Interface Function to Enable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vEnable(u8 A_u8Line) {
    SET_BIT(EXTI->IMR, A_u8Line);
}

/**********************************************************************************************************
 * Description : Interface Function to Disable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vDisable(u8 A_u8Line){
    CLR_BIT(EXTI->IMR, A_u8Line);
}

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Sense Control
 * Outputs     : void
 * Inputs      : line number, sense control
 ***********************************************************************************************************/
void EXTI_vSetSenseControl(u8 A_u8Line, u8 A_u8SenseControl){
    switch(A_u8SenseControl){
        case EXTI_SENSE_CONTROL_RISING_EDGE:    SET_BIT(EXTI->RTSR, A_u8Line);  break;
        case EXTI_SENSE_CONTROL_FALLING_EDGE:   SET_BIT(EXTI->FTSR, A_u8Line);  break;
        case EXTI_SENSE_CONTROL_BOTH_EDGES:     SET_BIT(EXTI->RTSR, A_u8Line);  SET_BIT(EXTI->FTSR, A_u8Line);  break;
        default:
            break;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Callback
 * Outputs     : void
 * Inputs      : pointer to function, line number
 ***********************************************************************************************************/
void EXTI_vSetCallback(u8 A_u8Line, ptr_func_t);

/**********************************************************************************************************
 * Description : Interface Function to Clear the EXTI Pending Flag
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vSwTrigger(u8 A_u8Line) {
    SET_BIT(EXTI->SWIER, A_u8Line);
}