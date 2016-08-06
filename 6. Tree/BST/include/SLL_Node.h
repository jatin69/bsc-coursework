#ifndef SLL_NODE_H
#define SLL_NODE_H
#include "BST_Node.h"

class SLL_Node
{
    public:

    BST_Node* treeNode; /// this acts as a data

    SLL_Node* next;  /// this is the address of the next node to be pointed

    SLL_Node(BST_Node* _treeNode=0 , SLL_Node* _next=0);  /// cons. which accepts (data , the next node )
};

#endif // SLL_NODE_H
