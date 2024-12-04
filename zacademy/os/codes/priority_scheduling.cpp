#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 10000000;
const int n = 3;  

struct Process {
    int pid;     
    double bt;    
    int priority; 
};

void func0()
{
    int sum = 0;
    for(int i=0; i<6*N; i++){
        sum = sum + i;
    }
}

void func1()
{
    int sum = 0;
    for(int i=0; i<12*N; i++){
            sum = sum + i;
    }

}

void func2()
{
    int sum = 0;
    for(int i=0;i<15*N;i++){
        sum = sum + i;
    }
}


void calculateTimes(Process proc[], double wt[], double tt[]) {
    wt[0] = 0; 
    
    
    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }

    
    for (int i = 0; i < n; i++) {
        tt[i] = proc[i].bt + wt[i];
    }
}

bool comparePriority(Process a, Process b) {
    return a.priority > b.priority;
}

int main() {
    Process proc[n];
    double wt[n] = {0};
    double tt[n] = {0};

    
    clock_t start_time, end_time;

    start_time = clock();
    func0(); 
    end_time = clock();
    proc[0] = {0, static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC, 2};

    
    start_time = clock();
    func1(); 
    end_time = clock();
    proc[1] = {1, static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC, 1};

    start_time = clock();
    func2(); 
    end_time = clock();
    proc[2] = {2, static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC, 3};

   
    sort(proc, proc + n, comparePriority);

    calculateTimes(proc, wt, tt);

    cout << "Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << proc[i].pid << "\t" << proc[i].bt << "\t\t" << proc[i].priority
             << "\t\t" << wt[i] << "\t\t" << tt[i] << endl;
    }

    double avg_wt = 0;
    double avg_tt = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    avg_wt /= n;
    avg_tt /= n;

    cout << "\nAverage waiting time = " << avg_wt << endl;
    cout << "Average turnaround time = " << avg_tt << endl;

    return 0;
}
