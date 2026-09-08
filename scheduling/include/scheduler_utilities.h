#ifndef SCHEDULER_UTILITIES_H
#define SCHEDULER_UTILITIES_H

#include <stdio.h>
#include "process.h"

#define SIZE 100
typedef enum Find_Policy {PID, AT, BT, PRIORITY} Find_Policy;

int is_READY_empty();
int enqueue(int list[]);
int dequeue();
int exists(const Process p[], size_t n, size_t clock);
void find_all(const Process p[], int A[], size_t n, int value, Find_Policy policy, int list[]);
int find_min_READY(const Process p[], Find_Policy policy);
int select_process(const Process p[], Find_Policy policy);

#endif