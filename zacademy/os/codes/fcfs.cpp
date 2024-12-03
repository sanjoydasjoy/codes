#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Process " << i + 1 << ":\n";
        cout << "PID: ";
        cin >> processes[i].pid;
        cout << "Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Burst Time: ";
        cin >> processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         {
        if(a.arrival_time == b.arrival_time)
            return a.pid < b.pid; 
        return a.arrival_time < b.arrival_time; });

    int current_time = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;

        cout << "Inside Process with PID : " << processes[i].pid << endl;

        for (long long j = 0; j < 1000000000; j++)
            ;

        cout << "Process with PID : " << processes[i].pid << " completed" << endl;

        current_time += processes[i].burst_time;

        processes[i].turnaround_time = current_time - processes[i].arrival_time;
    }

    cout << "\nFCFS Scheduling Results:\n";
    cout << left << '\t' << "PID"
         << '\t' << "Arrival Time"
         << '\t' << "Burst Time"
         << '\t' << "Waiting Time"
         << '\t' << "Turnaround Time" << endl;
    cout << "-----------------------------------------------------------------------\n";

    for (auto &p : processes)
    {
        cout << left << '\t' << p.pid
             << '\t' << p.arrival_time
             << '\t' << p.burst_time
             << '\t' << p.waiting_time
             << '\t' << p.turnaround_time << endl;
    }

    return 0;
}
