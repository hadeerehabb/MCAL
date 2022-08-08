
#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_int.h"

    U8 L_RETURN;
	void DIO_vWrtPinVal(U8 A_U8PortNo,U8 A_U8BitNo, U8 A_U8BitVal){
	switch ( A_U8PortNo){
	case DIO_PORTA: WRT_BIT(PORTA, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTB: WRT_BIT(PORTB, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTC: WRT_BIT(PORTC, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTD: WRT_BIT(PORTD, A_U8BitNo, A_U8BitVal); break;
	default: break;
	}
	}
	void DIO_vWrtPinDir(U8 A_U8PortNo,U8 A_U8BitNo, U8 A_U8BitVal){
	switch ( A_U8PortNo){
	case DIO_PORTA: WRT_BIT(DDRA, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTB: WRT_BIT(DDRB, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTC: WRT_BIT(DDRC, A_U8BitNo, A_U8BitVal); break;
	case DIO_PORTD: WRT_BIT(DDRD, A_U8BitNo, A_U8BitVal); break;
	default: break;
	}
	}
    U8 DIO_U8GetPinVal(U8 A_U8PortNo,U8 A_U8BitNo){
	switch ( A_U8PortNo){
	case DIO_PORTA:  L_RETURN= GET_BIT(PINA, A_U8BitNo); break;
	case DIO_PORTB:  L_RETURN= GET_BIT(PINB, A_U8BitNo); break;
	case DIO_PORTC:  L_RETURN= GET_BIT(PINC, A_U8BitNo ); break;
	case DIO_PORTD:  L_RETURN=GET_BIT(PIND, A_U8BitNo); break;
	default: break;
	}
	return L_RETURN;
	}

	void DIO_vSetPinVal(U8 A_U8PortNo,U8 A_U8BitNo){
	switch ( A_U8PortNo){
	case DIO_PORTA: SET_BIT(PORTA, A_U8BitNo); break;
	case DIO_PORTB: SET_BIT(PORTB, A_U8BitNo); break;
	case DIO_PORTC: SET_BIT(PORTC, A_U8BitNo); break;
	case DIO_PORTD: SET_BIT(PORTD, A_U8BitNo); break;
	default: break;
	}
	}
	void DIO_vClrPinVal(U8 A_U8PortNo,U8 A_U8BitNo){
	switch ( A_U8PortNo){
	case DIO_PORTA: CLR_BIT(PORTA, A_U8BitNo); break;
	case DIO_PORTB: CLR_BIT(PORTB, A_U8BitNo); break;
	case DIO_PORTC: CLR_BIT(PORTC, A_U8BitNo); break;
	case DIO_PORTD: CLR_BIT(PORTD, A_U8BitNo); break;
	default: break;
	}
	}
	void DIO_vWrtPortVal(U8 A_U8PortNo,U8 A_U8PortVal){
	switch ( A_U8PortNo){
	case DIO_PORTA: WRT_PORT(PORTA,A_U8PortVal); break;
	case DIO_PORTB: WRT_PORT(PORTB,A_U8PortVal); break;
	case DIO_PORTC: WRT_PORT(PORTC, A_U8PortVal); break;
	case DIO_PORTD: WRT_PORT(PORTD, A_U8PortVal); break;
	default: break;
	}
	}
	void DIO_vWrtPortDir(U8 A_U8PortNo,U8 A_U8PortVal){
	switch ( A_U8PortNo){
	case DIO_PORTA: WRT_PORT(DDRA, A_U8PortVal); break;
	case DIO_PORTB: WRT_PORT(DDRB, A_U8PortVal); break;
	case DIO_PORTC: WRT_PORT(DDRC, A_U8PortVal); break;
	case DIO_PORTD: WRT_PORT(DDRD, A_U8PortVal); break;
	default: break;
	}
	}


