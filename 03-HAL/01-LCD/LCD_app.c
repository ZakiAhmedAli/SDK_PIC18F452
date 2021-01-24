  /***************************************************************************
  *     File        : LCD_app.c								      	         *
  *     Auther      : Zaki Ahmed hamed                                       *
  *     Description : This file implementation LCD APIs   					 *
  *     Date        : 20 August 2020                                         *
  *     Version     : V04                                                    *
  ***************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

//static void LCD_voidWriteData(u8 Cpy_u8Data);


#if LCD_MODE == LCD_8BIT_MODE

static void LCD_VoidWriteCommand(u8 Cpy_u8Command)
{

	 GPIO_VoidSetPinValue(LCD_CMD_PORT , RS , GPIO_LOW);

	 GPIO_VoidSetPinValue(LCD_CMD_PORT , RW , GPIO_LOW);

	 GPIO_VoidSetPinValue(LCD_DATA_PORT , Cpy_u8Command);
	 	//GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);
	 GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);

	  delay_ms(1);

	 GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);
	  delay_ms(1);
}

void LCD_VoidInit(void)
{
	/* set data port as output */
	 GPIO_VoidSetPortDirecton(LCD_DATA_PORT, GPIO_OUTPUT);

		/* Make LCD command port direction as o/p */
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , RS , GPIO_OUTPUT);
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , RW , GPIO_OUTPUT);
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , EN , GPIO_OUTPUT);

	 delay_ms(35);

	 LCD_VoidWriteCommand(LCD_FUNCTION_SET_8BIT);

	 delay_ms(1);

	 LCD_VoidWriteCommand(LCD_DISPLAY_ON);

	 delay_ms(2);

	 LCD_VoidWriteCommand(LCD_CLEAR);

	 delay_ms(2);

	 LCD_VoidWriteCommand(LCD_ENTRY_MODE);
	 delay_ms(2);


}
static void LCD_voidWriteData(u8 Cpy_u8Data)
{

	 GPIO_VoidSetPinValue(LCD_CMD_PORT , RS , GPIO_HIGH);

	 GPIO_VoidSetPinValue(LCD_CMD_PORT , RW , GPIO_LOW);

	 GPIO_VoidWritePortValue(LCD_DATA_PORT , Cpy_u8Data);

 	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);

    delay_ms(1);

    GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);
    delay_ms(1);
}


#elif (LCD_MODE == LCD_4BIT_MODE)

static void LCD_VoidWriteCommand(u8 Cpy_u8Command)
{
	GPIO_VoidSetPinValue(LCD_CMD_PORT , RS , GPIO_LOW);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , RW , GPIO_LOW);

	//PORTC =(PORTC & 0x0F)|(Cpy_u8Command & 0xF0);/* Sending upper nibble */

	GPIO_voidWriteBitsInPort(LCD_DATA_PORT , M_4BIT_MASK , Cpy_u8Command);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);/* Enable pulse */

	delay_ms(1);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);

	delay_ms(1);

	//PORTC =(PORTC & 0x0F)|( Cpy_u8Command << 4);/* Sending upper nibble */
	GPIO_voidWriteBitsInPort(LCD_DATA_PORT , M_4BIT_MASK , (Cpy_u8Command<<4));
	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);/* Enable pulse */

	delay_ms(1);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);

	delay_ms(1);
}

void LCD_VoidInit(void)
{
	/* set data port as output */
	GPIO_VoidSetPinDirection(LCD_DATA_PORT , D4 , GPIO_OUTPUT);
	GPIO_VoidSetPinDirection(LCD_DATA_PORT , D5 , GPIO_OUTPUT);
	GPIO_VoidSetPinDirection(LCD_DATA_PORT , D6 , GPIO_OUTPUT);
	GPIO_VoidSetPinDirection(LCD_DATA_PORT , D7 , GPIO_OUTPUT);

		/* Make LCD command port direction as o/p */
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , RS , GPIO_OUTPUT);
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , RW , GPIO_OUTPUT);
	 GPIO_VoidSetPinDirection(LCD_CMD_PORT , EN , GPIO_OUTPUT);

	 delay_ms(35);

	 LCD_VoidWriteCommand(0x02);

	 delay_ms(1);

	 LCD_VoidWriteCommand(LCD_FUNCTION_SET_4BIT);

	 delay_ms(1);

	 LCD_VoidWriteCommand(LCD_DISPLAY_ON);

	 delay_ms(2);

	 LCD_VoidWriteCommand(LCD_CLEAR);

	 delay_ms(2);

	 LCD_VoidWriteCommand(LCD_ENTRY_MODE);

}

