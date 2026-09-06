#include "scheduler_utilities.h"

int READY[SIZE], front = -1, rear = -1, queue_count = 0;

int enqueue(int list[]){
        
    if (queue_count + list[0] > SIZE) return 0; // OVERFLOW
        
    if (front == -1) front = 0;

    for (size_t i = 1; i <= list[0]; i++){
        rear = (rear + 1) % SIZE;
        READY[rear] = list[i];
    }

    queue_count += list[0];

    return 1; // SUCCESS
}

int dequeue(){
    if (front == -1) return -1; //UNDERFLOW

    int pid = READY[front];

    front = (front + 1) % SIZE;
    queue_count--;

    if (front == (rear + 1) % SIZE) front = rear = -1;
    
    return pid;
}

int is_READY_empty(){
    return front == -1;
}

// return values are treated as boolean
int exists(const Process p[], size_t n, size_t clock){
    for (size_t i = 0; i < n; i++) if (p[i].AT == clock) return 1; // exist
    return 0; // does not exist
}

/*list[0] will contain the process count
This way we will not be required to clear the list again and again*/
void find_all(const Process p[], size_t n, size_t clock, int list[]){
    int count = 0;
    int idx = 1;
    for (size_t i = 0; i < n; i++)
        if (p[i].AT == clock){
            count++;
            list[idx++] = p[i].PID;
        }
    list[0] = count;
}

/* for SJF, READY does not behave as a queue
so we need separate delete logic*/
int SJF_delete(const Process p[]){
    int del_idx = 0;
    int min_BT = __INT_MAX__;

    //using reverse iteration to resolve tie conditions
    for (int i = queue_count - 1; i > -1; i--){
        if (p[READY[i]].BT <= min_BT){
            min_BT = p[READY[i]].BT;
            del_idx = i;
        }
    }

    int pid = READY[del_idx];

    for (size_t i = del_idx; i < queue_count - 1; i++)
        READY[i] = READY[i + 1];

    queue_count--;
    rear--;

    return pid;
}