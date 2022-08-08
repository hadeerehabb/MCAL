/*
 * MUART_Private.h
 *
 *  Created on: Jul 28, 2022
 *      Author: weza
 */

#ifndef MCAL_UART_MUART_PRIVATE_H_
#define MCAL_UART_MUART_PRIVATE_H_
// to select character size
#define CHARC_SIZE_5BIT   0
#define CHARC_SIZE_6BIT   1
#define CHARC_SIZE_7BIT   2
#define CHARC_SIZE_8BIT   3
#define CHARC_SIZE_RESERVED   4
#define CHARC_SIZE_9BIT   5
#define STOP1 0
#define STOP2 1
#define PARITY_MODE_MASK           0b11001111
#define PARITY_MODE_DISABLED       0b00000000
#define PARITY_MODE_RESERVED       0b00010000
#define PARITY_MODE_EVEN           0b00100000
#define PARITY_MODE_ODD            0b00000000
#define SYNCHRONOUS_MODE           1
#define ASSYNCHRONOUS_MODE         0
#endif /* MCAL_UART_MUART_PRIVATE_H_ */
