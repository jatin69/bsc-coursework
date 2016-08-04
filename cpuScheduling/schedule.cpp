#include <iostream>
using namespace std;
#include <stdlib.h>
// #include <iomanip>

#define border cout<<"\n-------------------------------------------------------------------------------\n"
#include "process.h"
#include "Queue_SLL.h"


/* prototype: process* getProcess(int);
parameter: 'n' which is the number of processes required by user.
Working: allocates memory for 'n' processes and takes input of processes from user.
Return type: returns a pointer to the newly allocated array of processes.
*/
process* getProcess(int size)
{
    process *p= new process[size];
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
    return p;
}

/* prototype: void putProcess( process* p , int size);
parameter: base pointer to an array of "process" type objects and "size" of array
Working: Displays table showing all contents of the process
return type : None
*/
void putProcess( process* p , int size)
{
    cout<<"\n\n";
    cout<<"\n\nProcess\t\tArrival time\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\t\tStarting Time\t\tFinishing Time\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\n\nP"<<p[i].processId<<"\t\t"<<p[i].arrivalTime<<"\t\t\t"<<p[i].burstTime<<"\t\t\t"<<p[i].turnaroundTime;
        cout<<"\t\t\t"<<p[i].waitingTime<<"\t\t\t"<<p[i].startingTime<<"\t\t\t"<<p[i].finishingTime<<"\t\t\t";
    }
    cout<<"\n\n";
}

/* prototype: process* getProcessPriority(int);
######### Used in case of priority scheduling ###########
parameter: 'n' which is the number of processes required by user.
Working: allocates memory for 'n' processes and takes input of processes from user.
Return type: returns a pointer to the newly allocated array of processes.
*/
process* getProcessPriority(int size)
{
    process *p= new process[size];
    cout<<"\n\nEnter values :\n\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\nProcess      : P"<<i;
        p[i].processId=i;
        cout<<"\nArrival time : ";
        cin>>p[i].arrivalTime;
        cout<<"Burst time   : ";
        cin>>p[i].burstTime;
        cout<<"priority     : ";
        cin>>p[i].priority;
    }
    return p;
}

/* prototype: void putProcessPriority( process* p , int size);
######### Used in case of priority scheduling ###########
parameter: base pointer to an array of "process" type objects and "size" of array
Working: Displays table showing all contents of the process
return type : None
*/
void putProcessPriority( process* p , int size)
{
    cout<<"\n\n";
    cout<<"\n\nProcess\t\tArrival time\tBurst Time\tPriority\t\tTurnaround Time\t\tWaiting Time\tStarting Time\t\tFinishing Time\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\n\nP"<<p[i].processId<<"\t\t"<<p[i].arrivalTime<<"\t\t"<<p[i].burstTime<<"\t\t"<<p[i].priority<<"\t\t\t";
        cout<<p[i].turnaroundTime<<"\t\t\t"<<p[i].waitingTime<<"\t\t"<<p[i].startingTime<<"\t\t\t"<<p[i].finishingTime<<"\t\t\t";
    }
    cout<<"\n\n";
}

