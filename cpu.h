#pragma once
// length of a time quantum
#define QUANTUM 10
#define MAX_PROCESS 100
#include <vector>
#include <iostream>
#include <iomanip>
#include "task.h"

class CPU {
public:
	int waitTime[MAX_PROCESS] = { 0 };
	int turnaroundTime[MAX_PROCESS] = { 0 };
	int remainingTime[MAX_PROCESS] = { 0 };
	int prevExits[MAX_PROCESS] = { 0 };
	int prevExit = 0;	

	void displayWaitAndTurnaround();
	void displayAvgWait();
	void displayAvgTurnaround();
	
	CPU();	//constructor
private:
};
