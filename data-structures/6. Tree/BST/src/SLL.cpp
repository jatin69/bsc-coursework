#include "SLL.h"
#include<iostream>
#include "SLL.h"

using namespace std;

SLL::SLL()
{
   head = tail =0;
}

SLL::~SLL()
{
    SLL_Node* temp;

    while(head)
    {
       temp = head;
       head = head-> next;
       delete temp;
    }
}

bool SLL:: isEmpty() const
{
    if(head == 0 && tail == 0)
        return true;

    return false;
}

void SLL:: addToHead(BST_Node* treeNode)
{
    if(treeNode==0)
        return;

    if(head == 0)
    {
        head = new SLL_Node(treeNode);
        tail = head;
    }
    else
    {
        SLL_Node* temp = new SLL_Node (treeNode,head);
        head = temp;
    }
}

void SLL:: addToTail(BST_Node* treeNode)
{
    if(treeNode==0)
        return;

    if(tail == 0)
    {
        tail = new SLL_Node(treeNode);
        head = tail;
    }
    else
    {
        tail->next  = new SLL_Node(treeNode);
        tail = tail->next;
    }
}


BST_Node* SLL:: deleteFromHead()
{
    BST_Node* treeNode = head->treeNode;

    if(head==tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        SLL_Node* temp = head;
        head = head->next;
        delete temp;
    }

    return treeNode;
}
