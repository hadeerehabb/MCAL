//
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_int.h"
#include "Reg.h"
#include "Pri.h"
#include "Conf.h"
#include "Int.h"

void M_ADC_vINIt()
{
	//choose the refrence voltage
	ADMUX=((ADMUX)&(ADC_VOLT_REF_BIT_MASK))|RefrecneSelection;
	//choose adjust
	CLR_BIT(ADMUX,ADLAR);
	//choose the prescaler
	ADCSRA=(ADCSRA&ADC_PRESCALER_ADCSRA_BIT_MASK)|PrescalerSelection;
	//enable the adc
	SET_BIT(ADCSRA,ADEN);
}
U16 M_ADC_u16ReadDigital(u8 A_u8ChannelId)
{
//choose channel
	ADMUX=(ADMUX&ADC_ADMUX_CHANNEL_BIT_MASK )|A_u8ChannelId;
	// start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait untill conversion is done
	while(GET_BIT(ADCSRA,ADIF)==0);
	// reset the flag
	SET_BIT(ADCSRA,ADIF);
	//get the digital value
	return ADCHL;
}
