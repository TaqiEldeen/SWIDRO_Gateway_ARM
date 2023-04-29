/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/
#ifndef SYSTICK_INT_H
#define SYSTICK_INT_H

/**********************************************************************************************************
 * Description : Interface Function to Initialize the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to Set the Reload Value
 * Outputs     : void
 * Inputs      : Reload Value
 ***********************************************************************************************************/
void SYSTICK_vSetReload(u32 A_u32Ticks);

/**********************************************************************************************************
 * Description : Interface Function to Get the Reload Value
 * Outputs     : Reload Value
 * Inputs      : void
 ***********************************************************************************************************/
u32 SYSTICK_u32GetElapsedTicks(void);

/**********************************************************************************************************
 * Description : Interface Function to Get the Remaining Ticks
 * Outputs     : Remaining Ticks
 * Inputs      : void
 ***********************************************************************************************************/
u32 SYSTICK_u32GetRemainingTicks(void);

/**********************************************************************************************************
 * Description : Interface Function to turn off the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vTurnOff(void);

/**********************************************************************************************************
 * Description : Interface Function to turn on the SYSTICK
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SYSTICK_vTurnOn(void);

/**********************************************************************************************************
 * Description : Interface Function to Set the Call Back Function
 * Outputs     : void
 * Inputs      : Pointer to the Call Back Function
 ***********************************************************************************************************/
void SYSTICK_vSetCallBack(ptr_func_t A_ptr_func);

#endif // SYSTICK_INT_H