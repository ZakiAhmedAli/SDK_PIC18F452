/*
*     Author      : Zaki Ahmed hamed                                                    
*     Description : ADC_interface.h for ADC file contain public functions and public macros                                            
*     Date        : 07 December 2020                                                         
*     Version     : V01                                                                 
*/

/******************************************************************************
*    Description : Guard to protect this file to include more than one time   *
******************************************************************************/

#ifndef  _ADC_INTERFACE_H
#define  _ADC_INTERFACE_H


/* A/D Conversion Clock Select bits */

typedef enum
{       
    FOSC_DIV_2    ,
    FOSC_DIV_8    ,
    FOSC_DIV_32   ,
    FRC           ,
    FOSC_DIV_4    ,
    FOSC_DIV_16   ,
    FOSC_DIV_64
        
}Fosc_t;

/* Analog Channel Select Macros*/


typedef enum
{
        Channel_0 =0 ,
        Channel_1         ,
        Channel_2         ,
        Channel_3         ,
        Channel_4         ,
        Channel_5         ,
        Channel_6         ,
        Channel_7

}Channel_t;


void ADC_VoidInit(Fosc_t Prescal);

u16 ADC_U16Read(Channel_t channel);

#endif //_ADC_INTERFACE_H