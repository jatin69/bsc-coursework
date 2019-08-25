#ifndef SLL_H
#define SLL_H
#include "SLL_Node.h"

class SLL
{
    private:
        SLL_Node* head;
        SLL_Node* tail;

    public:
        SLL();
        bool isEmpty() const;
        void addToHead(BST_Node*);
        void addToTail(BST_Node*);
        BST_Node* deleteFromHead();
        ~SLL();

};

#endif // SLL_H
