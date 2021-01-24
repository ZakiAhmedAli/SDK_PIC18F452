#ifndef	USART_CONFIG_H
#define USART_CONFIG_H


#define 


/* options : LOW_SPEED
			 HIGH_SPEED
*/

#define	BAUDE_MODE		HIGH_SPEED

/* options : ASYNC_MODE	
             SYNC_MODE
*/	
#define	USART_MODE	    ASYNC_MODE		

/*
	options : _8BIT_DATA
			  _9BIT_DATA	
*/
#define	DATA_TRANSMIT	_8BIT_DATA

#define CLOCK_SOURCE

//#define ASYNC_MODE




#endif // USART_CONFIG_H