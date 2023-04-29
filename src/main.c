/*
 * main.c
 *
 *  Created on: 28 Apr 2023
 *      Author: 20109
 */


/*			LIB Inclusion			*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*			HAL Inclusion			*/
#include "HC_int.h"

/*			MCAL Inclusion			*/
#include "RCC_int.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "EXTI_int.h"
#include "NVIC_int.h"
#include "SYSTICK_int.h"
#include "UART_int.h"

void HC_vHandler( u16 A_u16Data );
void ESP_vHandler( u16 A_u16Data );

void main(void) {
	/* Init System Clock */
	RCC_vInitSysClk();

	RCC_vEnableClk( RCC_APB2, IOPA );		/* Enable PORTA CLK: (For UART 1 & 2) */
	RCC_vEnableClk( RCC_APB2, USART1 );		/* Enable USART1 CLK */
	RCC_vEnableClk( RCC_APB1, USART2 );		/* Enable USART2 CLK */

	NVIC_vEnableInterrupt( NVIC_USART1 );	/* Enable USART Interrupt */

	DIO_vSetPinMode( PORTA_ID, PIN0_ID, OUTPUT_2MHZ_PP);	/* For LED */

	DIO_vSetPinVal( PORTA_ID, PIN0_ID, VAL_HIGH );

	HC_vInit();		/* Init UART anyway */
	UART_vSetCallBack( HC_vHandler, UART1_ID );

	while (1) {
	}

}

void ESP_vHandler( u16 A_u16Data ) {

}

void HC_vHandler( u16 A_u16Data ) {
	DIO_vTogPinVal( PORTA_ID, PIN0_ID );
	UART_vSendByte(A_u16Data, UART2_ID);
}
