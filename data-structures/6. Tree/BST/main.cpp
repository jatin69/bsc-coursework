#include <iostream>
#include "stdlib.h"
#include "BST.h"
#include "BST_Node.h"

using namespace std;

int main()
{
    BST mytree;
    int element;
    int choice;


    cout<<" \n\t\t\t******** BINARY TREE OPERATIONS ********* \n";

    do
    {
        cout<<"\n\n\t\t1. insert a element in binary tree ";
        cout<<"\n\t\t2. IN-order display";
        cout<<"\n\t\t3. PRE-order display";
        cout<<"\n\t\t4. POST-order display";
        cout<<"\n\t\t5. Exit";
        cout<<"\n\nEnter your choice : ";cin>>choice;
        cout<<"\n==========================================================================\n";

        switch(choice)
        {
            case 1:
            {
                cout<<"\n Enter the element :"; cin>>element;
                mytree.insertR1(mytree.root, element);
                cout<<"\n=========================================================================\n";

            }break;

            case 2:
                {
                    cout<<"\n\n [ IN-order traversal ] Tree is : \n\n\t";
                    mytree.inOrderR(mytree.root);
                    cout<<"\n=========================================================================\n";

                }break;

            case 3:
                {
                    cout<<"\n\n [ PRE-order traversal ] Tree is : \n\n\t";
                    mytree.preOrderR(mytree.root);
                    cout<<"\n=========================================================================\n";

                }break;

            case 4:
                {
                    cout<<"\n\n [ POST-order traversal ] Tree is : \n\n\t";
                    mytree.postOrderR(mytree.root);
                    cout<<"\n=========================================================================\n";

                }break;

            case 5:
            {
                cout<<"\n\t ********** User requested exit **********";
                cout<<"\n\n\tExiting ..  ..";
                cout<<"\n\n------------------------------------------------------------------------------\n";
                exit(0);
            }

    }

    }while(1);

    return 0;
}
