#include "schedule_sjf.h"


// add a new task to the list of tasks within schedule_sjf.h
void schedule_sjf::add(char* name, int priority, int burst) {
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
	scheduled_tasks.push_back(temp);
}


//sorts a vector of tasks by burst for SJF 
void schedule_sjf::sort(std::vector<task>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j].burst > v[j + 1].burst) {
				std::swap(v.at(j), v.at(j + 1));
			}
		}
	}
}


//SJF schedule() function: sorts vector by ascending burst size
void schedule_sjf::schedule() {
	int i = 0;

	sort(scheduled_tasks);

	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		//times for sjf
		int prev_time = cpu_handle.waitTime[i];
		cpu_handle.turnaroundTime[i] = temp.burst + prev_time;
		cpu_handle.waitTime[++i] = temp.burst + prev_time;

	}
	
	//doing a seperated printing section for sjf so it prints task name properly
	i = 0;
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		std::cout << temp.name << " waiting time: " << cpu_handle.waitTime[i] << ", turnaround time: " << cpu_handle.turnaroundTime[i] << '\n';
		i++;
	}
	cpu_handle.displayAvgWait();
	cpu_handle.displayAvgTurnaround();
}

