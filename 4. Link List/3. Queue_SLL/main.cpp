#include <iostream>
#include "Queue_SLL.h"
#include "stdlib.h"
#include "MyException.h"
using namespace std;

int main()
{
    int ele,choice;
    Queue_SLL LinkList_intQueue;

    do{

    cout<<"\n------------------------------------------------------------------------------\n";
    cout<<"\n\t******** Welcome To Queue Operations via Link - List ************\n";
    cout<<"\n1. Insert an element in Queue ";
    cout<<"\n2. delete an element from Queue ";

   cout<<"\n3. Display all elements of Queue";
   cout<<"\n4. Clear Queue";

   cout<<"\n5. Exit";
   cout<<"\n\n\nEnter your choice : ";
   cin>>choice;

   cout<<"\n--------------------------------------------------------------------------\n";
   switch(choice)
   {
      case 1:
      {
      cout<<"\n\nEnter the element  : ";
      cin>>ele;
      LinkList_intQueue.EnQueue(ele);
      }
        break;

	  case 2:
	  {
	     try
            {
                LinkList_intQueue.DeQueue();
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
                LinkList_intQueue.Display();
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
                LinkList_intQueue.clearQueue();
                cout<<"\n **** Queue is cleared ****";
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
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
        }
   }

 }while(1);

return 0;
}
