/*
 * MSPI_Int.h
 *
 *  Created on: Aug 2, 2022
 *      Author: weza
 */

#ifndef MCAL_SPI_MSPI_INT_H_
#define MCAL_SPI_MSPI_INT_H_
//#include"../../LIB/STD_TYPES.h"
U8 MSPIVoidTransRecieve(U8 A_U8DATA);
void MSPISLVVoidInit();
void MSPIMstrVoidInit();
void MSPIVoidSendString(U8 *A_U8STR);
U8* MSPIVoidTransRecString(U8 *A_U8STR,U8 *A_U8COUNTS);

#endif /* MCAL_SPI_MSPI_INT_H_ */
