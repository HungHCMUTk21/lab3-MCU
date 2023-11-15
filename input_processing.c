/*
 * input_processing.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#include "input_processing.h"

void clearAll(){//function to turn everything off
	display7SEG(10);

	turn_off_red_lane1();
	turn_off_yellow_lane1();
	turn_off_green_lane1();

	turn_off_red_lane0();
	turn_off_yellow_lane0();
	turn_off_green_lane0();
}

static int toggle = 0;
static int pre_status = 0;

void setting_fsm(){
	if(is_button_pressed(0) && (status >= INIT_SETTING) && (status < GREEN_SETTING)){
		status++;
		pre_status = status;
		status = INIT_SETTING;
		toggle = 0;
	}
	if(is_button_pressed(0) && (status == GREEN_SETTING)){
		status = RED_SETTING;
		pre_status = status;
		status = INIT_SETTING;
		toggle = 0;
	}

	switch(status){
		case INIT_SETTING:
			clearAll();
			status = pre_status;
			setTimer0(BLINK_DURATION);
			toggle = 0;
			break;
		case RED_SETTING://mode 2 (set the red light mode)
			modify_7seg_buffer(red_duration, 2);
			if(timer0_flag && toggle == 0){
				turn_on_red_lane0();
				turn_on_red_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 1;
			}
			if(timer0_flag && toggle == 1){
				turn_off_red_lane0();
				turn_off_red_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 0;
			}
			if(is_button_pressed(1)){
				red_duration++;
				if(red_duration > 99){
					red_duration = 1;
				}
				modify_7seg_buffer(red_duration, 2);
			}

			break;
		case YELLOW_SETTING://mode 3
			modify_7seg_buffer(yellow_duration, 3);
			if(timer0_flag && toggle == 0){
				turn_on_yellow_lane0();
				turn_on_yellow_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 1;
			}
			if(timer0_flag && toggle == 1){
				turn_off_yellow_lane0();
				turn_off_yellow_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 0;
			}
			if(is_button_pressed(1)){
				yellow_duration++;
				if(yellow_duration > 99){
					yellow_duration = 1;
				}
				modify_7seg_buffer(yellow_duration, 3);
			}
			while(is_duration_button_held()){//the duration increases as long as the 2nd button is held
				yellow_duration++;
				if(yellow_duration > 99){
					yellow_duration = 1;
				}
				modify_7seg_buffer(yellow_duration, 3);
			}
			break;
		case GREEN_SETTING://mode 4
			modify_7seg_buffer(green_duration, 4);
			if(timer0_flag && toggle == 0){
				turn_on_green_lane0();
				turn_on_green_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 1;
			}
			if(timer0_flag && toggle == 1){
				turn_off_green_lane0();
				turn_off_green_lane1();
				setTimer0(BLINK_DURATION);
				toggle = 0;
			}
			if(is_button_pressed(1)){
				green_duration++;
				if(green_duration > 99){
					green_duration = 1;
				}
				modify_7seg_buffer(green_duration, 4);
			}
			while(is_duration_button_held()){//the duration increases as long as the 2nd button is held
				green_duration++;
				if(green_duration > 99){
					green_duration = 1;
				}
				modify_7seg_buffer(green_duration, 4);
			}
			break;
		default:
			break;
	}

	if(is_button_pressed(2)){//if the 3rd button (SET button) is pressed, went back to normal mode
		status = INIT_NORMAL;
	}
}
