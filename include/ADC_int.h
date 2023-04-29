/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: ADC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 22 APRIL 2023	 	**************/
/*********************************************************/
#ifndef ADC_INT_H
#define ADC_INT_H

void ADC_vInit(void);
u16 ADC_u16ReadSync(u8 A_u8Channel, u8 A_u8Sequence);


#endif  /* ADC_INT_H_ */