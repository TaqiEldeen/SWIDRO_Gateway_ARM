/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_INT_H
#define UART_INT_H

typedef enum {
    UART1_ID,
    UART2_ID,
    UART3_ID
}UART_ENUM;

/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void UART_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to Send a Byte
 * Outputs     : void
 * Inputs      : Byte to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendByte(u8 A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Send a String
 * Outputs     : void
 * Inputs      : String to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Receive a Byte
 * Outputs     : Received Byte
 * Inputs      : UART ID
 ***********************************************************************************************************/
u8 UART_u8ReceiveByte(UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Receive a String
 * Outputs     : void
 * Inputs      : String to be received, UART ID
 ***********************************************************************************************************/
void UART_vReceiveString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Set Call Back Function
 * Outputs     : void
 * Inputs      : Pointer to Call Back Function, UART ID
 ***********************************************************************************************************/
void UART_vSetCallBack(ptr_func_Iu16_Ov A_ptr, UART_ENUM A_u8UartId);


#endif /* UART_INT_H */