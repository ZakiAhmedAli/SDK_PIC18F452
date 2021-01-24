/*********************************************************************************
*     Author      : Zaki Ahmed hamed                                             *
*     Description : Contain memory mapped of([ADMUX,ADCSRA,ADCH,ADCL] Registers) *
*     Date        : 07 December 2020                                             *
*     Version     : V01                                                          *
*********************************************************************************/




/******************************************************************************
*     Description : Guard to Protect this file from include more than one time*
******************************************************************************/

#ifndef    ADC_PRIVATE_H
#define    ADC_PRIVATE_H


/************************************************************************************
*     Description : from data sheet memory mapped register                          *
************************************************************************************/

#define ADCON0	*((volatile u8*)(0xFC2))

#define ADCON1	*((volatile u8*)(0xFC1))

#define ADCRESL	*((volatile u8*)(0xFC3))

#define ADCRESH	*((volatile u8*)(0xFC4))


/*ADCON0 REGISTER BITS*/

#define		ADCS1 	7
#define		ADCS0 	6
#define		CHS2 	5
#define		CHS1 	4
#define		CHS0 	3
#define		DONE	2
#define		ADON	0

/*ADCON1 REGISTER BITS*/

#define		ADFM 	7
#define		ADCS2	6
#define		PCFG3 	3
#define		PCFG2 	2
#define		PCFG1 	1
#define		PCFG0	0


#endif //ADC_PRIVATE_H