/*
 * MUART_Reg.h
 *
 *  Created on: Jul 28, 2022
 *      Author: weza
 */
#define UCSRA *(((volatile u8*)0x2B))
#define UCSRB *(((volatile u8*)0x2A))
#define UCSRC *(((volatile u8*)0x40)) // lazm bit7=1,w a7ot kol haga fel UCRSC daa Mra wahdaa m3odsh ahot kol bit lwhdha
//h3ml help register mkan ene a3ml setting lehom kolohom b or f nafs el wa2t
#define UBRRL *(((volatile U8*)0x29))
#define UBRRH *(((volatile U8*)0x40))
#define UDR    *(((volatile U8*)0x2C))
#define RXC  DIO_PIN7 //UCSRA, =1 if there is unread data ,type of error
#define TXC  DIO_PIN6    //=1 if there is data unshifted
#define UDRE DIO_PIN5    //=1 if the transmit buffer is ready to recieve new data
#define FE  DIO_PIN4     //error flag,must be equal 0 when writing in ucsra
#define DOR  DIO_PIN3      //must be equal 0 when writing in ucsra,=1 when a new start bit is detected
#define PE  DIO_PIN2       //parity error
#define U2X  DIO_PIN1       //double asynchronous transmission speed,=0 in synch mode
#define MPCM  DIO_PIN0      //ask
#define TXB8  DIO_PIN0          //UCSRB, MUST BE WRITTEN BEFORE WRITTING LOW BITS OF UDR
#define RXB8  DIO_PIN1          //must be read before reading UDR
#define UCSZ2 DIO_PIN2          //combined with UCSZ1:0 bit to generate no od data bits
#define TXEN  DIO_PIN3          //transmitter enable
#define RXEN  DIO_PIN4          //receiver enable
#define UDRIE DIO_PIN5          //enable interrupt for UDRE,=1 IF UDRE=1 AND GIE=1
#define TXCIE DIO_PIN6          //=1 to enable transmitter interrupt
#define RXCIE  DIO_PIN7         //=1 to enable reciever interrupt
#define UCPOL  DIO_PIN0 //UCSRC
#define UCSZ0  DIO_PIN1             // COMBINED WITH UCSZ2 TO SEKEST NO OF DATA
#define UCSZ1  DIO_PIN2
#define USBS  DIO_PIN3               //STOP BIT SELECT 1 OR 2 BITS
#define UPM0  DIO_PIN4               //SELECT PARITY
#define UPM1  DIO_PIN5               //MODE
#define UMSEL  DIO_PIN6              //=1IF SYNCH,=0 IF ASYNCH
#define URSEL  DIO_PIN7              // "CHOOSE BETWEEN UCR&UBRRH,IF UCR THEREFORE 0
