#include "scheduler_utilities.h"
#include "process.h"

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