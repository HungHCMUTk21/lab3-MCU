/*
 * hardware_driver.c
 *
 *  Created on: 15 Nov 2023
 *      Author: PC
 */

#include "hardware_driver.h"

//7 segment LED
static int scan_count = 0;
//Displaying
void display7SEG (int count){
	switch(count){
		case 0:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
			break;
		case 10:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
			break;
		default:
			break;
	}
}

//update the 7seg buffer
void modify_7seg_buffer(int num1, int num2){
	buffer_7seg[0] = num1 / 10;
	buffer_7seg[1] = num1 % 10;

	buffer_7seg[2] = num2 / 10;
	buffer_7seg[3] = num2 % 10;
}
//used when only want to modify 2 7SEG led instead of all 4
void modify_half_0(int num){
	buffer_7seg[0] = num / 10;
	buffer_7seg[1] = num % 10;
}

void modify_half_1(int num){
	buffer_7seg[2] = num / 10;
	buffer_7seg[3] = num % 10;
}

//Scanning
void scan_7seg(){
	switch(scan_count){
		case 0:
			display7SEG(buffer_7seg[0]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN1_Pin | EN2_Pin | EN3_Pin, 0);
			break;
		case 1:
			display7SEG(buffer_7seg[1]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN0_Pin | EN2_Pin | EN3_Pin, 0);
			break;
		case 2:
			display7SEG(buffer_7seg[2]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN0_Pin | EN1_Pin | EN3_Pin, 0);
			break;
		case 3:
			display7SEG(buffer_7seg[3]);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN0_Pin | EN1_Pin | EN2_Pin, 0);
			break;
		default:
			break;
	}
	if(timer7seg_scan_flag){
		setTimer7seg_scan();
		scan_count++;
		if(scan_count > 3){
			scan_count = 0;
		}
	}
}


//TRAFFIC LIGHT LEDs INTERACTION

//LANE 0 LEDs ACTIVATION AND DEACTIVATION
//ACTIVATION (TURN ON)
void turn_on_red_lane0(){
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, 1);
}


void turn_on_yellow_lane0(){
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, 1);
}

void turn_on_green_lane0(){
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, 1);
}

//DEACTIVATION (TURN OFF)
void turn_off_red_lane0(){
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, 0);
}


void turn_off_yellow_lane0(){
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, 0);
}

void turn_off_green_lane0(){
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, 0);
}

//LANE 1 LEDs ACTIVATION AND DEACTIVATION
//ACTIVATION (TURN ON)
void turn_on_red_lane1(){
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
}


void turn_on_yellow_lane1(){
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);
}

void turn_on_green_lane1(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);
}

//DEACTIVATION (TURN OFF)
void turn_off_red_lane1(){
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
}


void turn_off_yellow_lane1(){
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 0);
}

void turn_off_green_lane1(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 0);
}
