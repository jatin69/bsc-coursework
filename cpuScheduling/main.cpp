#include <iostream>
using namespace std;

#include "process.h"

/** Functions used in schedule.cpp:
*/
process* getProcess(int);
process* getProcessPriority(int);
void putProcess( process* ,int);
void putProcessPriority( process* ,int);

void fcfs();
void nonPreemptiveSJF();
void preemptiveSJF();

#include "Queue_SLL.h"
/** Priority scheduling has two parts: ascending and descending :
Descending - higher number has higher priority - bool is TRUE for descending.
Ascending  - lower  number has higher priority - bool is FALSE for ascending,
*/
void nonPreemptivePriority(bool);
void preemptivePriority(bool);

void roundRobin();


int main()
{
    int choice;
    cout<<"\n\t\t************ CPU Scheduling Techniques ************\n\n";
    cout<<"\n\t1. FCFS - First Come First Serve";
    cout<<"\n\n\t2. Non-Preemptive SJF - Shortest Job First"<<"\t3. Preemptive SJF - Shortest Job First";
    cout<<"\n\n\t4. Non-Preemptive Priority Scheduling"<<"\t\t5. Preemptive Priority Scheduling";
    cout<<"\n\n\t6. Round Robin Scheduling";
    cout<<"\n\n\nEnter your choice : ";
    cin>>choice;

    cout<<"\n-------------------------------------------------------------------------------------------------------\n";
    switch(choice)
    {
    case 1:
    {
        try
        {
            fcfs();
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 2:
    {
        try
        {
            nonPreemptiveSJF();
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 3:
    {
        try
        {
            preemptiveSJF();
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 4:
    {
        int type;
        cout<<"\nEnter the type of Priority for Non-Preemtive Priority Scheduling : ";
        cout<<"\n\n\t1. Higher Number -> Higher Priority "<<"\n\t2. Lower  Number -> Higher Priority ";
        cout<<"\n\n\tEnter your choice : ";
        cin>>type;
        cout<<"\n-------------------------------------------------------------------------------------------------------\n";
        try
        {
            switch(type)
            {
            case 1 :
            {
                nonPreemptivePriority(true);
            }
            break;
            case 2 :
            {
                nonPreemptivePriority(false);
            }
            break;
            default :
                cout<<"\n\nError: Please enter a valid choice.\n";
            }
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 5:
    {
        int type;
        cout<<"\nEnter the type of Priority for Preemtive Priority Scheduling: ";
        cout<<"\n\n\t1. Higher Number -> Higher Priority "<<"\n\t2. Lower  Number -> Higher Priority ";
        cout<<"\n\n\tEnter your choice : ";
        cin>>type;
        cout<<"\n-------------------------------------------------------------------------------------------------------\n";
        try
        {
            switch(type)
            {
            case 1 :
            {
                preemptivePriority(true);
            }
            break;
            case 2 :
            {
                preemptivePriority(false);
            }
            break;
            default :
                cout<<"\n\nError: Please enter a valid choice.\n";
            }
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 6:
    {
        try
        {
            roundRobin();
        }
        catch(char const* error)
        {
            cout<<error;
        }
    }
    break;

    case 7:
    {
        cout<<"\n\t ********** User requested exit **********";
        cout<<"\n\n\tExiting ..  ..";
        cout<<"\n\n------------------------------------------------------------------------------\n";
        break;
    }

    default :
        cout<<"\n\nError: Please enter a valid choice.\n";
    }
    cout<<"\n";
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    return 0;
}

