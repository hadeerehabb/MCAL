
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MEXINT_Reg.h"
#include "MEXINT_Priv.h"
#include "MEXINT_config.h"
#include "MEXINT_int.h"
#include "../DIO/DIO_int.h"

void MEXINTvInit(){
//choose which pin will generate interrupt request
	if((INTERRUPT_PIN==INT0)|(INTERRUPT_PIN==INT1)){
	SET_BIT(GICR,INTERRUPT_PIN); //activate int0,int1,int2
	SET_BIT(SREG,I); //enable interrupt
	MCUCR=((MCUCR&MCUCR_MASK)|SENSE_CONTROL);
	}// select sense control to pins int0 and int1
	else{
		CLR_BIT(GICR,INTERRUPT_PIN);
	    DIO_vWrtPinVal(MCUSCR ,ISC2,INT2_TRIGGER);

	}
}

U8 MEXINTvDisable(void){
U8	L_u8VALUE;
if (INTERRUPT_PIN==INT1){
L_u8VALUE=GET_BIT(GIFR,INTF1);
while (L_u8VALUE==0){
}
SET_BIT(GIFR,INTF1);}
else if(INTERRUPT_PIN==INT0){
L_u8VALUE=GET_BIT(GIFR,INTF0);
while (L_u8VALUE==0){
}
SET_BIT(GIFR,INTF0);}
else if (INTERRUPT_PIN==INT2){

L_u8VALUE=GET_BIT(GIFR,INTF2);
while (L_u8VALUE==0){
}
SET_BIT(GIFR,INTF2);}
return GIFR;
}





