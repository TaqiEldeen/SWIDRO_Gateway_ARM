/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: APP			 	**************/
/***********		Component: GTW			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 JUNE 2023	 	**************/
/*********************************************************/

#ifndef GTW_PRI_H
#define GTW_PRI_H

/**
 * @brief 
 * 
 * @param A_u16Data 
 */
static void GTW_vHcHandler( u16 A_u16Data );

/**
 * @brief 
 * 
 * @param A_u16Data 
 */
static void GTW_vEspHandler( u16 A_u16Data );

/**
 * @brief 
 * 
 */
static void GTW_vSetLedIndication();

/**
 * @brief 
 * 
 */
static void GTW_vHandleTimeout();

static void GTW_vInitSysClk();

#endif  /* GTW_PRI_H */
