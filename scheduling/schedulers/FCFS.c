#include "../include/schedulers.h"

void FCFS(Process p[], int N){

    int PID_list[N];
    for (size_t i = 0; i < N; i++) PID_list[i] = i;

    size_t clock = 0;
    
    int process_remaining = N;
    int is_running = 0; // FALSE. Currently no process is running
    int list[SIZE];
    int running_process;

    while (process_remaining > 0){
    
        if (exists(p, N, clock)){
            find_all(p, PID_list, N, clock, AT, list);
            enqueue(list);
        }

        if (!is_READY_empty() && is_running == 0){
            running_process = dequeue();
            p[running_process].CT = clock + p[running_process].BT;
            is_running = 1;
        }

        clock++;

        if (is_running == 1 && clock == p[running_process].CT){
            p[running_process].TAT = p[running_process].CT - p[running_process].AT;
            p[running_process].WT = p[running_process].TAT - p[running_process].BT;
            process_remaining--;
            is_running = 0;
        }
    }
}