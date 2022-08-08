//
// #define ADMUX *(((volatile U8*)0x27))
// #define ADCHL *(((volatile U16*)0x24))
// #define ADCSRA *(((volatile  U8*)0x26))
// #define ACSR *(((volatile U8*)0x28))
//#define MUX0 0
//#define MUX1 1
//#define MUX2 2
//#define MUX3 3
//#define MUX4 4
//#define ADLAR 5
//#define REFS0 6
//#define REFS1 7
//#define ADPS0 0
//#define ADPS1 1
//#define ADPS2 2
//#define ADIE 3
//#define ADIF 4
//#define ADATE 5
//#define ADSC 6
//#define ADEN 7
// #define ACIS0 0
// #define ACIS1 1
// #define ACIC 2
// #define ACIE 3
// #define ACI 4
// #define ACO 5
// #define ACBG 6
// #define ACD 7
//define registers
#define ADMUX *(((volatile u8*)0x27))
#define ADCSRA *(((volatile u8*)0x26))
#define ADCHL *((volatile u16*)0x24)
#define SFIOR *(((volatile u8*)0x50))
//define pins
//bits for ADMUX:
#define MUX0 0   // determine which channel will be used if 00000 adc0
#define MUX1 1   //if 00001 adc1
#define MUX2 2         //and etc
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7
//bits for ACSRA
#define  ADPS0 0
#define  ADPS1 1
#define  ADPS2 2
#define  ADIE 3
#define  ADIF 4
#define  ADATE 5
#define  ADSC 6
#define  ADEN 7
//bits for SFIOR
#define PSR10 0
#define PSR2 1
#define PUD 2
#define ACME 3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7
