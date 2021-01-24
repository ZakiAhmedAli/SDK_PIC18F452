


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/
#include "GPIO_interface.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/********************************************************/
/* Description : This function used to initialize USART */
/* Inputs      : void 									*/
/* return      : void							 		*/
/********************************************************/

void USART_Void_init(u16 Copy_BAUDRATE)
{
	#if 	(BAUDE_MODE == LOW_SPEED)
			 SPBRG = (((F_CPU / (Copy_BAUDRATE * 64))) - 1);
	
	#elif   (BAUDE_MODE == HIGH_SPEED)
			 SPBRG = (((F_CPU / (Copy_BAUDRATE * 16))) - 1);
		 
	#elif   (BAUDE_Mode == ASYC_SPEED)
			 SPBRG = (((F_CPU / (Copy_BAUDRATE * 4))) - 1);
	#endif		 
	
	#if		(BAUDE_MODE	== LOW_SPEED)
			 TXSTA.BRGH=DISABLE;
	#elif   (BAUDE_MODE == HIGH_SPEED)	 
			 TXSTA.BRGH=ENABLE;
	#if		(DATA_TRANSMIT == _8BIT_DATA)
			 TXSTA.TX9=DISABLE;
	#elif   (DATA_TRANSMIT == _9BIT_DATA)	 
			 TXSTA.TX9=ENABLE;
	#endif		 
	
	#if	    (USART_MODE	== ASYNC_MODE)
		     TXSTA.SYNC=DISABLE;
	#elif   (USART_MODE	== SYNC_MODE)	 
	         SET_BIT(TXSTA.SYNC=ENABLE;
	#endif
	
	/*enable TX*/
	TXSTA.TXEN=ENABLE;
	/* Enable Receive(RX) & Serial */
	RCSTA.SPEN=ENABLE;
	RCSTA.CREN=ENABLE;
	
	/* Enable Global Interrupt */
	INTCON.GIE=ENABLE;
	/* Enable Peripheral Interrupt */
	INTCON.PEIE=ENABLE;
	/* Enable Receive Interrupt*/
	PIE1.RCIE=ENABLE;
	/* Enable Transmit Interrupt*/
	PIE1.TXIE=ENABLE;
	
}

void USART_voidTransmit_Char(u8 Copy_u8Data)
{
	while(!(PIR1.TXIF));
	
	 TXREG = Copy_u8Data;	
}

void USART_voidTransmit_String(u8 *Copy_u8Str)
{
		/*loop until end string*/
	while( *Copy_u8Str != '\0' )
	{
		USART_voidTransmit_Char(*Copy_u8Str);
		/*next char*/
		Copy_u8Str++;
	}				
}

u8 USART_u8RXChar(void)
{
	/* wait until USART RCREG is full*/
	while( !(PIR1.RCIF) );
	
	return RCREG;
}


void UART_recieveString(u8 * Str_Ptr)
{
	u8 LOC_u8Counter =0 ;
	
	Str_Ptr[LOC_u8Counter] = USART_u8RXChar();
	
	while(Str_Ptr[LOC_u8Counter] != '\r')
	{
		LOC_u8Counter++;
		Str_Ptr[LOC_u8Counter] = USART_u8RXChar();
	}

	Str_Ptr[LOC_u8Counter] = '\0';
	
}

