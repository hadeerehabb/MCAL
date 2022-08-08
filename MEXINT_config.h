/*
 * MEXINT_config.h
 *
 *  Created on: Jun 2, 2022
 *      Author: weza
 */

#ifndef MCAL_INT_MEXINT_CONFIG_H_
#define MCAL_INT_MEXINT_CONFIG_H_
#define INTERRUPT_PIN  INT1                                                //OPTIONS INT1,INT0 low level interrupts,INT2 egde interrupt
#define SENSE_CONTROL INTERRUPT_RISING_EDGE_LEVEL_1SENSE_CONTROL
#define MCUCR_MASK 0b11110000
#define INT2_TRIGGER   INT2_TRIGGER_positive_edge
#endif /* MCAL_INT_MEXINT_CONFIG_H_ */
