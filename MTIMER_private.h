#define no_clock_source 0b00000000
 #define no_prescallar  0b00000001
 #define prescallar_8   0b00000010
 #define prescallar_64  0b00000011
 #define prescallar_256 0b00000100
 #define prescallar_1024 0b00000101
 #define prescallar_falling_edge 0b00000110
 #define prescallar_rising_edge 0b00000111
#define normal_mode 0b00000000
#define PWM_phasecorrect 0b01000000  //low freq DC=ocr0*2/510
#define CTC         0b00001000       //DC=ocr0/256
#define fast_PWM    0b01001000 //fast freq
#define  OC0_disconnected         0b00000000
#define Toggle_OC0_on_comparematch_nopwm 0b00010000
#define Clear_OC0_on_compare_match 0b00100000    //NON INVERTING MODE,OFF THEN ON WHEN CMP IS DONE,timer1 and 0 are the same as channelB
#define Set_OC0_on_compare_match 0b00110000     //INVERTING MODE,ON THEN OFF WHEN CMP IS DONE
#define reserved_OC0_on_comparematch 0b00010000
#define POSITIVE_EDGE 1
#define NEGATIVE_EDGE 0
//////////////////////////////////
//#define stop 0
//#define ps1 1
//#define ps8 2
//#define ps64 3
//#define ps256 4
//#define ps1024 5
//#define Normal 0b00000000
//#define CTC 0b00001000
//#define ps_Mask 0b11111000
//#define Mode_Mask 0b10110111
//#define rising 1
//#define falling 0
