#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "Node.h"


class DeQueue
{
    public:
        /** Default constructor */
        DeQueue();
        /** Default destructor */
        ~DeQueue();

        Node* Front;
        Node* Rear;

        bool isEmpty();
        void Display();

        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();

        void clearQueue();

    protected:
    private:
};


#endif // DEQUEUE_H


