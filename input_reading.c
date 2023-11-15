/*
 * input_reading.c
 *
 *  Created on: Nov 14, 2023
 *      Author: PC
 */

#include "input_reading.h"

// buffer for button result after debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
// three buffers for debouncing
static GPIO_PinState debounceBuffer_1[N0_OF_BUTTONS]; //newest state
static GPIO_PinState debounceBuffer_2[N0_OF_BUTTONS]; //prev state
static GPIO_PinState debounceBuffer_3[N0_OF_BUTTONS]; //state-before-prev state

// flag for duration button if it's held down
static GPIO_PinState duration_button_hold_flag = 0;
// a counter for duration button if it's held down
static uint16_t duration_button_counter = 0;

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer [index] == PRESSED_BUTTON);
}

unsigned char is_duration_button_held(){
	return (duration_button_hold_flag == 1);
}

void button_reading(void){
	//loop to register debouncing buffers
	for (int i = 0; i < N0_OF_BUTTONS; i++){
		debounceBuffer_3[i] = debounceBuffer_2[i];
		debounceBuffer_2[i] = debounceBuffer_1[i];
	}
	//assign the newest data received to the buffer
	debounceBuffer_1[0] = HAL_GPIO_ReadPin (MODE_GPIO_Port, MODE_Pin);
	debounceBuffer_1[1] = HAL_GPIO_ReadPin (DURATION_GPIO_Port, DURATION_Pin);
	debounceBuffer_1[2] = HAL_GPIO_ReadPin (SET_GPIO_Port, SET_Pin);

	for (int i = 0; i < N0_OF_BUTTONS; i ++){
		//button state accepted after checking the previous state
		//AND the the state-before-previous state
		if((debounceBuffer_1[i] == debounceBuffer_2[i])
			== (debounceBuffer_2[i] == debounceBuffer_3[i])
			== (debounceBuffer_1[i] == debounceBuffer_3[i])){
			buttonBuffer[i] = debounceBuffer_1[i];
		}
	}

	//duration button, hold case
	if(buttonBuffer[1] == PRESSED_BUTTON){
		// if the duration button is pressed , we start counting
		if(duration_button_counter < HOLD_DURATION){
			duration_button_counter++;
		}else{
			// the flag will be triggered once the hold duration is satisfied (300ms)
			duration_button_hold_flag = 1;
		}
	}else{
		duration_button_counter = 0;
		duration_button_hold_flag = 0;
	}
}
