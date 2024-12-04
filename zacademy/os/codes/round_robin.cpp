#include<bits/stdc++.h>
using namespace std;

void fun1(){
    int sum=0;
    for(int i=0;i<300000000;i++)sum++;
}
void fun2(){
    int sum=0;
    for(int i=0;i<100000000;i++)sum++;
}
void fun3(){
    int sum=0;
    for(int i=0;i<200000000;i++)sum++;
}

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum){
    
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];
 
    int current_time = 0; 
 
    while (1){

        bool done = true;
 
        for (int i = 0 ; i < n; i++){
            if (rem_bt[i] > 0){
                done = false; 
                if (rem_bt[i] > quantum){
                    current_time += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    current_time = current_time + rem_bt[i];
                    wt[i] = current_time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        } 
        if (done == true) 
        break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){

    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void displayProcessDetails(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    cout << "PN\t "<< " \tBT "
        << "      WT " << " \t         TAT\n";
 
    for (int i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];

        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl;
    }
    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
 
}

int main()
{
    int processes[] = { 1, 2, 3};
    int n = 3,quantum = 2;
    int burst_time[] = {0, 0, 0};

    clock_t start_time, end_time;
   
    start_time = clock();
    fun1();
    end_time=clock();
   
    burst_time[0] = int((end_time - start_time));

    start_time = clock();
    fun2();
    end_time=clock();
   
    burst_time[1] = int((end_time - start_time));


    start_time = clock();
    fun3();
    end_time=clock();
   
    burst_time[2] = int((end_time - start_time));

 
    displayProcessDetails(processes, n, burst_time, quantum);
}
