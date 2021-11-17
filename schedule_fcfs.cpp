#include "schedule_fcfs.h"

void schedule_fcfs::add(char* name, int priority, int burst){
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);
}

/**
 *   Run the FCFS scheduler
 */
void schedule_fcfs::schedule(){
	// if they all arrive at same time, just do them one by one
	int i = 0;
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		
		//wait time and turn around time for FCFS
		int prev_time = cpu_handle.waitTime[i];

		cpu_handle.turnaroundTime[i] = temp.burst + prev_time;
		cpu_handle.waitTime[++i] = temp.burst + prev_time;

	}
	cpu_handle.displayWaitAndTurnaround();
	cpu_handle.displayAvgWait();
	cpu_handle.displayAvgTurnaround();	
}
