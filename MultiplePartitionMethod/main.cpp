#include <iostream>
#include "Partition.h"
#include "Process.h"

using namespace std;

void firstFit(Partition*, int, Process*, int);
void bestFit(Partition*, int, Process*, int);
void worstFit(Partition*, int, Process*, int);

void enterPartitions(Partition *p, int n)
{
    int i;
    cout<<"\nEnter partitions:";
    for(i=0; i<n; i++)
    {
        cout<<"\nPartition "<<i;
        p[i].createPartition(i);
    }
}

void enterProcesses(Process *p, int n)
{
    int i;
    cout<<"\nEnter processes:";
    for(i=0; i<n; i++)
    {
        cout<<"\nProcess "<<i;
        p[i].enterProcess();
    }
}

void reset(Partition *pa, int noOfPa, Process *pr, int noOfPr)
{
    int i;
    for(i=0; i<noOfPa; i++)
    {
        pa[i].deallocateMemory();
    }

    for(i=0; i<noOfPr; i++)
    {
        pr[i].resetAllocated();
    }
}

void printInternalFragmentation(Partition *p, int n)
{
    int i;
    cout<<"\n\nId\tSize\tInternal Fragmentation";
    cout<<"\n......................................\n";
    for(i=0; i<n; i++)
    {
        cout<<p[i].retId()<<"\t"<<p[i].retSize()<<"\t";

        if(p[i].retSize() == p[i].retFreeMemory())
            cout<<"unallocated";
        else
            cout<<p[i].retFreeMemory();

        cout<<endl;
    }
}

void printExternalFragmentation(Partition *pa, int noOfPa, Process *pr, int noOfPr)
{
    int i;
    bool flag = false;

    for(i=0; i<noOfPr; i++)
    {
        if(!pr[i].isAllocated())
        {
            cout<<"\nProcess: "<<i<<"\tSize: "<<pr[i].retSize()<<"\tMust wait.";
            flag=true;
        }
    }

    if(flag == false)
    {
        cout<<"\n\nAll processes were successfully allocated. No external fragmentation.";
    }
    else
    {
        int exFr=0;
        for(i=0; i<noOfPa; i++)
        {
            exFr+= pa[i].retFreeMemory();
        }
        cout<<"\n\nExternal fragmentation: "<<exFr;
    }
}

int main()
{
    int noOfPa, noOfPr;

    cout<<"\nEnter no. of partitions: ";
    cin>>noOfPa;

    Partition *pa = new Partition[noOfPa];
    enterPartitions(pa,noOfPa);

    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nEnter no. of processes: ";
    cin>>noOfPr;


    Process *pr = new Process[noOfPr];
    enterProcesses(pr,noOfPr);

    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nFIRST FIT";
    firstFit(pa,noOfPa,pr,noOfPr);
    printExternalFragmentation(pa,noOfPa,pr,noOfPr);
    printInternalFragmentation(pa,noOfPa);
    reset(pa,noOfPa,pr,noOfPr);

    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nBEST FIT";
    bestFit(pa,noOfPa,pr,noOfPr);
    printExternalFragmentation(pa,noOfPa,pr,noOfPr);
    printInternalFragmentation(pa,noOfPa);
    reset(pa,noOfPa,pr,noOfPr);

    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nWORST FIT";
    worstFit(pa,noOfPa,pr,noOfPr);
    printExternalFragmentation(pa,noOfPa,pr,noOfPr);
    printInternalFragmentation(pa,noOfPa);

    cout<<"\n--------------------------------------------------------------------------";
    delete []pa;
    delete []pr;

    return 0;
}
