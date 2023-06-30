/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: APP			 	**************/
/***********		Component: GTW			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 JUNE 2023	 	**************/
/*********************************************************/

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

/*          MODULE Inclusion          */
#include "GTW_pri.h"
#include "GTW_int.h"

/*          STD C LIB 			*/
#include <string.h>


/*          GLOBAL Variables            */

volatile u8 str[50];						/* Buffer for receving data from HC-12 */
static volatile u8 G_u8StartFlag = 0;		/* For indicating a new device has started */
static const u8 G_u8StartFrame[] = "START";	/* Each band must first send start frame */
static u8 G_u8Counter = 0;					/* To count the needed timeout */

/**
 * @brief 
 * 
 */
void GTW_vInit(){
    /* Init Sys clock */
    GTW_vInitSysClk();

    /* Init LED indication */
    GTW_vSetLedIndication();

    /* Init HC Module */
	HC_vInit();		

    /* USART1 Callback */
	HC_u8ReceiveDataAsync( GTW_vHcHandler );	

	NVIC_vSetPriority( NVIC_USART1, 1, 0);

    /* Enable USART1 Interrupt */
	NVIC_vEnableInterrupt( NVIC_USART1 );	

    /* USART2 Callback */
	UART_vSetCallBack( GTW_vEspHandler, UART2_ID );

    /* Enable USART2 Interrupt */
	NVIC_vEnableInterrupt( NVIC_USART2 );

	/* Init SYSTICK */
	SYSTICK_vInit();
}

/**
 * @brief 
 * 
 */
void GTW_vUpdate(){
	if( !G_u8StartFlag ) {
		if(strncmp(G_u8StartFrame, str, 5) == 0){
			G_u8StartFlag = 1 ;	/* The device is operating! */
			SYSTICK_vSetIntervalPeriodic( 8000000, GTW_vHandleTimeout );	/* 2 seconds */
			SYSTICK_vTurnOn();
			DIO_vSetPinVal( PORTA_ID, PIN0_ID, VAL_HIGH );
		} else {

		}	
	} else {
		/* The device is operating! */
	}
}

static void GTW_vInitSysClk(){
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
}

static void GTW_vEspHandler( u16 A_u16Data ) {
	/* Check status from the application */
}

static void GTW_vHcHandler( u16 A_u16Data ) {
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

		// DIO_vTogPinVal( PORTA_ID, PIN0_ID );	/* Indication */
	}

	/* Reset the timeout */
	SYSTICK_vReset();
	G_u8Counter = 0;
}

static void GTW_vSetLedIndication() {
    DIO_vSetPinMode( PORTA_ID, PIN0_ID, OUTPUT_2MHZ_PP );
}

static void GTW_vHandleTimeout(){
	G_u8Counter++;

	if(G_u8Counter >= 8) {	/* 16 seconds */
		/* Emergency!! */
		HC_vSendData('E');							/* To the band if possible */
		UART_vSendString("DROWNING!\n", UART2_ID);	/* To the application. TODO: Make ESP HAL driver */
		G_u8Counter--;								/* Just to make sure it wont overflow*/
		DIO_vTogPinVal( PORTA_ID, PIN0_ID );		/* Emergency LED */
	} else {
		DIO_vSetPinVal( PORTA_ID, PIN0_ID, VAL_LOW );		/* Emergency LED */
	}
}
