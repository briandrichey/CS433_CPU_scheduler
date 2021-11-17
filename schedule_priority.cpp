#include <stdlib.h>
#include <stdio.h>

#include "schedule_priority.h"
#include "task.h"


// add a new task to the list of tasks
void schedule_priority::add(char* name, int priority, int burst){
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);
}

void schedule_priority::sort(std::vector<task>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j].priority > v[j + 1].priority) {
				std::swap(v.at(j), v.at(j + 1));
			}
		}
	}
}

/**
 *  * Run the Priority scheduler
 *
 */
void schedule_priority::schedule(){

	sort(scheduled_tasks);
	
	int i = 0;
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		
		//wait time and turn around time for PRIO
		int prev_time = cpu_handle.waitTime[i];

		cpu_handle.turnaroundTime[i] = temp.burst + prev_time;
		cpu_handle.waitTime[++i] = temp.burst + prev_time;

	}
	cpu_handle.displayWaitAndTurnaround();
	cpu_handle.displayAvgWait();
	cpu_handle.displayAvgTurnaround();
}
