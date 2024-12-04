#include <stdio.h>

typedef struct {
    int pid, burst_time, completion_time, turnaround_time, waiting_time;
} Process;

void calculateTimes(Process p[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += p[i].burst_time;
        p[i].completion_time = current_time;
        p[i].turnaround_time = p[i].completion_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void printTable(Process p[], int n) {
    printf("\nPID\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst_time, 
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
    }

    calculateTimes(p, n);
    printTable(p, n);
    return 0;
}

