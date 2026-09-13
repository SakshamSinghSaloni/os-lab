#include <stdio.h>
#include <stdlib.h>
#include "../include/schedulers.h"
#include "../include/process.h"

Process* processes_init(int N, InputMode mode){

    if (N < 1) return NULL;
    Process* p = malloc(sizeof(Process) * N);
    if (p == NULL) return NULL;

    for (size_t i = 0; i < N; i++){

        printf("P%d\n", i);

        p[i].PID = i;

        printf("Arrival Time = ");
        scanf("%d", &p[i].AT);

        printf("Burst Time = ");
        scanf("%d", &p[i].BT);

        p[i].CT = p[i].TAT = p[i].WT = 0;

        if (mode == PRIORITY_MODE){
            printf("Priority = ");
            scanf("%d", &p[i].PRIORITY);
        }

        else p[i].PRIORITY = 0;

    }

    return p;
}

void processes_dest(Process* p){
    free(p);
}

void print_process_table(const Process *p, int N){

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tPRIORITY\n");

    for (size_t i = 0; i < N; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].PRIORITY);
        
}