/* prototype : void sortArrivalTime(process* p, int Size);
parameter: base pointer to an array of "process" type objects and "size" of array
working: applies basic insertion sort and sorts in ascending order of Arrival time
return type : None
*/
void sortArrivalTime(process* p, int Size)
{
    // size is the actual size,, the last index is obviously size-1
    process temp;
    int i,j;
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


/* prototype: void fcfs();
parameter: None.
Working: Implements "First Come First Serve" Logic.
Return type: None.
*/
void fcfs()
{
    Queue_SLL readyQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n";
        exit(1);
    }
    process *p=getProcess(size);

    border;
    cout<<"\nFCFS applied :";
    sortArrivalTime(p,size);

    int clock= p[0].arrivalTime;
    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;

    for(int i=0; i<size; i++)
    {
        p[i].startingTime= clock;
        clock+=p[i].burstTime;
        p[i].finishingTime= clock;
        p[i].turnaroundTime= p[i].finishingTime - p[i].arrivalTime;
        p[i].waitingTime= p[i].startingTime - p[i].arrivalTime;

        sumOfTurnaroundTime+=p[i].turnaroundTime;
        sumOfWaitingTime+=p[i].waitingTime;

        readyQueue.enQueue(p[i]);   // push in ready queue
    }

    cout<<endl;
    // displaying gantt chart
    readyQueue.display();
    putProcess(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";
}

/* prototype: void nonPreemptiveSJF();
parameter: None.
Working: Implements Non-Preemptive "Shortest Job First" Logic.
Return type: None.
*/
void nonPreemptiveSJF()
{
    Queue_SLL readyQueue, intermediateQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n";
        exit(1);
    }
    process *p=getProcess(size);

    border;
    cout<<"\nNon-Preemptive SJF applied :";
    sortArrivalTime(p,size);

    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    int clock= p[0].arrivalTime;
    process currentProcess;
    int j=-1;

    while( (j+1)<size || !intermediateQueue.isEmpty())
    {
        for(int i=j+1; i<size && (p[i].arrivalTime <=clock) ; i++)
        {
            intermediateQueue.enQueue(p[i]);
            j=i;
        }

        intermediateQueue.sortBurstTime();

        currentProcess= intermediateQueue.deQueue();
        currentProcess.startingTime=clock;
        clock=clock+ currentProcess.burstTime;
        currentProcess.finishingTime=clock;
        currentProcess.turnaroundTime= currentProcess.finishingTime - currentProcess.arrivalTime;
        currentProcess.waitingTime= currentProcess.startingTime - currentProcess.arrivalTime;

        readyQueue.enQueue(currentProcess);
    }

    cout<<endl;
    // displaying gantt chart
    readyQueue.display();

    // assignment from queue to array
    process temp;
    while(!readyQueue.isEmpty())
    {
        temp=readyQueue.deQueue();
        sumOfTurnaroundTime+= temp.turnaroundTime;
        sumOfWaitingTime+= temp.waitingTime;
        p[temp.processId]=temp;
    }

    putProcess(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";
}

/* prototype: void preemptiveSJF();
parameter: None.
Working: Implements Preemptive "Shortest Job First" Logic.
Return type: None.
*/
void preemptiveSJF()
{
    Queue_SLL readyQueue, intermediateQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n2";
        exit(1);
    }
    process *p=getProcess(size);

    border;
    cout<<"\nPreemptive SJF applied :";
    sortArrivalTime(p,size);

    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    int clock= p[0].arrivalTime;
    process currentProcess;
    int j=-1;

    while( (j+1)<size || !intermediateQueue.isEmpty())
    {
        for(int i=j+1; i<size && (p[i].arrivalTime <=clock) ; i++)
        {
            intermediateQueue.enQueue(p[i]);
            j=i;
        }

        intermediateQueue.sortBurstTime();

        currentProcess= intermediateQueue.deQueue();
        currentProcess.startingTime=clock;

        if(p[currentProcess.processId].startingTime == -1)
        {
            // if a process is coming first time, set its starting time in array
            p[currentProcess.processId].startingTime = currentProcess.startingTime;
            // this is basic waiting time before starting
            p[currentProcess.processId].waitingTime =  p[currentProcess.processId].startingTime -  p[currentProcess.processId].arrivalTime;
        }
        else
        {
            /*    the logic of -  (currentProcess.finishingTime - currentProcess.startingTime);
            works because : the start time is modified according to current entry
            but the finishing time is still of the previous occurrence object.

            This is required because : It need to be updated by consecutive waiting times - in between the ready queue
            */
            p[currentProcess.processId].waitingTime += (currentProcess.startingTime - currentProcess.finishingTime);
        }

        clock ++;
        currentProcess.burstTime--;
        currentProcess.finishingTime=clock;
        if(currentProcess.burstTime != 0)
        {
            intermediateQueue.enQueueFront(currentProcess);
        }
        else
        {
            // setting final finish time in array
            p[currentProcess.processId].finishingTime=currentProcess.finishingTime;
        }

        readyQueue.enQueue(currentProcess);
    }

    readyQueue.display();

    for(int i=0; i<size; i++)
    {
        p[i].turnaroundTime= p[i].finishingTime - p[i].arrivalTime;
        sumOfTurnaroundTime+=p[i].turnaroundTime;
        sumOfWaitingTime+= p[i].waitingTime;
    }

    putProcess(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";
}


/* prototype: void nonPreemptivePriority();
parameter: None.
Working: Implements Non-Preemptive "Priority Scheduling" Logic.
Return type: None.
*/
void nonPreemptivePriority(bool typeOfPriority)
{
    Queue_SLL readyQueue, intermediateQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n";
        exit(1);
    }
    process *p=getProcessPriority(size);

    border;
    cout<<"\nNon-Preemptive Priority Scheduling applied :";
    sortArrivalTime(p,size);

    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    int clock= p[0].arrivalTime;
    process currentProcess;
    int j=-1;

    while( (j+1)<size || !intermediateQueue.isEmpty())
    {
        for(int i=j+1; i<size && (p[i].arrivalTime <=clock) ; i++)
        {
            intermediateQueue.enQueue(p[i]);
            j=i;
        }

        if(typeOfPriority)
        {
            intermediateQueue.sortDescPriority();
        }
        else
        {
            intermediateQueue.sortAscPriority();
        }

        currentProcess= intermediateQueue.deQueue();
        currentProcess.startingTime=clock;
        clock=clock+ currentProcess.burstTime;
        currentProcess.finishingTime=clock;
        currentProcess.turnaroundTime= currentProcess.finishingTime - currentProcess.arrivalTime;
        currentProcess.waitingTime= currentProcess.startingTime - currentProcess.arrivalTime;

        readyQueue.enQueue(currentProcess);
    }

    cout<<endl;
    // displaying gantt chart
    readyQueue.display();

    // assignment from queue to array
    process temp;
    while(!readyQueue.isEmpty())
    {
        temp=readyQueue.deQueue();
        sumOfTurnaroundTime+= temp.turnaroundTime;
        sumOfWaitingTime+= temp.waitingTime;
        p[temp.processId]=temp;
    }

    putProcessPriority(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";

}

/* prototype: void preemptivePriority();
parameter: None.
Working: Implements preemptive "Priority Scheduling" Logic.
Return type: None.
*/
void preemptivePriority(bool typeOfPriority)
{
    Queue_SLL readyQueue, intermediateQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n2";
        exit(1);
    }
    process *p=getProcessPriority(size);

    border;
    cout<<"\nPreemptive Priority Scheduling applied :";
    sortArrivalTime(p,size);
    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    int clock= p[0].arrivalTime;
    process currentProcess;
    int j=-1;

    while( (j+1)<size || !intermediateQueue.isEmpty())
    {
        for(int i=j+1; i<size && (p[i].arrivalTime <=clock) ; i++)
        {
            intermediateQueue.enQueue(p[i]);
            j=i;
        }

         if(typeOfPriority)
        {
            intermediateQueue.sortDescPriority();
        }
        else
        {
            intermediateQueue.sortAscPriority();
        }

        currentProcess= intermediateQueue.deQueue();
        currentProcess.startingTime=clock;

        if(p[currentProcess.processId].startingTime == -1)
        {
            // if a process is coming first time, set its starting time in array
            p[currentProcess.processId].startingTime = currentProcess.startingTime;
            // this is basic waiting time before starting
            p[currentProcess.processId].waitingTime =  p[currentProcess.processId].startingTime -  p[currentProcess.processId].arrivalTime;
        }
        else
        {
            /*    the logic of -  (currentProcess.finishingTime - currentProcess.startingTime);
            works because : the start time is modified according to current entry
            but the finishing time is still of the previous occurrence object.

            This is required because : It need to be updated by consecutive waiting times - in between the ready queue
            */
            p[currentProcess.processId].waitingTime += (currentProcess.startingTime - currentProcess.finishingTime);
        }

        clock ++;
        currentProcess.burstTime--;
        currentProcess.finishingTime=clock;
        if(currentProcess.burstTime != 0)
        {
            intermediateQueue.enQueueFront(currentProcess);
        }
        else
        {
            // setting final finish time in array
            p[currentProcess.processId].finishingTime=currentProcess.finishingTime;
        }

        readyQueue.enQueue(currentProcess);
    }

    readyQueue.display();

    for(int i=0; i<size; i++)
    {
        p[i].turnaroundTime= p[i].finishingTime - p[i].arrivalTime;
        sumOfTurnaroundTime+=p[i].turnaroundTime;
        sumOfWaitingTime+= p[i].waitingTime;
    }

    putProcessPriority(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";
}


/* prototype: void roundRobin();
parameter: None.
Working: Implements preemptive "Round Robin Scheduling" Logic.
Return type: None.
*/
void roundRobin()
{
    Queue_SLL readyQueue, intermediateQueue;
    int size;
    cout<<"\nEnter the number of processes : ";
    cin>>size;
    if(size==0)
    {
        cout<<"\nThe Force has Awaken !! \tRUN !!\n\n\n2";
        exit(1);
    }
    process *p=getProcess(size);

    int Tq;
    cout<<"\nEnter the time duration of Tq : ";
    cin>>Tq;

    border;
    cout<<"\nRound Robin applied :";
    sortArrivalTime(p,size);

    float sumOfTurnaroundTime=0,sumOfWaitingTime=0;
    int clock= p[0].arrivalTime;
    process currentProcess;
    int j=-1;

    while( (j+1)<size || !intermediateQueue.isEmpty())
    {
        for(int i=j+1; i<size && (p[i].arrivalTime <=clock) ; i++)
        {
            intermediateQueue.enQueue(p[i]);
            j=i;
        }

        currentProcess= intermediateQueue.deQueue();
        currentProcess.startingTime=clock;

        if(p[currentProcess.processId].startingTime == -1)
        {
            // if a process is coming first time, set its starting time in array
            p[currentProcess.processId].startingTime = currentProcess.startingTime;
            // this is basic waiting time before starting
            p[currentProcess.processId].waitingTime =  p[currentProcess.processId].startingTime -  p[currentProcess.processId].arrivalTime;
        }
        else
        {
            /*    the logic of -  (currentProcess.finishingTime - currentProcess.startingTime);
            works because : the start time is modified according to current entry
            but the finishing time is still of the previous occurrence object.

            This is required because : It need to be updated by consecutive waiting times - in between the ready queue
            */
            p[currentProcess.processId].waitingTime += (currentProcess.startingTime - currentProcess.finishingTime);
        }

        // for handling the burst times which are not perfect divisors of the Time Quantum
        for(int k=1;k<=Tq;k++){
            clock++;
            currentProcess.burstTime--;
            if(currentProcess.burstTime==0){
                break;
            }
        }
        currentProcess.finishingTime=clock;

        if(currentProcess.burstTime != 0)
        {
            intermediateQueue.enQueue(currentProcess);
        }
        else
        {
            // setting final finish time in array
            p[currentProcess.processId].finishingTime=currentProcess.finishingTime;
        }

        readyQueue.enQueue(currentProcess);
    }

    readyQueue.display();

    for(int i=0; i<size; i++)
    {
        p[i].turnaroundTime= p[i].finishingTime - p[i].arrivalTime;
        sumOfTurnaroundTime+=p[i].turnaroundTime;
        sumOfWaitingTime+= p[i].waitingTime;
    }

    putProcess(p,size);
    cout<<"\n\n\t\tAverage Turnaround Time is : "<<(sumOfTurnaroundTime/size);
    cout<<"\n\n\t\tAverage Waiting Time is    : "<<(sumOfWaitingTime/size);
    cout<<"\n\n\n\n";

}

