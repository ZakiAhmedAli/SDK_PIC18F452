/*****************************************************************
*     Author      : Zaki Ahmed hamed                             *
*     Description : this file implementation Dio Functios        *
*     Date        : 1 November 2020                              *
*     Version     : V03                                          *
*****************************************************************/



/***********************************************************
 *        Description : Libirary Directive                 *
 **********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***********************************************************
 *        Description : DIO Directive                      *
 **********************************************************/
#include "GPIO_Interface.h"
#include "GPIO_private.h"


/***********************************************************
 *        Description : DIO Implementaion                   *
 **********************************************************/



 /*****************************************************************************/
 /* Description    :  This Function Set The Pin Direction in The Run Time     */
 /* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinDirection]        */
 /* return         : void                                                     */
 /*****************************************************************************/
void GPIO_VoidSetPinDirection(u8 Cpy_u8PortID, u8 Cpy_u8PinNo , u8 Cpy_u8PinDirection)
{
        if((Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
           &&(Cpy_u8PinNo >= PIN0  && Cpy_u8PinNo  <=PIN7))
        {
                if(Cpy_u8PinDirection == GPIO_INPUT)
                {
                        switch(Cpy_u8PortID)
                        {
                                case GPIO_PORTA: SET_BIT(DDRA_REGISTER , Cpy_u8PinNo); break;
                                case GPIO_PORTB: SET_BIT(DDRB_REGISTER , Cpy_u8PinNo); break;
                                case GPIO_PORTC: SET_BIT(DDRC_REGISTER , Cpy_u8PinNo); break;
                                case GPIO_PORTD: SET_BIT(DDRD_REGISTER , Cpy_u8PinNo); break;
                                case GPIO_PORTE: SET_BIT(DDRE_REGISTER , Cpy_u8PinNo); break;
                                default : /* No thing*/  break;
                        }
                }
                else if(Cpy_u8PinDirection == GPIO_OUTPUT)
                {
                         switch(Cpy_u8PortID)
                          {
                                 case GPIO_PORTA: CLR_BIT(DDRA_REGISTER , Cpy_u8PinNo); break;
                                 case GPIO_PORTB: CLR_BIT(DDRB_REGISTER , Cpy_u8PinNo); break;
                                 case GPIO_PORTC: CLR_BIT(DDRC_REGISTER , Cpy_u8PinNo); break;
                                 case GPIO_PORTD: CLR_BIT(DDRD_REGISTER , Cpy_u8PinNo); break;
                                 case GPIO_PORTE: CLR_BIT(DDRE_REGISTER , Cpy_u8PinNo); break;
                                 default : /* No thing*/  break;
                          }
                }
                else{/* no thing*/}
        }
        else{/* no thing */}

}

/*********************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinLevel]    */
/* return         : void                                             */
/*********************************************************************/

void GPIO_VoidSetPinValue(u8 Cpy_u8PortID , u8 Cpy_u8PinNo , u8 Cpy_u8PinLevel)
{

    if((Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
       &&(Cpy_u8PinNo >= PIN0  && Cpy_u8PinNo  <=PIN7))
    {
            if(Cpy_u8PinLevel == GPIO_HIGH)
            {
                    switch(Cpy_u8PortID)
                    {
                            case GPIO_PORTA : SET_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTB : SET_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTC : SET_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTD : SET_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTE : SET_BIT(PORTE_REGISTER ,Cpy_u8PinNo ); break;
                            default : /*NO thing */ break;
                    }
            }
            else if(Cpy_u8PinLevel == GPIO_LOW)
            {
                    switch(Cpy_u8PortID)
                    {
                            case GPIO_PORTA : CLR_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTB : CLR_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTC : CLR_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTD : CLR_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
                            case GPIO_PORTE : CLR_BIT(PORTE_REGISTER ,Cpy_u8PinNo ); break;
                            default : /*NO thing */ break;
                    }
            }
    }
}
/**********************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time  */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo]                     */
/* return         : u8 Pin_Value High Or Low                          */
/**********************************************************************/
u8 GPIO_u8GetPinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo )
{
    /* Defiine the Local variable to get the Bit value*/
    u8 u8ResultLocal = 0x00;
   
    if((Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
       &&(Cpy_u8PinNo >= PIN0  && Cpy_u8PinNo  <=PIN7))
    {
            switch(Cpy_u8PortID)
            {
                case GPIO_PORTA : u8ResultLocal = GET_BIT(PORTA_REGISTER, Cpy_u8PinNo); break;
                case GPIO_PORTB : u8ResultLocal = GET_BIT(PORTB_REGISTER, Cpy_u8PinNo); break;
                case GPIO_PORTC : u8ResultLocal = GET_BIT(PORTC_REGISTER, Cpy_u8PinNo); break;
                case GPIO_PORTD : u8ResultLocal = GET_BIT(PORTD_REGISTER, Cpy_u8PinNo); break;
                case GPIO_PORTE : u8ResultLocal = GET_BIT(PORTE_REGISTER, Cpy_u8PinNo); break; 
                default         :                                                     break;
            }
    }
    else
    {
            /*in this case Return Error or portD */
            u8ResultLocal = 0xFF;
    }
    return u8ResultLocal;
}

/**************************************************************************/
/* Description    :  This Function Set The Port Direction in The Run Time */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortDirection]                 */
/* return         : void                                                  */
/**************************************************************************/
 void GPIO_VoidSetPortDirecton(u8 Cpy_u8PortID , u8 Cpy_u8PortDirection)
  {
      if(Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
      {
              if(Cpy_u8PortDirection == GPIO_INPUT)
              {
                      switch(Cpy_u8PortID)
                      {
                          case GPIO_PORTA :SET_BYTE(DDRA_REGISTER); break;
                          case GPIO_PORTB :SET_BYTE(DDRB_REGISTER); break;
                          case GPIO_PORTC :SET_BYTE(DDRC_REGISTER); break;
                          case GPIO_PORTD :SET_BYTE(DDRD_REGISTER); break;
                          case GPIO_PORTE :SET_BYTE(DDRE_REGISTER); break;
                          default         :                         break;
                      }
              }
              else if(Cpy_u8PortDirection == GPIO_OUTPUT)
              {
                      switch(Cpy_u8PortID)
                      {
                         case GPIO_PORTA :CLEAR_BYTE(DDRA_REGISTER); break;
                         case GPIO_PORTB :CLEAR_BYTE(DDRB_REGISTER); break;
                         case GPIO_PORTC :CLEAR_BYTE(DDRC_REGISTER); break;
                         case GPIO_PORTD :CLEAR_BYTE(DDRD_REGISTER); break;
                         case GPIO_PORTE :CLEAR_BYTE(DDRE_REGISTER); break;
                         default         :                           break;
                      }
              }
      }
 }


  void GPIO_VoidSetPortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue)
  {
          if(Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
          {
                  if(Cpy_u8PortValue == GPIO_LOW)
                  {
                          switch(Cpy_u8PortID)
                          {
                             case GPIO_PORTA : CLEAR_BYTE(PORTA_REGISTER); break;
                             case GPIO_PORTB : CLEAR_BYTE(PORTB_REGISTER); break;
                             case GPIO_PORTC : CLEAR_BYTE(PORTC_REGISTER); break;
                             case GPIO_PORTD : CLEAR_BYTE(PORTD_REGISTER); break;
                             case GPIO_PORTE : CLEAR_BYTE(PORTE_REGISTER); break;
                             default         :                             break;
                          }
                  }
                  else if(Cpy_u8PortValue == GPIO_HIGH)
                  {
                          switch(Cpy_u8PortID)
                          {
                                   case GPIO_PORTA :SET_BYTE(PORTA_REGISTER); break;
                                   case GPIO_PORTB :SET_BYTE(PORTB_REGISTER); break;
                                   case GPIO_PORTC :SET_BYTE(PORTC_REGISTER); break;
                                   case GPIO_PORTD :SET_BYTE(PORTD_REGISTER); break;
                                   case GPIO_PORTE :SET_BYTE(PORTE_REGISTER); break;
                                                                 default           :                          break;

                          }
                  }
                  else{ /* NO Thing*/}
          }
          else
          {
                  /* NO Thing */
          }

  }

 void GPIO_VoidWritePortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue)
 {
         if(Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
                 {
                  switch(Cpy_u8PortID)
                  {
                           case GPIO_PORTA : PORTA_REGISTER = Cpy_u8PortValue; break;
                           case GPIO_PORTB : PORTB_REGISTER = Cpy_u8PortValue; break;
                           case GPIO_PORTC : PORTC_REGISTER = Cpy_u8PortValue; break;
                           case GPIO_PORTD : PORTD_REGISTER = Cpy_u8PortValue; break;
                           case GPIO_PORTE : PORTE_REGISTER = Cpy_u8PortValue; break;
                                                   default            :                                                    break;

                  }
                 }
 }



void GPIO_voidWriteBitsInPort(u8 Cpy_u8PortID ,  u8 Cpy_u8Mask , u8 Cpy_u8Value )
{
        switch(Cpy_u8PortID)
        {
                case GPIO_PORTA :    CLEAR_BITS_REG(PORTA_REGISTER , Cpy_u8Mask);
                                     SET_BITS_REG(PORTA_REGISTER , Cpy_u8Mask & Cpy_u8Value);

                break;

                case GPIO_PORTB :    CLEAR_BITS_REG(PORTB_REGISTER , Cpy_u8Mask);
                                     SET_BITS_REG(PORTB_REGISTER , Cpy_u8Mask & Cpy_u8Value);

                break;

                case GPIO_PORTC :    CLEAR_BITS_REG(PORTC_REGISTER , Cpy_u8Mask);
                                     SET_BITS_REG(PORTC_REGISTER , Cpy_u8Mask & Cpy_u8Value);

                break;

                case GPIO_PORTD :    CLEAR_BITS_REG(PORTD_REGISTER , Cpy_u8Mask);
                                     SET_BITS_REG(PORTD_REGISTER , Cpy_u8Mask & Cpy_u8Value);

                break;
                case GPIO_PORTE :    CLEAR_BITS_REG(PORTE_REGISTER , Cpy_u8Mask);
                                     SET_BITS_REG(PORTE_REGISTER , Cpy_u8Mask & Cpy_u8Value);

                break;


        }
}




  /*************************************************************************/
  /* Description    :  This Function Set The Port Value in The Run Time    */
  /* Inputs         : [ Cpy_u8PortID]                                      */
  /* return         : u8 Port_Value High Or Low                            */
  /*************************************************************************/
  u8 GPIO_u8GetPortValue(u8 Cpy_u8PortID)
  {
          u8 u8ResultLocal = 0x00;
          if(Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
          {
                  switch(Cpy_u8PortID)
                  {
                     case GPIO_PORTA : u8ResultLocal = PORTA_REGISTER; break;
                     case GPIO_PORTB : u8ResultLocal = PORTB_REGISTER; break;
                     case GPIO_PORTC : u8ResultLocal = PORTC_REGISTER; break;
                     case GPIO_PORTD : u8ResultLocal = PORTD_REGISTER; break;
                     case GPIO_PORTE : u8ResultLocal = PORTE_REGISTER; break;
                     default         :                                 break;
                  }
          }
          return u8ResultLocal;
  }
  void GPIO_vidTogglePort(u8 Cpy_u8PortID)
  {
          if(Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
          {
                  switch(Cpy_u8PortID)
                  {
                     case GPIO_PORTA : PORTA_REGISTER = ~PORTA_REGISTER; break;
                     case GPIO_PORTB : PORTA_REGISTER = ~PORTB_REGISTER; break;
                     case GPIO_PORTC : PORTA_REGISTER = ~PORTC_REGISTER; break;
                     case GPIO_PORTD : PORTA_REGISTER = ~PORTD_REGISTER; break;
                     case GPIO_PORTE : PORTA_REGISTER = ~PORTE_REGISTER; break;
                                         default: /*NO Thing */ break;
                  }

      }
  }
  void GPIO_VoidTogglePinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo)
  {
        if((Cpy_u8PortID >= GPIO_PORTA && Cpy_u8PortID <= GPIO_PORTE)
                      &&(Cpy_u8PinNo >= PIN0  && Cpy_u8PinNo  <=PIN7))
		{
                       switch(Cpy_u8PortID)
                       {
                          case GPIO_PORTA : TOGGEL_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
                          case GPIO_PORTB : TOGGEL_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
                          case GPIO_PORTC : TOGGEL_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
                          case GPIO_PORTD : TOGGEL_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
                          case GPIO_PORTE : TOGGEL_BIT(PORTE_REGISTER ,Cpy_u8PinNo ); break;
                          default: /*NO Thing */ break;
                       }
        
               }
        else
        {
                /* no thing*/
        }

  }