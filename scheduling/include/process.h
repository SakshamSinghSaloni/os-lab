#ifndef PROCESS_H
#define PROCESS_H

typedef struct Process{
    int PID; // process ID
    int AT; // Arrival Time
    int BT; // Burst Time
    int CT; // Completion Time
    int TAT; // Turnaround Time
    int WT; // Waiting Time
    int PRIORITY; // Lower Priority, Higher Preference
}Process;

typedef struct{
    int PID; // PID of the process
    int ST; // Start time of the process
    int FT; // Finish time of the process
}Execution;

typedef enum Policy {PID, AT, BT, PRIORITY} Policy;
typedef enum {NON_PRIORITY_MODE, PRIORITY_MODE} InputMode;

#endif