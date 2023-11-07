/*
 * fsm_automatic.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Admin
 */

#include "fsm_automatic.h"

int sec1 = 0;
int sec2 = 0;
int index_led = 0;

void fsm_automatic_run(){
	switch(status){
	case INIT:
		clearAllLed();

		status = RED1_GREEN2;
		setTimer(1000, 0);

		sec1 = red;
		sec2 = green;
		updateClockBuffer(sec1, sec2);
		break;
	case RED1_GREEN2:
		turnonLight1(RED);
		turnonLight2(GREEN);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}
		updateClockBuffer(sec1, sec2);

		if(sec2 <= 0){
			status = RED1_YELLOW2;
			sec2 = yellow;
		}
		if(isButtonPressed(0) == 1){
			status = MAN_RED;
			setTimer(250, 2);
			clearAllLed();
		}
		break;
	case RED1_YELLOW2:
		turnonLight1(RED);
		turnonLight2(YELLOW);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}
		updateClockBuffer(sec1, sec2);

		if(sec2 <= 0){
			status = GREEN1_RED2;
			sec1 = green;
			sec2 = red;
		}
		break;
	case GREEN1_RED2:
		turnonLight1(GREEN);
		turnonLight2(RED);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}
		updateClockBuffer(sec1, sec2);

		if(sec1 <= 0){
			status = YELLOW1_RED2;
			sec1 = yellow;
		}
		break;
	case YELLOW1_RED2:
		turnonLight1(YELLOW);
		turnonLight2(RED);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}
		updateClockBuffer(sec1, sec2);

		if(sec1 <= 0){
			status = RED1_GREEN2;
			sec1 = red;
			sec2 = green;
		}
		break;
	default:
		break;
	}

}
