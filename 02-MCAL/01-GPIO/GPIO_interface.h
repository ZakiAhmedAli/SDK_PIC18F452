/******************************************
*     Author      : Zaki Ahmed hamed      *
*     Description : GPIO Driver           *
*     Date        : 1 November 2020       *
*     Version     : 1.0                   *
******************************************/




/*************************************************************************************
*     Description : Guard to Protect this file from include more than one time       *
*                                                                                    *
*************************************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


/**********************************
 *     Include Header Files       *
 *********************************/
#include "STD_TYPES.h"


/*************************************************************************************
*     Description : PINS DEFINITION                                                                                                 *
*                                                                                    *
*************************************************************************************/

#define PIN0              0
#define PIN1              1
#define PIN2              2
#define PIN3              3
#define PIN4              4
#define PIN5              5
#define PIN6              6
#define PIN7              7

/*************************************************************************************
*     Description : PORT DEFINITIOS                                                  *
*                                                                                    *
*************************************************************************************/
#define GPIO_PORTA          0
#define GPIO_PORTB          1
#define GPIO_PORTC          2
#define GPIO_PORTD          3
#define GPIO_PORTE          4
/*************************************************************************************
*     Description : DEFINITIOS FOR DIO I/P AND O/P                                   *
*                                                                                    *
*************************************************************************************/

#define  GPIO_INPUT         1
#define  GPIO_OUTPUT        0

/*******************************************************
*     Description : DEFINITIOS FOR DIO HIGH AND LOW     *
*                                                      *
*******************************************************/

#define  GPIO_LOW         0
#define  GPIO_HIGH        1



 /**************************************************************************************/
 /* Description    :  This Function Set The Pin Direction in The Run Time              */
 /* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinDirection]                 */
 /* return         : void                                                              */
 /**************************************************************************************/

void GPIO_VoidSetPinDirection(u8 Cpy_u8PortID, u8 Cpy_u8PinNo , u8 Cpy_u8PinDirection);

/*********************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinLevel]    */
/* return         : void                                             */
/*********************************************************************/

void GPIO_VoidSetPinValue(u8 Cpy_u8PortID , u8 Cpy_u8PinNo , u8 Cpy_u8PinLevel);


/**************************************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time                  */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo]                                     */
/* return         : u8 Pin_Value High Or Low                                          */
/**************************************************************************************/
u8 GPIO_u8GetPinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo );

void GPIO_VoidTogglePinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo);

/**************************************************************************************/
/* Description    :  This Function Set The Port Direction in The Run Time             */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortDirection]                             */
/* return         : void                                                              */
/**************************************************************************************/
void GPIO_VoidSetPortDirecton(u8 Cpy_u8PortID , u8 Cpy_u8PortDirection);

/***********************************************************************/
/* Description    : This Function used to write values on BITS Value   */
/* Inputs         : Cpy_u8Port ,Cpy_u8Mask, Cpy_u8Value                */
/* return         : void                                               */
/***********************************************************************/
void GPIO_voidWriteBitsInPort(u8 Cpy_u8PortID ,  u8 Cpy_u8Mask , u8 Cpy_u8Value );

/*****************************************************************************/
/* Description    :  This Function Set The Port HIGH/LOW at Run Time         */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortValue]                        */
/* return         : void                                                     */
/*****************************************************************************/
void GPIO_VoidSetPortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue);

/*********************************************************************/
/* Description    :  This Function used to write value on port       */
/* Inputs         :  [port number,  PortValue]                       */
/* return         :  void                                            */
/*********************************************************************/
void GPIO_VoidWritePortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue);
/*************************************************************************/
/* Description    :  This Function Set The Port Value at The Run Time    */
/* Inputs         : [ Cpy_u8PortID]                                      */
/* return         : u8 Port_Value High Or Low                            */
/*************************************************************************/
u8 GPIO_u8GetPortValue(u8 Cpy_u8PortID);

void GPIO_vidTogglePort(u8 Cpy_u8PortID);


#endif //_GPIO_INTERFACE_H