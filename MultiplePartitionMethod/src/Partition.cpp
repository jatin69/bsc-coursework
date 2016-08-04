#include "Partition.h"
#include<iostream>

using namespace std;

Partition::Partition()
{
    size=0;
    allocatedMemory=0;
}

void Partition:: createPartition(int i)
{
    id=i;
    do
    {
        cout<<"\nEnter size: ";
        cin>>size;
    }
    while(size <= 0);
}

void Partition:: allocateMemory(int a)
{
    allocatedMemory += a;
}

void Partition:: deallocateMemory()
{
    allocatedMemory =0;
}

int Partition:: retSize()
{
    return size;
}

int Partition:: retId()
{
    return id;
}

int Partition:: retFreeMemory()
{
    return size - allocatedMemory;
}
