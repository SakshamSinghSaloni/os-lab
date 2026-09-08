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
    return queue_count == 0;
}

int get_READY_count(){
    return queue_count;
}

// return values are treated as boolean
int exists(const Process p[], size_t n, size_t clock){
    for (size_t i = 0; i < n; i++) if (p[i].AT == clock) return 1; // exist
    return 0; // does not exist
}

/*list[0] will contain the process count
This way we will not be required to clear the list again and again*/
void find_all(const Process p[], int A[], size_t n, int value, Find_Policy policy, int list[]){
    int count = 0;
    size_t idx = 1;

    switch (policy)
    {
    case AT:
        for (size_t i = 0; i < n; i++)
            if (p[A[i]].AT == value){
                count++;
                list[idx++] = A[i];
            }
        list[0] = count;
        break;
    case BT:
        for (size_t i = 0; i < n; i++)
            if (p[A[i]].BT == value){
                count++;
                list[idx++] = A[i];
            }
        list[0] = count;
        break;
    case PRIORITY:
        for (size_t i = 0; i < n; i++)
            if (p[A[i]].PRIORITY == value){
                count++;
                list[idx++] = A[i];
            }
        list[0] = count;
        break;
    default:
        break;
    }
}

/*To find the minimum policy (PID, AT, BT, or PRIORITY) value
in the given list of PIDs*/
int find_min(const Process p[], int A[], int N, Find_Policy policy){
    int min = __INT_MAX__;
    switch (policy){
        case PID:
            for (size_t i = 0; i < N; i++) if (p[A[i]].PID < min) min = p[A[i]].PID;
            break;
        case AT:
            for (size_t i = 0; i < N; i++) if (p[A[i]].AT < min) min = p[A[i]].AT;
            break;
        case BT:
            for (size_t i = 0; i < N; i++) if (p[A[i]].BT < min) min = p[A[i]].BT;
            break;
        case PRIORITY:  
            for (size_t i = 0; i < N; i++) if (p[A[i]].PRIORITY < min) min = p[A[i]].PRIORITY;
            break;
    }

    return min;
}

int find_min_READY(const Process p[], Find_Policy policy){
    return find_min(p, READY, queue_count, policy);
}

void arr_delete(int A[], size_t n, int val){
    int del_idx;

    for (size_t i = 0; i < n; i++)
        if (A[i] == val)
            del_idx = i;
    
    for (size_t i = del_idx; i < n - 1; i++)
        A[i] = A[i + 1];
}

/* for SJF, READY does not behave as a queue
so we need separate delete logic*/
int select_process(const Process p[], Find_Policy policy){

    if (queue_count == 1){
        queue_count--;
        rear--;
        return READY[0];
    }

    int pid;
    int min_val = find_min(p, READY, queue_count, policy);
    int temp_out[SIZE];

    find_all(p, READY, queue_count, min_val, policy, temp_out);

    int temp_in[temp_out[0]];
    for (size_t i = 0; i < temp_out[0]; i++) temp_in[i] = temp_out[i + 1];

    if (temp_out[0] == 1) pid = temp_out[1];
    else{

        int min_AT = find_min(p, temp_in, temp_out[0], AT);
        find_all(p, temp_in, temp_out[0], min_AT, AT, temp_out);

        for (size_t i = 0; i < temp_out[0]; i++) temp_in[i] = temp_out[i + 1];

        if (temp_out[0] == 1) pid = temp_out[1];
        else pid = find_min(p, temp_in, temp_out[0], PID);
    }

    arr_delete(READY, queue_count, pid);
    queue_count--; rear--;
    
    return pid;
}