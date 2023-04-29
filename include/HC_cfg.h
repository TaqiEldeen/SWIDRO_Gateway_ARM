/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: HC-12		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 06/11/2022	 	**************/
/*********************************************************/


#ifndef HC_CFG_H_
#define HC_CFG_H_

/***********		SET pin is used to set commands	 	**************/
#define HC_SET_PIN	PIN6_ID
#define HC_SET_PORT	PORTD_ID


#define HC_UART_ID    UART1_ID


/* HC-12 modes
 *
 * Options:
 * 1- FU1	-> Moderate power saving mode
 * 2- FU2	-> Extreme power saving mode,
 * 3- FU3	-> Default	
 * 4- FU4	-> maximum range (1200bps)
 * */
#define HC_MODE	FU3

/* HC-12 Channel select
 *
 * Options:
 *  select a channel from C001 to C100 in form of string i.e. for channel one: "1"
 * */
#define HC_CHANNEL_SELECT	"AT+C001"

/* HC-12 Transmitting power select
 *
 * Options:
 * 1- PW_NEG_1DB
 * 2- PW_2DB
 * 3- PW_5DB
 * 4- PW_8DB
 * 5- PW_11DB
 * 6- PW_14DB
 * 7- PW_17DB
 * 8- PW_20DB
 * */
#define HC_PW_SELECT	PW_14DB

#define HC_SLEEP	"AT+SLEEP"



#endif /* HC_CFG_H_ */
