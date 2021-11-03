#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include "cpu.h"
#include "task.h"

class schedule_rr {
public:
	CPU cpu_handle;
	std::vector<task> scheduled_tasks;
	std::queue<task> incomplete_tasks;	//queue so we can access front easily
	void add(char* name, int priority, int burst);
	void schedule();
private:
};