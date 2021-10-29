#include "schedule_sjf.h"


// add a new task to the list of tasks
void schedule_sjf::add(char* name, int priority, int burst){
	task temp;
	temp.name = name, temp.priority = priority, temp.burst = burst;
		scheduled_tasks.push_back(temp);
}

//sort fxn for 
void schedule_sjf::sort( vector<task> &v ){
	for(int i=v.begin(), i < v.end(), i++){
		for(int j= v.begin()+1; j < v.end()-i; j++){
			if(temp1[j].burst > temp2[j+1].burst){
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
