#ifndef CIRCULAR_SLL_H
#define CIRCULAR_SLL_H
#include "Node.h"


class Circular_SLL
{
    public:
        Circular_SLL();

        Node* head;
        Node* tail;

        bool isEmpty();
        bool isInList(int);
        void Display();

        void addToTail(int);
        int deleteFromHead();
        bool reverse_list();
        void clearQueue();

};

#endif // CIRCULAR_SLL_H
