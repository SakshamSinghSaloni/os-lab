#ifndef PROCESS_IO_H
#define PROCESS_IO_H

#include "process.h"

Process* processes_init(int N, InputMode mode);
Process* processes_dest();
void print_process_table(const Process *p, int N);

#endif