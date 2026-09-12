#include "../include/schedulers.h"
#include "../internal/ready_manager.h"

void SRTF(Process p[], int N){

    int PID_list[N];
    for (size_t i = 0; i < N; i++) PID_list[i] = i;

    int original_BT[N];
    for (size_t i = 0; i < N; i++) original_BT[i] = p[i].BT;

    size_t clock = 0;

    int process_remaining = N;
    int is_running = 0; // FALSE. Currently no process is running
    int list[SIZE];
    int running_process;
    int min_BT = __INT_MAX__;

    while (process_remaining > 0){
    
        if (exists(p, N, clock)){
            find_all(p, PID_list, N, clock, AT, list);
            enqueue(list);
        }

        if (!is_READY_empty() && is_running == 0){
            running_process = select_process(p, BT);
            is_running = 1;
        }

        if (!is_READY_empty()) min_BT = find_min_READY(p, BT);

        //Preemption -- running the new process with minimum burst left and sending back old process back to READY simultaneously
        if (is_running == 1 && p[running_process].BT > min_BT){
            int old_process = running_process;

            running_process = select_process(p, BT);

            list[0] = 1;
            list[1] = old_process;
            enqueue(list);
        }

        if (is_running == 1) p[running_process].BT--;
        clock++;

        if (is_running == 1 && p[running_process].BT == 0){
            p[running_process].BT = original_BT[running_process];
            p[running_process].CT = clock;
            p[running_process].TAT = p[running_process].CT - p[running_process].AT;
            p[running_process].WT = p[running_process].TAT - p[running_process].BT;
            process_remaining--;
            is_running = 0;
        }
    }
}