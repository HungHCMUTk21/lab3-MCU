/*
 * software_timer.h
 *
 *  Created on: 15 Nov 2023
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer7seg_scan();
void timer_run();

//variable to calculate the timer cycle from the TIM2 values.
extern int TIMER_CYCLE;

//timer flags
extern int timer7seg_scan_flag;
extern int timer0_flag;
extern int timer1_flag;


#endif /* INC_SOFTWARE_TIMER_H_ */
