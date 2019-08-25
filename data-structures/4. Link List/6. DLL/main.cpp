#include <iostream>
#include "DLL.h"
#include "cstdlib"
#include "MyException.h"

using namespace std;

int main()
{

    int choice,ele,loc;
    DLL intLinkList;
    do
    {
    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"\n\t******** Welcome To Link - List Operations ************\n";

    cout<<"\n1. add to head \t\t\t3. delete from head ";
    cout<<"\n2. add to tail \t\t\t4. delete from tail";
    cout<<endl;

    cout<<"\n5. add before a data \t\t8. delete before a data ";
    cout<<"\n6. add after a data \t\t9. delete after a data ";
    cout<<"\n7. replace a data \t\t10.delete a data ";
    cout<<endl;

    cout<<"\n11.find in link list \t\t12.Reverse the link list";
    cout<<endl;
    cout<<"\n13.Display the link list \t14. Exit";

    cout<<"\n\n\nEnter your choice : ";
    cin>>choice;

    cout<<"\n------------------------------------------------------------------------------\n";
    switch(choice)
    {
    case 1:
        {
            cout<<"\nEnter the element to be inserted : ";
            cin>>ele;
            try
            {
                intLinkList.addToHead(ele);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;
    case 2:
        {
            cout<<"\nEnter the element to be inserted : ";
            cin>>ele;
            try
            {
                intLinkList.addToTail(ele);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;

    case 3:
        {
            try
            {
                intLinkList.deleteFromHead();
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;
    case 4:
        {
            try
            {
                intLinkList.deleteFromTail();
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;

    case 5:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            cout<<"\nEnter the element to be inserted : " ;
            cin>>ele;
            try
            {
                intLinkList.addBefore(loc,ele);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;
    case 6:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            cout<<"\nEnter the element to be inserted : " ;
            cin>>ele;
            try
            {
                intLinkList.addAfter(loc,ele);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;

    case 7:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            cout<<"\nEnter the element to be inserted : " ;
            cin>>ele;
            try
            {
                intLinkList.replaceData(loc,ele);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;
    case 8:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            try
            {
                intLinkList.deleteBefore(loc);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;

    case 9:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            try
            {
                intLinkList.deleteAfter(loc);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;
    case 10:
        {
            cout<<"\nEnter the location element : ";
            cin>>loc;
            try
            {
                intLinkList.deleteData(loc);
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }
        }
        break;

    case 11:
        {
            cout<<"\nenter the element to be found : ";
            cin>>ele;
            try
            {
                if(intLinkList.isInList(ele))
                {
                    cout<<"\nElement found !!!";
                }
                else
                {
                    cout<<"\nElement not found !!!";
                }
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }


        }
        break;
    case 12:
        {

            try
            {
                if(intLinkList.reverse_list())
                {
                    cout<<"\nLink List REVERSED ";
                    cout<<"\nNOW,";
                    intLinkList.Display();
                }
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }

        }
        break;
    case 13:
        {
           try
            {
                intLinkList.Display();
            }
            catch( MyException ob)
            {
                cout<<"\n\t";
                ob.printerror();
            }

        }
        break;

    case 14:
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
