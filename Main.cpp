/**
 * Driver file
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "scheduler.h"

#define SIZE 100

int main(int argc, char* argv[])
{
    std::cout << "--------------------------------------------------" << std::endl;  
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: Jake Tremblay, Danny Ha, Brian Richey" << std::endl;
    std::cout << "Date: 10/31/2021 [happy halloween!]" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : CPU SCheduling Algorithm Simulation" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << '\n';
   

    FILE* in;
    char* temp;
    char task[SIZE]; 

    char* name;
    int priority;
    int burst;

    in = fopen(argv[1], "r");
    if (in == NULL) {
        perror("File name not found!");
        return 1;
    }

    scheduler master_scheduler;
    std::cout << "Tasks found in " << argv[1] << ":\n";
    while (fgets(task, SIZE, in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp, ",");
        priority = atoi(strsep(&temp, ","));
        burst = atoi(strsep(&temp, ","));

        std::cout << name << " " << priority << " " << burst << '\n';
        
        // add the task to the scheduler's list of tasks
        master_scheduler.add(name, priority, burst);
        
        free(temp);
    }

    fclose(in);

    // invoke the schedulers
    master_scheduler.schedule();

    return 0;
}
