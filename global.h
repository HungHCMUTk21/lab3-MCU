/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"
#include "input_processing.h"
#include "hardware_driver.h"
#include "main.h"
#include "normal_mode.h"
//states in setting modes
#define INIT_SETTING		1
#define RED_SETTING			2
#define YELLOW_SETTING		3
#define GREEN_SETTING		4
//states in normal modes
#define INIT_NORMAL			10
#define RUN_NORMAL			11
#define RED_NORMAL			12
#define YELLOW_NORMAL		13
#define GREEN_NORMAL		14

//7 SEGMENT LED scan duration
#define SCAN_DURATION 300

extern int status, red_duration, yellow_duration, green_duration;

extern int buffer_7seg[4];

#endif /* INC_GLOBAL_H_ */
