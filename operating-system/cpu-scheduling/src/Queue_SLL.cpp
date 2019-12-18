#include <iostream>
using namespace std;

#include "Queue_SLL.h"

Queue_SLL::Queue_SLL()
{
    //constructor
    Front=0;
    Rear=0;
    length=0;
}

Queue_SLL::~Queue_SLL()
{
    //destructor
    clearQueue();
}

void Queue_SLL::enQueue(process _data)
{
    if(Rear==0)
    {
        Front=new Node(_data ,Front);
        Rear=Front;
    }
    else
    {
        Rear->next= new Node(_data);
        Rear=Rear->next;
    }
    length++;
}

void Queue_SLL::enQueueFront(process _data)
{
    Front=new Node(_data ,Front);
    if(Rear==0)
    {
        Rear=Front;
    }
}

process Queue_SLL::deQueue()
{
    if(Front==0)
    {
        throw("Error: Queue is empty !!");
    }
    if(Front->next==0)
    {
        process _data=Front->data;
        delete Front;
        Front=0;
        Rear=0;
        length--;
        return _data;
    }
    else
    {
        process _data=Front->data;
        Node *temp=Front;
        Front=Front->next;
        delete temp;
        length--;
        return _data;
    }
}

bool Queue_SLL::isEmpty()
{
    return (Front==0);
}

void Queue_SLL::clearQueue()
{
    while(Front!=0)
    {
        deQueue();
    }
}

/** Displays Gantt chart
*/
void Queue_SLL::display()
{
    if(Front==0)
    {
        return;
    }
    Node* curr, *later;
    cout<<"\n\n\nGantt chart : \n\n\n";

    cout<<"\t| ";
    for(curr=Front, later=curr->next; curr->next!=0; curr=later, later=later->next)
    {
        if(curr->data.processId != later->data.processId)
        {
            cout<<"\tP"<<curr->data.processId<<"\t|";
        }
    }
    cout<<"\tP"<<curr->data.processId<<"\t|";

    cout<<"\n";

    cout<<"\t"<<Front->data.startingTime;
    for(curr=Front, later=curr->next; curr->next!=0; curr=later, later=later->next)
    {
        if(curr->data.processId != later->data.processId)
        {
            cout<<"\t\t"<<curr->data.finishingTime;
        }
    }
    cout<<"\t\t"<<curr->data.finishingTime;
}


/** Sorts the queue in ascending order of Burst time
    using:  In-Place Insertion sort
*/
void Queue_SLL::sortBurstTime()
{
    if(Front == Rear) return ;

    // assume Front is sorted
    Node *unsort = Front->next;
    while(unsort != 0)
    {
        // take key as an element in the unsorted Node.
        Node *prev = 0;
        Node *curr = Front;
        Node *key = unsort;

        // move within the sorted Node and find the position
         while(curr != 0 && curr!=key)
       {
            if(curr->data.burstTime <= key->data.burstTime)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                break;

            }
        }
        unsort = unsort->next;
        // if reached the end of sorted Node, continue
        if(curr == key)
            continue;

        // note down the position to place
        Node *place = curr;

        //move curr to end of the sorted Node and connect with unsort
        while(curr!= 0 && curr->next != key)
        {
            curr=curr->next;
        }

        if(curr!= 0)
        {
            curr->next = unsort;
        }

        // delete the key and place it in sorted Node
        if(prev == 0)
        {
            Front = key;
        }
        else
        {
            prev->next = key;
        }
        key->next = place;
    }

    Node* temp=Front;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    Rear=temp;
}


/** Sorts the queue in Ascending order of Priority - i.e. Lower number implies higher priority
    using:  In-Place Insertion sort
    Medium Difficulty && HIGH Importance
*/
void Queue_SLL::sortAscPriority()
{
    if(Front == Rear) return ;

    // assume Front is sorted
    Node *unsort = Front->next;
    while(unsort != 0)
    {
        // take key as an element in the unsorted Node.
        Node *prev = 0;
        Node *curr = Front;
        Node *key = unsort;

        // move within the SORTED Node and find the position
        while(curr != 0 && curr!=key)
        {
            if(curr->data.priority <= key->data.priority)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                break;

            }
        }
        unsort = unsort->next;
        // if reached the end of sorted Node, continue
        if(curr == key)
            continue;

        // note down the position to place
        Node *place = curr;
        //move curr to end of the sorted Node and connect with unsort
        while(curr!= 0 && curr->next != key)
        {
            curr=curr->next;
        }

        if(curr!= 0)
        {
            curr->next = unsort;
        }

        // delete the key and place it in sorted Node
        if(prev == 0)
        {
            Front = key;
        }
        else
        {
            prev->next = key;
        }
        key->next = place;
    }

    Node* temp=Front;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    Rear=temp;
}

/** Sorts the queue in Descending order of Priority - i.e. Higher number implies higher priority
    using:  In-Place Insertion sort
*/
void Queue_SLL::sortDescPriority()
{
    if(Front == Rear) return ;

    // assume Front is sorted
    Node *unsort = Front->next;
    while(unsort != 0)
    {
        // take key as an element in the unsorted Node.
        Node *prev = 0;
        Node *curr = Front;
        Node *key = unsort;

        // move within the sorted Node and find the position
         while(curr != 0 && curr!=key)
       {
            if(curr->data.priority >= key->data.priority)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                break;

            }
        }
        unsort = unsort->next;
        // if reached the end of sorted Node, continue
        if(curr == key)
            continue;

        // note down the position to place
        Node *place = curr;

        //move curr to end of the sorted Node and connect with unsort
        while(curr!= 0 && curr->next != key)
        {
            curr=curr->next;
        }

        if(curr!= 0)
        {
            curr->next = unsort;
        }

        // delete the key and place it in sorted Node
        if(prev == 0)
        {
            Front = key;
        }
        else
        {
            prev->next = key;
        }
        key->next = place;
    }

    Node* temp=Front;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    Rear=temp;
}
