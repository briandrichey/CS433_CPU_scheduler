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
	int i = 0;
	//first loop will go through scheduled_tasks, builds incomplete_tasks queue
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		temp.tid = i;	//we capture i into tid so we can alter wait times of just those elements
		
		if (temp.burst > QUANTUM) {
			temp.burst -= QUANTUM;
			cpu_handle.waitTime[i] += cpu_handle.prevExit; //wait time of T2 = T1 pre-empted time

			cpu_handle.prevExit += QUANTUM;	//the new pre-empted time is increased by QUANTUM
			cpu_handle.prevExits[i] = cpu_handle.prevExit;	//update list of exits with time

			incomplete_tasks.push(temp);	//add to list
			
		}
		else {	//if temp.burst < QUANTUM
			cpu_handle.turnaroundTime[i] += cpu_handle.prevExit + temp.burst;
			cpu_handle.waitTime[i] += cpu_handle.prevExit;	//wait time for a job with no pre-emption is just previous task exit

			cpu_handle.prevExit += temp.burst;	//the new pre-empted time is increased by remaining burst time
			cpu_handle.prevExits[i] = cpu_handle.prevExit;	
		}
		i++;
	}

	//second loop will go through the incompleted tasks until each task has burst < quantum
	while (!incomplete_tasks.empty()) {
		task temp = incomplete_tasks.front();
		if (temp.burst > QUANTUM) {
			temp.burst -= QUANTUM;
			cpu_handle.waitTime[temp.tid] += cpu_handle.prevExit - cpu_handle.prevExits[temp.tid];	//T2 wait time += previous tasks pre-emption time - the last time this task was on cpu

			cpu_handle.prevExit += QUANTUM;
			cpu_handle.prevExits[temp.tid] = cpu_handle.prevExit;
			incomplete_tasks.push(temp);
		}
		else {
			cpu_handle.turnaroundTime[temp.tid] += cpu_handle.prevExit + temp.burst;
			cpu_handle.waitTime[temp.tid] += cpu_handle.prevExit - cpu_handle.prevExits[temp.tid];
			cpu_handle.prevExit += temp.burst;
		}
		incomplete_tasks.pop();
		
	}
	cpu_handle.displayWaitAndTurnaround();
	cpu_handle.displayAvgWait();
	cpu_handle.displayAvgTurnaround();
}
