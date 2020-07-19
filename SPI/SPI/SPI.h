/*
 * SPI.h
 *
 * Created: 17/07/2020 03:10:44
 *  Author: ADHM
 */ 


#ifndef SPI_H_
#define SPI_H_

#include<avr/io.h>

#define SET_BIT(REG,INDX) ((REG) |=  (1<<(INDX)))
#define CLR_BIT(REG,INDX) ((REG) &= ~(1<<(INDX)))
#define READ_BIT(REG,INDX)	((REG>>INDX)&0x01)
//#include "USART.h"
/*#define READ_BIT(REG,INDX) ((REG)&(1<<INDX))
#define SET_BIT(REG,INDX) ((REG)|=(1<<INDX))
#define CLR_BIT(REG,INDX) ((REG)&=(~(1<<INDX)))*/
//---------------------------------------------
//ORDER
#define MSB 0
#define LSB 1
//------------------------------------
 //MODE 
 //normal speed 
 #define NORMAL 0
 //double speed 
 #define DOUBLE 1 
 //----------------------------------
//PRESCALERS 
#define PRE_4 1
#define PRE_16 2
#define PRE_64 3
#define PRE_128 4
/*#define PRE_2 4
#define PRE_8 5
#define PRE_32 6
#define PRE_64 7*/
//---------------------------------
//POLARITY MODE 
#define MODE1 0
#define MODE2 1
#define MODE3 2
#define MODE4 3
//-----------------------
#define MASTER 0
#define SLAVE 1
//-----------------------HARDWARE
#define SCK 7
#define MISO 6
#define MOSI 5
#define SS 4

	
void SPI_INI();
void SPI_SET(uint8_t ORDER,uint8_t speed,uint8_t POLARITY_MODE,uint8_t mode);
void SPI_WRITE(char DATA);
char SPI_READ();
//SPI ADDRESS_GETTER();



#endif /* SPI_H_ */