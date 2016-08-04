#include "Process.h"
#include<iostream>

using namespace std;

Process::Process()
{
    size=0;
    allocated=false;
}

void Process:: enterProcess()
{
    do
    {
        cout<<"\nEnter size: ";
        cin>>size;
    }
    while(size <= 0);
}

void Process:: setAllocated()
{
    allocated = true;
}

void Process:: resetAllocated()
{
    allocated = false;
}

int Process:: retSize()
{
    return size;
}

bool Process:: isAllocated()
{
    return allocated;
}
