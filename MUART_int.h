
#ifndef MCAL_UART_MUART_INT_H_
#define MCAL_UART_MUART_INT_H_
void MUART_voidInit();
void MUART_voidTransmitData(U16 A_U16DATA);
U16 MUART_voidRecieveData(void);
void MUART_voidSendString(U8 *A_U16DATA);

#endif /* MCAL_UART_MUART_INT_H_ */
