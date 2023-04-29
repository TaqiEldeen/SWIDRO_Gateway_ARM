/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: HC-12		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 06/11/2022	 	**************/
/*********************************************************/

/*		LIB Inclusion		*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*		MCAL Inclusion		*/
#include "UART_int.h"
#include "DIO_int.h"

/*		Module Inclusion		*/
#include "HC_pri.h"
#include "HC_cfg.h"
#include "HC_int.h"
#include <string.h>

/**********************************************************************************************************
 * Description : Interface Function to initialize the HC-12 based on the configuration
 * Outputs     : void
 * Inputs      : void
 * NOTES	   : 1-from UART data sheet do not set global interrupts before calling initialize
 * 				 2-If willing to use interrupt use HC_u8ReceiveDataAsync before this function
 ***********************************************************************************************************/
void HC_vInit(){
//	DIO_vSetPinDir(HC_SET_PORT, HC_SET_PIN, DIR_OUTPUT);
//	/*Energize the SET pin*/
//	DIO_vSetPinVal(HC_SET_PORT, HC_SET_PIN, VAL_HIGH);
//	/*Initialize the UART*/
	UART_vInit();
}

/**********************************************************************************************************
 * Description : Interface Function to send data through HC-12 Sync
 * Outputs     : void
 * Inputs      : Data
 ***********************************************************************************************************/
void HC_vSendData(u8 A_u8Data){
	UART_vSendByte(A_u8Data, HC_UART_ID);
}

/**********************************************************************************************************
 * Description : Interface Function to receive data async
 * Outputs     : void
 * Inputs      : the function of input u16
 * NOTES	   : Enable global interrupts before using this function
 ***********************************************************************************************************/
void HC_u8ReceiveDataAsync(ptr_func_Iu16_Ov ptr){
	UART_vSetCallBack(ptr, HC_UART_ID);
}

/**********************************************************************************************************
 * Description : Interface Function to send data through HC-12
 * Outputs     : void
 * Inputs      : Data
 ***********************************************************************************************************/
void HC_vSendString(u8 *A_u8Data){
	UART_vSendString(A_u8Data, HC_UART_ID);
}

/**********************************************************************************************************
 * Description : Interface Function to Receive data sync
 * Outputs     : void
 * Inputs      : void
 * NOTES	   : 
 ***********************************************************************************************************/
u8 HC_u8ReceiveDataSync(){
	return UART_u8ReceiveByte( HC_UART_ID );
}
