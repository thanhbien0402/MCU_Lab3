/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int duration, int timer);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
