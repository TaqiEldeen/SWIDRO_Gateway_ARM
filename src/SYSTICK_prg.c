/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/

/*  LIB Inclusion   */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  Module Inclusion   */
#include "SYSTICK_pri.h"
#include "SYSTICK_cfg.h"
#include "SYSTICK_int.h"
#include "SYSTICK_reg.h"

static ptr_func_t SYSTICK_CallBack = ADDRESS_NULL;

/**********************************************************************************************************
 * Description : Interface Function to Initialize the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vInit(void) {
    SYSTICK-> CTRL = 0;                       /* Clear CTRL */
    SYSTICK-> LOAD = SYSTICK_RELOAD_VALUE;    /* Set the maximum value */   
    SYSTICK-> VAL  = 0;                       /* Clear the current value */
    SYSTICK-> CTRL |= (SYSTICK_ENABLE << ENABLE)              /* Enable the counter */
                    | (SYSTICK_INTERRUPT << TICKINT)          /* Enable the interrupt */
                    | (SYSTICK_CLKSOURCE << CLKSOURCE);       /* Select the clock source */
}

/**********************************************************************************************************
 * Description : Interface Function to Turn on the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vTurnOn(void) {
    SET_BIT(SYSTICK-> CTRL, ENABLE);
}

/**********************************************************************************************************
 * Description : Interface Function to Turn off the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vTurnOff(void) {
    CLR_BIT(SYSTICK-> CTRL, ENABLE);
}

/**********************************************************************************************************
 * Description : Interface Function to Set the Reload Value
 * Outputs     : void
 * Inputs      : Reload Value
 ***********************************************************************************************************/
void SYSTICK_vSetReload(u32 A_u32Ticks){
    SYSTICK-> LOAD = A_u32Ticks;
}

/**********************************************************************************************************
 * Description : Interface Function to Get the Reload Value
 * Outputs     : Reload Value
 * Inputs      : void
 ***********************************************************************************************************/
u32 SYSTICK_u32GetElapsedTicks(void) {
    return ( (SYSTICK->LOAD) - (SYSTICK-> VAL) );
}

/**********************************************************************************************************
 * Description : Interface Function to Get the Remaining Ticks
 * Outputs     : Remaining Ticks
 * Inputs      : void
 ***********************************************************************************************************/
u32 SYSTICK_u32GetRemainingTicks(void) {
    return (SYSTICK-> VAL);
}

/**********************************************************************************************************
 * Description : Interface Function to Set the Call Back Function
 * Outputs     : void
 * Inputs      : Pointer to the Call Back Function
 ***********************************************************************************************************/
void SYSTICK_vSetCallBack(ptr_func_t A_ptr_func){
    SYSTICK_CallBack = A_ptr_func;
}

/**********************************************************************************************************
 * Description : Interrupt Service Routine for the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SysTick_Handler(void) {
    if (SYSTICK_CallBack != ADDRESS_NULL) {
        SYSTICK_CallBack();
    } else {
        /*  Do Nothing  */
    }
}