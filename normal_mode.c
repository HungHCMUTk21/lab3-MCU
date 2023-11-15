/*
 * normal_mode.c
 *
 *  Created on: Nov 16, 2023
 *      Author: PC
 */


#include "normal_mode.h"

static int lane0 = 0;
static int lane1 = 0;

void run_fsm(){
	switch(lane0){
		case RED_NORMAL:
			modify_half_0(red_duration);
			turn_on_red_lane0();
			if(timer0_flag){
				turn_off_red_lane0();
				setTimer0(green_duration * 1000);
				lane0 = GREEN_NORMAL;
			}
			break;
		case GREEN_NORMAL:
			modify_half_0(green_duration);
			turn_on_green_lane0();
			if(timer0_flag){
				turn_off_green_lane0();
				setTimer0(yellow_duration * 1000);
				lane0 = YELLOW_NORMAL;
			}
			break;
		case YELLOW_NORMAL:
			modify_half_0(yellow_duration);
			turn_on_yellow_lane0();
			if(timer0_flag){
				turn_off_yellow_lane0();
				setTimer0(red_duration * 1000);
				lane0 = RED_NORMAL;
			}
			break;
		default:
			break;
	}

	switch(lane1){
		case RED_NORMAL:
			modify_half_1(red_duration);
			turn_on_red_lane1();
			if(timer1_flag){
				turn_off_red_lane1();
				setTimer1(green_duration * 1000);
				lane1 = GREEN_NORMAL;
			}
			break;
		case GREEN_NORMAL:
			modify_half_1(green_duration);
			turn_on_green_lane1();
			if(timer1_flag){
				turn_off_green_lane1();
				setTimer1(yellow_duration * 1000);
				lane1 = YELLOW_NORMAL;
			}
			break;
		case YELLOW_NORMAL:
			modify_half_1(yellow_duration);
			turn_on_yellow_lane1();
			if(timer1_flag){
				turn_off_yellow_lane1();
				setTimer1(red_duration * 1000);
				lane1 = RED_NORMAL;
			}
			break;
		default:
			break;
	}
}

void normal_fsm(){
	if(is_button_pressed(0) && (status >= INIT_NORMAL)){
		status = INIT_SETTING;
		return;
	}

	if(status == INIT_NORMAL){
		clearAll();
		lane0 = RED_NORMAL;
		lane1 = GREEN_NORMAL;
		setTimer0(red_duration * 1000);
		setTimer1(green_duration * 1000);
		status++;
	}

	if(status == RUN_NORMAL){
		run_fsm();
	}

}
