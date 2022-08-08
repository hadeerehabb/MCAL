/*
 * MSPI_Reg.h
 *
 *  Created on: Aug 2, 2022
 *      Author: weza
 */

#ifndef MCAL_SPI_MSPI_REG_H_
#define MCAL_SPI_MSPI_REG_H_
#define SPCR *(((volatile u8*)0x2D))
#define SPSR *(((volatile u8*)0x2E))
#define SPDR *(((volatile u8*)0x2F))
 #define SPIE DIO_PIN7     //SPCR REG,INTERRUPT ENABLE
 #define SPE DIO_PIN6      //if=1, spi is enabled
 #define DORD DIO_PIN5    //if=1,LSB is transmitted first, if 0 MSB
 #define MSTR DIO_PIN4    //MASTER,SLAVE SELECT. if=1 master, if=0 slave
 #define CPOL DIO_PIN3    //clk polarity, if=1, high in idle state
 #define CPHA DIO_PIN2    //msh fhma
 #define SPR1 DIO_PIN1    //clk rate select
 #define SPR0 DIO_PIN0
 #define SPIF DIO_PIN7 //SPSR, SPI interrupt flag,=1 when serial transfere is complete
 #define WCOL DIO_PIN6 //=1 when SPDR is beimg written during data transfer
 #define SPI2X DIO_PIN0 //if =1, speed is doubled
 #define MSB DIO_PIN7 //SPDR elbn2l 3leh el data
 #define LSB DIO_PIN0
#endif /* MCAL_SPI_MSPI_REG_H_ */
