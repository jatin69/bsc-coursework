#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(int);
        Node* next;
        Node* previous;
        int data;
};

#endif // NODE_H
