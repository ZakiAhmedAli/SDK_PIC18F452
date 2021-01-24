#ifndef USRT_INTERFACE_H
#define USRT_INTERFACE_H



#define F_CPU 4000000UL


#define	HIGH_SPEED		1
#define	LOW_SPEED		2
#define ASYC_SPEED		3
	
	
#define	ASYNC_MODE		0
#define	SYNC_MODE		1
	
	
	
#define _9BIT_DATA		0
#define _8BIT_DATA		1

#define CLOCK_INTERNAL  1
#define CLOCK_EXTERNAL  0

#define MASTER			1
#define SLAVE			2


#define ENABLE		   (u8)1
#define DISABLE		   (u8)0


void USART_Void_init(u16 Copy_BAUDRATE);
/************************************************************************/
/* Description	: Data transmitting function 							*/
/* Input 		: Copy_u8Data to send									*/
/* Return		: void													*/
 /***********************************************************************/
void USART_voidTransmit_Char(u8 Copy_u8Data);

/************************************************************/
/* Description	: Send string of USART data function 	   	*/
/* Input 		: string to send							*/
/* Return		: void					  					*/
 /***********************************************************/
void USART_voidTransmit_String(u8 *Copy_u8Str);



/************************************************************/
/* Description	: Data receiving function	 		 	   	*/
/* Input 		: void										*/
/* Return		: receiving data		  					*/
 /***********************************************************/
u8 USART_u8RXChar(void);

/************************************************************/
/* Description	: this functoin used to receiving string  	*/
/* Input 		: Str_Ptr to receiving tring				*/
/* Return		: void		  								*/
 /***********************************************************/
void UART_recieveString(u8 * Str_Ptr);


#endif //USRT_INTERFACE_H	