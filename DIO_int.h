/*
 * DIO_int.h
 *
 *  Created on: May 18, 2022
 *      Author: weza
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7
#define PORT_HIGH 255
#define PORT_LOW 0
#define DIO_INPUT  0
#define DIO_OUTPUT 1
#define u8 U8
#define DIO_HIGH   1
#define DIO_LOW    0
#define PORT_OUTPUT 255
#define PORT_INPUT 0

void DIO_vWrtPinVal(U8 A_U8PortNo,U8 A_U8BitNo,U8 A_U8BitVal);
void DIO_vSetPinVal(U8 A_U8PortNo,U8 A_U8BitNo);
void DIO_vClrPinVal(U8 A_U8PortNo,U8 A_U8BitNo);
void DIO_vWrtPortVal(U8 A_U8PortNo,U8 A_U8PortVal);
void DIO_vWrtPortDir(U8 A_U8PortNo,U8 A_U8PortVal);
U8 DIO_U8GetPinVal(U8 A_U8PortNo,U8 A_U8BitNo);
void DIO_vWrtPinDir(U8 A_U8PortNo,U8 A_U8BitNo, U8 A_U8BitVal);
#endif /* MCAL_DIO_DIO_INT_H_ */

