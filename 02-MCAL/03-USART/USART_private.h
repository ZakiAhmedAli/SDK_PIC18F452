#ifndef  USRT_PRIVATE_H
#define  USAT_PRIVATE_H




#define RCSTA		*((volatile RCSTA_t*)(0xFAB))
#define TXSTA		*((volatile TXSTA_t*)(0xFAC))
#define TXREG		*((volatile u8*)(0xFAD))
#define RCREG		*((volatile u8*)(0xFAE))
#define SPBRG		*((volatile u8*)(0xFAF))

#define PIR1 		*((volatile PIR1_t*)(0xF9E))
#define	IPR1 		*((volatile u8*)(0xF9F))
#define	PIE1 		*((volatile PIE1_t*)(0xF9D))
#define INTCON		*((volatile INTCON*)(0xFF2))

#define GIE		7
#define PEIE	6


#define RCIE 	5
#define TXIE	4

/*TXSTA: TRANSMIT STATUS AND CONTROL REGISTER BITS*/

typedef struct
{
	u8 CSRC    :1 ;
	u8 TX9 	   :1 ;   
	u8 TXEN	   :1 ;   
	u8 SYNC	   :1 ;   
	u8 RESERVED:1 ;
	u8 BRGH	   :1 ;   
	u8 TRMT	   :1 ;   
	u8 TX9D	   :1 ;   
}TXSTA_t;



/*RCSTA: RECEIVE STATUS AND CONTROL REGISTER BITS*/
typedef struct
{
	u8 SPEN 	:1 ;
	u8 RX9  	:1 ;
	u8 SREN 	:1 ;
	u8 CREN 	:1 ;
	u8 ADDEN	:1 ;
	u8 FERR 	:1 ;
	u8 OERR 	:1 ;
	u8 RX9D 	:1 ;
}RCSTA_t;

typedef struct
{
	u8 TMR1IF  :1 ; 
	u8 TMR2IF  :1 ; 
	u8 CCP1IF  :1 ;
	u8 SSPIF   :1 ;
	u8 TXIF    :1 ;
	u8 RCIF    :1 ;
	u8 ADIF    :1 ;
	u8 PSPIF   :1 ;
}PIR1_t;	 

typedef struct
{
	u8 RBIF   :1 ;
	u8 INT0IF :1 ;
	u8 TMR0IF :1 ;
	u8 RBIE   :1 ;
	u8 INT0IE :1 ;
	u8 TMR0IE :1 ;
	u8 PEIE   :1 ;
	u8 GIE    :1 ; 
}INTCON_t;

typedef struct
{
	u8 TMR1IE:1 ;
	u8 TMR2IE:1 ;
	u8 CCP1IE:1 ;
	u8 SSPIE :1 ;
	u8 TXIE  :1 ;
	u8 RCIE  :1 ;
	u8 ADIE  :1 ;
	u8 PSPIE :1 ;     
}PIE1_t;

#endif