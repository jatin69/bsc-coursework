#ifndef SLL_H
#define SLL_H
#include "Node.h"

class Stack_SLL
{
    public:
        Node* top;

        Stack_SLL();
        ~Stack_SLL();
        bool isEmpty();
        void Display();
        int element_at_top();
        void clearStack();

        void push(int);
        int pop();

};

#endif // SLL_H
