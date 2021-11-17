#include "scheduler.h"

scheduler::scheduler() {
	//default constructor, do something here, maybe create CPU object to track timings of each program
}

void scheduler::add(char* name, int priority, int burst) {

	fcfs.add(name, priority, burst);
	sjf.add(name, priority, burst);
	prio.add(name, priority, burst);
	rr.add(name, priority, burst);
}

void scheduler::schedule() {
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
