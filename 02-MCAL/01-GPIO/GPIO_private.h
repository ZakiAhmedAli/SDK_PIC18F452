/****************************************
*     Author      : Zaki Ahmed hamed    *
*     Description : Dio Driver          *
*     Date        : 1 November 2020     *
*     Version     : V01                 *
****************************************/




/*************************************************************************************
*     Description : Guard to Protect this file from include more than one time       *
*                                                                                    *
*************************************************************************************/

#ifndef  GPIO_REGISTER_H_
#define  GPIO_REGISTER_H_

/*************************************************************************************
*     Description : Memory Mapping I/O Preipheral                                    *
*                                                                                    *
*************************************************************************************/

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} REG;

#define DDRA      *((volatile  u8* )(0x0F92)) // diriection input output register
#define PINRA     *((volatile  u8* )(0x0F80)) // pin input output register

/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT A                                    *
*************************************************************************************/

#define            PORTA_REGISTER  *((volatile u8*) (0x0F80))
#define            DDRA_REGISTER   *((volatile u8*) (0x0F92))
#define            DDRAbit         (*(volatile REG*)(0x0F92)) // access bit field
#define            PINRAbit        (*(volatile REG*)(0x0F80)) // pin input output register


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT B                                    *
*************************************************************************************/
#define                 PORTB_REGISTER  (*(volatile u8*) (0x0F81))
#define                 DDRB_REGISTER   (*(volatile u8*) (0x0F93))
#define                 DDRBbit         (*(volatile REG*)(0x0F93)) // access bit field
#define                 PINRBbit        (*(volatile REG*)(0x0F81)) // pin input output register


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT C                                    *
*************************************************************************************/


#define                 PORTC_REGISTER  (*(volatile u8*) (0x0F82))
#define                 DDRC_REGISTER   (*(volatile u8*) (0x0F94))
#define                 DDRCbit         (*(volatile REG*)(0x0F94)) // access bit field 
#define                 PINRCbit        (*(volatile REG*)(0x0F82)) // pin input output register


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT D                                   *
*************************************************************************************/
#define                 PORTD_REGISTER  (*(volatile u8*) (0x0F83))
#define                 DDRD_REGISTER   (*(volatile u8*) (0x0F95))
#define                 DDRDbit         (*(volatile REG*)(0x0F95)) // access bit field
#define                 PINDAbit        (*(volatile REG*)(0x0F83)) // pin input output register


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT E                                    *
*************************************************************************************/
#define                 PORTE_REGISTER  *((volatile u8*) (0x0F84))
#define                 DDRE_REGISTER   *((volatile u8*) (0x0F96))
#define                 DDREbit         (*(volatile REG*)(0x0F96)) // access bit field
#define              	PINEAbit        (*(volatile REG*)(0x0F84)) // pin input output register
 




#endif