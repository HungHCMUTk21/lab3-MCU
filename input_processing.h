 /*
 * input_processing.h
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

// every led blink with a freq of 2Hz -> each cycle is 0.5s
// -> turn on for 250ms and vice versa
#define BLINK_DURATION 250

#include "global.h"

void setting_fsm(); //finite state machine for setting modes
void clearAll();

#endif /* INC_INPUT_PROCESSING_H_ */
