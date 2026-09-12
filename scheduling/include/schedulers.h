#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include <stddef.h>
#include "process.h"

void FCFS(Process p[], int N);
void PRIORITY_NP(Process p[], int N);
void PRIORITY_P(Process p[], int N);
void ROUND_ROBIN(Process p[], int N, int quanta);
void SJF(Process p[], int N);
void SRTF(Process p[], int N);

#endif