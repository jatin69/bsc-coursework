#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node* next;
        Node( int _data=-1 , Node* _node=0);
        ~Node();
    protected:
    private:
};

#endif // NODE_H
