#include "scheduler.h"

scheduler::scheduler(){
	//default constructor, do something here, maybe create CPU object to track timings of each program
}

void scheduler::add(char* name, int priority, int burst){
	//here create temp task and push it to the master_schedulers list of tasks
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);


	fcfs.add(name, priority, burst);
	sjf.add(name, priority, burst);
	//when we add to schedule_priority, we need to assign random prios 1-10
	//prio.add(name,priority,burst);
	//round robin uses time quantum 
	//rr.add(name,priority,burst);
}

void scheduler::schedule(){
	//invoke each of the algos, report time using CPU in each algo
	std::cout << "=========Running FCFS==========" << '\n';
	fcfs.schedule();
}
