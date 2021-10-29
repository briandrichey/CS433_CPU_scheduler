#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"
#include "task.h"

class schedule_sjf {
public:
	std::vector<task> scheduled_tasks;
	void add(char* name, int priority, int burst);
	void schedule();
private:
};