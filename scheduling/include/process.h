#ifndef PROCESS_H
#define PROCESS_H

typedef struct Process{
    int PID; // process ID
    int AT; // Arrival Time
    int BT; // Burst Time
    int CT; // Completion Time
    int TAT; // Turnaround Time
    int WT; // Waiting Time
    int PRIORITY;
}Process;

#endif