#include "SLL_Node.h"


SLL_Node::SLL_Node(BST_Node* _treeNode , SLL_Node* _next)
{
   treeNode = _treeNode;   /// direct copying via assignment operator is possible as we have made copy cons.
   next = _next;        /// only the address copied
}