static void LCD_voidWriteData(u8 Cpy_u8Data)
{
	GPIO_VoidSetPinValue(LCD_CMD_PORT , RS , GPIO_HIGH);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , RW , GPIO_LOW);

	//PORTC =(PORTC & 0x0F)|(Cpy_u8Data & 0xF0);/* Sending upper nibble */
	GPIO_voidWriteBitsInPort(LCD_DATA_PORT , M_4BIT_MASK , (Cpy_u8Data));

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);/* Enable pulse */

	delay_ms(1);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);

	delay_ms(1);

	//PORTC =(PORTC & 0x0F)|( Cpy_u8Data << 4);/* Sending lower nibble */

	GPIO_voidWriteBitsInPort(LCD_DATA_PORT , M_4BIT_MASK , (Cpy_u8Data<<4));

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_HIGH);/* Enable pulse */

	delay_ms(1);

	GPIO_VoidSetPinValue(LCD_CMD_PORT , EN , GPIO_LOW);

	delay_ms(2);
}

#endif


/*************************** service functions*******************************/
void LCD_VoidWriteChar(u8 Cpy_u8Char)
{

	LCD_voidWriteData(Cpy_u8Char);
}

void LCD_VoidWriteString(u8 *Cpy_u8String)
{
	/*u8 LOC_u8Count=0;
	for(LOC_u8Count=0 ; Cpy_u8String[LOC_u8Count] !='\n' ; LOC_u8Count++)
	{
		LCD_VoidWriteChar(Cpy_u8String[LOC_u8Count]);
	} */
		while(*Cpy_u8String > 0 )
		 LCD_VoidWriteChar(*Cpy_u8String++);

	/*while(*Cpy_u8String > 0 )
		 LCD_VoidWriteChar(*Cpy_u8String++);*/
}


 void LCD_GoToXy(u8 cpy_u8Row , u8 Cpy_u8Coulmn)
 {
 	if (cpy_u8Row==1 )
 	{
 		if(Cpy_u8Coulmn < 16)
 		{
 			/* Command of first row and required position<16 */
 			LCD_VoidWriteCommand(Cpy_u8Coulmn + LCD_SetCursor);
 		}
 	}
 	else if(cpy_u8Row == 2)
 	{
 		if(Cpy_u8Coulmn < 16)
 		{
 			 /*Move cursor to the beginning of second line*/
 			LCD_VoidWriteCommand(Cpy_u8Coulmn + LCD_2ndLine);
 		}
 	}
 }


void LCD_VoidWriteNum(u16 Copy_U16Number)
{


	if((Copy_U16Number / 10000)!=0)
	{
		LCD_VoidWriteChar((Copy_U16Number) + 48);
		Copy_U16Number %= 10000;
	}
	if((Copy_U16Number / 1000)!=0)
	{
		LCD_VoidWriteChar((Copy_U16Number / 1000) + 48);
		Copy_U16Number %= 1000;
	}
	if((Copy_U16Number / 100)!=0)
	{
		LCD_VoidWriteChar( (Copy_U16Number / 100)  + 48);
		Copy_U16Number %= 100;
	}
	if((Copy_U16Number / 10)!=0)
	{
		LCD_VoidWriteChar( (Copy_U16Number / 10)+48);
		Copy_U16Number %= 10;
	}
	LCD_VoidWriteChar(Copy_U16Number + 48);

}
void LCD_voidClear(void)
{
	LCD_VoidWriteCommand(LCD_CLEAR);
	/*_delay_ms(2);
	LCD_VoidWriteCommand(LCD_SetCursor);
	_delay_ms(2);
*/
}