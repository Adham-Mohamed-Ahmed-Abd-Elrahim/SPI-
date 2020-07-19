/*
 * SPI.c
 *
 * Created: 17/07/2020 03:08:49
 * Author : ADHM
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

#include "SPI.h"

#define mode MASTER

int main(void)
{  
SPI_SET(MSB,PRE_16,MODE1,NORMAL);
	SPI_INI();

	
 char recieve[6]="adham";

    /* Replace with your application code */
    while (1) 
    {//recieve=USART_RECIVE();
for(uint8_t i=0;i<6;i++)
   {     SPI_WRITE(recieve[i]);}
   }
}

