#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include "process.h";
#include "scheduler_utilities.h";

void FCFS(Process p[], int N);
void PRIORITY_NP(Process p[], int N);
void PRIORITY_P(Process p[], int N);
void ROUND_ROBIN(Process p[], int N, int quanta);
void SJF(Process p[], int N);
void SRTF(Process p[], int N);

#endif