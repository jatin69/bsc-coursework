#ifndef QUEUE_SLL_H
#define QUEUE_SLL_H
#include "Node.h"


class Queue_SLL
{
    public:
        /** Default constructor */
        Queue_SLL();
        /** Default destructor */
        ~Queue_SLL();

        Node* Front;
        Node* Rear;

        bool isEmpty();
        void Display();
        void EnQueue(int);
        int DeQueue();
        void clearQueue();



    protected:
    private:
};

#endif // QUEUE_SLL_H
