#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"
#include "task.h"

class schedule_rr {
public:
	CPU cpu_handle;
	std::vector<task> scheduled_tasks;
	std::vector<task> incomplete_tasks;
	void add(char* name, int priority, int burst);
	void schedule();
private:
};