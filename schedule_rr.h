#pragma once

class schedule_rr {
public:
	void add(char* name, int priority, int burst);
	void schedule();
private:
};