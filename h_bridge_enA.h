/*
 * h_bridge.h - XvR 2020
 */

#ifndef _H_BRIDGE_H_
#define _H_BRIDGE_H_

// These pins are available on the shield via the header:
//
//		Mega	Uno
// digital 5	PE3	PD5
// digital 6	PH3	PD6
// digital 9	PH6	PB1
// analog 5	PF5	PC5

// The settings below are for the Mega, modify
// in case you want to use other pins
#define PORT_RPWM	PORTH
#define PIN_RPWM	PH6 //PWN pin 9
#define DDR_RPWM	DDRH

#define PORT_LPWM	PORTH
#define PIN_LPWM	PH5 //PWM pin 8
#define DDR_LPWM	DDRH

void init_h_bridge_enA(void);
void h_bridge_set_percentage_enA(signed char percentage);

#endif /* _H_BRIDGE_H_ */
