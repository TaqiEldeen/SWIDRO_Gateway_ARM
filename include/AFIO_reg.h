/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: AFIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef AFIO_REG_H
#define AFIO_REG_H

#define AFIO_BASE_ADDRESS	0x40010000

typedef struct
{
    volatile u32 EVCR;      // Event control register
    volatile u32 MAPR;      // AF remap and debug I/O configuration register
    volatile u32 EXTICR[4]; // External interrupt configuration registers
    volatile u32 MAPR2;     // AF remap and debug I/O configuration register2
}AFIO_t;

#define AFIO ((volatile AFIO_t *) AFIO_BASE_ADDRESS)

#endif /* AFIO_REG_H */