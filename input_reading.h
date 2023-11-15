/*
 * input_reading.h
 *
 *  Created on: Nov 14, 2023
 *      Author: PC
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "global.h"

// 3 separate buttons
# define N0_OF_BUTTONS 3

//button states
#define PRESSED_BUTTON GPIO_PIN_RESET
#define RELEASED_BUTTON GPIO_PIN_SET

//hold trigger duration
#define HOLD_DURATION 30 //300ms will be considered hold down

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_duration_button_held();

#endif /* INC_INPUT_READING_H_ */
