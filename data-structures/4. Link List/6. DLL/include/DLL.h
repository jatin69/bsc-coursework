#ifndef DLL_H
#define DLL_H
#include "Node.h"


class DLL
{
    public:
        DLL();
        ~DLL();

        Node* head;
        Node* tail;

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

};

#endif // DLL_H
