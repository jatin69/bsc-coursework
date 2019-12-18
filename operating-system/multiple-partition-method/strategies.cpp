#include "Partition.h"
#include "Process.h"

void insertionSortSizeAsc(Partition *p, int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        j = i-1;
        Partition temp = p[i];

        while(p[j].retFreeMemory() > temp.retFreeMemory() && j>=0)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

void insertionSortSizeDesc(Partition *p, int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        j = i-1;
        Partition temp = p[i];

        while(p[j].retFreeMemory() < temp.retFreeMemory() && j>=0)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

void insertionSortID(Partition *p, int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        j = i-1;
        Partition temp = p[i];

        while(p[j].retId() > temp.retId() && j>=0)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

void firstFit(Partition *pa, int noOfPa, Process *pr, int noOfPr)
{
    int i,j;

    for(i=0; i<noOfPr; i++)
    {
        for(j=0; j<noOfPa; j++)
        {
            if(pr[i].retSize() <= pa[j].retFreeMemory())
            {
                pr[i].setAllocated();
                pa[j].allocateMemory(pr[i].retSize());
                break;
            }
        }
    }
}

void bestFit(Partition *pa, int noOfPa, Process *pr, int noOfPr)
{
    insertionSortSizeAsc(pa,noOfPa);

    int i,j;
    for(i=0; i<noOfPr; i++)
    {
        for(j=0; j<noOfPa; j++)
        {
            if(pr[i].retSize() <= pa[j].retFreeMemory())
            {
                pr[i].setAllocated();
                pa[j].allocateMemory(pr[i].retSize());
                insertionSortSizeAsc(pa,noOfPa);
                break;
            }
        }
    }

    insertionSortID(pa,noOfPa);
}

void worstFit(Partition *pa, int noOfPa, Process *pr, int noOfPr)
{
    insertionSortSizeDesc(pa,noOfPa);

    int i,j;
    for(i=0; i<noOfPr; i++)
    {
        for(j=0; j<noOfPa; j++)
        {
            if(pr[i].retSize() <= pa[j].retFreeMemory())
            {
                pr[i].setAllocated();
                pa[j].allocateMemory(pr[i].retSize());
                insertionSortSizeDesc(pa,noOfPa);
                break;
            }
        }
    }

    insertionSortID(pa,noOfPa);
}
