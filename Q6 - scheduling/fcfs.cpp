#include <iostream>
using namespace std;

struct process{
    int processId;
    int arrivalTime;
    int burstTime;
    int startingTime;
    int finishingTime;
    int waitingTime;
    int turnaroundTime;
};

void getProcess(process *p, int size)
{
    cout<<"\n\nEnter values :\n\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\nProcess      : P"<<i;
        p[i].processId=i;
        cout<<"\nArrival time : ";
        cin>>p[i].arrivalTime;
        cout<<"Burst time   : ";
        cin>>p[i].burstTime;
    }
}

void putProcess( process* p , int size)
{
    cout<<"\n\n";
    cout<<"\n\nProcess\t\tArrival time\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\n\nP"<<p[i].processId<<"\t\t"<<p[i].arrivalTime<<"\t\t\t"<<p[i].burstTime<<"\t\t\t"<<p[i].turnaroundTime;
        cout<<"\t\t\t"<<p[i].waitingTime<<"\t\t\t";
    }
    cout<<"\n\n";
}


void sortArrivalTime(process* p, int Size)
{
    process temp;
    int i,j;
   /* p[0] is assumed as initially sorted array */
    for(i=1; i<Size; i++)
    {
        temp=p[i];
        j = i;
        while(j>0 && temp.arrivalTime < p[j-1].arrivalTime)
        {
            p[j]=p[j-1];
            j--;
        }
        p[j]=temp;
    }
}


int main(){
    cout<<"\n\t ****************** FCFS Scheduling Technique ***************** \n";
    cout<<"\nEnter the no of processes : "; int n; cin>>n; 
    
    process *p= new process[n];
    getProcess(p,n);
    sortArrivalTime(p,n);
    
    int clock= p[0].arrivalTime;
    double sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    
    for(int i=0; i<n; i++)
    {
        p[i].startingTime= clock;
        clock+=p[i].burstTime;
        p[i].finishingTime= clock;
        p[i].turnaroundTime= p[i].finishingTime - p[i].arrivalTime;
        p[i].waitingTime= p[i].startingTime - p[i].arrivalTime;

        sumOfTurnaroundTime+=p[i].turnaroundTime;
        sumOfWaitingTime+=p[i].waitingTime;
   }
   
    putProcess(p,n);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/n);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/n);
    cout<<"\n\n\n";

    return 0;
}