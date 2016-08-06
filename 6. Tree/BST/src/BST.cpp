#include "BST.h"
#include "BST_Node.h"
#include "iostream"
#include "SLL.h"
#include "SLL_Node.h"
using namespace std;

BST::BST()
{
    root=0;
}

BST::~BST()
{
     /// THE WHOLE TREE NEEDS TO BE DELETED
}

/******************************************************************************************************************/

void BST::insertR1(BST_Node*& root , int ele)
{
    if(root==0)
    {
        root=new BST_Node(ele);
    }
    else if(ele <= root->data)
    {
        insertR1(root->left,ele);
    }
    else if( ele > root->data)
    {
            insertR1(root->right,ele);
    }
}


void BST:: insertI1(int ele)
{
    if(root==0)
    {
        root = new BST_Node(ele);
        return;
    }

    BST_Node* temp = root;
/// doubt -- while(temp->left!=0 || temp->right!=0)
    while(1)
    {
        if(ele <= temp->data)
        {
            if(temp->left==0)
            {
                temp->left = new BST_Node(ele);
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if(temp->right==0)
            {
                temp->right = new BST_Node(ele);
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

/******************************************************************************************************************/
/// working : find the appropriate position & then insert
/// when we hit a dead end . "curr" becomes 0 --- so insert at  previous position "prev"
/// drozdek method

void BST:: insertI2(int ele)
{
     if(root==0)
    {
        root = new BST_Node(ele);
        return;
    }

    BST_Node* curr = root;     /// point to current node in traversal
    BST_Node* prev = 0;     /// points to previous of curr

    while(curr!=0)
    {
        prev = curr;

        if(ele <= curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    /// here curr becomes 0 , dead end
    /// so insertion at previous
    if( ele <= prev->data )
        prev->left = new BST_Node(ele);
    else
        prev->right = new BST_Node(ele);

}

/// drozdek insertion method - Recursive
/// ( previous node , current node , element )
void BST:: insertR2(BST_Node* prev, BST_Node* curr, int ele)
{
    if(prev == 0 && curr == 0)
        return;

    if(curr==0)
    {   ///  curr becomes 0 , dead end
        /// so insertion at previous
        if(ele <= prev->data )
            prev->left = new BST_Node(ele);
        else
            prev->right = new BST_Node(ele);
    }
    else
    {
        if( ele <= curr->data)
            insertR2(curr,curr->left,ele);       /// "curr"  is essentially the previous for "curr->left"
        else
            insertR2(curr,curr->right,ele);
    }
}

/******************************************************************************************************************/
/******************************************************************************************************************/

bool BST:: noTree() const
{
    return (root==0) ;
}

/******************************************************************************************************************/

void BST::inOrderR(BST_Node* root) const
{
    if(root==0)
    {
        return;
        /* cant do  --- throw MyException("tree is empty");
        because -- we are using recursive calls here */
    }
    inOrderR(root->left);
    cout<<"   " <<root->data;
    inOrderR(root->right);
}

/// the iterative in-order is not preferred at all , for obvious reasons && Complexity
void BST::inOrderI(BST_Node* root) const
{
    BST_Node* parent=root;
    SLL stackObj;

    while(parent!=0)
    {
        while(parent!=0)
        {
            if(parent->right!=0)
                stackObj.addToHead(parent->right);

            stackObj.addToHead(parent);
            parent=parent->right;
        }
        parent=stackObj.deleteFromHead();
        while(!stackObj.isEmpty() && parent->right==0)
        {
            cout<<"  "<<parent->data;
            parent=stackObj.deleteFromHead();
        }
        cout<<"  "<<parent->data;

        if(!stackObj.isEmpty())
            parent=stackObj.deleteFromHead();
        else
            parent=0;
    }
}

/******************************************************************************************************************/

/// note : the PRE-ORDER iterative & the DFS is the same when coded
void BST::preOrderI(BST_Node* root) const
{
    if(root!=0)
    {
        SLL stackObj;
        stackObj.addToHead(root);
        BST_Node* temp;
        while(!stackObj.isEmpty())
        {
           temp=stackObj.deleteFromHead();
            cout<<"  "<<temp->data;
            if(temp->right!=0)
                stackObj.addToHead(temp->right);
            if(temp->left!=0)
                stackObj.addToHead(temp->left);
        }
    }

}

void BST::preOrderR(BST_Node* root) const
{
    if(root==0)
    {
        return;
    }
    cout<<"   " <<root->data;
    preOrderR(root->left);
    preOrderR(root->right);
}

/******************************************************************************************************************/

void BST::postOrderI(BST_Node* root) const
{
    SLL stackObj;
    BST_Node* parent=root;
    BST_Node* child =root;
    while(parent!=0)
    {
        for(;parent->left!=0;parent=parent->left)
            stackObj.addToHead(parent);

        while(parent!=0 && (parent->right==0 || parent->right==child))
        {
            cout<<"   "<<parent->data;
            child=parent;
            if(stackObj.isEmpty())
                return;
            parent=stackObj.deleteFromHead();
        }
        stackObj.addToHead(parent);
        parent=parent->right;
    }
}

void BST::postOrderR(BST_Node* root) const
{
    if(root==0)
    {
        return;
    }
    postOrderR(root->left);
    postOrderR(root->right);
    cout<<"   " <<root->data;
}

/******************************************************************************************************************/

void BST:: BFS() const
{
    if(root==0)
    {
        cout<<"\nThe tree does not exist.";
        return;
    }

    SLL queueObj;

    queueObj.addToTail(root);

    while(!queueObj.isEmpty())
    {
        BST_Node* treeNode = queueObj.deleteFromHead();

        cout<<treeNode->data<<"   ";
        queueObj.addToTail(treeNode->left);
        queueObj.addToTail(treeNode->right);
    }

}

/// note : the PRE-ORDER iterative & the DFS is the same when coded
void BST:: DFS() const
{
    if(root==0)
    {
        cout<<"\nThe tree does not exist.";
        return;
    }

    SLL stackObj;

    stackObj.addToHead(root);

    while(!stackObj.isEmpty())
    {
        BST_Node* treeNode = stackObj.deleteFromHead();

        cout<<treeNode->data<<"   ";
        stackObj.addToHead(treeNode->right);
        stackObj.addToHead(treeNode->left);
    }

}

/******************************************************************************************************************/


int BST:: calc_sum(BST_Node* root)
{
    if(root == 0)
        return 0;

    return root->data + calc_sum(root->left) + calc_sum(root->right);
}

int BST:: noOfNodes(BST_Node* root)
{
    if(root == 0)
        return 0;

    return 1 + noOfNodes(root->left) + noOfNodes(root->right);
}

/******************************************************************************************************************/

void BST:: calcMinMax(BST_Node* root)
{
    if(root==0)
        return;

    static int minimum = root->data;
    static int maximum = root->data;

    if(root->data < minimum)
        minimum = root->data;

    if(root->data > maximum)
        maximum = root->data;

    calcMinMax(root->left);
    calcMinMax(root->right);
}

int BST:: calc_height(BST_Node* root)
{
    if(root == 0)
        return 0;

    int h1 = calc_height(root->left) +1;
    int h2 = calc_height(root->right) +1;

    if(h1 > h2)
        return h1;
    else
        return h2;
}


/******************************************************************************************************************/

void BST::findAndDeleteByMerging(const int& ele)
{
    BST_Node *temp=root , *prev=0;

    while(temp!=0 && temp->data!=ele)
    {
        prev=temp;
        if(ele <= temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp==0)
    {
        cout<<"\nElement not found in the Tree\n";
        return;
    }
    else
    {
        /// if data is found at the root node
        if(temp==root)
            deleteByMerging(root);
        else if(prev->left==temp)
            deleteByMerging(prev->left);
        else
            deleteByMerging(prev->right);
    }
}


void BST::deleteByMerging(BST_Node*& treeNode)
{
        BST_Node* temp=treeNode;

        if(treeNode->right==0)              // satisfies , single child as well as no child cases
            treeNode=treeNode->left;

        else if(treeNode->left==0)
            treeNode=treeNode->right;

        else
        {
            /** this is : attaching the RIGHTMOST element of the LEFT subtree
                or commonly known as attaching the LARGEST   **/

            temp=treeNode->left;            // move to the left subtree

            while(temp->right!=0)           // find the rightmost node
            temp=temp->right;               // i.e. the largest element in the left subtree

            temp->right=treeNode->right;    /// create a link b/w the [largest element in left subtree] & [the right subtree]

            temp=treeNode;                  // treeNode is made temp as it needs to be deleted
            treeNode=treeNode->left;        /// treeNode->left is made the new "ROOT" [head of family]
        }

       delete temp;                        /// the node pointed by temp is deleted
}


/*
    else
        {
            /// this is : attaching the LEFTMOST element of the RIGHT subtree
            /// or commonly known as attaching the SMALLEST

            temp=treeNode->right;            /// move to the right subtree

            while(temp->left!=0)           /// find the leftmost node
            temp=temp->left;               /// i.e. the smallest element in the right subtree

            temp->left=treeNode->left;    /// create a link b/w the [smallest element in right subtree] & [the LEFT subtree]

            temp=treeNode;                  /// treeNode is made temp as it needs to be deleted
            treeNode=treeNode->right;        /// treeNode->right is made the new "ROOT" [head of family]
        }
*/

/******************************************************************************************************************/
/******************************************************************************************************************/


void BST::findAndDeleteByCopying(const int& ele)
{
    BST_Node *temp=root , *prev=0;

    while(temp!=0 && temp->data!=ele)
    {
        prev=temp;
        if(ele <= temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp==0)
    {
        cout<<"\nElement not found in the Tree\n";
        return;
    }
    else
    {
        // if data is found at the root node
        if(temp==root)
            deleteByCopying(root);
        else if(prev->left==temp)
            deleteByCopying(prev->left);
        else
            deleteByCopying(prev->right);
    }
}


void BST::deleteByCopying(BST_Node*& treeNode)
{
        BST_Node* temp=treeNode;
        BST_Node* previous=treeNode;

        if(treeNode->right==0)              // satisfies , single child as well as no child cases
            treeNode=treeNode->left;

        else if(treeNode->left==0)
            treeNode=treeNode->right;

        else
        {
            temp=treeNode->left;            // move to the left subtree

            previous=treeNode;

            while(temp->right!=0)           // find the rightmost node
            {
                previous=temp;
                temp=temp->right;           // i.e. the largest element in the left subtree
            }

            treeNode->data=temp->data;      /// copy the "data" from the found RIGHT MOST node to the treeNode

            /// Making of new links to Bypass temp , so that it can be deleted safely

            if(previous==treeNode)          /************ S P E C I A L  C A S E *************/
                previous->left=temp->left;
            else
                previous->right=temp->left;     /************ G E N E R A L  C A S E  *************/
        }

        delete temp;                        // the node pointed by temp is deleted
}

/**

                    ***************** S P E C I A L  C A S E  *********************
    This case arises when ,
    the first element in LEFT subtree is the RIGHT MOST element [no NODE in LEFT subtree has a right child]
    SO ,        previous is treeNode;      AND     temp is treeNode->left;
    so ,  deletion of temp is done by forming of link as :  previous->left = temp->left ;


                    ***************** G E N E R A L  C A S E  *********************
    The point is : temp [ RIGHT MOST NODE of left subtree] is to be deleted , and previous is its parent.
    Now , 1. temp can either be a leaf with NO CHILD , i.e. ( temp->left && temp->right )  is 0
    or ,  2.  have a LEFT child [ right child is NOT possible , otherwise its right child would have been the RIGHTMOST ]
    In Both the cases :     " previous->right = temp->left ; "  does the work

**/


/******************************************************************************************************************/
/******************************************************************************************************************/
