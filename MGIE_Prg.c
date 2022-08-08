/*
 * MGIE_Prg.c

 *
 *  Created on: Jul 19, 2022
 *      Author: weza
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "M_GIE_Register.h"
#include "M_GIE_Int.h"
#include "../DIO/DIO_int.h"
void MGIE_VEnable(void){
	SET_BIT(SREG,GIE);
}

void MGIE_VDisable(void){
	CLR_BIT(SREG,GIE);
}

