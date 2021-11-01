#include "scheduler.h"

scheduler::scheduler(){
	//default constructor, do something here, maybe create CPU object to track timings of each program
}

void scheduler::add(char* name, int priority, int burst){
	//here create temp task and push it to the master_schedulers list of tasks
	//task temp;
	//temp.name = name, temp.priority = priority, temp.burst = burst;
	//cpu_handle.scheduled_tasks.push_back(temp);


	fcfs.add(name, priority, burst);
	sjf.add(name, priority, burst);
	prio.add(name,priority,burst);
	rr.add(name,priority,burst);
}

void scheduler::schedule(){
	//invoke each of the algos, report time using CPU in each algo
	std::cout << "=========Running FCFS==========" << '\n';
	fcfs.schedule();

	std::cout << "=========Running SJF==========" << '\n';
	sjf.schedule();

	std::cout << "=========Running PRIORITY==========" << '\n';
	prio.schedule();

	std::cout << "=========Running ROUND ROBIN==========" << '\n';
	rr.schedule();
}
