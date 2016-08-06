#ifndef BST_H
#define BST_H
#include "BST_Node.h"


class BST
{
    private:
        void deleteByMerging(BST_Node*& );
        void deleteByCopying(BST_Node*& );

    public:
        BST_Node* root;

        BST();
        ~BST();

        bool noTree() const ;

        /// INSERTION
        void insertR1(BST_Node*& , int);
        void insertI1(int);

        void insertI2(int ele);
        void insertR2(BST_Node* , BST_Node* , int );

        /// DELETION
        void findAndDeleteByMerging(const int&);
        void findAndDeleteByCopying(const int&);

        /// TRAVERSAL
        void inOrderR(BST_Node* ) const;
        void inOrderI(BST_Node* ) const;
        void preOrderR(BST_Node*) const;
        void preOrderI(BST_Node*) const;
        void postOrderR(BST_Node*) const;
        void postOrderI(BST_Node*) const;
        void BFS() const;
        void DFS() const;

        /// other operations
        int calc_height(BST_Node*);
        int calc_sum(BST_Node*);
        int noOfNodes(BST_Node*);
        void calcMinMax(BST_Node*);




};

#endif // BST_H
