/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/
#ifndef EXTI_REG_H
#define EXTI_REG_H

#define EXTI_BASE_ADDRESS 0x40010400

typedef struct
{
    volatile u32 IMR;   // Interrupt Mask Register
    volatile u32 EMR;   // Event Mask Register
    volatile u32 RTSR;  // Rising Trigger Selection Register
    volatile u32 FTSR;  // Falling Trigger Selection Register
    volatile u32 SWIER; // Software Interrupt Event Register
    volatile u32 PR;    // Pending Register
}EXTI_t;

#define EXTI ((volatile EXTI_t *) EXTI_BASE_ADDRESS)

#endif /* EXTI_REG_H */