/*
 * MSPI_Prg.c
 *
 *  Created on: Aug 2, 2022
 *      Author: weza
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../DIO/DIO_int.h"
#include"MSPI_Int.h"
#include"MSPI_Conf.h"
#include"MSPI_Pri.h"
#include"MSPI_Reg.h"
#include<util/delay.h>
void MSPIMstrVoidInit(){
	SET_BIT(SPCR,DORD);// MSB
	CLR_BIT(SPCR,CPOL); //CLK POLARITY IDLE STATE
	CLR_BIT(SPCR,CPHA); //CLK PHASE    SAMPLING

CLR_BIT(SPCR,SPR0); //PRESCALLAR
CLR_BIT(SPCR,SPR1);
SET_BIT(SPSR,SPI2X);

	SET_BIT(SPCR,MSTR); //SELECT AS MASTER

	SET_BIT(SPCR,SPE); //SPI ENABLE

}
void MSPISLVVoidInit(){
	SET_BIT(SPCR,DORD);// MSB
	CLR_BIT(SPCR,CPOL); //CLK POLARITY IDLE STATE
	CLR_BIT(SPCR,CPHA); //CLK PHASE    SAMPLING


	CLR_BIT(SPCR,MSTR); //SELECT AS SLAVE

	SET_BIT(SPCR,SPE); //SPI ENABLE

}
U8 MSPIVoidTransRecieve(u8 A_U8DATA){
SPDR=A_U8DATA; //send from master to slave
while(GET_BIT(SPSR,SPIF)==0);
return SPDR; // ana recieved eh mn el master
}

 U8* MSPIVoidTransRecString(U8 *A_U8STR,U8 *A_U8COUNTS){
	U8 COUNTER=0;
	static U8 CHARCTERS[20];
	while (A_U8STR[COUNTER]!='\0'){ //TRANSMIT CHAR BY CHAR, SPDR CONTAINS ONLY A CHAR
		SPDR=A_U8STR[COUNTER];
		CHARCTERS[COUNTER]=SPDR;  //stores char that is sent by spdr in an array of strings
		COUNTER++;
	}
	*A_U8COUNTS=COUNTER;
	U8 *PTR=CHARCTERS; //points to the array that is recieving from spdr
	while(GET_BIT(SPSR,SPIF)==0);
	return PTR;
}

//ask hwo can i write on sbdr during data transfer
