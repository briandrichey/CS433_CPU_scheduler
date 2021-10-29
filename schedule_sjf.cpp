#include "schedule_sjf.h"


// add a new task to the list of tasks
void schedule_sjf::add(char* name, int priority, int burst){
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);
}

/**
 * Run the SJF scheduler
 */
void schedule_sjf::schedule(){
	// TODO: add your implementation here
}
