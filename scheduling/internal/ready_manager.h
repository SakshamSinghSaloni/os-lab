#ifndef READY_MANAGER_H
#define READY_MANAGER_H

#include <stddef.h>
#include "../include/process.h"

#define SIZE 100

int is_READY_empty();
int enqueue(int list[]);
int dequeue();
int exists(const Process p[], size_t n, size_t clock);
void find_all(const Process p[], int A[], size_t n, int value, Policy policy, int list[]);
int find_min_READY(const Process p[], Policy policy);
int select_process(const Process p[], Policy policy);

#endif