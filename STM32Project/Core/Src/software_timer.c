/*
 * software_timer.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Admin
 */

#include "software_timer.h"

int timer_counter[10] = {0};
int timer_flag[10] = {0};

void setTimer(int duration, int timer){
	timer_counter[timer] = duration / 10;
	timer_flag[timer] = 0;
}
void timerRun(){
	for(int i = 0; i <= 5; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
