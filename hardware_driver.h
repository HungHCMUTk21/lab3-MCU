/*
 * hardware_driver.h
 *
 *  Created on: 15 Nov 2023
 *      Author: PC
 */

#ifndef INC_HARDWARE_DRIVER_H_
#define INC_HARDWARE_DRIVER_H_

#include "global.h"

//7 SEGMENT LED DISPLAY
void display7SEG(int count);
void scan_7seg();
void modify_7seg_buffer(int num1, int num2);
void modify_half_0(int num);
void modify_half_1(int num);

//LANE 0 LEDs ACTIVATION AND DEACTIVATION
//ACTIVATION (TURN ON)
void turn_on_red_lane0();
void turn_on_yellow_lane0();
void turn_on_green_lane0();
//DEACTIVATION (TURN OFF)
void turn_off_red_lane0();
void turn_off_yellow_lane0();
void turn_off_green_lane0();

//LANE 1 LEDs ACTIVATION AND DEACTIVATION
//ACTIVATION (TURN ON)
void turn_on_red_lane1();
void turn_on_yellow_lane1();
void turn_on_green_lane1();

//DEACTIVATION (TURN OFF)
void turn_off_red_lane1();
void turn_off_yellow_lane1();
void turn_off_green_lane1();

#endif /* INC_HARDWARE_DRIVER_H_ */
