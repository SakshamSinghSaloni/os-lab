#include <stdio.h>
#include <stdlib.h>
#include "../include/schedulers.h"
#include "../include/process.h"

Process* processes_init(int N, Policy policy){

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

        if (policy == PRIORITY){
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

int enter_value(){
    int n;

    do{
        printf("Enter : ");
        scanf("%d", &n);

        if (n < 1) printf("Enter value greater than 0!\n");
    
    } while (n < 1);

    return n;
}

void print_process_table(const Process *p, int N){

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tPRIORITY\n");

    for (size_t i = 0; i < N; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].PRIORITY);
        
}

int main(){

    printf("Processes ");
    int N = enter_value();

    printf("Quanta ");
    int quanta = enter_value();
    
    Process *p = processes_init(N, PID);
    // Process* p = processes_init(N, PRIORITY);

    // FCFS(p, N);
    // SJF(p, N);
    // SRTF(p, N);
    // PRIORITY_NP(p, N);
    // PRIORITY_P(p, N);
    ROUND_ROBIN(p, N, quanta);

    print_process_table(p, N);

    processes_dest(p);
}