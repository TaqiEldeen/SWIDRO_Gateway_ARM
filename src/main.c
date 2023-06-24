/*
 * main.c
 *
 *  Created on: 28 Apr 2023
 *      Author: TaqiEldeen
 */


/*			LIB Inclusion			*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*			MCAL Inclusion			*/
#include "RCC_int.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "EXTI_int.h"
#include "NVIC_int.h"
#include "SYSTICK_int.h"
#include "UART_int.h"

/*			HAL Inclusion			*/
#include "HC_int.h"


void HC_vHandler( u16 A_u16Data );
void ESP_vHandler( u16 A_u16Data );
static void delay();
volatile u8 str[50];

static volatile u8 G_u8StartFlag = 0;	/* For indicating a new device has started */

void main(void) {
	/* Init System Clock:
	 *
	 * PLL -> x4 = 32 MHZ
	 * AHB 		-> 32 MHZ
	 * APB1 / 4 -> 8 MHZ
	 * APB2 / 4 -> 8 MHZ
	 *  */
	RCC_vInitSysClk();

	RCC_vEnableClk( RCC_APB2, IOPA );		/* Enable PORTA CLK: (For UART 1 & 2) */
	RCC_vEnableClk( RCC_APB2, USART1 );		/* Enable USART1 CLK */
	RCC_vEnableClk( RCC_APB1, USART2 );		/* Enable USART2 CLK */

	

	DIO_vSetPinMode( PORTA_ID, PIN0_ID, OUTPUT_2MHZ_PP );	/* For LED */

	DIO_vSetPinVal( PORTA_ID, PIN0_ID, VAL_HIGH );

	HC_vInit();		/* Init UART anyway */

	//HC_vSendDataAsync()

	HC_u8ReceiveDataAsync( HC_vHandler );	/* USART1 Callback */

	NVIC_vEnableInterrupt( NVIC_USART1 );	/* Enable USART1 Interrupt */

	UART_vSetCallBack( ESP_vHandler, UART2_ID );

	while (1) {

	}
}

static void delay() {
	for(u16 i=0; i<700; i++) {
		for(u16 i=0; i<700; i++) {
			asm("NOP");
		}
	}
}

void ESP_vHandler( u16 A_u16Data ) {

}

void HC_vHandler( u16 A_u16Data ) {
	static u8 counter = 0;
	if(A_u16Data != '$') {
		str[counter] = (u8) A_u16Data;
		counter++;
	} else {
		str[counter] = '\n';				/* Terminating char at ESP-01*/
		counter++;

		str[counter] = '\0';				/* Terminating char for string */
		counter++;
		UART_vSendString(str, UART2_ID);	/* Send the recieved data to ESP-01*/
		counter = 0;						/* Reset the index */

		DIO_vTogPinVal( PORTA_ID, PIN0_ID );	/* Indication: Not Yet Flashed */
	}
}
