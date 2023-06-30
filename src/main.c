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
#include <stdio.h>
#include "GTW_int.h"

void main(void) {
	/* Init the gateway */
	GTW_vInit();

	while (1) {
		GTW_vUpdate();
	}
	
}
