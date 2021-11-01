#pragma once
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#include "task.h"
#include <iostream>
#include "schedule_fcfs.h"
#include "schedule_sjf.h"
#include "schedule_priority.h"
#include "schedule_rr.h"

class scheduler {
public:
	scheduler(); //default constructor

	// handles to the schedule_algos 
	schedule_fcfs fcfs;
	schedule_sjf sjf;
	schedule_priority prio;
	schedule_rr rr;

	void add(char* name, int priority, int burst);	// add a task to each of the algos
	 
	void schedule();	// invoke the schedulers

	CPU cpu_handle;
private:

};


