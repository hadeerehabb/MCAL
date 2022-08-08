#define ADC_PRESCALER_ADCSRA_BIT_MASK 0b11111000
#define ADC_VOLT_REF_BIT_MASK         0b00111111
#define ADC_ADMUX_CHANNEL_BIT_MASK 0b11100000
#define ADC_ADJUST_BIT_MASK        0b11011111
#define ADC_PRESCALER_DIV_FACTOR2  0b00000000
#define ADC_PRESCALER_DIV_FACTOR4  0b00000010
#define ADC_PRESCALER_DIV_FACTOR8  0b00000011
#define ADC_PRESCALER_DIV_FACTOR16 0b00000100
#define ADC_PRESCALER_DIV_FACTOR32 0b00000101
#define ADC_PRESCALER_DIV_FACTOR64 0b00000110
#define ADC_PRESCALER_DIV_FACTOR128 0b00000111
#define VOLTAGE_REF_AREF            0b00000000
#define VOLTAGE_REF_AVCC            0b01000000
#define VOLTAGE_REF_RESERVED        0b10000000
#define VOLTAGE_REF_INTWITHEXTERNALCAP    0b11000000

//refrence selection:
//#define EXT 0
//#define VCC 1
//#define internal 3
//adjust direction
#define AdjustLeft 1
#define AdjustRight 0b00000000
//prescaler selection
//#define PS2 0 //prescallar
//#define PS4 2
//define PS8 3
//#define PS16 4
//#define PS32 5
//#define PS64 6
//#define PS128 7
