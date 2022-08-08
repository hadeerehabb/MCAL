#define waveform_generation_mode fast_PWM
#define prescallar               prescallar_8
#define output_mode_change_mask         0b11001111
#define generation_prescallar_mode_mask 0b11111000
#define waveform_generation_mode_mask   0b10110111
#define output_mode                     Clear_OC0_on_compare_match
#define Timer1_Channel_Selection         ChannelA
#define ChannelA_bit_mask                0b00111111
#define ChannelB_bit_mask                0b11001111
#define Timer1ICUedgeTrigger              POSITIVE_EDGE

