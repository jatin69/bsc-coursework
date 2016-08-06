#include <iostream>
#include "Stack_SLL.h"
#include "MyException.h"
#include "cstdlib"

using namespace std;

int main()
{

    int choice,ele;
    Stack_SLL LinkList_intStack;
    do
    {
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"\n\t******** Welcome To Stack Operations via Link - List ************\n";

    cout<<"\n1. Push ";
    cout<<"\n2. Pop";
    cout<<"\n3. Display Element at top ";
    cout<<"\n4. Display the Stack";
    cout<<"\n5. clear the stack ";
    cout<<"\n6. Exit";

    cout<<"\n\n\nEnter your choice : ";
    cin>>choice;

    cout<<"\n------------------------------------------------------------------------------\n";
    switch(choice)
    {
    case 1:
        {
            cout<<"\nEnter the element to be pushed : ";
            cin>>ele;
            LinkList_intStack.push(ele);
        }
        break;
    case 2:
        {
            try
            {
                LinkList_intStack.pop();
            }
            catch( MyException* ob)
            {
                cout<<"\n\t";
                ob->printerror();
            }
        }
        break;
    case 3:
        {
            try
            {
                cout<<LinkList_intStack.element_at_top();
                 cout<<" is the Element at top ";

            }
            catch( MyException* ob)
            {
                cout<<"\n\t";
                ob->printerror();
            }


        }
        break;

    case 4:
        {
           try
            {
                LinkList_intStack.Display();
            }
            catch( MyException* ob)
            {
                cout<<"\n\t";
                ob->printerror();
            }

        }
        break;
    case 5:
        {
            try
            {
                LinkList_intStack.clearStack();
                cout<<"\n **** Stack is cleared ****";
            }
            catch( MyException* ob)
            {
                cout<<"\n\t";
                ob->printerror();
            }
        }
        break;

    case 6:
        {
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
        }
    }

    }while(1);
}

