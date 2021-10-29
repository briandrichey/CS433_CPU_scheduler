#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "cpu.h"
#include "task.h"


class schedule_fcfs {
public:
	CPU cpu_handle;
	std::vector<task> scheduled_tasks;
	void add(char* name, int priority, int burst);
	void schedule();
private:
};

