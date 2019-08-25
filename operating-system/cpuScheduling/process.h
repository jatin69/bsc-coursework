#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

struct process
{
    int processId;
    int startingTime;
    int finishingTime;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int priority;

    process()
    {
        processId=-1;
        startingTime=-1;
        finishingTime=-1;
        arrivalTime=-1;
        burstTime=-1;
        waitingTime=-1;
        turnaroundTime=-1;
        priority=-1;
    }

    void operator=(const process& source )
    {
        processId=source.processId;
        startingTime=source.startingTime;
        arrivalTime=source.arrivalTime;
        finishingTime=source.finishingTime;
        burstTime=source.burstTime;
        waitingTime=source.waitingTime;
        turnaroundTime=source.turnaroundTime;
        priority=source.priority;
    }

};

#endif // PROCESS_H_INCLUDED
