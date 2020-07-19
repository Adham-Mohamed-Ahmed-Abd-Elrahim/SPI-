/*
 * SPI.c
 *
 * Created: 17/07/2020 03:10:33
 *  Author: ADHM
 */ 
#include "SPI.h"
void SPI_SET(uint8_t ORDER,uint8_t speed,uint8_t POLARITY_MODE,uint8_t mode)
{
	switch(mode)
	{case NORMAL:	
		CLR_BIT(SPSR,SPI2X);break;
	case DOUBLE :   
	SET_BIT(SPSR,SPI2X);break;
	default :       
	CLR_BIT(SPSR,SPI2X);break;
		
	}

		switch (speed)
		{   case PRE_4:
			{CLR_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);break;}
			case PRE_16:
			 {SET_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);break;}
				 
			case PRE_64:
			{CLR_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);break;}
			case PRE_128:
			{SET_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);break;}
			//default : prescale /16
			default	:SET_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);break;
			}
		

	switch (ORDER)
	{case MSB :CLR_BIT(SPCR,DORD);break;
		case LSB :SET_BIT(SPCR,DORD);break;
		//default oder of transfere from most significant bit
		default:CLR_BIT(SPCR,DORD);break;
	}
	
	switch(POLARITY_MODE)
	{   case MODE1: CLR_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);break;
		case MODE2: CLR_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);break;
		case MODE3: SET_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);break;
		case MODE4: SET_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);break;
		//MODE1
		default :CLR_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);break;
	}
	
	
	
	}

	
	

void SPI_WRITE(char DATA)
{	char flush_buffer;
	SPDR = DATA;			/* Write data to SPI data register */
	while(!(READ_BIT(SPSR,SPIF)));	/* Wait till transmission complete */
	flush_buffer = SPDR;
}
#define MODE 
#ifdef MASTER
void SPI_INI()
{   //Making MOSI-CS-CLSK As output /MISO AS INPUT
	CLR_BIT(DDRB,MISO); 	SET_BIT(DDRB,MOSI); 	SET_BIT(DDRB,SS); SET_BIT(DDRB,SCK);
	//DDRB|=0b00001101;
	SET_BIT(PORTB,SS);
	//Enabling SPI
	SET_BIT(SPCR,SPE);SET_BIT(SPCR,MSTR);
	
	
	//USART_TRASMIT('a');
}


//------------------------------------------FOR MASTER 

char SPI_READ()
{
	SPDR=0xff;
	while(!(READ_BIT(SPSR,SPIF)));
return SPDR ;
	
}
//----------------------------------------------FOR SLAVE
#elif defined (SLAVE)
void SPI_INI()
{
	//Making MOSI-CS-CLSK As input /MISO AS OUTPUT
SET_BIT(DDRB,MISO); 	CLR_BIT(DDRB,MOSI); 	CLR_BIT(DDRB,SS); CLR_BIT(DDRB,SCK);
	//DDRB|=0b00001101;
	//Enabling SPI
	SET_BIT(SPCR,SPE); CLR_BIT(SPCR,MSTR);
}
char SPI_READ()
{
	while(!(READ_BIT(SPSR,SPIF)));
	return SPDR ;
	
}

#endif