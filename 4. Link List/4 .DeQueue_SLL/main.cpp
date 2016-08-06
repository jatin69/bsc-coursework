#include <iostream>
#include "DeQueue.h"
#include "stdlib.h"
#include "MyException.h"
using namespace std;

int main()
{

    int ele,choice;
    DeQueue LinkList_intQueue;

    do{

    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"\n\t******** Welcome To DeQueue Operations via Link - List ************\n";
    cout<<"\n1. Insert element at Front\t\t2. Insert element at Rear ";
    cout<<"\n3. Delete element from Front\t\t4. Delete element from Rear ";
    cout<<endl;

    cout<<"\n5. Display all elements of Queue\t6. Clear Queue";
    cout<<endl;

   cout<<"\n7. Exit";
   cout<<"\n\n\nEnter your choice : ";
   cin>>choice;

   cout<<"\n--------------------------------------------------------------------------\n";
   switch(choice)
   {
      case 1:
      {
      cout<<"\n\nEnter the element  : ";
      cin>>ele;
      LinkList_intQueue.addToHead(ele);
      }
        break;

      case 2:
      {
      cout<<"\n\nEnter the element  : ";
      cin>>ele;
      LinkList_intQueue.addToTail(ele);
      }
        break;

	  case 3:
	  {
	     try
            {
                LinkList_intQueue.deleteFromHead();
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
                LinkList_intQueue.deleteFromTail();
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
          try
            {
                LinkList_intQueue.Display();
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
	      try
            {
                LinkList_intQueue.clearQueue();
                cout<<"\n **** Queue is cleared ****";
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
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
        }
   }

 }while(1);

return 0;
}
