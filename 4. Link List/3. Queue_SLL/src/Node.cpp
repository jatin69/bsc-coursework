#include "Node.h"

Node::Node( int _data, Node* _node)
{
    data=_data;
    next=_node;
}


Node::~Node()
{

}
