#include "BST_Node.h"

BST_Node::BST_Node(int _data, BST_Node* _left , BST_Node* _right )
{
  data = _data;
  left = _left;
  right = _right;
}

BST_Node:: BST_Node(const BST_Node& treeNode)
{
	data = treeNode.data;
	left = treeNode.left;
	right = treeNode.right;
}
