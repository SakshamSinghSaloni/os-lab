#include <stdio.h>
#include <stdlib.h>
#include "../include/scheduler_utilities.h"

int main(){

    int N;
    printf("\nEnter the total number of processes: ");
    scanf("%d", &N);

    int PID_list[N];
    for (size_t i = 0; i < N; i++) PID_list[i] = i;

    Process *p = malloc(sizeof(Process) * N);
    if (p == NULL) return 1;

    for (size_t i = 0; i < N; i++){
        p[i].PID = i;
        printf("\nP%d\n", i);
        printf("Arrival time = ");
        scanf("%d", &p[i].AT);
        printf("Burst Time = ");
        scanf("%d", &p[i].BT);
        p[i].CT = p[i].TAT = p[i].WT = p[i].PRIORITY = 0;
    }

    size_t clock = 0;

    int original_BT[N];
    for (size_t i = 0; i < N; i++) original_BT[i] = p[i].BT;
    
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
            running_process = select_process(p, N, BT);
            is_running = 1;
        }

        if (!is_READY_empty()) min_BT = find_min_READY(p, BT);

        //Preemption -- running the new process with minimum burst left and sending back old process back to READY simultaneously
        if (is_running == 1 && p[running_process].BT > min_BT){
            int old_process = running_process;

            running_process = select_process(p, N, BT);

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

    int total_tat = 0;
    int total_wt = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (size_t i = 0; i < N; i++){
        total_tat += p[i].TAT;
        total_wt += p[i].WT;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    
    float avg_tat = (float)total_tat / N;
    float avg_wt = (float)total_wt / N;

    printf("\nAverage TAT = %.2f", avg_tat);
    printf("\nAverage WT = %.2f", avg_wt);
}