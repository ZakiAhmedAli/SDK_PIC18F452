#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"ADC_interface.h"
#include"ADC_private.h"





void ADC_VoidInit(Fosc_t Prescal)
{ /*
  switch(Prescal)
  {
  case FOSC_DIV_2 : CLR_BIT(ADCON0 , ADCS0);
                    CLR_BIT(ADCON0 , ADCS1);
                    CLR_BIT(ADCON1 , ADCS2);
  break;

  case FOSC_DIV_8 : SET_BIT(ADCON0 , ADCS0);
                    CLR_BIT(ADCON0 , ADCS1);
                    CLR_BIT(ADCON1 , ADCS2);
  break;
  case FOSC_DIV_32: CLR_BIT(ADCON0 , ADCS0);
                    SET_BIT(ADCON0 , ADCS1);
                    CLR_BIT(ADCON1 , ADCS2);
  break;
  case FRC        : SET_BIT(ADCON0 , ADCS0);
                    SET_BIT(ADCON0 , ADCS1);
                    CLR_BIT(ADCON1 , ADCS2);
  break;
  case FOSC_DIV_4 : CLR_BIT(ADCON0 , ADCS0);
                    CLR_BIT(ADCON0 , ADCS1);
                    SET_BIT(ADCON1 , ADCS2);
  break;
  case FOSC_DIV_16: SET_BIT(ADCON0 , ADCS0);
                    CLR_BIT(ADCON0 , ADCS1);
                    SET_BIT(ADCON1 , ADCS2);
  break;
  case FOSC_DIV_64: CLR_BIT(ADCON0 , ADCS0);
                    SET_BIT(ADCON0 , ADCS1);
                    SET_BIT(ADCON1 , ADCS2);
  break;
  default : break;
  }
*/
    ADCON0 |= (1 << 0) | (1 << 7); // power up && Fosc/64 "BEST COHICE"

    ADCON1 |= (1 << 6) | (1 << 7); //port a all analog  && fosc/64 && right-justified

}
u16 ADC_U16Read(Channel_t channel)
{
    u16 digital , digital1;

    /* Channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000) & ADC is disabled */
    ADCON0 |= (channel<<3);

    ADCON0 |= ((1<<ADON)|(1<<DONE));	/*Enable ADC and start conversion*/

    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while(ADCON0 & (1 << DONE));

    digital = (u16)((ADRESH*256) | (ADRESL));	/*Combine 8-bit LSB and 2-bit MSB*/
    
    digital =  digital *( 5000 / 1023);
    
    return (digital);
}