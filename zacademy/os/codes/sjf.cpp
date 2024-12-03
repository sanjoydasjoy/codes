#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void abc(int id, int burst_time)
{
    printf("Inside Process %d\n", id);
    sleep(burst_time);
    for (int i = 0; i < 4 * id; i++)
    {
        for (int j = 0; j < 4 * id; j++)
        {
            printf("_ ");
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void calculateCompletionTime(struct Process processes[], int n)
{
    int current_time = 0;

    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        int min_burst = processes[i].burst_time;

        for (int j = i + 1; j < n; j++)
        {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time < min_burst)
            {
                smallest = j;
                min_burst = processes[j].burst_time;
            }
        }

        struct Process temp = processes[i];
        processes[i] = processes[smallest];
        processes[smallest] = temp;

        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }

        abc(processes[i].pid, processes[i].burst_time);
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void calculateWaitingTime(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        if (processes[i].waiting_time < 0)
        {
            processes[i].waiting_time = 0; // Waiting time cannot be negative
        }
    }
}

void displayProcessDetails(struct Process processes[], int n)
{
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;

        printf("Enter Process ID, Arrival Time, and Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    calculateCompletionTime(processes, n);
    calculateTurnaroundTime(processes, n);
    calculateWaitingTime(processes, n);

    displayProcessDetails(processes, n);

    return 0;
}
