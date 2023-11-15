/*
 * software_timer.c
 *
 *  Created on: 15 Nov 2023
 *      Author: PC
 */

#include "software_timer.h"

int timer7seg_scan_counter = 0;
int timer7seg_scan_flag = 0;

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int TIMER_CYCLE;

void setTimer7seg_scan(){
	timer7seg_scan_counter = SCAN_DURATION / TIMER_CYCLE;
	timer7seg_scan_flag = 0;
}

void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}

void setTimer1(int duration){
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void timer_run(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}

	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}

	if(timer7seg_scan_counter > 0){
		timer7seg_scan_counter--;
		if(timer7seg_scan_counter == 0) timer7seg_scan_flag = 1;
	}
}
