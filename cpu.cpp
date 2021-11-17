/**
 * "Virtual" CPU that maintains track of timing
 */

#include <stdio.h>

#include "task.h"
#include "cpu.h"

CPU::CPU() {
    waitTime[0] = 0;  
    //default const
}

void CPU::displayAvgWait() {
    double totalWaitTime = 0.0;
    int w_count = 0;

    for (int i = 0; i < MAX_PROCESS; i++) {
        if (turnaroundTime[i] != 0) {
            w_count++;
            totalWaitTime += waitTime[i];
        }
    }
    std::cout << "Average wait time: " << std::fixed << std::setprecision(1) << totalWaitTime / w_count << '\n';
}

void CPU::displayWaitAndTurnaround(){
    for (int i = 0; i < MAX_PROCESS; i++) {
        if (turnaroundTime[i] != 0) {
            std::cout << "T" << i + 1 << " waiting time: " << waitTime[i] << ", turnaround time: " << turnaroundTime[i] << '\n';
        }
    }
}

void CPU::displayAvgTurnaround() {
    double totalTime = 0.0;
    int count = 0;          //non-zero elements in list
    for (int i = 0; i < MAX_PROCESS; i++) {
        if (turnaroundTime[i] != 0) {
            count++;
            totalTime += turnaroundTime[i];         
        }
    }
    std::cout << "Average turnaround time: " << std::fixed << std::setprecision(1) << totalTime / count << '\n';
}

