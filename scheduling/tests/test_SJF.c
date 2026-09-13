#include <stdio.h>
#include "process.h"
#include "process_io.h"
#include "schedulers.h"

int main(){

    int N;
    do {
        printf("Enter the total number of processes: ");
        scanf("%d", &N);

        if (N < 1) printf("Enter a natural number (N > 0)!\n");
    } while (N < 1);

    Process* p = processes_init(N, PRIORITY_MODE);
    if (p == NULL) return 1;

    SJF(p, N);

    print_process_table(p, N);

    processes_dest();

    return 0;
}