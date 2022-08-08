/*
 * MUART_prg.c
 *
 *  Created on: Jul 28, 2022
 *      Author: weza
 */
// EXTERNAL CLK (xck pin)ONLY USED AT MASTER SLAVE OPERATION(SYNCHRONOUS SLAVE MODE)
// INTERNAL CLK GENERATION THEREFORE ASYNCHRONOUS
// TRANSMITTER: SERIAL OPERATION WITH NO DELAY BETWEEN FRAMES
//ERROR FLAGS (FE and DOR AND  (RXB8)), CHECK ON THEM BEFORE LOADING DATA OF THE NEXT FRAME(READING USDR)

//ASK WHAT IS The recovery units are used for asynchronous data reception.
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"MUART_conf.h"
#include "MUART_Reg.h"
#include "MUART_Private.h"
#include"MUART_int.h"
void MUART_voidInit(){ //enables must be at the end

	U8 L_HELP_REG=0;
	SET_BIT(L_HELP_REG,URSEL);            //WRITE ON UCSRC
	CLR_BIT(L_HELP_REG,UMSEL);            //ASYNCH OPERATION
	CLR_BIT(L_HELP_REG,USBS);             //1STOP
	CLR_BIT(L_HELP_REG,UPM0);             //PARITY DISABLED
	CLR_BIT(L_HELP_REG,UPM1);
	SET_BIT(L_HELP_REG,UCSZ0);            //CHARC SIZE 8BIT MODE
	//SET_BIT(L_HELP_REG,UCSZ1);
	SET_BIT(L_HELP_REG,UCSZ2);
	UCSRC=L_HELP_REG;
	//UBRRL=(Fosc/16*BAUD)-1; ----------------------- –                              //set the buad rate
	UBRRL=51;                                                                                //setting frame format
	CLR_BIT(UCSRB,UCSZ2);                              // disable the GIE
                                  //CHECK THAT transmitter has completed all transfers from txc flag
                                 //CHECK THAT there are no unread data in the receive buffer rxc
  SET_BIT(UCSRB,RXEN) ;                               	//enabling the Transmitter enable the transmitter (TXEN BIT) or the Receiver depending on the usage
  SET_BIT(UCSRB,TXEN) ;
}
void MUART_voidTransmitData(U16 A_U16DATA){
	 while(GET_BIT(UCSRA,UDRE)==0){
		 UDR=A_U16DATA;
		 UCSRB|=(A_U16DATA>>8);
	  }   // check if the transmission of the previous operation is done
	                              //WRITE DATA ON THE UDR BUT FIRST MAKE SURE THAT THE FIRST FRAME IS SENT
}
U16 MUART_voidRecieveData(void){
	U16 L_U16BIT9=0;
	 while( GET_BIT(UCSRA,UDRE)!=1 );
	 L_U16BIT9=UDR|((UCSRB&0b00000010)<<7);
	 return UDR;//if there is unread data keep receiving

} //ask hwa ana h3ml recive 3la ehh (another microcont?)
void MUART_voidSendString(U8 *A_U16DATA){
	U8 COUNTER=0;
	while(A_U16DATA[COUNTER]!='\0'){
	MUART_voidTransmitData(A_U16DATA[COUNTER]);
	COUNTER++;
	}

}






