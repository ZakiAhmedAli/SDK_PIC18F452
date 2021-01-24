  /***********************************************************************
  *     File        : LCD_config.h                                       *
  *     Auther      : Zaki Ahmed hamed                                   *
  *     Description : This file includes LCD configuration definitions   *
  *     Date        : 20 August 2020                                     *
  *     Version     : V04                                                *
  ***********************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define  LCD_DATA_PORT                GPIO_PORTC        /* Define LCD data port */

#define  LCD_CMD_PORT                 GPIO_PORTB        /*Define LCD data port */

/***************** define control pins   ******************/

/* Define Register Select (data reg./command reg.) signal pin */
#define  RS         PIN0

#define  RW         PIN1                /* Define Read/Write signal pin */

#define  EN         PIN2                /* Define Enable signal pin */

/**********************   configure LCD Mode    ****************************/

#define LCD_MODE                LCD_4BIT_MODE

/****************************************************************************/


#endif /* LCD_CONFIG_H_ */