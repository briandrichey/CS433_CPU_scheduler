#pragma once
// length of a time quantum
#define QUANTUM 10
#define MAX_PROCESS 10
#include <vector>
#include <iostream>
#include <iomanip>

class CPU {
public:
	int waitTime[MAX_PROCESS] = { 0 };
	int activationTime;
	int remainingTime;

	void displayAvgWait();
	void displayTurnaround();
	void displayUtilization();

	CPU();	//constructor
	
private:

};
