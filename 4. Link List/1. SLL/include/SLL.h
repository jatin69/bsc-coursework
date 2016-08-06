#ifndef SLL_H
#define SLL_H
#include "Node.h"

class SLL
{
    public:
        Node* head;
        Node* tail;

        SLL();
        ~SLL();
        bool isEmpty();
        bool isInList(int);
        void Display();

        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();

        void addBefore(int,int);
        void addAfter(int,int);
        void replaceData(int,int);

        bool reverse_list();

        int deleteBefore(int);
        int deleteAfter(int);
        int deleteData(int);

    protected:
    private:
};

#endif // SLL_H
