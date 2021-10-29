#include "schedule_sjf.h"


// add a new task to the list of tasks
void schedule_sjf::add(char* name, int priority, int burst){
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
		scheduled_tasks.push_back(temp);
}

//sort fxn for 
void schedule_sjf::sort( vector<task> &v ){
	for(int i=0, i < v.size()-1, i++){
		for(int j= 0; j < v.size()-i-1; j++){
			if(v[j].burst > v[j+1].burst){
				std::swap(v.at(j),v.at(j+1));
			}
		}
	}
}

/**
 * Run the SJF scheduler
 */
void schedule_sjf::schedule(){
	int i = 0;
	for (auto it = scheduled_tasks.begin(); it != scheduled_tasks.end(); it++) {
		task temp = *(it);
		std::cout << "Processing Task: " << temp.name << " " << temp.priority << " " << temp.burst << " " << '\n';
		
		//wait time for SJF
		int prev_time = cpu_handle.waitTime[i];
		cpu_handle.waitTime[++i] = temp.burst + prev_time;

		cpu_handle.displayAvgWait();
		cpu_handle.displayUtilization();
}
