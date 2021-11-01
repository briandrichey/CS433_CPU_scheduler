#include <stdlib.h>
#include <stdio.h>

#include "schedule_rr.h"
#include "task.h"


// add a new task to the list of tasks
void schedule_rr::add(char* name, int priority, int burst) {
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);
}

/**
 *  * Run the RR scheduler
 *   */
void schedule_rr::schedule(){
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		while (temp.burst - QUANTUM > 0) {
			if (temp.burst > QUANTUM) {
				temp.burst -= QUANTUM;

				incomplete_tasks.push_back(temp);
			}
		}
		//calc completed task times and stuff here
	}
}
