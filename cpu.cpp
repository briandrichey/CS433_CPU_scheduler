/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "task.h"
#include "cpu.h"

CPU::CPU() {
    waitTime[0] = 0;
    activationTime = 0;
    remainingTime = 0;
    
    //default const
}

void CPU::displayAvgWait() {
    double totalTime = 0.0;
    for (int i = 0; i < scheduled_tasks.size(); i++) {
        totalTime += waitTime[i];
    }
    std::cout << "Average wait time: " << std::fixed << std::setprecision(1) << totalTime/MAX_PROCESS << '\n';
}

void CPU::displayUtilization(){
    //activationTime = waitTime[MAX_PROCESS];
    //std::cout << "Total CPU activation: " << activationTime << '\n';
}

void CPU::displayTurnaround(){

}


