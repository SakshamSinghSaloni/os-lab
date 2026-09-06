#ifndef SCHEDULER_UTILITIES_H
#define SCHEDULER_UTILITIES_H

#include <stdio.h>
#include "process.h"

#define SIZE 100

int is_READY_empty();
int enqueue(int list[]);
int dequeue();
int exists(const Process p[], size_t n, size_t clock);
void find_all(const Process p[], size_t n, size_t clock, int list[]);
int SJF_delete(const Process p[]);

#endif