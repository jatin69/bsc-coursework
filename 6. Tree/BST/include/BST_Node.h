#ifndef BST_NODE_H
#define BST_NODE_H


class BST_Node
{
      public:
        int data;
        BST_Node(int _data, BST_Node* _left =0 , BST_Node* _right =0 );
        BST_Node(const BST_Node&);
        BST_Node* left;
        BST_Node* right;

};

#endif // BST_NODE_H
