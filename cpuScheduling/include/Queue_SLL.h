#ifndef QUEUE_SLL_H
#define QUEUE_SLL_H

/* The "Node" holds a data, which is of process type.
*/
#include "../process.h"


/* This is a Node structure for implementing Queue_SLL.
It holds data which is of "process" type and a normal Node* to point to next.
*/
struct Node
{
    process data;
    Node* next;
    Node(process _data, Node* _node=0)
    {
        data=_data;
        next=_node;
    }
};

/* This is a Queue made by SLL, works as dynamic queue for filling up processes.
*/
class Queue_SLL
{
private:
    Node* Front;
    Node* Rear;
    int length;

public:
    /** Default constructor */
    Queue_SLL();

    /** Default destructor */
    ~Queue_SLL();

    /* enQueue(process) is add to rear */
    void enQueue(process);

    /* enQueueFront(process) is add to Front */
    void enQueueFront(process);

    /* deQueue() is Delete from Front */
    process deQueue();

    /* Sorts the queue in ascending order of Burst time*/
    void sortBurstTime();

    /* Sorts the queue in ascending order of priority i.e. Lower number implies higher priority*/
    void sortAscPriority();
    /* Sorts the queue in Descending order of priority i.e. Higher number implies higher priority*/
    void sortDescPriority();

    /* Displays Gantt chart for the queue*/
    void display();

    /* Called in the destructor to clear the queue*/
    void clearQueue();

    /* Returns true if the queue is Empty*/
    bool isEmpty();
};


#endif // QUEUE_SLL_H
